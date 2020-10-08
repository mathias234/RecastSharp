using System;
using System.IO;
using System.Runtime.InteropServices;

namespace RecastSharp.DetourNative
{
    public unsafe struct DtNavMeshCreateParams
    {
        public ushort* Verts;
        public int VertCount;
        public ushort* Polys;
        public ushort* PolyFlags;
        public byte* PolyAreas;
        public int PolyCount;
        public int Nvp;

        public uint* DetailMeshes;
        public float* DetailVerts;
        public int DetailVertsCount;
        public byte* DetailTris;
        public int DetailTriCount;

        public float* OffMeshConVerts;
        public float* OffMeshConRad;
        public ushort* OffMeshConFlags;
        public byte* OffMeshConAreas;
        public byte* OffMeshConDir;
        public uint* OffMeshConUserId;
        public int OffMeshConCount;

        public uint UserId;
        public int TileX;
        public int TileY;
        public int TileLayer;
        public float* BMin;
        public float* BMax;

        public float WalkableHeight;
        public float WalkableRadius;
        public float WalkableClimb;
        public float Cs;
        public float Ch;

        public bool BuildBvTree;

        // A simple helper for Marshal.AllocHGlobal
        private unsafe static T* AllocHGlobal<T>(int ele) where T : unmanaged
        {
            var size = ele * sizeof(T);
            if(size > 0) { 
                return (T*)Marshal.AllocHGlobal(size);
            }
            else
            {
                return (T*)0;
            }
        }

        public static DtNavMeshCreateParams Deserialize(Stream stream)
        {
            var dtParams = new DtNavMeshCreateParams();

            using (var br = new BinaryReader(stream))
            {
                // Poly Mesh
                dtParams.VertCount = br.ReadInt32();
                dtParams.Verts = AllocHGlobal<ushort>(dtParams.VertCount * 3);
                for (int i = 0; i < dtParams.VertCount * 3; i++)
                {
                    dtParams.Verts[i] = br.ReadUInt16();
                }

                dtParams.PolyCount = br.ReadInt32();
                dtParams.Nvp = br.ReadInt32();
                dtParams.Polys = AllocHGlobal<ushort>(dtParams.PolyCount * 2 * dtParams.Nvp);
                for (int i = 0; i < dtParams.PolyCount * 2 * dtParams.Nvp; i++)
                {
                    dtParams.Polys[i] = br.ReadUInt16();
                }

                dtParams.PolyAreas = AllocHGlobal<byte>(dtParams.PolyCount);
                dtParams.PolyFlags = AllocHGlobal<ushort>(dtParams.PolyCount);
                for (int i = 0; i < dtParams.PolyCount; i++)
                {
                    dtParams.PolyAreas[i] = br.ReadByte();
                    dtParams.PolyFlags[i] = br.ReadUInt16();
                }

                // Detail poly mesh
                dtParams.DetailMeshes = AllocHGlobal<uint>(dtParams.PolyCount * 4);
                for (int i = 0; i < dtParams.PolyCount * 4; i++)
                {
                    dtParams.DetailMeshes[i] = br.ReadUInt32();
                }

                dtParams.DetailVertsCount = br.ReadInt32();
                dtParams.DetailVerts = AllocHGlobal<float>(dtParams.DetailVertsCount * 3);
                for (int i = 0; i < dtParams.DetailVertsCount * 3; i++)
                {
                    dtParams.DetailVerts[i] = br.ReadSingle();
                }

                dtParams.DetailTriCount = br.ReadInt32();
                dtParams.DetailTris = AllocHGlobal<byte>(dtParams.DetailTriCount * 4);
                for (int i = 0; i < dtParams.DetailTriCount * 4; i++)
                {
                    dtParams.DetailTris[i] = br.ReadByte();
                }

                // Offmesh Connections
                dtParams.OffMeshConCount = br.ReadInt32();
                dtParams.OffMeshConVerts = AllocHGlobal<float>(dtParams.OffMeshConCount * 6);
                for (int i = 0; i < dtParams.OffMeshConCount * 6; i++)
                {
                    dtParams.OffMeshConVerts[i] = br.ReadSingle();
                }

                dtParams.OffMeshConFlags = AllocHGlobal<ushort>(dtParams.OffMeshConCount);
                dtParams.OffMeshConAreas = AllocHGlobal<byte>(dtParams.OffMeshConCount);
                dtParams.OffMeshConDir = AllocHGlobal<byte>(dtParams.OffMeshConCount);
                dtParams.OffMeshConUserId = AllocHGlobal<uint>(dtParams.OffMeshConCount);
                for (int i = 0; i < dtParams.OffMeshConCount; i++)
                {
                    dtParams.OffMeshConFlags[i] = br.ReadUInt16();
                    dtParams.OffMeshConAreas[i] = br.ReadByte();
                    dtParams.OffMeshConDir[i] = br.ReadByte();
                    dtParams.OffMeshConUserId[i] = br.ReadUInt32();
                }

                // Tile attributes

                dtParams.UserId = br.ReadUInt32();
                dtParams.TileX = br.ReadInt32();
                dtParams.TileY = br.ReadInt32();
                dtParams.TileLayer = br.ReadInt32();

                dtParams.BMin = AllocHGlobal<float>(3);
                dtParams.BMin[0] = br.ReadSingle();
                dtParams.BMin[1] = br.ReadSingle();
                dtParams.BMin[2] = br.ReadSingle();

                dtParams.BMax = AllocHGlobal<float>(3);
                dtParams.BMax[0] = br.ReadSingle();
                dtParams.BMax[1] = br.ReadSingle();
                dtParams.BMax[2] = br.ReadSingle();

                // General Config
                dtParams.WalkableHeight = br.ReadSingle();
                dtParams.WalkableRadius = br.ReadSingle();
                dtParams.WalkableClimb = br.ReadSingle();
                dtParams.Cs = br.ReadSingle();
                dtParams.Ch = br.ReadSingle();

                dtParams.BuildBvTree = br.ReadBoolean();

            }

            return dtParams;
        }



        public void Serialize(Stream stream)
        {
            using (var bw = new BinaryWriter(stream))
            {
                // Poly Mesh

                bw.Write(VertCount);
                for (int i = 0; i < VertCount * 3; i++)
                {
                    bw.Write(Verts[i]);
                }

                bw.Write(PolyCount);
                bw.Write(Nvp);
                for (int i = 0; i < PolyCount * 2 * Nvp; i++)
                {
                    bw.Write(Polys[i]);
                }
                for (int i = 0; i < PolyCount; i++)
                {
                    bw.Write(PolyAreas[i]);
                    bw.Write(PolyFlags[i]);
                }

                // Detail Poly Mesh
                for (int i = 0; i < PolyCount * 4; i++)
                {
                    bw.Write(DetailMeshes[i]);
                }
                bw.Write(DetailVertsCount);
                for (int i = 0; i < DetailVertsCount * 3; i++)
                {
                    bw.Write(DetailVerts[i]);
                }
                bw.Write(DetailTriCount);
                for (int i = 0; i < DetailTriCount * 4; i++)
                {
                    bw.Write(DetailTris[i]);
                }

                // Offmesh Connections
                bw.Write(OffMeshConCount);
                for (int i = 0; i < OffMeshConCount * 6; i++)
                {
                    bw.Write(OffMeshConVerts[i]);
                }

                for (int i = 0; i < OffMeshConCount; i++)
                {
                    bw.Write(OffMeshConFlags[i]);
                    bw.Write(OffMeshConAreas[i]);
                    bw.Write(OffMeshConDir[i]);
                    bw.Write(OffMeshConUserId[i]);
                }

                // Tile Attributes
                bw.Write(UserId);
                bw.Write(TileX);
                bw.Write(TileY);
                bw.Write(TileLayer);

                bw.Write(BMin[0]);
                bw.Write(BMin[1]);
                bw.Write(BMin[2]);

                bw.Write(BMax[0]);
                bw.Write(BMax[1]);
                bw.Write(BMax[2]);

                // General config

                bw.Write(WalkableHeight);
                bw.Write(WalkableRadius);
                bw.Write(WalkableClimb);
                bw.Write(Cs);
                bw.Write(Ch);

                bw.Write(BuildBvTree);
            }
        }
    }
}

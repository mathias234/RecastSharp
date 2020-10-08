using System.IO;

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

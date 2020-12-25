using System;
using System.Collections.Generic;
using System.IO;
using RecastSharp;
using RecastSharp.DetourNative;
using RecastSharp.RecastNative;

namespace RecastSharpTest
{
    class Program
    {
        static void Main(string[] args)
        {
            using(var stream = new FileStream("G:/Navmeshes/566.dat", FileMode.Open))
            using (var br = new BinaryReader(stream))
            {
                var navmesh = DetourNative.dtwAllocNavMesh();
                var navmeshParams = new DtNavMeshParams();

                var worldOrig = new float[]
                {
                        br.ReadSingle(),
                        br.ReadSingle(),
                        br.ReadSingle()
                };

                float tileSize = br.ReadSingle();
                int tileCount = br.ReadInt32();

                navmeshParams.OrigX = worldOrig[0];
                navmeshParams.OrigY = worldOrig[1];
                navmeshParams.OrigZ = worldOrig[2];

                navmeshParams.TileWidth = tileSize;
                navmeshParams.TileHeight = tileSize;
                navmeshParams.MaxTiles = tileCount;
                int maxPolys = 0;
                List<DtNavMeshCreateParams> createParams = new List<DtNavMeshCreateParams>();
                for(int i = 0; i < tileCount; i++)
                {
                    var dtcp = DtNavMeshCreateParams.Deserialize(stream);
                    if (dtcp.PolyCount > maxPolys)
                        maxPolys = dtcp.PolyCount;

                    createParams.Add(dtcp);
                }

                navmeshParams.MaxPolys = maxPolys;
                Console.WriteLine("Max Polys" + maxPolys);

                var status = DetourNative.dtwNavMesh_Init(navmesh, ref navmeshParams);
                if (DetourNative.dtwStatusFailed(status))
                {
                    Console.WriteLine("Failed to init navmesh error code: " + status);
                    return;
                }
            }
        }
    }
}

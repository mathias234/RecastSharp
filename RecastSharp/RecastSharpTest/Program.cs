using System;
using RecastSharp;
using RecastSharp.RecastNative;

namespace RecastSharpTest
{
    class Program
    {
        unsafe static void Main(string[] args)
        {
            int ntris = 50;

            var ctx = RecastNative.rcwAllocContext();

            float[] bmin = new float[3];
            float[] bmax = new float[3];
            bmax[0] = 100;
            bmax[1] = 100;
            bmax[2] = 100;

            float cs = 0.2f;
            float ch = 0.2f;

            float walkableSlopAngle = 50;

            int width = 0;
            int height = 0;


            RecastNative.rcwCalcGridSize(ref bmin[0], ref bmax[0], cs, ref width, ref height);

            Console.WriteLine("Width: " + width + " Height: " + height);

            var solid = RecastNative.rcwAllocHeightfield();
            if(solid == IntPtr.Zero) {
                Console.WriteLine("Failed to allocated heightfield");
                return;
            }

            if (!RecastNative.rcwCreateHeightfield(ctx, solid, width, height, ref bmin[0], ref bmax[0], cs, ch))
            {
                Console.WriteLine("Failed to create heightfield");
                return;
            }

            var triareas = new byte[ntris];

            RecastNative.rcwMarkWalkableTriangles(ctx, walkableSlopAngle, );

            RecastNative.rcwFreeHeightfield(solid);
            RecastNative.rcwFreeContext(ctx);

            Console.ReadLine();
        }
    }
}

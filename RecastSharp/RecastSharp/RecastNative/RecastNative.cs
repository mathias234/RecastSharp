using System;
using System.Runtime.InteropServices;

namespace RecastSharp.RecastNative
{
    public unsafe class RecastNative
    {
#if Win32
        private const string DLL_NAME = "RecastWrapper32";
#elif LINUX
        private const string DLL_NAME = "libRecastWrapper64";
#elif MACOS
        private const string DLL_NAME = "libRecastWrapper64";
#else 
        private const string DLL_NAME = "RecastWrapper64";
#endif


        /* Context */
        [DllImport(DLL_NAME)]
        public static extern IntPtr rcwAllocContext();
        [DllImport(DLL_NAME)]
        public static extern void rcwFreeContext(IntPtr ctx);


        /* Heightfield */
        [DllImport(DLL_NAME)]
        public static extern IntPtr rcwAllocHeightfield();

        [DllImport(DLL_NAME)]
        public static extern void rcwFreeHeightfield(IntPtr hf);

        [DllImport(DLL_NAME)]
        public static extern bool rcwCreateHeightfield(IntPtr ctx, IntPtr hf, int width, int height, ref float bmin, ref float bmax, float cs, float ch);

        [DllImport(DLL_NAME)]
        public static extern void rcwMarkWalkableTriangles(IntPtr ctx, float walkableSlopeAngle, float* verts, int nv, int* tris, int nt, byte* areas);

        [DllImport(DLL_NAME)]
        public static extern bool rcwRasterizeTriangles(IntPtr ctx, float* verts, int nv, int* tris, byte* areas, int nt, IntPtr hf, int flagMergeThr = 1);

        [DllImport(DLL_NAME)]
        public static extern void rcwFilterLowHangingWalkableObstacles(IntPtr ctx, int walkableClimb, IntPtr hf);

        [DllImport(DLL_NAME)]
        public static extern void rcwFilterLedgeSpans(IntPtr ctx, int walkableHeight, int walkableClimb, IntPtr hf);

        [DllImport(DLL_NAME)]
        public static extern void rcwFilterWalkableLowHeightSpans(IntPtr ctx, int walkableHeight, IntPtr hf);

        /* CompactHeightfield */
        [DllImport(DLL_NAME)]
        public static extern IntPtr rcwAllocCompactHeightfield();

        [DllImport(DLL_NAME)]
        public static extern void rcwFreeCompactHeightfield(IntPtr hf);

        [DllImport(DLL_NAME)]
        public static extern bool rcwBuildCompactHeightfield(IntPtr ctx, int walkableHeight, int walkableClimb, IntPtr hf, IntPtr chf);

        [DllImport(DLL_NAME)]
        public static extern bool rcwErodeWalkableArea(IntPtr ctx, int radius, IntPtr chf);

        [DllImport(DLL_NAME)]
        public static extern void rcwMarkConvexPolyArea(IntPtr ctx, float* verts, int nverts, float hmin, float hmax, byte areaId, IntPtr chf);

        [DllImport(DLL_NAME)]
        public static extern bool rcwBuildDistanceField(IntPtr ctx, IntPtr chf);

        [DllImport(DLL_NAME)]
        public static extern bool rcwBuildRegions(IntPtr ctx, IntPtr chf, int borderSize, int minRegionArea, int mergeRegionArea);

        [DllImport(DLL_NAME)]
        public static extern bool rcwBuildRegionsMonotone(IntPtr ctx, IntPtr chf, int borderSize, int minRegionArea, int mergeRegionArea);

        [DllImport(DLL_NAME)]
        public static extern bool rcwBuildLayerRegions(IntPtr ctx, IntPtr chf, int borderSize, int minRegionArea);

        /* ContourSet */ 
        [DllImport(DLL_NAME)]
        public static extern IntPtr rcwAllocContourSet();

        [DllImport(DLL_NAME)]
        public static extern void rcwFreeContourSet(IntPtr cset);

        [DllImport(DLL_NAME)]
        public static extern bool rcwBuildContours(IntPtr ctx, IntPtr chf, float maxError, int maxEdgeLen, IntPtr cset, int buildFlags = 1);

        /* PolyMesh */
        [DllImport(DLL_NAME)]
        public static extern IntPtr rcwAllocPolyMesh();

        [DllImport(DLL_NAME)]
        public static extern void rcwFreePolyMesh(IntPtr pmesh);

        [DllImport(DLL_NAME)]
        public static extern bool rcwBuildPolyMesh(IntPtr ctx, IntPtr cset, int nvp, IntPtr mesh);

        /* PolyMeshDetail */
        [DllImport(DLL_NAME)]
        public static extern IntPtr rcwAllocPolyMeshDetail();

        [DllImport(DLL_NAME)]
        public static extern void rcwFreePolyMeshDetail(IntPtr dmesh);

        [DllImport(DLL_NAME)]
        public static extern bool rcwBuildPolyMeshDetail(IntPtr ctx, IntPtr mesh, IntPtr chf, float sampleDist, float sampleMaxError, IntPtr dmesh);

        /* Utils */
        [DllImport(DLL_NAME)]
        public static extern void rcwVCopy(float* dest, float* v);

        [DllImport(DLL_NAME)]
        public static extern void rcwCalcGridSize(ref float bmin, ref float bmax, float cs, ref int w, ref int h);

    }
}

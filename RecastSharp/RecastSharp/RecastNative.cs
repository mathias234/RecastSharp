using System;
using System.Runtime.InteropServices;

namespace RecastSharp
{
    public unsafe class RecastNative
    {
        private const string DLL_NAME = "native/RecastWrapper";

        /* Heightfield */
        [DllImport(DLL_NAME)]
        public static extern IntPtr rcwAllocHeightfield();

        [DllImport(DLL_NAME)]
        public static extern void rcwFreeHeightField(IntPtr hf);

        [DllImport(DLL_NAME)]
        public static extern bool rcwCreateHeightfield(IntPtr ctx, IntPtr hf, int width, int height, float* bmin, float* bmax, float cs, float ch);

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

        /* PolyMeshDetail */
        [DllImport(DLL_NAME)]
        public static extern IntPtr rcwAllocPolyMeshDetail();

        [DllImport(DLL_NAME)]
        public static extern void rcwFreePolyMeshDetail(IntPtr dmesh);

        /* Utils */
        [DllImport(DLL_NAME)]
        public static extern void rcwVCopy(float* dest, float* v);

        [DllImport(DLL_NAME)]
        public static extern void rcwCalcGridSize(float* bmin, float* bmax, float cs, int* w, int* h);

    }
}

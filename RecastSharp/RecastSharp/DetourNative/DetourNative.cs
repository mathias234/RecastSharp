using System;
using System.Runtime.InteropServices;

namespace RecastSharp.DetourNative
{
    [Flags]
    public enum DtwStatus : uint
    {
        // High level status.
        Failure = 1u << 31,            // Operation failed.
        Success = 1u << 30,            // Operation succeed.
        InProgress = 1u << 29,        // Operation still in progress.
        WrongMagic = 1 << 0,      // Input data is not recognized.
        WrongVersion = 1 << 1,    // Input data is in wrong version.
        OutOfMemory = 1 << 2,    // Operation ran out of memory.
        InvalidParam = 1 << 3,    // An input parameter was invalid.
        BufferToSmall = 1 << 4, // Result buffer for the query was too small to store all results.
        OutOfNodes = 1 << 5,     // Query ran out of nodes during search.
        PartialResult = 1 << 6,   // Query did not reach the end location, returning best guess. 
        AlreadyOccupied = 1 << 7, // A tile has already been assigned to the given x,y coordinate
    }

    public unsafe class DetourNative
    {
#if Win32
        private const string DLL_NAME = "runtimes/RecastWrapper32";
#elif LINUX
        private const string DLL_NAME = "runtimes/libRecastWrapper64";
#else
        private const string DLL_NAME = "runtimes/RecastWrapper64";
#endif

        [DllImport(DLL_NAME)]
        public static extern void dtwFree(IntPtr ptr);

        [DllImport(DLL_NAME)]
        public static extern bool dtwCreateNavMeshData(ref DtNavMeshCreateParams createParams, out byte* outData, out int outDataSize);

        [DllImport(DLL_NAME)]
        public static extern IntPtr dtwAllocNavMesh();

        [DllImport(DLL_NAME)]
        public static extern DtwStatus dtwNavMesh_Init(IntPtr navmesh, ref DtNavMeshParams dtParams);

        [DllImport(DLL_NAME)]
        public static extern DtwStatus dtwNavMesh_AddTile(IntPtr navmesh, byte* data, int dataSize, int flags, int lastRef, IntPtr result);

        [DllImport(DLL_NAME)]
        public static extern DtwStatus dtwNavMesh_RemoveTile(IntPtr navmesh, int tileRef, out byte* data, out int dataSize);

        [DllImport(DLL_NAME)]
        public static extern int dtwNavMesh_GetTileRefAt(IntPtr navmesh, int x, int y, int layer);


        [DllImport(DLL_NAME)]
        public static extern IntPtr dtwAllocPolyRef();

        [DllImport(DLL_NAME)]
        public static extern IntPtr dtwAllocQueryFilter();

        [DllImport(DLL_NAME)]
        public static extern IntPtr dtwAllocNavMeshQuery();

        [DllImport(DLL_NAME)]
        public static extern DtwStatus dtwNavMeshQuery_Init(IntPtr query, IntPtr navmesh, int maxNodes);

        [DllImport(DLL_NAME)]
        public static extern DtwStatus dtwNavMeshQuery_FindNearestPoly(
            IntPtr query,
            ref float center,
            ref float halfExtents,
            IntPtr filter,
            ref int nearestRef,
            ref float nearestPt
        );

        [DllImport(DLL_NAME)]
        public static extern DtwStatus dtwNavMeshQuery_FindPath(
            IntPtr query,
            int startRef, int endRef,
            ref float startPos, ref float endPos,
            IntPtr filter, ref int path, out int pathCount, int maxPath
        );

        [DllImport(DLL_NAME)]
        public static extern DtwStatus dtwNavMeshQuery_FindStraightPath(
            IntPtr query,
            ref float startPos, ref float endPos,
            ref int path, int pathSize,
            ref float straightPath, ref byte straightPathFlags, ref int straightPathRefs,
	        out int straightPathCount, int maxStraightPath, int options = 0);

        [DllImport(DLL_NAME)]
        public static extern bool dtwStatusSucceed(DtwStatus status);

        [DllImport(DLL_NAME)]
        public static extern bool dtwStatusFailed(DtwStatus status);

        [DllImport(DLL_NAME)]
        public static extern bool dtwStatusInProgress(DtwStatus status);

        [DllImport(DLL_NAME)]
        public static extern bool dtwStatusDetail(DtwStatus status, uint detail);
    }
}

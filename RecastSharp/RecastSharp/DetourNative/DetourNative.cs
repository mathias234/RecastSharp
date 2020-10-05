using System;
using System.Runtime.InteropServices;

namespace RecastSharp.DetourNative
{
    public unsafe class DetourNative
    {
        private const string DLL_NAME = "native/RecastWrapper";

        [DllImport(DLL_NAME)]
        public static extern void dtwFree(IntPtr ptr);

        [DllImport(DLL_NAME)]
        public static extern bool dtwCreateNavMeshData(DtNavMeshCreateParams* createParams, byte** outData, int* outDataSize);

        [DllImport(DLL_NAME)]
        public static extern IntPtr dtwAllocNavMesh();

        [DllImport(DLL_NAME)]
        public static extern bool dtwStatusSucceed(int status);

        [DllImport(DLL_NAME)]
        public static extern bool dtwStatusFailed(int status);

        [DllImport(DLL_NAME)]
        public static extern bool dtwStatusInProgress(int status);

        [DllImport(DLL_NAME)]
        public static extern bool dtwStatusDetail(int status, uint detail);
    }
}

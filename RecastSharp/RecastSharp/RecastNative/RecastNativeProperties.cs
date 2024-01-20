using System;
using System.Collections.Generic;
using System.Runtime.InteropServices;
using System.Text;

namespace RecastSharp.RecastNative
{
    public unsafe class RecastNativeProperties
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


        /* PolyMesh */
        [DllImport(DLL_NAME)]
        public static extern void polyMesh_GetVerts(IntPtr mesh, out ushort* verts, out int nverts);

        [DllImport(DLL_NAME)]
        public static extern void polyMesh_GetPolys(IntPtr mesh, out ushort* polys, out int npolys);

        [DllImport(DLL_NAME)]
        public static extern void polyMesh_GetPolyAreas(IntPtr mesh, out byte* areas);

        [DllImport(DLL_NAME)]
        public static extern void polyMesh_GetPolyFlags(IntPtr mesh, out ushort* areas);

        [DllImport(DLL_NAME)]
        public static extern void polyMesh_GetVertsPerPoly(IntPtr mesh, out int nvp);

        [DllImport(DLL_NAME)]
        public static extern void polyMesh_GetBmin(IntPtr mesh, out float* bmin);
        [DllImport(DLL_NAME)]
        public static extern void polyMesh_GetBmax(IntPtr mesh, out float* max);



        /* DetailPolyMesh */

        [DllImport(DLL_NAME)]
        public static extern void detailMesh_GetMeshes(IntPtr mesh, out uint* meshes, out int nmeshes);

        [DllImport(DLL_NAME)]
        public static extern void detailMesh_GetVerts(IntPtr mesh, out float* verts, out int nverts);

        [DllImport(DLL_NAME)]
        public static extern void detailMesh_GetTris(IntPtr mesh, out byte* tris, out int ntris);
    }
}

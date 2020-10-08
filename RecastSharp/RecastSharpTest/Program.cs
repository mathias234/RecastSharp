using System;
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
            var dtParams = DtNavMeshCreateParams.Deserialize(new FileStream("G:/Navmeshes/540.dat", FileMode.Open));
        }
    }
}

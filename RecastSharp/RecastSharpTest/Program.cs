using System;
using RecastSharp;

namespace RecastSharpTest
{
    class Program
    {
        unsafe static void Main(string[] args)
        {
            var hf = RecastNative.rcwAllocHeightfield();
            Console.WriteLine("Address of allocated heightfield " + hf);
            RecastNative.rcwFreeHeightField(hf);

            var test = new float[3];
            test[0] = 1;
            test[1] = 2;
            test[2] = 3;
            float[] result = new float[3];

            
            fixed (float* ptr = &test[0])
            fixed (float* ptr1 = &result[0])
            {
                RecastNative.rcwVCopy(ptr1, ptr);
            }

            Console.WriteLine("X " + result[0]);
            Console.WriteLine("Y " + result[1]);
            Console.WriteLine("Z " + result[2]);

        }
    }
}

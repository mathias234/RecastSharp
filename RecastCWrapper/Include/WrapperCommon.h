#ifndef WRAPPER_COMMON_H
#define WRAPPER_COMMON_H


#if _MSC_VER
#define EXPORT_API extern "C" __declspec(dllexport)
#else
#define EXPORT_API extern "C"
#endif

#define rcwHeightfield int
#define rcwContext int
#define rcwCompactHeightfield int
#define rcwContourSet int
#define rcwPolyMesh int
#define rcwPolyMeshDetail int

#endif
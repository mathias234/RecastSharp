#ifndef WRAPPER_COMMON_H
#define WRAPPER_COMMON_H


#if _MSC_VER
#define EXPORT_API extern "C" __declspec(dllexport)
#else
#define EXPORT_API extern "C"
#endif

#define rcwType int

#define rcwHeightfield rcwType
#define rcwContext rcwType
#define rcwCompactHeightfield rcwType
#define rcwContourSet rcwType
#define rcwPolyMesh rcwType
#define rcwPolyMeshDetail rcwType

#define dtwNavMeshCreateParams rcwType
#define dtwNavMesh rcwType
#define dtwNavMeshQuery rcwType
#define dtwStatus rcwType
#define dtwNavMeshParams rcwType
#define dtwTileRef rcwType
#define dtwPolyRef rcwType
#define dtwQueryFilter rcwType

#endif
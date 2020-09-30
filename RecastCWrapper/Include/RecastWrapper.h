#ifndef RECAST_WRAPPER_H
#define RECAST_WRAPPER_H

#include "WrapperCommon.h"

#define rcwHeightfield int
#define rcwContext int
#define rcwCompactHeightfield int
#define rcwContourSet int
#define rcwPolyMesh int
#define rcwPolyMeshDetail int

EXPORT_API void rcwVCopy(float* dest, const float* v);

EXPORT_API void rcwCalcGridSize(const float* bmin, const float* bmax, float cs, int* w, int* h);

EXPORT_API rcwHeightfield* rcwAllocHeightfield();

EXPORT_API void rcwFreeHeightField(rcwHeightfield* hf);

EXPORT_API bool rcwCreateHeightfield(rcwContext* ctx, rcwHeightfield& hf, int width, int height,
	const float* bmin, const float* bmax,
	float cs, float ch);

EXPORT_API void rcwMarkWalkableTriangles(rcwContext* ctx, const float walkableSlopeAngle, const float* verts, int nv,
	const int* tris, int nt, unsigned char* areas);

EXPORT_API bool rcwRasterizeTriangles(rcwContext* ctx, const float* verts, const int nv,
	const int* tris, const unsigned char* areas, const int nt,
	rcwHeightfield& solid, const int flagMergeThr = 1);

EXPORT_API void rcwFilterLowHangingWalkableObstacles(rcwContext* ctx, const int walkableClimb, rcwHeightfield& solid);

EXPORT_API void rcwFilterLedgeSpans(rcwContext* ctx, const int walkableHeight,
	const int walkableClimb, rcwHeightfield& solid);

EXPORT_API void rcwFilterWalkableLowHeightSpans(rcwContext* ctx, int walkableHeight, rcwHeightfield& solid);

EXPORT_API rcwCompactHeightfield* rcwAllocCompactHeightfield();
EXPORT_API void rcwFreeCompactHeightfield(rcwCompactHeightfield* chf);

EXPORT_API bool rcwErodeWalkableArea(rcwContext* ctx, int radius, rcwCompactHeightfield& chf);

EXPORT_API void rcwMarkConvexPolyArea(rcwContext* ctx, const float* verts, const int nverts,
	const float hmin, const float hmax, unsigned char areaId,
	rcwCompactHeightfield& chf);

EXPORT_API bool rcwBuildDistanceField(rcwContext* ctx, rcwCompactHeightfield& chf);

EXPORT_API bool rcwBuildRegions(rcwContext* ctx, rcwCompactHeightfield& chf,
	const int borderSize, const int minRegionArea, const int mergeRegionArea);

EXPORT_API bool rcwBuildRegionsMonotone(rcwContext* ctx, rcwCompactHeightfield& chf,
	const int borderSize, const int minRegionArea, const int mergeRegionArea);

EXPORT_API bool rcwBuildLayerRegions(rcwContext* ctx, rcwCompactHeightfield& chf,
	const int borderSize, const int minRegionArea);

EXPORT_API rcwContourSet* rcwAllocContourSet();

EXPORT_API void rcwFreeContourSet(rcwContourSet* cset);

EXPORT_API bool rcwBuildContours(rcwContext* ctx, rcwCompactHeightfield& chf,
	const float maxError, const int maxEdgeLen,
	rcwContourSet& cset, const int buildFlags = 1);

EXPORT_API rcwPolyMesh* rcwAllocPolyMesh();
EXPORT_API void rcwFreePolyMesh(rcwPolyMesh* pmesh);

EXPORT_API bool rcwBuildPolyMesh(rcwContext* ctx, rcwContourSet& cset, const int nvp, rcwPolyMesh& mesh);

EXPORT_API rcwPolyMeshDetail* rcwAllocPolyMeshDetail();
EXPORT_API void rcwFreePolyMeshDetail(rcwPolyMeshDetail* dmesh);


#endif
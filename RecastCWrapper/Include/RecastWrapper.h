#ifndef RECAST_WRAPPER_H
#define RECAST_WRAPPER_H

#include "WrapperCommon.h"


/* Context */
EXPORT_API rcwContext* rcwAllocContext();
EXPORT_API void rcwFreeContext(rcwContext* ctx);


/* Heightfield */

EXPORT_API rcwHeightfield* rcwAllocHeightfield();

EXPORT_API void rcwFreeHeightfield(rcwHeightfield* hf);

EXPORT_API bool rcwCreateHeightfield(rcwContext* ctx, rcwHeightfield& hf, int width, int height,
	float* bmin, float* bmax,
	float cs, float ch);

EXPORT_API void rcwMarkWalkableTriangles(rcwContext* ctx, float walkableSlopeAngle, float* verts, int nv,
	int* tris, int nt, unsigned char* areas);

EXPORT_API bool rcwRasterizeTriangles(rcwContext* ctx, float* verts, int nv,
	int* tris, unsigned char* areas, int nt,
	rcwHeightfield& solid, int flagMergeThr = 1);

EXPORT_API void rcwFilterLowHangingWalkableObstacles(rcwContext* ctx, int walkableClimb, rcwHeightfield& solid);

EXPORT_API void rcwFilterLedgeSpans(rcwContext* ctx, int walkableHeight,
	int walkableClimb, rcwHeightfield& solid);

EXPORT_API void rcwFilterWalkableLowHeightSpans(rcwContext* ctx, int walkableHeight, rcwHeightfield& solid);

/* CompactHeightfield */

EXPORT_API rcwCompactHeightfield* rcwAllocCompactHeightfield();
EXPORT_API void rcwFreeCompactHeightfield(rcwCompactHeightfield* chf);

EXPORT_API bool rcwBuildCompactHeightfield(rcwContext* ctx, const int walkableHeight, const int walkableClimb,
	rcwHeightfield& hf, rcwCompactHeightfield& chf);

EXPORT_API bool rcwErodeWalkableArea(rcwContext* ctx, int radius, rcwCompactHeightfield& chf);

EXPORT_API void rcwMarkConvexPolyArea(rcwContext* ctx, float* verts, int nverts,
	float hmin, float hmax, unsigned char areaId,
	rcwCompactHeightfield& chf);

EXPORT_API bool rcwBuildDistanceField(rcwContext* ctx, rcwCompactHeightfield& chf);

EXPORT_API bool rcwBuildRegions(rcwContext* ctx, rcwCompactHeightfield& chf,
	int borderSize, int minRegionArea, int mergeRegionArea);

EXPORT_API bool rcwBuildRegionsMonotone(rcwContext* ctx, rcwCompactHeightfield& chf,
	int borderSize, int minRegionArea, int mergeRegionArea);

EXPORT_API bool rcwBuildLayerRegions(rcwContext* ctx, rcwCompactHeightfield& chf,
	int borderSize, int minRegionArea);

/* ContourSet */

EXPORT_API rcwContourSet* rcwAllocContourSet();

EXPORT_API void rcwFreeContourSet(rcwContourSet* cset);

EXPORT_API bool rcwBuildContours(rcwContext* ctx, rcwCompactHeightfield& chf,
	float maxError, int maxEdgeLen,
	rcwContourSet& cset, int buildFlags = 1);

/* PolyMesh */

EXPORT_API rcwPolyMesh* rcwAllocPolyMesh();
EXPORT_API void rcwFreePolyMesh(rcwPolyMesh* pmesh);

EXPORT_API bool rcwBuildPolyMesh(rcwContext* ctx, rcwContourSet& cset, int nvp, rcwPolyMesh& mesh);

/* PolyMeshDetail */

EXPORT_API rcwPolyMeshDetail* rcwAllocPolyMeshDetail();
EXPORT_API void rcwFreePolyMeshDetail(rcwPolyMeshDetail* dmesh);

EXPORT_API bool rcwBuildPolyMeshDetail(rcwContext* ctx, const rcwPolyMesh& mesh, const rcwCompactHeightfield& chf,
	const float sampleDist, const float sampleMaxError,
	rcwPolyMeshDetail& dmesh);

/* Utils */

EXPORT_API void rcwVCopy(float* dest, float* v);
EXPORT_API void rcwCalcGridSize(float* bmin, float* bmax, float cs, int* w, int* h);


#endif
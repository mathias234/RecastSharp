#include "RecastWrapper.h"

#include <cstdio>

#include "Recast.h"

class WrappedContext : rcContext
{
	void doLog(const rcLogCategory cat, const char* msg, const int len) override
	{
		switch (cat)
		{
		case RC_LOG_PROGRESS:
			printf("Progress: %s\n", msg);
			break;
		case RC_LOG_WARNING:
			printf("Warning: %s\n", msg);
			break;
		case RC_LOG_ERROR:
			printf("Error: %s\n", msg);
			break;
		}
	}
};

EXPORT_API rcwContext* rcwAllocContext()
{
	auto ctx = new WrappedContext();
	return (rcwContext*)ctx;
}
EXPORT_API void rcwFreeContext(rcwContext* ctx)
{
	delete ctx;
}

EXPORT_API rcwHeightfield* rcwAllocHeightfield() {
	return (rcwHeightfield*)rcAllocHeightfield();
}

EXPORT_API void rcwFreeHeightfield(rcwHeightfield* hf) {
	rcFreeHeightField((rcHeightfield*)hf);
}

EXPORT_API bool rcwCreateHeightfield(rcwContext* ctx, rcwHeightfield& hf, int width, int height,
	float* bmin, float* bmax,
	float cs, float ch) {
	return rcCreateHeightfield((rcContext*)ctx, (rcHeightfield&)hf, width, height, bmin, bmax, cs, ch);
}

EXPORT_API void rcwMarkWalkableTriangles(rcwContext* ctx, float walkableSlopeAngle, float* verts, int nv,
	int* tris, int nt, unsigned char* areas) {
	rcMarkWalkableTriangles((rcContext*)ctx, walkableSlopeAngle, verts, nv, tris, nt, areas);
}

EXPORT_API bool rcwRasterizeTriangles(rcwContext* ctx, float* verts, int nv,
	int* tris, unsigned char* areas, int nt,
	rcwHeightfield& solid, int flagMergeThr) {
	return rcRasterizeTriangles((rcContext*)ctx, verts, nv, tris, areas, nt, (rcHeightfield&)solid, flagMergeThr);
}

EXPORT_API void rcwFilterLowHangingWalkableObstacles(rcwContext* ctx, int walkableClimb, rcwHeightfield& solid) {
	rcFilterLowHangingWalkableObstacles((rcContext*)ctx, walkableClimb, (rcHeightfield&)solid);
}

EXPORT_API void rcwFilterLedgeSpans(rcwContext* ctx, int walkableHeight,
	int walkableClimb, rcwHeightfield& solid) {
	rcFilterLedgeSpans((rcContext*)ctx, walkableHeight, walkableClimb, (rcHeightfield&)solid);
}

EXPORT_API void rcwFilterWalkableLowHeightSpans(rcwContext* ctx, int walkableHeight, rcwHeightfield& solid) {
	rcFilterWalkableLowHeightSpans((rcContext*)ctx, walkableHeight, (rcHeightfield&)solid);
}

EXPORT_API rcwCompactHeightfield* rcwAllocCompactHeightfield() {
	return (rcwCompactHeightfield*)rcAllocCompactHeightfield();
}

EXPORT_API bool rcwBuildCompactHeightfield(rcwContext* ctx, const int walkableHeight, const int walkableClimb,
	rcwHeightfield& hf, rcwCompactHeightfield& chf) {
	return rcBuildCompactHeightfield((rcContext*)ctx, walkableHeight, walkableClimb, (rcHeightfield&)hf, (rcCompactHeightfield&)chf);
}

EXPORT_API void rcwFreeCompactHeightfield(rcwCompactHeightfield* chf) {
	rcFreeCompactHeightfield((rcCompactHeightfield*)chf);
}

EXPORT_API bool rcwErodeWalkableArea(rcwContext* ctx, int radius, rcwCompactHeightfield& chf) {
	return rcErodeWalkableArea((rcContext*)ctx, radius, (rcCompactHeightfield&)chf);
}

EXPORT_API void rcwMarkConvexPolyArea(rcwContext* ctx, float* verts, int nverts,
	float hmin, float hmax, unsigned char areaId,
	rcwCompactHeightfield& chf) {
	rcMarkConvexPolyArea((rcContext*)ctx, verts, nverts, hmin, hmax, areaId, (rcCompactHeightfield&)chf);
}

EXPORT_API bool rcwBuildDistanceField(rcwContext* ctx, rcwCompactHeightfield& chf) {
	return rcBuildDistanceField((rcContext*)ctx, (rcCompactHeightfield&)chf);
}

EXPORT_API bool rcwBuildRegions(rcwContext* ctx, rcwCompactHeightfield& chf,
	int borderSize, int minRegionArea, int mergeRegionArea) {
	return rcBuildRegions((rcContext*)ctx, (rcCompactHeightfield&)chf, borderSize, minRegionArea, mergeRegionArea);
}

EXPORT_API bool rcwBuildRegionsMonotone(rcwContext* ctx, rcwCompactHeightfield& chf,
	int borderSize, int minRegionArea, int mergeRegionArea) {
	return rcBuildRegionsMonotone((rcContext*)ctx, (rcCompactHeightfield&)chf, borderSize, minRegionArea, mergeRegionArea);
}

EXPORT_API bool rcwBuildLayerRegions(rcwContext* ctx, rcwCompactHeightfield& chf,
	int borderSize, int minRegionArea) {
	return rcBuildLayerRegions((rcContext*)ctx, (rcCompactHeightfield&)chf, borderSize, minRegionArea);
}

EXPORT_API rcwContourSet* rcwAllocContourSet() {
	return (rcwContourSet*)rcAllocContourSet();
}

EXPORT_API void rcwFreeContourSet(rcwContourSet* cset) {
	rcFreeContourSet((rcContourSet*)cset);
}

EXPORT_API bool rcwBuildContours(rcwContext* ctx, rcwCompactHeightfield& chf,
	float maxError, int maxEdgeLen,
	rcwContourSet& cset, int buildFlags) {
	return rcBuildContours((rcContext*)ctx, (rcCompactHeightfield&)chf, maxError, maxEdgeLen, (rcContourSet&)cset, buildFlags);
}

EXPORT_API rcwPolyMesh* rcwAllocPolyMesh() {
	return (rcwPolyMesh*)rcAllocPolyMesh();
}

EXPORT_API void rcwFreePolyMesh(rcwPolyMesh* pmesh) {
	rcFreePolyMesh((rcPolyMesh*)pmesh);
}

EXPORT_API bool rcwBuildPolyMesh(rcwContext* ctx, rcwContourSet& cset, int nvp, rcwPolyMesh& mesh) {
	return rcBuildPolyMesh((rcContext*)ctx, (rcContourSet&)cset, nvp, (rcPolyMesh&)mesh);
}

EXPORT_API rcwPolyMeshDetail* rcwAllocPolyMeshDetail() {
	return (rcwPolyMeshDetail*)rcAllocPolyMeshDetail();
}

EXPORT_API void rcwFreePolyMeshDetail(rcwPolyMeshDetail* dmesh) {
	rcFreePolyMeshDetail((rcPolyMeshDetail*)dmesh);
}

EXPORT_API bool rcwBuildPolyMeshDetail(rcwContext* ctx, const rcwPolyMesh& mesh, const rcwCompactHeightfield& chf,
	const float sampleDist, const float sampleMaxError,
	rcwPolyMeshDetail& dmesh) {
	return rcBuildPolyMeshDetail((rcContext*)ctx, (rcPolyMesh&)mesh, (rcCompactHeightfield&)chf, sampleDist, sampleMaxError, (rcPolyMeshDetail&)dmesh);
}

EXPORT_API void rcwVCopy(float* dest, float* v) {
	return rcVcopy(dest, v);
}

EXPORT_API void rcwCalcGridSize(float* bmin, float* bmax, float cs, int* w, int* h)
{
	return rcCalcGridSize(bmin, bmax, cs, w, h);
}
#include "RecastWrapper.h"
#include "Recast.h"

EXPORT_API void rcwVCopy(float* dest, const float* v) {
	return rcVcopy(dest, v);
}

EXPORT_API void rcwCalcGridSize(const float* bmin, const float* bmax, float cs, int* w, int* h)
{
	return rcCalcGridSize(bmin, bmax, cs, w, h);
}

EXPORT_API rcwHeightfield* rcwAllocHeightfield() {
	return (rcwHeightfield*)rcAllocHeightfield();
}

EXPORT_API void rcwFreeHeightField(rcwHeightfield* hf) {
	rcFreeHeightField((rcHeightfield*)hf);
}

EXPORT_API bool rcwCreateHeightfield(rcwContext* ctx, rcwHeightfield& hf, int width, int height,
	const float* bmin, const float* bmax,
	float cs, float ch) {
	return rcCreateHeightfield((rcContext*)ctx, (rcHeightfield&)hf, width, height, bmin, bmax, cs, ch);
}

EXPORT_API void rcwMarkWalkableTriangles(rcwContext* ctx, const float walkableSlopeAngle, const float* verts, int nv,
	const int* tris, int nt, unsigned char* areas) {
	rcMarkWalkableTriangles((rcContext*)ctx, walkableSlopeAngle, verts, nv, tris, nt, areas);
}

EXPORT_API bool rcwRasterizeTriangles(rcwContext* ctx, const float* verts, const int nv,
	const int* tris, const unsigned char* areas, const int nt,
	rcwHeightfield& solid, const int flagMergeThr) {
	return rcRasterizeTriangles((rcContext*)ctx, verts, nv, tris, areas, nt, (rcHeightfield&)solid, flagMergeThr);
}

EXPORT_API void rcwFilterLowHangingWalkableObstacles(rcwContext* ctx, const int walkableClimb, rcwHeightfield& solid) {
	rcFilterLowHangingWalkableObstacles((rcContext*)ctx, walkableClimb, (rcHeightfield&)solid);
}

EXPORT_API void rcwFilterLedgeSpans(rcwContext* ctx, const int walkableHeight,
	const int walkableClimb, rcwHeightfield& solid) {
	rcFilterLedgeSpans((rcContext*)ctx, walkableHeight, walkableClimb, (rcHeightfield&)solid);
}

EXPORT_API void rcwFilterWalkableLowHeightSpans(rcwContext* ctx, int walkableHeight, rcwHeightfield& solid) {
	rcFilterWalkableLowHeightSpans((rcContext*)ctx, walkableHeight, (rcHeightfield&)solid);
}

EXPORT_API rcwCompactHeightfield* rcwAllocCompactHeightfield() {
	return (rcwCompactHeightfield*)rcAllocCompactHeightfield();
}

EXPORT_API void rcwFreeCompactHeightfield(rcwCompactHeightfield* chf) {
	rcFreeCompactHeightfield((rcCompactHeightfield*)chf);
}

EXPORT_API bool rcwErodeWalkableArea(rcwContext* ctx, int radius, rcwCompactHeightfield& chf) {
	return rcErodeWalkableArea((rcContext*)ctx, radius, (rcCompactHeightfield&)chf);
}

EXPORT_API void rcwMarkConvexPolyArea(rcwContext* ctx, const float* verts, const int nverts,
	const float hmin, const float hmax, unsigned char areaId,
	rcwCompactHeightfield& chf) {
	rcMarkConvexPolyArea((rcContext*)ctx, verts, nverts, hmin, hmax, areaId, (rcCompactHeightfield&)chf);
}

EXPORT_API bool rcwBuildDistanceField(rcwContext* ctx, rcwCompactHeightfield& chf) {
	return rcBuildDistanceField((rcContext*)ctx, (rcCompactHeightfield&)chf);
}

EXPORT_API bool rcwBuildRegions(rcwContext* ctx, rcwCompactHeightfield& chf,
	const int borderSize, const int minRegionArea, const int mergeRegionArea) {
	return rcBuildRegions((rcContext*)ctx, (rcCompactHeightfield&)chf, borderSize, minRegionArea, mergeRegionArea);
}

EXPORT_API bool rcwBuildRegionsMonotone(rcwContext* ctx, rcwCompactHeightfield& chf,
	const int borderSize, const int minRegionArea, const int mergeRegionArea) {
	return rcBuildRegionsMonotone((rcContext*)ctx, (rcCompactHeightfield&)chf, borderSize, minRegionArea, mergeRegionArea);
}

EXPORT_API bool rcwBuildLayerRegions(rcwContext* ctx, rcwCompactHeightfield& chf,
	const int borderSize, const int minRegionArea) {
	return rcBuildLayerRegions((rcContext*)ctx, (rcCompactHeightfield&)chf, borderSize, minRegionArea);
}

EXPORT_API rcwContourSet* rcwAllocContourSet() {
	return (rcwContourSet*)rcAllocContourSet();
}

EXPORT_API void rcwFreeContourSet(rcwContourSet* cset) {
	rcFreeContourSet((rcContourSet*)cset);
}

EXPORT_API bool rcwBuildContours(rcwContext* ctx, rcwCompactHeightfield& chf,
	const float maxError, const int maxEdgeLen,
	rcwContourSet& cset, const int buildFlags) {
	return rcBuildContours((rcContext*)ctx, (rcCompactHeightfield&)chf, maxError, maxEdgeLen, (rcContourSet&)cset, buildFlags);
}

EXPORT_API rcwPolyMesh* rcwAllocPolyMesh() {
	return (rcwPolyMesh*)rcAllocPolyMesh();
}

EXPORT_API void rcwFreePolyMesh(rcwPolyMesh* pmesh) {
	rcFreePolyMesh((rcPolyMesh*)pmesh);
}

EXPORT_API bool rcwBuildPolyMesh(rcwContext* ctx, rcwContourSet& cset, const int nvp, rcwPolyMesh& mesh) {
	return rcBuildPolyMesh((rcContext*)ctx, (rcContourSet&)cset, nvp, (rcPolyMesh&)mesh);
}

EXPORT_API rcwPolyMeshDetail* rcwAllocPolyMeshDetail() {
	return (rcwPolyMeshDetail*)rcAllocPolyMeshDetail();
}

EXPORT_API void rcwFreePolyMeshDetail(rcwPolyMeshDetail* dmesh) {
	rcFreePolyMeshDetail((rcPolyMeshDetail*)dmesh);
}
#include "DetourWrapper.h"
#include "DetourNavMeshBuilder.h"
#include "DetourNavMesh.h"
#include "DetourNavMeshQuery.h"
#include <iostream>

EXPORT_API bool dtwCreateNavMeshData(dtwNavMeshCreateParams* params, unsigned char** outData, int* outDataSize) {
	dtNavMeshCreateParams* dtParams = (dtNavMeshCreateParams*)params;
	return dtCreateNavMeshData(dtParams, outData, outDataSize);
}

EXPORT_API dtwNavMesh* dtwAllocNavMesh() {
	return (dtwNavMesh*)dtAllocNavMesh();
}

EXPORT_API dtwStatus dtwNavMesh_Init(dtwNavMesh* navmesh, dtwNavMeshParams* params) {
	auto dtNm = (dtNavMesh*)navmesh;
	auto dtParams = (dtNavMeshParams*)params;
					
	return (dtwStatus)dtNm->init(dtParams);
}

EXPORT_API dtwStatus dtwNavMesh_AddTile(dtwNavMesh* navmesh, unsigned char* data, int dataSize, int flags, dtwTileRef lastRef, dtwTileRef* result) {
	auto dtNm = (dtNavMesh*)navmesh;
	auto dtLastRef = (dtTileRef)lastRef;
	auto dtResult = (dtTileRef*)result;
	return (dtwStatus)dtNm->addTile(data, dataSize, flags, dtLastRef, dtResult);
}

EXPORT_API dtwStatus dtwNavMesh_RemoveTile(dtwNavMesh* navmesh, dtwTileRef ref, unsigned char** data, int* dataSize) {
	auto dtNm = (dtNavMesh*)navmesh;
	auto dtRef = (dtTileRef)ref;
	return (dtwStatus)dtNm->removeTile(dtRef, data, dataSize);
}

EXPORT_API dtwTileRef dtwNavMesh_GetTileRefAt(dtwNavMesh* navmesh, int x, int y, int layer) {
	auto dtNm = (dtNavMesh*)navmesh;
	return (dtwTileRef)dtNm->getTileRefAt(x, y, layer);
}


EXPORT_API dtwPolyRef* dtwAllocPolyRef() {
	return (dtwPolyRef*)new dtPolyRef();
}

EXPORT_API dtwQueryFilter* dtwAllocQueryFilter() {
	auto filter = new dtQueryFilter();
	return (dtwQueryFilter*)filter;
}

EXPORT_API dtwNavMeshQuery* dtwAllocNavMeshQuery() {
	return (dtwNavMeshQuery*)dtAllocNavMeshQuery();
}

EXPORT_API dtwStatus dtwNavMeshQuery_Init(dtwNavMeshQuery* query, dtwNavMesh* navmesh, int maxNodes) {
	auto dtNm = (dtNavMesh*)navmesh;
	auto dtQuery = (dtNavMeshQuery*)query;

	return (dtwStatus)dtQuery->init(dtNm, maxNodes);
}

EXPORT_API dtwStatus dtwNavMeshQuery_FindNearestPoly(dtwNavMeshQuery* query, const float* center, const float* halfExtents,
	const dtwQueryFilter* filter,
	dtwPolyRef* nearestRef, float* nearestPt) {
	auto dtQuery = (dtNavMeshQuery*)query;
	auto dtFilter = (dtQueryFilter*)filter;
	auto dtNearestRef = (dtPolyRef*)nearestRef;
	return dtQuery->findNearestPoly(center, halfExtents, dtFilter, dtNearestRef, nearestPt);
}

EXPORT_API dtwStatus dtwNavMeshQuery_FindPath(dtwNavMeshQuery* query, 
	dtwPolyRef startRef, dtwPolyRef endRef, 
	const float* startPos, const float* endPos, 
	const dtwQueryFilter* filter, dtwPolyRef* path, int* pathCount, const int maxPath) {
	auto dtQuery = (dtNavMeshQuery*)query;
	auto dtStartRef = (dtPolyRef)startRef;
	auto dtEndRef = (dtPolyRef)endRef;
	auto dtFilter = (dtQueryFilter*)filter;
	auto dtPath = (dtPolyRef*)path;

	return dtQuery->findPath(dtStartRef, dtEndRef, startPos, endPos, dtFilter, dtPath, pathCount, maxPath);
}

EXPORT_API dtwStatus dtwNavMeshQuery_FindStraightPath(dtwNavMeshQuery* query, const float* startPos, const float* endPos,
	const dtPolyRef* path, const int pathSize,
	float* straightPath, unsigned char* straightPathFlags, dtPolyRef* straightPathRefs,
	int* straightPathCount, const int maxStraightPath, const int options){
	auto dtQuery = (dtNavMeshQuery*)query;
	auto dtPath = (dtPolyRef*)path;
	auto dtStraightPathRefs = (dtPolyRef*)straightPathRefs;
	return dtQuery->findStraightPath(startPos, endPos, dtPath, pathSize, straightPath, straightPathFlags, dtStraightPathRefs, straightPathCount, maxStraightPath, options);
}

EXPORT_API void dtwFree(void* ptr) {
	dtFree(ptr);
}

EXPORT_API bool dtwStatusSucceed(dtwStatus status) {
	return dtStatusSucceed(status);
}

EXPORT_API bool dtwStatusFailed(dtwStatus status) {
	return dtStatusFailed(status);
}


EXPORT_API bool dtwStatusInProgress(dtwStatus status) {
	return dtStatusInProgress(status);
}


EXPORT_API bool dtwStatusDetail(dtwStatus status, unsigned int detail) {
	return dtStatusDetail(status, detail);
}
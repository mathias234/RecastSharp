#ifndef DETOUR_WRAPPER_H
#define DETOUR_WRAPPER_H

#include "WrapperCommon.h"

EXPORT_API bool dtwCreateNavMeshData(dtwNavMeshCreateParams* params, unsigned char** outData, int* outDataSize);

EXPORT_API dtwNavMesh* dtwAllocNavMesh();
EXPORT_API dtwStatus dtwNavMesh_Init(dtwNavMesh* navmesh, dtwNavMeshParams* params);
EXPORT_API dtwStatus dtwNavMesh_AddTile(dtwNavMesh* navmesh, unsigned char* data, int dataSize, int flags, dtwTileRef lastRef, dtwTileRef* result);
EXPORT_API dtwStatus dtwNavMesh_RemoveTile(dtwNavMesh* navmesh, dtwTileRef ref, unsigned char** data, int* dataSize);
EXPORT_API dtwTileRef dtwNavMesh_GetTileRefAt(dtwNavMesh* navmesh, int x, int y, int layer);

EXPORT_API dtwPolyRef* dtwAllocPolyRef();
EXPORT_API dtwQueryFilter* dtwAllocQueryFilter();

EXPORT_API dtwNavMeshQuery* dtwAllocNavMeshQuery();
EXPORT_API dtwStatus dtwNavMeshQuery_Init(dtwNavMeshQuery* query, dtwNavMesh* navmesh, int maxNodes);
EXPORT_API dtwStatus dtwNavMeshQuery_FindNearestPoly(dtwNavMeshQuery* query, const float* center, const float* halfExtents,
	const dtwQueryFilter* filter,
	dtwPolyRef* nearestRef, float* nearestPt);
EXPORT_API dtwStatus dtwNavMeshQuery_FindPath(dtwNavMeshQuery* query,
	dtwPolyRef startRef, dtwPolyRef endRef,
	const float* startPos, const float* endPos,
	const dtwQueryFilter* filter, dtwPolyRef* path, int* pathCount, const int maxPath);

EXPORT_API void dtwFree(void* ptr);


EXPORT_API bool dtwStatusSucceed(dtwStatus status);
EXPORT_API bool dtwStatusFailed(dtwStatus status);
EXPORT_API bool dtwStatusInProgress(dtwStatus status);
EXPORT_API bool dtwStatusDetail(dtwStatus status, unsigned int detail);


#endif
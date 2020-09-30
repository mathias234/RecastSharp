#ifndef DETOUR_WRAPPER_H
#define DETOUR_WRAPPER_H

#include "WrapperCommon.h"

#define dtwNavMeshCreateParams int
#define dtwNavMesh int
#define dtwStatus int

EXPORT_API bool dtwCreateNavMeshData(dtwNavMeshCreateParams* params, unsigned char** outData, int* outDataSize);

EXPORT_API dtwNavMesh* dtwAllocNavMesh();

EXPORT_API void dtwFree(void* ptr);


EXPORT_API bool dtwStatusSucceed(dtwStatus status);
EXPORT_API bool dtwStatusFailed(dtwStatus status);
EXPORT_API bool dtwStatusInProgress(dtwStatus status);
EXPORT_API bool dtwStatusDetail(dtwStatus status, unsigned int detail);


#endif
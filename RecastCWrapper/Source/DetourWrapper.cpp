#include "DetourWrapper.h"
#include "DetourNavMeshBuilder.h"
#include "DetourNavMesh.h"

EXPORT_API bool dtwCreateNavMeshData(dtwNavMeshCreateParams* params, unsigned char** outData, int* outDataSize) {
	return dtCreateNavMeshData((dtNavMeshCreateParams*)params, outData, outDataSize);
}

EXPORT_API dtwNavMesh* dtwAllocNavMesh() {
	return (dtwNavMesh*)dtAllocNavMesh();
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
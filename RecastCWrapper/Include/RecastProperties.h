#ifndef RECAST_PROPERTIES_H
#define RECAST_PROPERTIES_H

#include "WrapperCommon.h"
#include "Recast.h"


EXPORT_API void polyMesh_GetVerts(rcwPolyMesh* mesh, unsigned short*& verts, int& nverts)
{
	auto pMesh = (rcPolyMesh*)mesh;
	verts = pMesh->verts;
	nverts = pMesh->nverts;
}

EXPORT_API void polyMesh_GetPolys(rcwPolyMesh* mesh, unsigned short*& polys, int& npolys)
{
	auto pMesh = (rcPolyMesh*)mesh;
	polys = pMesh->polys;
	npolys = pMesh->npolys;
}

EXPORT_API void polyMesh_GetPolyAreas(rcwPolyMesh* mesh, unsigned char*& areas)
{
	auto pMesh = (rcPolyMesh*)mesh;
	areas = pMesh->areas;
}

EXPORT_API void polyMesh_GetPolyFlags(rcwPolyMesh* mesh, unsigned short*& flags)
{
	auto pMesh = (rcPolyMesh*)mesh;
	flags = pMesh->flags;
}

EXPORT_API void polyMesh_GetVertsPerPoly(rcwPolyMesh* mesh, int& nvp)
{
	auto pMesh = (rcPolyMesh*)mesh;
	nvp = pMesh->nvp;
}

EXPORT_API void polyMesh_GetBmin(rcwPolyMesh* mesh, float*& bmin)
{
	auto pMesh = (rcPolyMesh*)mesh;
	bmin = pMesh->bmin;
}

EXPORT_API void polyMesh_GetBmax(rcwPolyMesh* mesh, float*& bmax)
{
	auto pMesh = (rcPolyMesh*)mesh;
	bmax = pMesh->bmax;
}


EXPORT_API void detailMesh_GetMeshes(rcwPolyMeshDetail* mesh, unsigned int*& meshes, int& nmeshes)
{
	auto dMesh = (rcPolyMeshDetail*)mesh;
	meshes = dMesh->meshes;
	nmeshes = dMesh->nmeshes;
}

EXPORT_API void detailMesh_GetVerts(rcwPolyMeshDetail* mesh, float*& verts, int& nverts)
{
	auto dMesh = (rcPolyMeshDetail*)mesh;
	verts = dMesh->verts;
	nverts = dMesh->nverts;
}

EXPORT_API void detailMesh_GetTris(rcwPolyMeshDetail* mesh, unsigned char*& tris, int& ntris)
{
	auto dMesh = (rcPolyMeshDetail*)mesh;
	tris = dMesh->tris;
	ntris = dMesh->ntris;
}


#endif
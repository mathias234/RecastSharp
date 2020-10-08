namespace RecastSharp.DetourNative
{
    public unsafe struct DtNavMeshCreateParams
    {
		public ushort* Verts;
		public int VertCount;
		public ushort* Polys;
		public ushort* PolyFlags;
		public byte* PolyAreas;
		public int PolyCount;              
		public int Nvp;       

		public uint* DetailMeshes;
		public float* DetailVerts;
		public int DetailVertsCount;
		public byte* DetailTris;
		public int DetailTriCount;
		
        public float* OffMeshConVerts;
		public float* OffMeshConRad;
		public ushort* OffMeshConFlags;
		public byte* OffMeshConAreas;
		public byte* OffMeshConDir;
		public uint* OffMeshConUserId;
		public int OffMeshConCount;

		public uint UserId;
		public int TileX;
		public int TileY;
		public int TileLayer; 
		public float* BMin; 
        public float* BMax;

		public float WalkableHeight;
		public float WalkableRadius;
		public float WalkableClimb; 
		public float Cs;
		public float Ch;   
        
		public bool BuildBvTree;
	}
}

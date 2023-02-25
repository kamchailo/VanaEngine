#pragma once

#include "Mesh.h"

class MeshCollection
{
public:
	~MeshCollection();
	static void Init();
	inline static Mesh* meshSprite;
};
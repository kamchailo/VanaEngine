#pragma once

#include "Shader.h"

class ShaderCollection
{
public:
	~ShaderCollection();
	static void Init();
	inline static Shader* default2D;
	inline static Shader* fillRed2D;
	inline static Shader* sprite2D;
};
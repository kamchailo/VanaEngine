#include "pch.h"
#include "ShaderCollection.h"

void ShaderCollection::Init()
{
	ShaderCollection::default2D = new Shader(SHADER_DEFAULT_VERT, SHADER_DEFAULT_FRAG);
}

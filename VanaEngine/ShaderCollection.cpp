#include "pch.h"
#include "ShaderCollection.h"

ShaderCollection::~ShaderCollection()
{
	delete(ShaderCollection::default2D);
}

void ShaderCollection::Init()
{
	// Default 2D
	ShaderCollection::default2D = new Shader(SHADER_DEFAULT_VERT, SHADER_DEFAULT_FRAG);
	glUseProgram(ShaderCollection::default2D->ID);
	ShaderCollection::default2D->setVec4("fillColor", glm::vec4(0.5f, 0.5f, 1.0f, 1.0f));
}

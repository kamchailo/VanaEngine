#include "pch.h"
#include "ShaderCollection.h"

void ShaderCollection::Init()
{
	ShaderCollection::default2D = new Shader(SHADER_DEFAULT_VERT, SHADER_DEFAULT_FRAG);
	glUseProgram(ShaderCollection::default2D->ID);
	ShaderCollection::default2D->setVec4("fillColor", glm::vec4(0.5f, 0.5f, 1.0f, 1.0f));
}

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
	ShaderCollection::default2D->use();
	ShaderCollection::default2D->setVec4("fillColor", glm::vec4(0.5f, 0.5f, 1.0f, 1.0f));

	// Sprite
	ShaderCollection::sprite2D = new Shader(SHADER_SPRITE_VERT, SHADER_SPRITE_FRAG);
	ShaderCollection::sprite2D->setInt("texture1", 0);
	ShaderCollection::sprite2D->use();
}

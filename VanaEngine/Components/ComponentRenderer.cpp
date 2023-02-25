#include "pch.h"
#include "ComponentRenderer.h"

#include "Graphics/MeshCollection.h"
#include "Graphics/ShaderCollection.h"

#include "Nodes/Node.h"

#include <glm/glm.hpp>

ComponentRenderer::ComponentRenderer()
{
	this->type = SHAPE_MESH;
	this->mesh = MeshCollection::meshSprite;
	this->shader = ShaderCollection::default2D;
	this->texture = NULL;
	this->spriteSize = glm::vec2(99.0,99.0);
	this->alpha = false;
}

ComponentRenderer::ComponentRenderer(Mesh* mesh, Shader* shader, Texture* texture, glm::vec2 size)
{
	this->type = SHAPE_SPRITE;
	this->mesh = mesh;
	this->shader = shader;
	this->texture = texture;
	this->spriteSize = size;
	this->tilling = glm::vec2(1);
	this->tillingOffset = glm::vec2(0);
	this->alpha = texture->Alpha();
}

ComponentRenderer::ComponentRenderer(Texture* texture, glm::vec2 size)
{
	this->type = SHAPE_SPRITE;
	this->mesh = MeshCollection::meshSprite;
	this->shader = ShaderCollection::sprite2D;
	this->texture = texture;
	this->spriteSize = size;
	this->tilling = glm::vec2(1);
	this->tillingOffset = glm::vec2(0);
	this->alpha = texture->Alpha();
}

void ComponentRenderer::Init()
{
}

void ComponentRenderer::Update(double _dt)
{
	//Draw();
	if (alpha)
	{
		GraphicSystem::GetInstance()->RegisterAlphaComponent(GetOwner()->GetPosition().z, this);
	}
	else
	{
		GraphicSystem::GetInstance()->RegisterOpaqueComponent(this);
	}

}

void ComponentRenderer::Shutdown()
{
}

void ComponentRenderer::HandleEvent(Event* _event)
{
}


void ComponentRenderer::Draw()
{
	glBindVertexArray(mesh->VAO);
	shader->use();

	shader->setMat4("transform", 
		GraphicSystem::GetInstance()->GetviewMatrix() 
		* owner->parentTransform.GetTransform() 
		* glm::scale(owner->transform.GetTransform(), glm::vec3(spriteSize / 2.0f, 1.0))
	);

	shader->setVec2("uniform_tilling", tilling);
	shader->setVec2("uniform_tillingOffset", tillingOffset);

	if (type == SHAPE_VERT)
	{
		glDrawArrays(GL_TRIANGLES, 0, 3);
	}
	else if (type == SHAPE_MESH)
	{
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	}
	else if (type == SHAPE_SPRITE)
	{
		texture->Bind(0);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	}
}

void ComponentRenderer::ChangeTexture(Texture* _texture)
{
	texture = _texture;
}

void ComponentRenderer::SetTilling(glm::vec2 _tilling)
{
	this->tilling = _tilling;
}

void ComponentRenderer::SetTillingOffset(glm::vec2 _tillingOffset)
{
	this->tillingOffset = _tillingOffset;
}

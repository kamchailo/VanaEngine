#include "pch.h"
#include "ComponentRenderer.h"

ComponentRenderer::ComponentRenderer()
{
	this->type = SHAPE_MESH;
	this->mesh = MeshCollection::meshSprite;
	this->shader = ShaderCollection::default2D;
	this->texture = NULL;
}

ComponentRenderer::ComponentRenderer(Mesh* mesh, Shader* shader, Texture* texture, glm::vec2 size)
{
	this->type = SHAPE_SPRITE;
	this->mesh = mesh;
	this->shader = shader;
	this->texture = texture;
	this->spriteSize = size;
}

ComponentRenderer::ComponentRenderer(Texture* texture, glm::vec2 size)
{
	this->type = SHAPE_SPRITE;
	this->mesh = MeshCollection::meshSprite;
	this->shader = ShaderCollection::sprite2D;
	this->texture = texture;
	this->spriteSize = size;
}

void ComponentRenderer::Init()
{
}

void ComponentRenderer::Update()
{
	Draw();
}

void ComponentRenderer::Shutdown()
{
}

void ComponentRenderer::HandleEvent()
{
}


void ComponentRenderer::Draw()
{
	glBindVertexArray(mesh->VAO);
	shader->use();

	shader->setMat4("transform", GraphicSystem::GetInstance()->GetviewMatrix() * owner->parentTransform.GetTransform() * glm::scale(owner->transform.GetTransform(), glm::vec3(spriteSize / 2.0f, 1.0)));
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
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, texture->ID);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	}
}
#include "pch.h"
#include "NodeGraphic.h"

NodeGraphic::NodeGraphic(Node* parentNode, Mesh* mesh, Shader* shader, ShapeType type, glm::vec2 spriteSize) : Node(parentNode)
{
	this->type = type;
	this->shader = shader;
	this->mesh = mesh;
	this->spriteSize = spriteSize;
}

NodeGraphic::NodeGraphic(Node* parentNode, Mesh* mesh, Shader* shader, Texture* texture, glm::vec2 spriteSize) : Node(parentNode)
{
	this->type = SHAPE_SPRITE;
	this->shader = shader;
	this->mesh = mesh;
	this->texture = texture;
	shader->use();
	shader->setInt("texture1", 0);
	this->spriteSize = spriteSize;
}

NodeGraphic::~NodeGraphic()
{
}

void NodeGraphic::DefaultInit()
{
	Node::DefaultInit();
}

void NodeGraphic::DefaultUpdate()
{
	Draw();
	Node::DefaultUpdate();
}

void NodeGraphic::Draw()
{
	//std::cout << "inside draw >>>ID:" << nodeID << std::endl;
	glBindVertexArray(mesh->VAO);
	shader->use();
	//shader->setMat4("transform", parentTransform.GetTransform() * transform.GetTransform());
	shader->setMat4("transform", GraphicSystem::GetInstance()->GetviewMatrix() * parentTransform.GetTransform() * glm::scale( transform.GetTransform(), glm::vec3(spriteSize / 2.0f,1.0)));
	if (type == SHAPE_VERT)
	{
		std::cout << "inside draw VERT >>>ID:" << nodeID << std::endl;
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

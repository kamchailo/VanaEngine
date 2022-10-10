#include "pch.h"
#include "NodeGraphic.h"

NodeGraphic::NodeGraphic(Node* parentNode, Mesh* mesh, Shader* shader, ShapeType type) : Node(parentNode)
{
	this->type = type;
	this->shader = shader;
	this->mesh = mesh;
}

NodeGraphic::NodeGraphic(Node* parentNode, Mesh* mesh, Shader* shader, Texture* texture) : Node(parentNode)
{
	this->type = SHAPE_SPRITE;
	this->shader = shader;
	this->mesh = mesh;
	this->texture = texture;
	shader->use();
	shader->setInt("texture1", 0);
	//std::cout << "Sprite Init " << type << " " << shader << " " << mesh << " " << texture << " " << std::endl;
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
	Node::DefaultUpdate();
	Draw();
}

void NodeGraphic::Draw()
{
	//std::cout << "inside draw" << std::endl;
	glBindVertexArray(mesh->VAO);
	shader->use();
	shader->setMat4("transform", parentTransfrom * transform);
	//std::cout << VBO << std::endl;
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

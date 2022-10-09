#include "pch.h"
#include "NodeGraphic.h"

NodeGraphic::NodeGraphic(Node* parentNode, Mesh* mesh, Shader* shader, ShapeType type) : Node(parentNode)
{
	this->type = type;
	this->mesh = mesh;
	this->shader = shader;
}

NodeGraphic::NodeGraphic(Node* parentNode, Mesh* mesh, Shader* shader, char* texturePath) : Node(parentNode)
{
	this->type = type;
	this->mesh = mesh;
	this->shader = shader;
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
	glUseProgram(shader->ID);
	shader->setMat4("transform", parentTransfrom * transform);
	//std::cout << VBO << std::endl;
	glBindVertexArray(mesh->VAO);
	if (type == SHAPE_VERT)
	{
		glDrawArrays(GL_TRIANGLES, 0, 3);
	}
	else if (type == SHAPE_MESH)
	{
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	}
}

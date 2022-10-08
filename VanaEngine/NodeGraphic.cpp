#include "pch.h"
#include "NodeGraphic.h"

NodeGraphic::NodeGraphic(Node* parentNode, float* vertices, unsigned int shaderID) : Node(parentNode)
{
	this->geometry = new Geometry;
	this->geometry->vertices = vertices;
	this->shaderID = shaderID;
	GenNodeBuffer();
}

NodeGraphic::NodeGraphic(Node* parentNode, float* vertices, unsigned int* indices, unsigned int shaderID) : Node(parentNode)
{
	this->geometry = new Geometry;
	this->geometry->vertices = vertices;
	this->geometry->indices = indices;
	this->shaderID = shaderID;
	GenNodeBuffer();
}

NodeGraphic::~NodeGraphic()
{
	delete(geometry);
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
}

void NodeGraphic::Update()
{
	Node::Update();
	Draw();
}

void NodeGraphic::Draw()
{
	glUseProgram(shaderID);
	//std::cout << VBO << std::endl;
	//glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, 3);
}

void NodeGraphic::GenNodeBuffer()
{
	std::cout << ">> 4. Gen VAO VBO" << std::endl;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);
	// bind VAO first to record
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(geometry->vertices), geometry->vertices, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(geometry->indices), geometry->indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	std::cout << "glGetError: " << glGetError() << std::endl;

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

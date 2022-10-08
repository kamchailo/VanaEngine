#include "pch.h"
#include "NodeGraphic.h"

NodeGraphic::NodeGraphic(Node* parentNode, float* vertices, int verticesCount, unsigned int shaderID) : Node(parentNode)
{
	type = SHAPE_VERT;
	this->geometry = new Geometry;
	this->geometry->vertices = vertices;
	this->geometry->verticesCount = verticesCount;
	this->shaderID = shaderID;
	GenNodeBufferForVert();
}

NodeGraphic::NodeGraphic(Node* parentNode, float* vertices, int verticesCount, unsigned int* indices, int indicesCount, unsigned int shaderID) : Node(parentNode)
{
	type = SHAPE_MESH;
	this->geometry = new Geometry;
	this->geometry->vertices = vertices;
	this->geometry->verticesCount = verticesCount;
	this->geometry->indices = indices;
	this->geometry->indicesCount = indicesCount;
	this->shaderID = shaderID;
	GenNodeBufferIndices();
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
	unsigned int transformLoc = glGetUniformLocation(shaderID, "transform");
	glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));
	Draw();
}

void NodeGraphic::Draw()
{
	glUseProgram(shaderID);
	//std::cout << VBO << std::endl;
	glBindVertexArray(VAO);
	if (type == SHAPE_VERT)
	{
		glDrawArrays(GL_TRIANGLES, 0, 3);
	}
	else
	{
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	}
}


void NodeGraphic::GenNodeBufferForVert()
{
	std::cout << ">> 4. Gen VAO VBO" << std::endl;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	// bind VAO first to record
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, geometry->verticesCount, geometry->vertices, GL_STATIC_DRAW);
	std::cout << " size of geometry->vertices : " << sizeof(geometry->vertices);

	std::cout << std::endl;
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	std::cout << "glGetError: " << glGetError() << std::endl;

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void NodeGraphic::GenNodeBufferIndices()
{
	std::cout << ">> 4. Gen VAO VBO" << std::endl;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);
	// bind VAO first to record
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, geometry->verticesCount, geometry->vertices, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, geometry->indicesCount, geometry->indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	std::cout << "glGetError: " << glGetError() << std::endl;

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

#include "pch.h"
#include "Transform.h"
#include "Graphics.h"

void Vana::Transform::SetInit(glm::vec3 translate, glm::vec3 rotate, glm::vec3 scale)
{
	initMatrix = glm::mat4(1);
	// calc transform = 
	glm::vec3 worldTranslate(0);
	worldTranslate.x = (translate.x / GraphicSystem::windowSize.x) * 2.0;
	worldTranslate.y = (translate.y / GraphicSystem::windowSize.y) * 2.0;
	//std::cout << nodeID <<" World Translate: " << worldTranslate.x << ", " << worldTranslate.y << std::endl;
	initMatrix = glm::translate(initMatrix, worldTranslate);
	if (rotate.x != 0)
	{
		initMatrix = glm::rotate(initMatrix, glm::radians(rotate.x), glm::vec3(1.0, 0.0, 0.0));
	}
	if (rotate.y != 0)
	{
		initMatrix = glm::rotate(initMatrix, glm::radians(rotate.y), glm::vec3(0.0, 1.0, 0.0));
	}
	if (rotate.z != 0)
	{
		initMatrix = glm::rotate(initMatrix, glm::radians(rotate.z), glm::vec3(0.0, 0.0, 1.0));
	}
	initMatrix = glm::scale(initMatrix, scale);
}

void Vana::Transform::Translate(const glm::vec3 translate)
{
	this->translate += translate;
}

void Vana::Transform::Rotate(const glm::vec3 rotate)
{
	this->rotate += rotate;
}

void Vana::Transform::Scale(const glm::vec3 scale)
{
	this->scale *= scale;
}

glm::mat4 const& Vana::Transform::GetTransform() const
{
	return this->transformMatrix;
}

void Vana::Transform::SetTransform(glm::mat4 const matrix)
{
	this->transformMatrix = matrix;
}

void Vana::Transform::UpdateTransform()
{
	// calc transform = 
	glm::vec3 worldTranslate(0);
	worldTranslate.x = (translate.x / GraphicSystem::windowSize.x) * 2.0;
	worldTranslate.y = (translate.y / GraphicSystem::windowSize.y) * 2.0;
	//std::cout << nodeID <<" World Translate: " << worldTranslate.x << ", " << worldTranslate.y << std::endl;
	transformMatrix = glm::translate(transformMatrix, worldTranslate);
	if (rotate.x != 0)
	{
		transformMatrix = glm::rotate(transformMatrix, glm::radians(rotate.x), glm::vec3(1.0, 0.0, 0.0));
	}
	if (rotate.y != 0)
	{
		transformMatrix = glm::rotate(transformMatrix, glm::radians(rotate.y), glm::vec3(0.0, 1.0, 0.0));
	}
	if (rotate.z != 0)
	{
		transformMatrix = glm::rotate(transformMatrix, glm::radians(rotate.z), glm::vec3(0.0, 0.0, 1.0));
	}
	transformMatrix = glm::scale(transformMatrix, scale);
	// reset translate rotate scale variable
	translate = glm::vec3(0);
	rotate = glm::vec3(0);
	scale = glm::vec3(1);
}

void Vana::Transform::ResetTransform()
{
	//transformMatrix = glm::mat4(1);
	transformMatrix = initMatrix;
}

glm::vec3 Vana::Transform::GetPosition()
{
	return glm::vec3();
}

glm::vec3 Vana::Transform::GetRotation()
{
	return glm::vec3();
}

glm::vec3 Vana::Transform::GetScale()
{
	return glm::vec3();
}

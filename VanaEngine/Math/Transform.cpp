#include "pch.h"
#include "Transform.h"
#include "Graphics/Graphics.h"

void Vana::Transform::SetInit(glm::vec3 translate, glm::vec3 rotate, glm::vec3 scale)
{
	initMatrix = glm::mat4(1);

	initMatrix = glm::translate(initMatrix, translate);
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


glm::mat4 const& Vana::Transform::GetTransform() const
{
	return this->transformMatrix;
}

void Vana::Transform::SetTransform(glm::mat4 const matrix)
{
	this->transformMatrix = matrix;
}

void Vana::Transform::UpdateTransform(glm::vec3 inputTranslate, glm::vec3 inputRotation, glm::vec3 inputScale)
{
	transformMatrix = glm::translate(transformMatrix, inputTranslate);
	if (inputRotation.x != 0)
	{
		transformMatrix = glm::rotate(transformMatrix, glm::radians(inputRotation.x), glm::vec3(1.0, 0.0, 0.0));
	}
	if (inputRotation.y != 0)
	{
		transformMatrix = glm::rotate(transformMatrix, glm::radians(inputRotation.y), glm::vec3(0.0, 1.0, 0.0));
	}
	if (inputRotation.z != 0)
	{
		transformMatrix = glm::rotate(transformMatrix, glm::radians(inputRotation.z), glm::vec3(0.0, 0.0, 1.0));
	}
	transformMatrix = glm::scale(transformMatrix, inputScale);
}

void Vana::Transform::ResetTransform()
{
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

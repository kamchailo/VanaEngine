#pragma once
#include <glm/glm.hpp>

namespace Vana {
	class Transform
	{
	public:
		Transform()
			: transformMatrix(glm::mat4(1))
			, initMatrix(glm::mat4(1))
		{}
		Transform(glm::mat4 const& pTransfrom) 
			: transformMatrix(glm::mat4(1))
			, initMatrix(glm::mat4(1))
		{};
		void SetInit(glm::vec3 translate, glm::vec3 rotate, glm::vec3 scale);
		glm::mat4 const& GetTransform() const;
		void SetTransform(glm::mat4 const matrix);
		void UpdateTransform(glm::vec3 inputTranslate, glm::vec3 inputRotation, glm::vec3 inputScale);
		void ResetTransform();

		glm::vec3 GetPosition();
		glm::vec3 GetRotation();
		glm::vec3 GetScale();
	private:
		glm::mat4 transformMatrix;
		glm::mat4 initMatrix;
	};
}
#pragma once
#include <glm/glm.hpp>

namespace Vana {
	class Transform
	{
	public:
		Transform()
			: transformMatrix(glm::mat4(1))
			, initMatrix(glm::mat4(1))
			, translate(glm::vec3(0)), rotate(glm::vec3(0)), scale(glm::vec3(1))
		{}
		Transform(glm::mat4 const& pTransfrom) 
			: transformMatrix(glm::mat4(1))
			, initMatrix(glm::mat4(1))
			, translate(glm::vec3(0)), rotate(glm::vec3(0)), scale(glm::vec3(1))
		{};
		void SetInit(glm::vec3 translate, glm::vec3 rotate, glm::vec3 scale);
		void Translate(glm::vec3);
		void Rotate(glm::vec3);
		void Scale(glm::vec3);
		glm::mat4 const& GetTransform() const;
		void SetTransform(glm::mat4 const matrix);
		void UpdateTransform();
		void ResetTransform();

		glm::vec3 GetPosition();
		glm::vec3 GetRotation();
		glm::vec3 GetScale();
	private:
		// Go to Transfom
		glm::mat4 transformMatrix;
		glm::mat4 initMatrix;
		glm::vec3 translate;
		glm::vec3 rotate;
		glm::vec3 scale;
	};
}
#pragma once
#include <glm/glm.hpp>

namespace Vana {
	class Transform
	{
	public:
		Transform()
			: transformMatrix(glm::mat4(1))
			//, parentTransfrom(NULL)
			, translate(glm::vec3(0)), rotate(glm::vec3(0)), scale(glm::vec3(1))
		{}
		Transform(glm::mat4 const& pTransfrom) 
			: transformMatrix(glm::mat4(1))
			//, parentTransfrom(pTransfrom)
			, translate(glm::vec3(0)), rotate(glm::vec3(0)), scale(glm::vec3(1))
			//, defaultTranslate(glm::vec3(0)), defaultRotate(glm::vec3(0)), defaultScale(glm::vec3(1))
		{};
		//void SetDefaultTransform(glm::vec3 translate, glm::vec3 rotate, glm::vec3 scale);
		void Translate(glm::vec3);
		void Rotate(glm::vec3);
		void Scale(glm::vec3);
		glm::mat4 const& GetTransform() const;
		void SetTransform(glm::mat4 const matrix);
		//glm::mat4 const& GetWorldTransform() const;
		void UpdateTransform();
		void ResetTransform();
	private:
		// Go to Transfom
		glm::mat4 transformMatrix;
		//glm::mat4 parentTransfrom; // can not change by this
		glm::vec3 translate;
		glm::vec3 rotate;
		glm::vec3 scale;
		//glm::vec3 defaultTranslate;
		//glm::vec3 defaultRotate;
		//glm::vec3 defaultScale;
	};
}
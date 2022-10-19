#pragma once

#ifndef VENA_CLASS_NODE
#define VENA_CLASS_NODE
#include "Transform.h"

namespace Vana {
	// separate Transform as its own class
	// transform has world-accum and local
	class Node
	{
	public:
		Node();
		Node(Node*);
		virtual void DefaultInit();
		virtual void Init();
		virtual void DefaultUpdate();
		virtual void Update();
		std::map< unsigned int, Node*> GetChildren();
		Node const* GetChild(unsigned int);
		Node const* GetParent() const;
		void AddChild(Node*);
		Transform transform;
		Transform parentTransform;
		//void SetDefaultTransform(glm::vec3, glm::vec3, glm::vec3);
		//void Translate(glm::vec3);
		//void Rotate(glm::vec3);
		//void Scale(glm::vec3);
		//glm::mat4* transform;
		//glm::mat4* parentTransfrom;
		unsigned int nodeID;
	protected:
	private:
		//void UpdateTransform();
		//void ResetTransform();
		Node* parent;
		std::map< unsigned int, Node*> children;
		// Go to Transfom
		//glm::vec3 translate;
		//glm::vec3 rotate;
		//glm::vec3 scale;
		//glm::vec3 defaultTranslate;
		//glm::vec3 defaultRotate;
		//glm::vec3 defaultScale;
		inline unsigned int static nodeIDMax;
	};
}

#endif
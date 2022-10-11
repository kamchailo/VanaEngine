#pragma once

#ifndef VENA_CLASS_NODE
#define VENA_CLASS_NODE

namespace Vana {

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
		Node* GetChild(unsigned int);
		Node* GetParent();
		Node* AddChild(Node*);
		void Translate(glm::vec3);
		void Rotate(glm::vec3);
		void Scale(glm::vec3);
		glm::mat4 transform;
		glm::mat4 parentTransfrom;
	private:
		void UpdateTransform();
		unsigned int nodeID;
		Node* parent;
		std::map< unsigned int, Node*> children;
		glm::vec3 translate;
		glm::vec3 rotate;
		glm::vec3 scale;
		inline unsigned int static nodeIDMax;
	};
}

#endif
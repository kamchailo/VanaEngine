#pragma once

#ifndef VENA_CLASS_NODE
#define VENA_CLASS_NODE

namespace Vana {

	class Node
	{
	public:
		Node();
		Node(Node*);
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
		unsigned int nodeID;
		Node* parent;
		std::map< unsigned int, Node*> children;
		inline unsigned int static nodeIDMax;



	};
}

#endif
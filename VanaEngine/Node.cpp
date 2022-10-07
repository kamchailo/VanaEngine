#include "pch.h"
#include "Node.h"

namespace Vana {
	Node::Node()
	{
		this->parent = NULL;
		this->transform = glm::mat4(1);
		this->parentTransfrom = glm::mat4(1);
	}

	Node::Node(Node* parentNode)
	{
		//this->nodeID = ++Node::nodeIDMax;
		this->parent = parentNode;
		this->transform = glm::mat4(1);
		if (parentNode)
		{
			this->parentTransfrom = parentNode->transform * parentNode->parentTransfrom;
		}
		else
		{
			this->parentTransfrom = glm::mat4(1);
		}
	}
	void Node::Update()
	{
		for (const auto& child : children)
		{
			child.second->Update();
		}
	}
	std::map<unsigned int, Node*> Node::GetChildren()
	{
		return children;
	}
	Node* Node::GetChild(unsigned int childNodeID)
	{
		return children[childNodeID];
	}

	Node* Node::GetParent()
	{
		return parent;
	}

	Node* Node::AddChild(Node* newChild)
	{
		children[newChild->nodeID] = newChild;
		return this;
	}

	void Node::Translate(glm::vec3)
	{
	}

	void Node::Rotate(glm::vec3)
	{
	}

	void Node::Scale(glm::vec3)
	{
	}
}

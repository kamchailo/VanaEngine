#include "pch.h"
#include "Node.h"
#include "Graphics.h"

namespace Vana {
	Node::Node()
	{
		this->nodeID = ++Node::nodeIDMax;
		this->parent = NULL;
		this->transform = glm::mat4(1);
		this->parentTransfrom = glm::mat4(1);
	}

	Node::Node(Node* parentNode)
	{
		this->nodeID = ++Node::nodeIDMax;
		this->parent = parentNode;
		this->transform = glm::mat4(1);
		if (parentNode)
		{
			parentNode->AddChild(this);
			this->parentTransfrom = parentNode->transform * parentNode->parentTransfrom;
		}
		else
		{
			this->parentTransfrom = glm::mat4(1);
		}
	}

	void Node::DefaultInit()
	{
		for (const auto& child : children)
		{
			child.second->DefaultInit();
			child.second->Init();
		}
	}

	void Node::Init()
	{
	}

	void Node::DefaultUpdate()
	{
		// Transformation 
		if (parent)
		{
			parentTransfrom = parent->parentTransfrom * parent->transform;
			//transform = parentTransfrom * transform;
		}
		for (const auto& child : children)
		{
			child.second->DefaultUpdate();
			child.second->Update();
		}
	}

	void Node::Update()
	{
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

	void Node::Translate(glm::vec3 translateVec)
	{
		translateVec.x = translateVec.x / GraphicSystem::windowSize.x;
		translateVec.y = translateVec.y / GraphicSystem::windowSize.y;
		transform = glm::translate(transform, translateVec);
	}

	void Node::Rotate(glm::vec3 rotateVec)
	{
		if (rotateVec.x != 0)
		{
			transform = glm::rotate(transform,glm::radians(rotateVec.x), glm::vec3(1.0,0.0,0.0));
		}
		if (rotateVec.y != 0)
		{
			transform = glm::rotate(transform, glm::radians(rotateVec.y), glm::vec3(0.0, 1.0, 0.0));
		}
		if (rotateVec.z != 0)
		{
			transform = glm::rotate(transform, glm::radians(rotateVec.z), glm::vec3(0.0, 0.0, 1.0));
		}
	}

	void Node::Scale(glm::vec3 scaleVec)
	{
		transform = glm::scale(transform, scaleVec);
	}
}

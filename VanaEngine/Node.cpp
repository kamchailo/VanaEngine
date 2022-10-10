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
		this->scale = glm::vec3(1.0);
	}

	Node::Node(Node* parentNode)
	{
		this->nodeID = ++Node::nodeIDMax;
		this->parent = parentNode;
		this->transform = glm::mat4(1);
		this->scale = glm::vec3(1.0);
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
		translate = glm::vec3(0);
		rotate = glm::vec3(0);
		scale = glm::vec3(1);
		for (const auto& child : children)
		{
			child.second->DefaultInit();
			child.second->Init();
		}
	}

	void Node::Init()
	{
		// To be replaced by user
	}

	void Node::DefaultUpdate()
	{
		//std::cout << "inside node default update" << std::endl;
		// reset transform
		transform = glm::mat4(1);
		UpdateTransform();
		// Transformation 
		if (parent)
		{
			//rotate = glm::vec3(0, 0, 0.01);
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
		// To be replaced by user
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
		translate = translateVec;
	}

	void Node::Rotate(glm::vec3 rotateVec)
	{rotate = rotateVec;
	}

	void Node::Scale(glm::vec3 scaleVec)
	{
		scale = scaleVec;
	}

	// Calculate transformmation per frame
	void Node::UpdateTransform()
	{
		// calc transform = 
		glm::vec3 worldTranslate(0);
		worldTranslate.x = (translate.x / GraphicSystem::windowSize.x);
		worldTranslate.y = (translate.y / GraphicSystem::windowSize.y);
		//std::cout << nodeID <<" World Translate: " << worldTranslate.x << ", " << worldTranslate.y << std::endl;
		transform = glm::translate(transform, worldTranslate);
		if (rotate.x != 0)
		{
			transform = glm::rotate(transform, glm::radians(rotate.x), glm::vec3(1.0, 0.0, 0.0));
		}
		if (rotate.y != 0)
		{
			transform = glm::rotate(transform, glm::radians(rotate.y), glm::vec3(0.0, 1.0, 0.0));
		}
		if (rotate.z != 0)
		{
			transform = glm::rotate(transform, glm::radians(rotate.z), glm::vec3(0.0, 0.0, 1.0));
		}
		transform = glm::scale(transform, scale);
		// reset translate rotate scale
		translate = glm::vec3(0);
		rotate = glm::vec3(0);
		scale = glm::vec3(1);
	}
}

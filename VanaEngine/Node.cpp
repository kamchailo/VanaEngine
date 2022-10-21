#include "pch.h"
#include "Node.h"
#include "Graphics.h"

namespace Vana {
	Node::Node()
	{
		this->nodeID = ++Node::nodeIDMax;
		this->parent = NULL;
		this->transform = Transform();
		this->parentTransform = Transform();
	}

	Node::Node(Node* parentNode)
	{
		this->nodeID = ++Node::nodeIDMax;
		this->parent = parentNode;
		this->transform = Transform();
		parentNode->AddChild(this);
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
		// To be overrided by user
	}

	void Node::DefaultUpdate()
	{
		// Transform always update first to support GetTransforation in Update
		transform.ResetTransform();
		transform.UpdateTransform();
		// Transformation 
		if (parent)
		{
			parentTransform.SetTransform(parent->parentTransform.GetTransform() * parent->transform.GetTransform());
		}
		for (const auto& child : children)
		{
			child.second->DefaultUpdate();
			child.second->Update();
		}
	}

	void Node::Update()
	{
		// To be overrided by user
	}

	std::map<unsigned int, Node*> Node::GetChildren()
	{
		return children;
	}
	Node const* Node::GetChild(unsigned int childNodeID)
	{
		return children[childNodeID];
	}

	Node const* Node::GetParent() const
	{
		return parent;
	}

	void Node::AddChild(Node* newChild)
	{
		children[newChild->nodeID] = newChild;
		newChild->parentTransform = Transform();
	}
}

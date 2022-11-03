#include "pch.h"
#include "Node.h"

namespace Vana {
	Node::Node()
	{
		this->nodeID = ++Node::nodeIDMax;
		this->parent = NULL;
		this->transform = Transform();
		this->parentTransform = Transform();
		this->position = glm::vec3(0);
		this->rotation = glm::vec3(0);
		this->scale = glm::vec3(1);
	}

	Node::Node(Node* parentNode)
	{
		this->nodeID = ++Node::nodeIDMax;
		this->parent = parentNode;
		parentNode->AddChild(this);
		this->transform = Transform();
		this->position = glm::vec3(0);
		this->rotation = glm::vec3(0);
		this->scale = glm::vec3(1);
	}

	Node::~Node()
	{
		for (int i = 0; i < components.size(); i++)
		{
			delete components[i];
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
		// To be overrided by user
	}

	void Node::DefaultUpdate()
	{
		// Transform always update first to support GetTransforation in Update
		//transform.ResetTransform();
		//transform.UpdateTransform(position, rotation, scale);
		if (collider)
		{
			collider->SetPosition(position);
			collider->SetRotation(rotation);
		}
		// Transformation 
		//if (parent)
		//{
			//parentTransform.SetTransform( parent->parentTransform.GetTransform() * parent->transform.GetTransform());
			//std::cout << "nodeID " << nodeID << " pTransform " << parentTransform.GetTransform()[0][0] << std::endl;
		//}
		for (Component* c : components)
		{
			c->Update();
		}
		for (const auto& child : children)
		{
			child.second->DefaultUpdate();
			child.second->Update(); // user update
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

	glm::vec3 Node::GetPosition() const
	{
		return position;
	}
	glm::vec3 Node::GetRotation() const
	{
		return rotation;
	}
	glm::vec3 Node::GetScale() const
	{
		return scale;
	}
	void Node::SetPosition(glm::vec3 const& newPosition)
	{
		position = newPosition;
	}
	void Node::SetRotation(glm::vec3 const& newRotation)
	{
		rotation = newRotation;
	}
	void Node::SetScale(glm::vec3 const& newScale)
	{
		scale = newScale;
	}
	void Node::AddComponent(Component* component)
	{
		component->SetOwner(this);
		components.push_back(component);
	}
}

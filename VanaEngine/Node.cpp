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
		this->name = "noname";
		this->nodeID = ++Node::nodeIDMax;
		this->parent = parentNode;
		parentNode->AddChild(this);
		this->transform = Transform();
		this->parentTransform = parentNode->parentTransform;
		this->position = glm::vec3(0);
		this->rotation = glm::vec3(0);
		this->scale = glm::vec3(1);
	}

	Node::Node(std::string name, Node* parentNode)
	{
		this->name = name;
		this->nodeID = ++Node::nodeIDMax;
		this->parent = parentNode;
		parentNode->AddChild(this);
		this->transform = Transform();
		this->parentTransform = parentNode->parentTransform;
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
		for (auto& child : children)
		{
			delete &child;
		}
	}

	void Node::DefaultInit()
	{
		for (Component* c : components)
		{
			c->Init();
		}
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

	void Node::DefaultUpdate(double _dt)
	{
		for (Component* c : components)
		{
			c->Update(_dt);
		}
		for (const auto& child : children)
		{
			child.second->DefaultUpdate(_dt);
			child.second->Update(_dt); // user update
		}
	}

	void Node::Update(double _dt)
	{
		// To be overrided by user
	}

	void Node::HandleEvent(Event* _event)
	{
		//std::cout << "inside handle event" << std::endl;
		for (Component* c : components)
		{
			c->HandleEvent(_event);
		}
		for (const auto& child : children)
		{
			child.second->HandleEvent(_event);
		}
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

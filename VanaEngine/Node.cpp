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
		//this->transform = glm::mat4(1);
		//this->parentTransfrom = glm::mat4(1);
		//this->scale = glm::vec3(1.0);
	}

	Node::Node(Node* parentNode)
	{
		this->nodeID = ++Node::nodeIDMax;
		this->parent = parentNode;
		this->transform = Transform();
		parentNode->AddChild(this);
		//this->transform = new Transform(parent->transform->GetTransform());
		//this->transform = glm::mat4(1);
		//this->scale = glm::vec3(1.0);
		//if (parentNode)
		//{
		//	parentNode->AddChild(this);
		//	this->parentTransfrom = parentNode->transform * parentNode->parentTransfrom;
		//}
		//else
		//{
		//	this->parentTransfrom = glm::mat4(1);
		//}
	}

	void Node::DefaultInit()
	{
		//defaultTranslate = glm::vec3(0);
		//defaultRotate = glm::vec3(0);
		//defaultScale = glm::vec3(1);
		//transform->SetDefaultTransform(glm::vec3(0), glm::vec3(0), glm::vec3(1));
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
		//std::cout << "inside node default update >>>ID:" << nodeID << std::endl;
		//ResetTransform();
		// reset transform
		//transform = glm::mat4(1);
		transform.ResetTransform();
		transform.UpdateTransform();
		// Transformation 
		if (parent)
		{
			parentTransform.SetTransform(parent->parentTransform.GetTransform() * parent->transform.GetTransform());
			//parentTransform = parent->transform;
			//rotate = glm::vec3(0, 0, 0.01);
			//transform->UpdateTransform();
			//parentTransfrom = parent->parentTransfrom * parent->transform;
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
		// To be overrided by user
	}

	//void Node::SetDefaultTransform(glm::vec3 translate, glm::vec3 rotate, glm::vec3 scale)
	//{
	//	defaultTranslate = translate;
	//	defaultRotate = rotate;
	//	defaultScale = scale;
	//}

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

	//void Node::Translate(glm::vec3 translateVec)
	//{
	//	translate = defaultTranslate + translateVec;
	//}

	//void Node::Rotate(glm::vec3 rotateVec)
	//{rotate = defaultRotate + rotateVec;
	//}

	//void Node::Scale(glm::vec3 scaleVec)
	//{
	//	scale = defaultScale * scaleVec;
	//}

	//// Calculate transformmation per frame
	//void Node::UpdateTransform()
	//{
	//	// calc transform = 
	//	glm::vec3 worldTranslate(0);
	//	worldTranslate.x = (translate.x / GraphicSystem::windowSize.x) * 2.0;
	//	worldTranslate.y = (translate.y / GraphicSystem::windowSize.y) * 2.0;
	//	//std::cout << nodeID <<" World Translate: " << worldTranslate.x << ", " << worldTranslate.y << std::endl;
	//	transform = glm::translate(transform, worldTranslate);
	//	if (rotate.x != 0)
	//	{
	//		transform = glm::rotate(transform, glm::radians(rotate.x), glm::vec3(1.0, 0.0, 0.0));
	//	}
	//	if (rotate.y != 0)
	//	{
	//		transform = glm::rotate(transform, glm::radians(rotate.y), glm::vec3(0.0, 1.0, 0.0));
	//	}
	//	if (rotate.z != 0)
	//	{
	//		transform = glm::rotate(transform, glm::radians(rotate.z), glm::vec3(0.0, 0.0, 1.0));
	//	}
	//	transform = glm::scale(transform, scale);
	//	// reset translate rotate scale
	//	translate = glm::vec3(0);
	//	rotate = glm::vec3(0);
	//	scale = glm::vec3(1);
	//}
	//void Node::ResetTransform()
	//{
	//	translate = defaultTranslate;
	//	rotate = defaultRotate;
	//	scale = defaultScale;
	//}
}

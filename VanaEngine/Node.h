#pragma once
#include "pch.h"


#ifndef VENA_CLASS_NODE
#define VENA_CLASS_NODE

class Collider;
class Component;

namespace Vana {
	// separate Transform as its own class
	// transform has world-accum and local
	class Node
	{
	public:
		Node();
		Node(Node*);
		virtual void DefaultInit();
		virtual void Init(); // for user
		virtual void DefaultUpdate();
		virtual void Update(); // for user
		std::map< unsigned int, Node*> GetChildren();
		Node const* GetChild(unsigned int);
		Node const* GetParent() const;
		void AddChild(Node*);
		glm::vec3 GetPosition() const;
		glm::vec3 GetRotation() const;
		glm::vec3 GetScale() const;
		void SetPosition(glm::vec3 const&);
		void SetRotation(glm::vec3 const&);
		void SetScale(glm::vec3 const&);
		Transform transform; // local
		Transform parentTransform; // world = (parent->world * parent->local)
		unsigned int nodeID;

		template<class T>
		T* GetComponent()
		{
			std::vector<Component*>::iterator it = components.begin();
			while (it != components.end())
			{
				T* type = dynamic_cast<T*>(*it);
				if (type != 0)
				{
					return type;
				}
				it = it + 1;
			}
			return nullptr;
		}
		void AddComponent(Component* component);

		Collider* collider;
	private:
		std::vector<Component*> components;

		glm::vec3 position;
		glm::vec3 rotation;
		glm::vec3 scale;
		glm::vec3 absoluteScale;
		Node* parent;
		std::map< unsigned int, Node*> children;
		inline unsigned int static nodeIDMax;
	};
}

#endif
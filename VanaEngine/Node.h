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
		virtual ~Node();
		// Scene Graph
		unsigned int nodeID;
		void AddChild(Node*);
		Node const* GetParent() const;
		Node const* GetChild(unsigned int);
		std::map< unsigned int, Node*> GetChildren();

		// Game Update
		virtual void DefaultInit();
		virtual void Init(); // for user
		virtual void DefaultUpdate();
		virtual void Update(); // for user

		// Event
		void HandleEvent(Event* _event);

		// Transform
		glm::vec3 GetPosition() const;
		glm::vec3 GetRotation() const;
		glm::vec3 GetScale() const;
		void SetPosition(glm::vec3 const&);
		void SetRotation(glm::vec3 const&);
		void SetScale(glm::vec3 const&);
		Transform transform; // local
		Transform parentTransform; // world = (parent->world * parent->local)

		// Components
		void AddComponent(Component* component);
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

		// Physics
		//Collider* collider;
	private:

		// Scene Graph
		inline unsigned int static nodeIDMax;
		Node* parent;
		std::map< unsigned int, Node*> children;
		
		// Transform
		glm::vec3 position;
		glm::vec3 rotation;
		glm::vec3 scale;

		// Components
		std::vector<Component*> components;
	};
}

#endif
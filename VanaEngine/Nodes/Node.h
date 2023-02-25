#pragma once

#include "../Math/Transform.h"

class Collider;
class Component;

namespace Vana {
	class Node
	{
	public:
		Node();
		Node(Node*);
		Node(std::string,Node*);
		virtual ~Node();
		// Scene Graph
		unsigned int nodeID;
		void AddChild(Node*);
		Node const* GetParent() const;
		Node const* GetChild(unsigned int);
		std::map< unsigned int, Node*> GetChildren() const;
		void RemoveChild(int nodeId);

		// Game Update
		virtual void DefaultInit();
		virtual void Init(); // for user
		virtual void DefaultUpdate(double _dt);
		virtual void Update(double _dt); // for user

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

		// Scene System
		bool IsAwake();
		bool IsAlive();
		void CheckIsDestroy(std::vector<Node*>& collector);
		void Destroy();
	private:
		// Editor
		std::string name;

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

		// Scene System
		bool isAwake = false;
		bool isAlive = true;
	};
}
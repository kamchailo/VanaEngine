#include "pch.h"
#include "NodeGameObject.h"

NodeGameObject::~NodeGameObject()
{
	for (Component* component : components)
	{
		delete(component);
	}
}

void NodeGameObject::DefaultInit()
{
	Node::DefaultUpdate();
	for (Component* component : components)
	{
		component->Update();
	}
}

void NodeGameObject::DefaultUpdate()
{
}

void NodeGameObject::AddComponent(Component* component)
{
	components.push_back(component);
}
#pragma once
#include "pch.h"

class NodeGameObject : public Vana::Node
{
public:
	~NodeGameObject();
	void DefaultInit();
	void DefaultUpdate();
	//Component GetComponent(Component);
	bool MarkAsDelete();
	void SetAlive(bool state);
	void SetDelete(bool state);

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
private:
	std::vector<Component*> components;
	bool isAlive;
	bool needsDeletion;
};
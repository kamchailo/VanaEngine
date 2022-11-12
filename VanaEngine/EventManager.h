#pragma once
#include"pch.h"
//#include "Node.h"

namespace Vana
{
	class Node;
}

class EventManager
{
public:
	EventManager();
	~EventManager();

	void AddEvent(Event* _event);
	void ClearEvent();
	void DispatchEvent(Vana::Node* root);
	std::list<Event*>* GetEvents() const;
private:
	std::list<Event*>* events;
};
#include "pch.h"
#include "EventManager.h"
#include "Nodes/Node.h"

EventManager::EventManager() : events(new std::list<Event*>)
{
	
}

EventManager::~EventManager()
{
	for (Event* e : *events)
	{
		delete e;
	}
	delete events;
}

void EventManager::AddEvent(Event* _event)
{
	events->push_back(_event);
}

void EventManager::ClearEvent()
{
	for (auto* e : *events)
	{
		delete e;
	}
	events->clear();
}

void EventManager::DispatchEvent(Vana::Node* root)
{
	for (Event* e : *events)
	{
		root->HandleEvent(e);
	}
	ClearEvent();
}

std::list<Event*>* EventManager::GetEvents() const
{
	return events;
}
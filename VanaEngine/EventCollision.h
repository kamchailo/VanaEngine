#pragma once

#include "pch.h"

class Collider;

class EventCollisionMessage
{
public:
	EventCollisionMessage(Collider* _origin)
		: origin(_origin) {};
	Collider* origin;
};

class EventCollision : public Event
{
public:
	EventCollision(EventCollisionMessage* _message) : Event(_message) {};
};

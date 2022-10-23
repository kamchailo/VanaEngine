#include "pch.h"
#include "Component.h"


Node* Component::GetOwner() const
{
	return owner;
}

void Component::SetOwner(Node* newOwner)
{
	owner = newOwner;
}
#include "pch.h"

#include "Nodes/Node.h"
#include "Math/Transform.h"

ComponentTransform::ComponentTransform()
{
}

void ComponentTransform::Init()
{
}

void ComponentTransform::Update(double _dt)
{
	owner->transform.ResetTransform();
	owner->transform.UpdateTransform(
		owner->GetPosition()
		, owner->GetRotation()
		, owner->GetScale());
	if (owner->GetParent())
	{
		owner->parentTransform.SetTransform(
			owner->GetParent()->parentTransform.GetTransform() 
			* owner->GetParent()->transform.GetTransform());
	}

}

void ComponentTransform::Shutdown()
{
}

void ComponentTransform::HandleEvent(Event* _event)
{
}
#include "pch.h"

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
		
		//std::cout << "nodeID " << owner->nodeID << " pTransform " << owner->parentTransform.GetTransform()[3][0] << std::endl;
	}

}

void ComponentTransform::Shutdown()
{
}

void ComponentTransform::HandleEvent(Event* _event)
{
}

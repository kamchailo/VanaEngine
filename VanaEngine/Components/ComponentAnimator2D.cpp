#include "pch.h"
#include "ComponentAnimator2D.h"

ComponentAnimator2D::ComponentAnimator2D()
{
	animator = new Animator2D();
}

ComponentAnimator2D::~ComponentAnimator2D()
{
	delete animator;
}

void ComponentAnimator2D::Init()
{
}

void ComponentAnimator2D::Update(double _dt)
{
	owner->GetComponent<ComponentRenderer>()
		->SetTilling(animator->GetCurrentAnimation()->GetSpriteTilling());
	owner->GetComponent<ComponentRenderer>()
		->SetTillingOffset(animator->GetCurrentAnimation()->GetSpriteOffset());
	if (animator->IsPlaying())
	{
		animator->Play(_dt);
	}
}

void ComponentAnimator2D::Shutdown()
{
}

void ComponentAnimator2D::HandleEvent(Event* _event)
{
}

void ComponentAnimator2D::Play()
{
	animator->StartPlaying();
}

void ComponentAnimator2D::Pause()
{
	animator->Pause();
}

void ComponentAnimator2D::Stop()
{
	animator->Pause();
	animator->Reset();
}

Animator2D* ComponentAnimator2D::GetAnimator2D() const
{
	return animator;
}

void ComponentAnimator2D::SetPlayingAnimation(Animation2D* _animation)
{
	animator->SetAnimation(_animation);
	ComponentRenderer* renderer = owner->GetComponent<ComponentRenderer>();
	if (renderer)
	{
		renderer->ChangeTexture(_animation->GetTexture());
	}
}
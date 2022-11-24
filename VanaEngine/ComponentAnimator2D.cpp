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
	//animator->AddFrame(0.0, 0);
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

//void ComponentAnimator2D::AddFrame(double _time, int _frame)
//{
//	animator->AddFrame(_time, _frame);
//}

//void ComponentAnimator2D::SetMaxDuration(double _time)
//{
//	animator->GetCurrentAnimation()->SetMaxDuration(_time);
//}

Animator2D* ComponentAnimator2D::GetAnimator2D() const
{
	return animator;
}

void ComponentAnimator2D::SetPlayingAnimation(Animation2D* _animation)
{
	animator->SetAnimation(_animation);
}
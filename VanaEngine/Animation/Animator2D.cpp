#include "pch.h"
#include "Animator2D.h"

#include "Animation2D.h"

Animator2D::Animator2D()
{
}

Animator2D::~Animator2D()
{
}

void Animator2D::Play(double _dt)
{
	elapsedTime += _dt;
	currentAnimation->GoToCurrentFrame(elapsedTime);

	if (elapsedTime >= currentAnimation->GetMaxDuration())
	{
		elapsedTime = 0.0;
		if (!currentAnimation->IsRepeat())
		{
			isPlaying = false;
		}
	}
}

void Animator2D::Pause()
{
	isPlaying = false;
}

void Animator2D::Reset()
{
	isPlaying = true;
	elapsedTime = 0.0;
	currentAnimation->GoToCurrentFrame(elapsedTime);
}

void Animator2D::SetAnimation(Animation2D* _animation)
{
	currentAnimation = _animation;
}

Animation2D* Animator2D::GetCurrentAnimation() const
{
	return currentAnimation;
}

bool Animator2D::IsPlaying() const
{
	return isPlaying;
}

void Animator2D::StartPlaying()
{
	isPlaying = true;
}
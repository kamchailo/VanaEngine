#pragma once

#include "../Animation/Animation2D.h"
#include "../Animation/Animator2D.h"


class ComponentAnimator2D : public Component
{
public:
	ComponentAnimator2D();
	~ComponentAnimator2D();
	void Init();
	void Update(double _dt);
	void Shutdown();
	virtual void HandleEvent(Event* _event);
	void Play();
	void Pause();
	void Stop();
	Animator2D* GetAnimator2D() const;
	void SetPlayingAnimation(Animation2D* _animation);
private:
	Animator2D* animator;
};
#pragma once

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
	//void AddFrame(double _time, int _frame);
	//void SetMaxDuration(double _time);
	void SetPlayingAnimation(Animation2D* _animation);
private:
	Animator2D* animator;
	//std::map<unsigned int, Animation2D*> animations;
};
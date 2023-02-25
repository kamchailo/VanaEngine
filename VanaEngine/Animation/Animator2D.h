#pragma once

class Animation2D;

class Animator2D
{
public:
	Animator2D();
	~Animator2D();
	void Play(double _dt);
	void Pause();
	void Reset();
	bool IsPlaying() const;
	void StartPlaying();
	void SetAnimation(Animation2D* _animation);
	Animation2D* GetCurrentAnimation() const;
private: 
	double elapsedTime = 0;
	bool isPlaying = false;
	std::map<std::string,Animation2D*> animations;
	Animation2D* currentAnimation;
};



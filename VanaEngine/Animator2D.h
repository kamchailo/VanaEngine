#pragma once

#include "pch.h"

/*
* 
* Class Animator  
* - Switch Animations
* - Play
* - Pause
* - Stop
* - Reset
* - Hold vector<Animations>
*/
class Animator2D
{
public:
	Animator2D();
	//Animator2D(int _col, int _row, bool _isRepeat, bool _autoplay);
	~Animator2D();
	void Play(double _dt);
	void Pause();
	void Reset();
	bool IsPlaying() const;
	void StartPlaying();
	//void AddAnimation(Animation2D* _animation);
	void SetAnimation(Animation2D* _animation);
	Animation2D* GetCurrentAnimation() const;
	// Move to Animation
	//void AddFrame(double _time, int _frame);
	//void SetMaxDuration(double _maxDuration);
	//glm::vec2 GetSpriteTilling();
	//glm::vec2 GetSpriteOffset();
private: 
	double elapsedTime = 0;
	bool isPlaying = false;
	std::map<std::string,Animation2D*> animations;
	Animation2D* currentAnimation;
	// Move to Animation
	//int spriteRow;
	//int spriteColumn;
	//int spriteAt;
	//double maxDuration = 0;
	//bool isRepeat = false;
	//std::map<double, int> animation;
	//int GetCurrentFrame();
};



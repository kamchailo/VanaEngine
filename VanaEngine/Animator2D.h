#pragma once

#include "pch.h"

class Animator2D
{
public:
	Animator2D(int _row, int _col, bool _isRepeat, bool _autoplay);
	~Animator2D();
	void Play();
	void Pause();
	void Reset();
	void AddAnimation(double _time, int _frame);
private:
	int spriteRow;
	int spriteColumn;
	int spriteAt;
	bool isRepeat = false;
	bool isPlaying = false;
	std::map<double, int> animation;
	glm::vec2 GetSpriteTotal();
	glm::vec2 GetSpriteAt();
};
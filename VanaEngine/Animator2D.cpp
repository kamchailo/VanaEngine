#include "pch.h"
#include "Animator2D.h"

Animator2D::Animator2D()
{
}

//Animator2D::Animator2D(int _col, int _row, bool _isRepeat, bool _autoplay)
//	: spriteColumn(_col)
//	, spriteRow(_row)
//	, spriteAt(0)
//	, isRepeat(_isRepeat)
//	, isPlaying(_autoplay)
//{
//}

Animator2D::~Animator2D()
{
}

void Animator2D::Play(double _dt)
{
	//if (currentAnimation->GetKeyframesSize() == 0) { return; }
	elapsedTime += _dt;
	currentAnimation->GoToCurrentFrame(elapsedTime);

	//if (animation.size() == 0) { return; }
	//elapsedTime += _dt;
	// change frame
	//spriteAt = GetCurrentFrame();
	//std::cout<< elapsedTime << "animation at frame " << spriteAt << std::endl;
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
	//spriteAt = animation.begin()->second;
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

//void Animator2D::AddFrame(double _time, int _frame)
//{
//	//animation.emplace(_time, _frame);
//	animation[_time] = _frame;
//	std::cout << "add animation " << animation.size() << std::endl;
//}
//
//void Animator2D::SetMaxDuration(double _maxDuration)
//{
//	maxDuration = _maxDuration;
//}
//
//glm::vec2 Animator2D::GetSpriteTilling()
//{
//	return glm::vec2(1.0 / static_cast<float>(spriteColumn), 1.0 / static_cast<float>(spriteRow));
//}
//
//glm::vec2 Animator2D::GetSpriteOffset()
//{
//	// 3 * 5 spritesheet
//	// 0  1  2  3  4
//	// 5  6  7  8  9
//	//10 11 12 13 14
//	// 13
//	// row = 13 / 5 = 2
//	// column = 13 % 5 = 3
//	int rowAt = spriteAt / spriteColumn + 1;
//	int colAt = spriteAt % spriteColumn;
//	glm::vec2 tilling = GetSpriteTilling();
//	// OpenGl Column Major
//	// OpenGL flip y
//	// ^
//	// | y
//	// + ---> x
//	return glm::vec2(colAt * tilling.x, -rowAt * tilling.y);
//}
//
//int Animator2D::GetCurrentFrame()
//{
//	std::map<double, int>::iterator it, prev;
//	for (it = animation.begin(); it != animation.end(); ++it)
//	{
//		if (elapsedTime < it->first) 
//		{ 
//			//std::cout << "Get Break" << std::endl;
//			break; 
//		}
//	}
//	// Go back one
//	it = --it;
//	return it->second;
//}

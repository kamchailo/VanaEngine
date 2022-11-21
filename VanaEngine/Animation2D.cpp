#include "pch.h"
#include "Animation2D.h"

unsigned int MAXID = 0;

Animation2D::Animation2D(Texture* _texture, int _col, int _row, bool _isRepeat, bool _autoplay)
	: texture(_texture)
	, column(_col)
	, row(_row)
	, frameAt(0)
	, isRepeat(_isRepeat)
	, isAutoplay(_autoplay)
{
	id = ++MAXID;
}

unsigned int Animation2D::GetID() const
{
	return id;
}

int Animation2D::GetKeyframesSize() const
{
	return keyframes.size();
}

void Animation2D::SetRepeat(bool _repeat)
{
	isRepeat = _repeat;
}

bool Animation2D::IsRepeat() const
{
	return isRepeat;
}

void Animation2D::AddKeyFrame(double _time, int _frame)
{
	keyframes[_time] = _frame;
	std::cout << "add keyframe " << keyframes.size() << std::endl;
}

int Animation2D::GoToCurrentFrame(double elapsedTime)
{
	if (keyframes.size() == 0) { return -1; }
	std::map<double, int>::iterator it;
	for (it = keyframes.begin(); it != keyframes.end(); ++it)
	{
		if (elapsedTime < it->first)
		{
			//std::cout << "Get Break" << std::endl;
			break;
		}
	}
	// Go back one
	if (it == keyframes.begin())
	{
		return it->second;
	}
	it = --it;
	frameAt = it->second;
	return it->second;
}

void Animation2D::SetMaxDuration(double _maxDuration)
{
	maxDuration = _maxDuration;
}

double Animation2D::GetMaxDuration() const
{
	return maxDuration;
}

glm::vec2 Animation2D::GetSpriteTilling()
{
	return glm::vec2(1.0 / static_cast<float>(column), 1.0 / static_cast<float>(row));
}

// 3 * 5 spritesheet
// 0  1  2  3  4
// 5  6  7  8  9
//10 11 12 13 14
// 13
// row = 13 / 5 = 2
// column = 13 % 5 = 3
// 
// OpenGl Column Major
// OpenGL flip y
// ^
// | y
// + ---> x
glm::vec2 Animation2D::GetSpriteOffset()
{
	int rowAt = frameAt / column + 1;
	int colAt = frameAt % column;
	glm::vec2 tilling = GetSpriteTilling();
	return glm::vec2(colAt * tilling.x, -rowAt * tilling.y);
}

#include "pch.h"
#include "Animator2D.h"

Animator2D::Animator2D(int _row, int _col, bool _isRepeat, bool _autoplay)
	: spriteRow(_row)
	, spriteColumn(_col)
	, spriteAt(0)
	, isRepeat(_isRepeat)
	, isPlaying(_autoplay)
{
}


glm::vec2 Animator2D::GetSpriteTotal()
{
	return glm::vec2(1.0 / static_cast<float>(spriteRow), 1.0 / static_cast<float>(spriteColumn));
}

glm::vec2 Animator2D::GetSpriteAt()
{
	// 3 * 5 spritesheet
	// 0  1  2  3  4
	// 5  6  7  8  9
	//10 11 12 13 14
	// 13
	// row = 13 / 5 = 2
	// column = 13 % 5 = 3
	int rowAt = spriteAt / spriteColumn;
	int colAt = spriteAt % spriteColumn;
	return glm::vec2(rowAt, colAt);
}
#pragma once

#include "pch.h"

/*
* 
* Class Animation
* Hold data for animation\
* - Map<Time, Keyframe>
* - Texture
*/
class Animation2D
{
public:
	Animation2D(Texture* _texture, int _col, int _row, bool _isRepeat, bool _autoplay);
	unsigned int GetID() const;
	Texture* GetTexture() const;
	int GetKeyframesSize() const;
	void SetRepeat(bool _repeat);
	bool IsRepeat() const;
	void AddKeyFrame(double _time, int _frame);
	int GoToCurrentFrame(double elapsedTime);
	void SetMaxDuration(double _maxDuration);
	double GetMaxDuration() const;
	glm::vec2 GetSpriteTilling();
	glm::vec2 GetSpriteOffset();
private:
	unsigned int id;
	Texture* texture;
	int column;
	int row;
	int frameAt;
	double maxDuration = 0;
	bool isRepeat = false;
	bool isAutoplay = false;
	std::map<double, int> keyframes;
	//static
	inline static unsigned int MAXID;
};
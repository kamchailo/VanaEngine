#pragma once
#include <VanaEngine.h>


class ScoreSprite : public Vana::Node
{
public:
	ScoreSprite(Vana::Node * _parent, Texture* _tex, glm::vec2 _size, glm::vec3 _position);
	~ScoreSprite();
	void Init() override;
	void Update(double _dt) override;
	void SetNumber(int _number);
private:
	Animation2D* animation;
	int number;
};

class ScoreBoard : public Vana::Node 
{
public:
	ScoreBoard(Texture* _tex, glm::vec2 _size, glm::vec3 _position);
	~ScoreBoard();
	void Init() override;
	void Update(double _dt) override;
	void SetScore(int _score);
private:
	std::vector<ScoreSprite*> scoreSprites;
	int score;
	glm::vec2 size;
};
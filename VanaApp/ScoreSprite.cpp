#include "ScoreSprite.h"

ScoreSprite::ScoreSprite(Vana::Node* _parent, Texture* _tex, glm::vec2 _size, glm::vec3 _position)
	:Node("score", _parent)
{
	ComponentTransform* ct = new ComponentTransform();
	ComponentRenderer* cr = new ComponentRenderer(_tex, _size);
	ComponentAnimator2D* compAnim2D = new ComponentAnimator2D();
	this->AddComponent(ct);
	this->AddComponent(cr);
	this->AddComponent(compAnim2D);
	this->SetPosition(_position);
	animation = new Animation2D(_tex, 10, 1, true, true);
	animation->SetMaxDuration(1.0);
	animation->AddKeyFrame(0.0, 0.0);
	animation->AddKeyFrame(1.0, 1.0);
	animation->AddKeyFrame(2.0, 2.0);
	animation->AddKeyFrame(3.0, 3.0);
	animation->AddKeyFrame(4.0, 4.0);
	animation->AddKeyFrame(5.0, 5.0);
	animation->AddKeyFrame(6.0, 6.0);
	animation->AddKeyFrame(7.0, 7.0);
	animation->AddKeyFrame(8.0, 8.0);
	animation->AddKeyFrame(9.0, 9.0);
}

ScoreSprite::~ScoreSprite()
{
	delete animation;
}

void ScoreSprite::Init()
{
	this->GetComponent<ComponentAnimator2D>()->SetPlayingAnimation(animation);
	this->GetComponent<ComponentAnimator2D>()->Play();
}

void ScoreSprite::Update(double _dt)
{
	animation->GoToCurrentFrame(number);
}

void ScoreSprite::SetNumber(int _number)
{
	number = _number;
}

ScoreBoard::ScoreBoard(Texture* _tex, glm::vec2 _size, glm::vec3 _position)
	:size(_size)
	, score(0)
{
	for (int i = 0; i < 2; ++i)
	{
		glm::vec3 digitPosition(_position.x - i * _size.x, _position.y, _position.z);
		ScoreSprite* sprite = new ScoreSprite(this, _tex, _size, digitPosition);
		scoreSprites.push_back(sprite);
	}
}

ScoreBoard::~ScoreBoard()
{
	for (auto& s : scoreSprites)
	{
		delete s;
	}
}

void ScoreBoard::Init()
{
	// Add 2 ScoreSprited
}

void ScoreBoard::Update(double _dt)
{
}

void ScoreBoard::SetScore(int _score)
{
	score = min(pow(10, scoreSprites.size()) - 1, _score);
	std::cout << "score " << score << std::endl;
	for (int i = 0; i < scoreSprites.size(); ++i)
	{
		if (i == 0)
		{
			scoreSprites[i]->SetNumber(score % 10);
		}
		else
		{
			scoreSprites[i]->SetNumber(score / (i * 10));
		}
	}
}

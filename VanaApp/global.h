#pragma once

#include <VanaEngine.h>

// DEFINE
#define WINDOW_WIDTH 1600
#define WINDOW_HEIGHT 1200

class Actor;
class ActorDebug;
class ScoreBoard;

inline NodeFactory nf;
inline Scene* mainScene;
inline Scene* endScene;

// Textures
inline Texture* texPlayer;
inline Texture* texDiamondHead;
inline Texture* texDiamondArrow;
inline Texture* texScore;

// Animations
inline Animation2D* diamondHeadIdle;
inline Animation2D* diamondArrowIdle;
inline Animation2D* scoreAnimation;

// SpriteSize
inline glm::vec3 diamondHeadSpriteSize = glm::vec3(50, 50,0);
inline glm::vec3 diamondArrowSpriteSize = glm::vec3(20, 20, 0);
inline glm::vec2 scoreFontSize = glm::vec2(50, 50);

// NodeInstance
inline Actor* player;

// UI
inline ActorDebug* actorDebug;
inline ScoreBoard* scoreBoard;


inline void TerminateGlobalVal()
{
	// Delete Lists
	// - Scene
	// - Animation

	// Animation
	delete diamondHeadIdle;
	delete diamondArrowIdle;
	delete scoreAnimation;

	// UI
	//delete actorDebug;
}


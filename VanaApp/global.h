#pragma once

#include <VanaEngine.h>

inline NodeFactory nf;
inline Scene* mainScene;
inline Scene* endScene;

// Textures
inline Texture* texPlayer;
inline Texture* texDiamondHead;
inline Texture* texDiamondArrow;

// Animations
inline Animation2D* diamondHeadIdle;
inline Animation2D* diamondArrowIdle;

// SpriteSize
inline glm::vec3 diamondHeadSpriteSize = glm::vec3(50, 50,0);
inline glm::vec3 diamondArrowSpriteSize = glm::vec3(20, 20, 0);

// NodeInstance
inline Actor* player;
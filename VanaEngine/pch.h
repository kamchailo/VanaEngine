// pch.h: This is a precompiled header file.
// Files listed below are compiled only once, improving build performance for future builds.
// This also affects IntelliSense performance, including code completion and many code browsing features.
// However, files listed here are ALL re-compiled if any one of them is updated between builds.
// Do not add files here that you will be updating frequently as this negates the performance advantage.

#ifndef PCH_H
#define PCH_H

// add headers that you want to pre-compile here
// STL and thrid party
#include "framework.h"
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <glm/glm.hpp>
#include <string>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <nlohmann/json.hpp>
#include "VanaDefine.h"

// Utilities
#include "Logger.h"
#include "Input.h"
#include "Event.h"
#include "EventManager.h"
#include "EventCollision.h"

// Core
#include "Graphics.h"
#include "GameUI.h"
#include "Transform.h"
#include "Mesh.h"
#include "Shader.h"
#include "Texture.h"
#include "Node.h"
#include "NodeFactory.h"

// Physics
#include "Collider.h"
#include "ColliderAABB.h"
#include "ColliderOOBB.h"
#include "CollisionManager.h"
#include "PhysicsBody.h"

// Art
#include "Animation2D.h"
#include "Animator2D.h"

// Components
#include "Component.h"
#include "ComponentTransform.h"
#include "ComponentRenderer.h"
#include "ComponentPhysics.h"
#include "ComponentAnimator2D.h"

#include "VanaEngine.h"

#endif //PCH_H

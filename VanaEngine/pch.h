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
#include "Utilities/Logger.h"
#include "Input/Input.h"
#include "Event/Event.h"
#include "Event/EventManager.h"
#include "Event/EventCollision.h"

// Core
#include "Graphics/Graphics.h"
#include "UI/GameUI.h"
#include "UI/GameUIWindow.h"
#include "Math/Transform.h"
#include "Graphics/Mesh.h"
#include "Graphics/Shader.h"
#include "Graphics/Texture.h"
#include "Nodes/Node.h"
#include "Nodes/NodeFactory.h"
#include "Scene/Scene.h"
#include "Scene/SceneSystem.h"

// Physics
#include "Physics/Collider.h"
#include "Physics/ColliderAABB.h"
#include "Physics/ColliderOOBB.h"
#include "Physics/CollisionManager.h"
#include "Physics/PhysicsBody.h"

// Art
#include "Animation/Animation2D.h"
#include "Animation/Animator2D.h"

// Components
#include "Components/Component.h"
#include "Components/ComponentTransform.h"
#include "Components/ComponentRenderer.h"
#include "Components/ComponentPhysics.h"
#include "Components/ComponentAnimator2D.h"

#include "VanaEngine.h"

#endif //PCH_H

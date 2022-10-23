// pch.h: This is a precompiled header file.
// Files listed below are compiled only once, improving build performance for future builds.
// This also affects IntelliSense performance, including code completion and many code browsing features.
// However, files listed here are ALL re-compiled if any one of them is updated between builds.
// Do not add files here that you will be updating frequently as this negates the performance advantage.

#ifndef PCH_H
#define PCH_H

// add headers that you want to pre-compile here
#include "framework.h"
#include <iostream>
#include <vector>
#include <map>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "VanaDefine.h"
#include "Logger.h"
#include "Input.h"
#include "Graphics.h"
#include "Transform.h"
#include "Mesh.h"
#include "Shader.h"
#include "Node.h"
#include "NodeGraphic.h"
//#include "Shape.h"
#include "Collider.h"
#include "ColliderAABB.h"
#include "ColliderOOBB.h"
#include "CollisionManager.h"

#include "Component.h"
#include "NodeGameObject.h"

#include "VanaEngine.h"

#endif //PCH_H

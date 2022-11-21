#include "pch.h"
#include "Scene.h"

void Scene::Init()
{
	root->DefaultInit();
}

void Scene::Update(double _dt)
{
	root->DefaultUpdate(_dt);
}

#include "pch.h"
#include "Scene.h"

// private use by SceneSystem
Scene::Scene()
{
	root = new Vana::Node();
}

Scene::Scene(NodeFactory& _factory, std::string _path)
{
	this->factory = &_factory;
	this->path = _path;
}

Scene::~Scene()
{
	delete root;
}

void Scene::Reset()
{
	root->DefaultInit();
}

void Scene::Load()
{
	root = &factory->CreateScene(path);
	for (int i = 0; i < extendedNodes.size(); ++i)
	{
		//Attach Extended Node to root
		root->AddChild(extendedNodes[i]);
	}
	root->DefaultInit();
}

void Scene::Unload()
{
	root->Destroy();
	delete root;
}

void Scene::Update(double _dt)
{
	// @@ switch scene

	root->DefaultUpdate(_dt);
}

Vana::Node* Scene::GetRoot() const
{
	return root;
}

void Scene::AddExtendedNode(Vana::Node* _node)
{
	extendedNodes.push_back(_node);
}

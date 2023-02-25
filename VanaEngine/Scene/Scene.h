#pragma once

namespace Vana
{
	class Node;
}

class SceneSystem;

class Scene
{
public:
	Scene(NodeFactory& _factory, std::string _path);
	~Scene();
	void Reset();
	void Load();
	void Unload();
	void ClearDeadNode();
	void Update(double _dt);
	Vana::Node* GetRoot() const;
	void AddExtendedNode(Vana::Node* _node);
private:
	Scene();
	friend SceneSystem;
	Vana::Node* root;
	NodeFactory* factory;
	std::string path;
	std::vector<Vana::Node*> extendedNodes;
};
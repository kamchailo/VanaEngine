#pragma once

namespace Vana
{
	class Node;
}

class Scene
{
public:
	void Init();
	void Update(double _dt);
private:
	Vana::Node* root;
};
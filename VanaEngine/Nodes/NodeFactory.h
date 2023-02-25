#pragma once

#include "Node.h"

class NodeFactory
{
public:
	NodeFactory();
	virtual ~NodeFactory();
	Vana::Node& CreateScene(std::string _filename);
private:
	virtual void AttachTree(Vana::Node& root, nlohmann::json const& children);
	std::map<std::string, Vana::Node*> nodes;
};

class NodeFactoryConstants {
private:
	friend NodeFactory;
	static const std::string NODE_ROOT;
	static const std::string NODE_CHILDREN;
	static const std::string NODE_BODY_2D;
	static const std::string NODE_SPRITE;
	static const std::string NAME;
	static const std::string POSITION;
	static const std::string ROTATION;
	static const std::string SCALE;
	static const std::string WIDTH;
	static const std::string HEIGHT;
	static const std::string TEXTURE;
};
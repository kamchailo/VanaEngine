#include "actor.h"
#include <MeshCollection.h>


float i = 0;

Actor::Actor(Node* parent, Texture* tex) : NodeGraphic(parent, MESH_SPRITE, SHADER_SPRITE, tex)
{
}

void Actor::Init()
{
	//this->Scale(glm::vec3(1.0, 0.2, 1.0));
}

void Actor::Update()
{
	//this->Scale(glm::vec3(1.0 - sin(i * 0.01), sin(i*0.01), 1.0));
	i += 0.001;
	this->Translate(glm::vec3(400*sin(i), 0.0, 0.0));
	//std::cout << i << std::endl;
	this->Rotate(glm::vec3(0.0, 0.0, 20*sin(i)));
}

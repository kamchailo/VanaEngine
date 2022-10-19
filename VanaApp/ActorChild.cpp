#include "ActorChild.h"
#include <MeshCollection.h>

float j = 0;


ActorChild::ActorChild(Node* parent, Texture* tex) : NodeGraphic(parent, MESH_SPRITE, SHADER_SPRITE, tex)
{
}

void ActorChild::Init()
{
}

void ActorChild::Update()
{
	j += 0.01;
	transform.Scale(glm::vec3(1.2));
	transform.Rotate(glm::vec3(0, 0,j));
	transform.Translate(glm::vec3(-200, -800, 0));
}

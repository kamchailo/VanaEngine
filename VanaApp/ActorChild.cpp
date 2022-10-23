#include "ActorChild.h"
#include <MeshCollection.h>

float j = 0;

ActorChild::ActorChild(Node* parent, Texture* tex, glm::vec2 spriteSize) : NodeGraphic(parent, MESH_SPRITE, SHADER_SPRITE, tex, spriteSize)
{
}

void ActorChild::Init()
{
}

void ActorChild::Update()
{
	j += 0.01;
	//SetScale(glm::vec3(100));
	//transform.Scale(glm::vec3(0.5));
	//transform.Rotate(glm::vec3(0, 0,j));
	//transform.Translate(glm::vec3(-200, -800, 0));
}

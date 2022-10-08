#include "pch.h"
#include "MeshCollection.h"

float spriteVertices[32] = {
    // positions          // colors           // texture coords
     0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // top right
     0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // bottom right
    -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // bottom left
    -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // top left 
};

unsigned int spriteIndices[] = {  // note that we start from 0!
    0, 1, 3,   // first triangle
    1, 2, 3    // second triangle
};

MeshCollection::~MeshCollection()
{
    delete(meshSprite);
}

void MeshCollection::Init()
{
    meshSprite = new Mesh(spriteVertices, sizeof(spriteVertices), spriteIndices, sizeof(spriteIndices), 8, 3, 6);
}
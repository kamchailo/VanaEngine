#include "pch.h"
#include "SceneSystem.h"

SceneSystem::~SceneSystem()
{
    delete defaultScene;
}

void SceneSystem::Init()
{
    // Create Empty Scene 
    defaultScene = new Scene();
    currentScene = defaultScene;
    nextScene = currentScene;
}

void SceneSystem::Update(double _dt)
{
    // @@ Switch Scene
    if (nextScene != currentScene)
    {
        currentScene->Unload();
        nextScene->Load();
        currentScene = nextScene;
    }
    currentScene->Update(_dt);
}

void SceneSystem::SetStartScene(Scene* scene)
{
    scene->Load();
    currentScene = scene;
    nextScene = currentScene;
}

void SceneSystem::SwitchScene(Scene* scene)
{
    //currentScene->Unload();
    //scene->Load();
    //currentScene = scene;
    nextScene = scene;
}

Scene* SceneSystem::GetCurrentScene() const
{
    return currentScene;
}

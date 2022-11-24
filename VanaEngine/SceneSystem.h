#pragma once

class Scene;

class SceneSystem
{
public:
	static SceneSystem* GetInstance() {
		static SceneSystem* instance = new SceneSystem();
		return instance;
	}
	~SceneSystem();
	void Init();
	void Update(double _dt);
	void SetStartScene(Scene* scene);
	void SwitchScene(Scene* scene);
	Scene* GetCurrentScene() const;
private:
	SceneSystem() {};
	//static SceneSystem* _instance;
	Scene* defaultScene;
	Scene* currentScene;
	Scene* nextScene;
};
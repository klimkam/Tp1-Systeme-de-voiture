#pragma once
#include "Scene.h"
#include "MainScene.h"
#include <vector>

class CarSystem
{
	Scene* m_currentScene;

	MainScene* p_mainScene = new MainScene();
	std::vector<Scene*> m_sceneCollection = {
		{new Scene()}, {new Scene()}
	};

public:
	CarSystem();

public:
	void RenderProgram();
	void HandleInput(char input);
	void GoToMain();
};


#pragma once
#include "Scene.h"
#include <vector>

class CarSystem
{
	Scene* m_currentScene;

	std::vector<Scene*> m_sceneCollection = {
		{new Scene()}, {new Scene()}
	};

public:
	CarSystem();
public:
	void RenderProgram();
};


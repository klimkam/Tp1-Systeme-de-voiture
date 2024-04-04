#pragma once
#include "Scene.h"
#include "MainScene.h"
#include <vector>

class CarSystem
{
	Scene* m_currentScene;

	InventoryScene* p_inventoryScene = new InventoryScene();
	MainScene* p_mainScene = new MainScene(p_inventoryScene);

public:
	CarSystem();

public:
	void RenderProgram();
	void HandleInput(char input);
	void GoToMain();
};


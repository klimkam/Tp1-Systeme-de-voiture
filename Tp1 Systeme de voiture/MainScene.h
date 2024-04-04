#pragma once
#include "Scene.h"
#include "InventoryScene.h"
#include "Scene.h"

class MainScene : public Scene
{
	InventoryScene* m_inventoryScene;
	Scene* m_companyScene;

public:
	MainScene();
	MainScene(InventoryScene* inventoryScene);
	Scene* HandleInput(char input) override;
};


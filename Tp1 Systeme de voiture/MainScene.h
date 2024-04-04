#pragma once
#include "Scene.h"
#include "InventoryScene.h"
#include "Scene.h"

class MainScene : public Scene
{
	Scene* m_inventoryScene = new InventoryScene(this);
	Scene* m_companyScene;

public:
	MainScene();
	Scene* HandleInput(char input) override;
};


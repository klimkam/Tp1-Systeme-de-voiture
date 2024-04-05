#pragma once
#include "Scene.h"
#include "InventoryScene.h"
#include "CompanySelectionScene.h"
#include "Scene.h"

class MainScene : public Scene
{
	InventoryScene* m_inventoryScene;
	Scene* m_companyScene;

public:
	MainScene(InventoryScene* inventoryScene, CompanySelectionScene* companySelectionScene);
	Scene* HandleInput(char input) override;
};


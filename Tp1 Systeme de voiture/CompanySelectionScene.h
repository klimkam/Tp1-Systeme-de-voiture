#pragma once
#include "Scene.h"
#include "CompanyManager.h"
#include "InventoryScene.h"


class CompanySelectionScene : public Scene
{
	CompanyManager* m_companyManager;
	InventoryScene* m_inventoryScene;

public:
	CompanySelectionScene(CompanyManager* companyManager);
	void SetInventoryScene(InventoryScene* inventoryScene);

	Scene* HandleInput(char input) override;
	Scene* HandleStringInput(std::string input) override;
};


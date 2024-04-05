#pragma once
#include "Scene.h"
#include "MainScene.h"
#include "CompanySelectionScene.h"
#include <vector>

class CarSystem
{
	Scene* m_currentScene;
	CompanyManager* m_company_manager = new CompanyManager();

	InventoryScene* p_inventoryScene = new InventoryScene(m_company_manager->GetCompany("Tesla"));
	CompanySelectionScene* p_companySelectionScene = new CompanySelectionScene(m_company_manager);
	MainScene* p_mainScene = new MainScene(p_inventoryScene, p_companySelectionScene);

public:
	CarSystem();

public:
	void RenderProgram();
	void HandleInput(char input);
	void GoToMain();
};


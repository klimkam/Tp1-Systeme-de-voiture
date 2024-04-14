#pragma once
#include "Scene.h"
#include "MainScene.h"
#include "CompanySelectionScene.h"
#include <vector>
#include <string>
#include <functional>

class CarSystem
{
	Scene* m_currentScene;
	CompanyManager* m_company_manager = new CompanyManager();
	InventoryScene* p_inventoryScene = new InventoryScene(m_company_manager->GetCompanyFromIterator(), m_company_manager);
	CompanySelectionScene* p_companySelectionScene = new CompanySelectionScene(m_company_manager);
	
	MainScene* p_mainScene = new MainScene(p_inventoryScene, p_companySelectionScene);

public:
	CarSystem();

public:
	void RenderProgram();
	void HandleInput(char input);
	void HandleStringInput(std::string input);
	void GoToMain();
};


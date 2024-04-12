#pragma once
#include "Scene.h"
#include "MainScene.h"
#include "CompanySelectionScene.h"
#include "VehicleEditScene.h"
#include <vector>
#include <string>

class CarSystem
{
	Scene* m_currentScene;
	CompanyManager* m_company_manager = new CompanyManager();

	InventoryScene* m_inventoryScene = new InventoryScene(m_company_manager->GetCompany("Tesla"));
	CompanySelectionScene* m_companySelectionScene = new CompanySelectionScene(m_company_manager);
	VehicleEditScene* m_vehicleEditScene = new VehicleEditScene();
	
	MainScene* p_mainScene = new MainScene(m_inventoryScene, m_companySelectionScene);

public:
	CarSystem();

public:
	void RenderProgram();
	void HandleInput(char input);
	void HandleStringInput(std::string input);
	void GoToMain();
};


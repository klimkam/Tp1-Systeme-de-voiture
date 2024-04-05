#include "CompanySelectionScene.h"

CompanySelectionScene::CompanySelectionScene(CompanyManager* companyManager)
{
	m_sceneName = "Company Selection Scene";
	m_informationPrompt += " Press B to go Back.";
	m_informationPrompt += " Type Company name to proceed.";

	m_companyManager = companyManager;
}

void CompanySelectionScene::SetInventoryScene(InventoryScene* inventoryScene)
{
	m_inventoryScene = inventoryScene;
}

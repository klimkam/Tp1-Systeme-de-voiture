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

Scene* CompanySelectionScene::HandleInput(char input)
{
	return nullptr;
}

Scene* CompanySelectionScene::HandleStringInput(std::string input)
{
	Company* tempCompany = m_companyManager->GetCompany(input);
	if (tempCompany) {
		m_inventoryScene->SetCompany(tempCompany);
		return m_inventoryScene;
	}

	return this;
}

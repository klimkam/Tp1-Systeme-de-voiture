#include "MainScene.h"

MainScene::MainScene(InventoryScene* inventoryScene, CompanySelectionScene* companySelectionScene) {
	m_sceneName = "Main Scene";
	m_informationPrompt += " Please write 'I' to go to Inventory Menu. Please write 'C' to go to Company Menu.";
	m_inventoryScene = inventoryScene;
	m_inventoryScene->SetPreviousScene(this);
	m_companyScene = companySelectionScene;
}

Scene* MainScene::HandleInput(char input)
{
	switch (input)
	{
	case'I':
	case'i':
		return m_inventoryScene;
		break;
	case'C':
	case'c':
		return m_companyScene;
		break;
	default:
		return NULL;
		break;
	}
}
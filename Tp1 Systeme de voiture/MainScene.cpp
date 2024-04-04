#include "MainScene.h"

MainScene::MainScene()
{
	m_sceneName = "Main Scene";
	m_informationPrompt += " Please write 'I' to go to Inventory Menu. Please write 'C' to go to Company Menu.";
}

MainScene::MainScene(InventoryScene* inventoryScene)
{
	m_sceneName = "Main Scene";
	m_informationPrompt += " Please write 'I' to go to Inventory Menu. Please write 'C' to go to Company Menu.";
	m_inventoryScene = inventoryScene;
	m_inventoryScene->SetPreviousScene(this);
}

Scene* MainScene::HandleInput(char input)
{
	switch (input)
	{
	case'I':
	case'i':
		return m_inventoryScene;
		break;
	default:
		return NULL;
		break;
	}
}
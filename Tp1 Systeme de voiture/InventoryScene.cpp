#include "InventoryScene.h"

InventoryScene::InventoryScene()
{
	SetUpInfoPromp();
}

InventoryScene::InventoryScene(Scene* previousScene)
{
	SetUpInfoPromp();
	m_peviousScene = previousScene;
}

Scene* InventoryScene::HandleInput(char input)
{
	switch (input)
	{
	case'B':
	case'b':
		return m_peviousScene;
		break;
	default:
		return NULL;
		break;
	}
}

void InventoryScene::SetUpInfoPromp()
{
	m_sceneName = "Inventory System";
	m_informationPrompt += " Press 'A' to show previous vehicle.";
	m_informationPrompt += " Press 'D' to show next vehicle.";
	m_informationPrompt += " Press 'X' to delete this vehicle.";
	m_informationPrompt += " Press 'Z' to modify this vehicle.";
	m_informationPrompt += " Press 'C' to create a new vehicle.";
}

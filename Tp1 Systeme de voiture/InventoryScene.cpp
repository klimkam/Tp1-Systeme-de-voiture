#include "InventoryScene.h"

InventoryScene::InventoryScene()
{
	m_sceneName = "Inventory System";
	m_informationPrompt += " Press 'A' to show previous vehicle.";
	m_informationPrompt += " Press 'D' to show next vehicle.";
	m_informationPrompt += " Press 'X' to delete this vehicle.";
	m_informationPrompt += " Press 'M' to modify this vehicle.";
	m_informationPrompt += " Press 'C' to create a new vehicle.";
}

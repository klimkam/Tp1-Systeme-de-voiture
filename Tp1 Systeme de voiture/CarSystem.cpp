#include "CarSystem.h"

void CarSystem::RenderProgram()
{
	system("cls");
	m_currentScene->DrawScene();
}

CarSystem::CarSystem()
{
	m_currentScene = p_mainScene;
	p_companySelectionScene->SetInventoryScene(p_inventoryScene);
}

void CarSystem::HandleInput(char input)
{
	switch (input)
	{
	case 'm':
	case'M':
		GoToMain();
		break;
	default:
		Scene* tempSceneRef = m_currentScene->HandleInput(input);
		if (tempSceneRef) {
			m_currentScene = tempSceneRef;
		}
		break;
	}
}

void CarSystem::HandleStringInput(std::string input) {
	Scene* tempSceneRef = m_currentScene->HandleStringInput(input);
	if (tempSceneRef) {
		m_currentScene = tempSceneRef;
	}
}

void CarSystem::GoToMain()
{
	m_currentScene = p_mainScene;
}

#include "CarSystem.h"

void CarSystem::RenderProgram()
{
	system("cls");
	m_currentScene->DrawScene();
}

CarSystem::CarSystem()
{
	m_currentScene = p_mainScene;
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

void CarSystem::GoToMain()
{
	m_currentScene = p_mainScene;
}

#include "CarSystem.h"

void CarSystem::RenderProgram()
{
	system("cls");
	m_currentScene->DrawScene();
}

CarSystem::CarSystem()
{
	m_currentScene = m_sceneCollection.at(0);
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
		break;
	}
}

void CarSystem::GoToMain()
{
	m_currentScene = p_mainScene;
}

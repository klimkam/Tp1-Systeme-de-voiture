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

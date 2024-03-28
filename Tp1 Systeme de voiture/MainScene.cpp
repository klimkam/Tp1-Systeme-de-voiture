#include "MainScene.h"

MainScene::MainScene()
{
	m_sceneName = "Main Scene";
	m_informationPrompt += " Please write 'I' to go to Inventory Menu. Please write 'C' to go to Company Menu.";
}

Scene* MainScene::HandleInput()
{
}
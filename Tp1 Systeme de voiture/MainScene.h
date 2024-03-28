#pragma once
#include "Scene.h"
class MainScene : public Scene
{
	Scene* m_inventoryScene;
	Scene* m_companyScene;
public:
	MainScene();
	Scene* HandleInput();
};


#pragma once
#include "Scene.h"
class InventoryScene : public Scene
{
	Scene* m_peviousScene;
public:
	InventoryScene();
	InventoryScene(Scene* previousScene);
	Scene* HandleInput(char input) override;
private:
	void SetUpInfoPromp();
};


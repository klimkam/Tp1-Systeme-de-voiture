#pragma once
#include "Scene.h"
#include "CompanyManager.h"
#include "InventoryScene.h"


class CompanySelectionScene : public Scene
{
	CompanyManager* m_companyManager;
	Scene* m_previousScene;
	InventoryScene* m_inventoryScene;

public:
	CompanySelectionScene(CompanyManager* companyManager);
	void SetInventoryScene(InventoryScene* inventoryScene);

	Scene* HandleInput(char input) override;
	Scene* HandleStringInput(std::string input) override;

	void SetPreviousScene(Scene* previousScene);

private:
	void DrawMainPage(int xPos, int yPos, int startXPos, bool& retFlag) override;
	const void PrintVehicleInformation(int xPos, int startXPos, int& currentLine, int yPos, std::string& companyInformation, bool& retFlag);
};


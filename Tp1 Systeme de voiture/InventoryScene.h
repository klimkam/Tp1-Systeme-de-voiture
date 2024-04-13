#pragma once
#include "Scene.h"
#include "Company.h"
#include "Enums.h"
#include "Car.h"
#include "CompanyManager.h"

#include <vector>

class InventoryScene : public Scene
{
	Scene* m_previousScene;
	CompanyManager m_company_manager = CompanyManager();

	Company* m_company;

public:
	InventoryScene();
	InventoryScene(Scene* previousScene);
	InventoryScene(Company* company);
	Scene* HandleInput(char input) override;

	void SetPreviousScene(Scene* previousScene);
	void SetCompany(Company* company);

private:
	void SetUpInfoPromp();
	void DrawMainPage(int xPos, int yPos, int startXPos, bool& retFlag) override;

	const void DrawASCIIDrawing(int yPos, int xPos, int startXPos, int currentLine, bool& retFlag, std::vector<std::vector <char>> asciiDrawing);
	
	const void PrintVehicleInformation(int xPos, int startXPos, int& currentLine, int yPos, std::string& companyInformation, bool& retFlag);
};


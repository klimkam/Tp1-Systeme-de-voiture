#include "InventoryScene.h"
#include <iostream>
#include<string>
#include "Maps.h"
#include "CarSystem.h"

InventoryScene::InventoryScene()
{
	SetUpInfoPromp();
}

InventoryScene::InventoryScene(Scene* previousScene)
{
	SetUpInfoPromp();
	m_previousScene = previousScene;
}

InventoryScene::InventoryScene(Scene* thisScene, Scene* previousScene)
{
	SetUpInfoPromp();
	m_thisScene = thisScene;
	m_previousScene = previousScene;
}

Scene* InventoryScene::HandleInput(char input)
{
	switch (input)
	{
	case'B':
	case'b':
		return m_previousScene;
		break;
	case'D':
	case 'd':
		m_company->GetNextVehicle();
		m_thisScene->DrawScene();
		//extern CarSystem* p_carSystem;
		//p_carSystem->RenderProgram();
		break;
	default:
		return NULL;
		break;
	}
}

void InventoryScene::SetUpInfoPromp()
{
	m_sceneName = "Inventory System";
	m_informationPrompt += " Press 'A' to show previous vehicle.";
	m_informationPrompt += " Press 'D' to show next vehicle.";
	m_informationPrompt += " Press 'X' to delete this vehicle.";
	m_informationPrompt += " Press 'Z' to modify this vehicle.";
	m_informationPrompt += " Press 'C' to create a new vehicle.";
}

void InventoryScene::DrawMainPage(int xPos, int yPos, bool& retFlag)
{
	retFlag = true;

	int startXPos = 8;
	int currentLine = 0;

	std::string informationToShow[5] = {
		{"The vehicle Company: " + m_company->GetCompanyName()},
		{"The vehicle ID: " + std::to_string(m_company->GetVehicle()->GetVehicleId())},
		{"The vehicle Color: " + M_ColorToNames[m_company->GetVehicle()->GetColor()]},
		{"The vehicle Price: " + std::to_string(m_company->GetVehicle()->GetPrice())},
		{m_company->GetVehicle()->GetIsSold() ? "The Vehicle Is Sold" : "The Vehicle Is Not Sold"},
	};

	for (int i = 0; i < size(informationToShow); i++) {
		bool retRetFlag;
		PrintVehicleInformation(xPos, startXPos, currentLine, yPos, informationToShow[i], retRetFlag);
		if (retRetFlag) return;
	}

	if (yPos == m_sceneHeight / 2) {
		DrawVerticalBorder();
		return;
	}

	retFlag = false;
}

void InventoryScene::PrintVehicleInformation(int xPos, int startXPos, int& currentLine, int yPos, std::string& companyInformation, bool& retFlag)
{
	retFlag = true;
	if (xPos == startXPos + currentLine && yPos == 1) {
		std::cout << companyInformation;
		return;
	}
	if (xPos == startXPos + currentLine && yPos < 1 + companyInformation.size()) {
		return;
	}
	++currentLine;
	retFlag = false;
}

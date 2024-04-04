#include "InventoryScene.h"
#include <iostream>
#include <string>
#include <vector>
#include "Maps.h"
#include "CarSystem.h"
#include "ASCIIDrawings.h"

InventoryScene::InventoryScene()
{
	SetUpInfoPromp();
}

InventoryScene::InventoryScene(Scene* previousScene)
{
	SetUpInfoPromp();
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
		return this;
		break;
	case'A':
	case 'a':
		m_company->GetPreviousVehicle();
		return this;
		break;
	default:
		return NULL;
		break;
	}
}

void InventoryScene::SetPreviousScene(Scene* previousScene)
{
	m_previousScene = previousScene;
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
	bool retRetFlag;

	std::string informationToShow[5] = {
		{"The vehicle Company: " + m_company->GetCompanyName()},
		{"The vehicle ID: " + std::to_string(m_company->GetVehicle()->GetVehicleId())},
		{"The vehicle Color: " + M_ColorToNames[m_company->GetVehicle()->GetColor()]},
		{"The vehicle Price: " + std::to_string(m_company->GetVehicle()->GetPrice())},
		{m_company->GetVehicle()->GetIsSold() ? "The Vehicle Is Sold" : "The Vehicle Is Not Sold"},
	};

	for (int i = 0; i < size(informationToShow); i++) {
		PrintVehicleInformation(xPos, startXPos, currentLine, yPos, informationToShow[i], retRetFlag);
		if (retRetFlag) return;
	}

	if (yPos == m_sceneWidth / 2) {
		DrawVerticalBorder();
		return;
	}

	if (m_company->GetVehicle()->GetVehicleType() == E_VehicleType::Car) {
		DrawASCIIDrawing(yPos, xPos, startXPos, currentLine, retRetFlag, ASCII_CarDrawing);
		if (retRetFlag) return;
	}

	if (m_company->GetVehicle()->GetVehicleType() == E_VehicleType::Airplain) {
		DrawASCIIDrawing(yPos, xPos, startXPos, currentLine, retRetFlag, ASCII_AirplainDrawing);
		if (retRetFlag) return;
	}

	retFlag = false;
}

const void InventoryScene::DrawASCIIDrawing(int yPos, int xPos, int startXPos, int currentLine, bool& retFlag, std::vector<std::vector <char>> asciiDrawing)
{
	retFlag = true;
	std::vector<std::vector <char>> carDrawing = asciiDrawing;
	int yDrawStartPosition = (m_sceneWidth / 2) + 1;

	if (yPos >= yDrawStartPosition && (xPos - startXPos) < carDrawing.size() && (yPos - yDrawStartPosition) < carDrawing.at(currentLine - 1).size()) {
		std::cout << carDrawing.at(xPos - startXPos).at(yPos - yDrawStartPosition);
		return;
	}
	retFlag = false;
}

const void InventoryScene::PrintVehicleInformation(int xPos, int startXPos, int& currentLine, int yPos, std::string& companyInformation, bool& retFlag)
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

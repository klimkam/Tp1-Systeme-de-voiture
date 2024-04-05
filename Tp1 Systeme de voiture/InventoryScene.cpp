#include "InventoryScene.h"
#include <iostream>
#include <string>
#include <vector>
#include "CarSystem.h"
#include "ASCIIDrawings.h"
#include "Vehicle.h"

InventoryScene::InventoryScene()
{
	SetUpInfoPromp();
}

InventoryScene::InventoryScene(Scene* previousScene)
{
	SetUpInfoPromp();
	m_previousScene = previousScene;
}

InventoryScene::InventoryScene(Company* company)
{
	SetUpInfoPromp();
	m_company = company;
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
	case'X':
	case'x':
		m_company->RemoveVehicle();
		return this;
		break;
	default:
		return this;
		break;
	}
}

void InventoryScene::SetPreviousScene(Scene* previousScene)
{
	m_previousScene = previousScene;
}

void InventoryScene::SetCompany(Company* company)
{
	m_company = company;
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

void InventoryScene::DrawMainPage(int xPos, int yPos, int startXPos, bool& retFlag)
{
	retFlag = true;

	int currentLine = 0;
	bool retRetFlag;

	std::vector<std::string> informationToShow = m_company->GetInformation();

	int middleXPositionForInformation = (m_sceneHeight - startXPos - informationToShow.size()) / 2 + startXPos - 1;

	for (int i = 0; i < size(informationToShow); i++) {
		PrintVehicleInformation(xPos, middleXPositionForInformation, currentLine, yPos, informationToShow.at(i), retRetFlag);
		if (retRetFlag) return;
	}

	if (yPos == m_sceneWidth / 2) {
		DrawVerticalBorder();
		return;
	}

	if (m_company->GetVehicle()->GetVehicleType() == E_VehicleType::Car) {
		int middleXPositionForDrawing = (m_sceneHeight - startXPos - size(ASCII_CarDrawing)) / 2 + startXPos - 1;
		DrawASCIIDrawing(yPos, xPos, middleXPositionForDrawing, currentLine, retRetFlag, ASCII_CarDrawing);
		if (retRetFlag) return;
	}

	if (m_company->GetVehicle()->GetVehicleType() == E_VehicleType::Airplain) {
		int middleXPositionForDrawing = (m_sceneHeight - startXPos - size(ASCII_AirplainDrawing)) / 2 + startXPos - 1;
		DrawASCIIDrawing(yPos, xPos, middleXPositionForDrawing, currentLine, retRetFlag, ASCII_AirplainDrawing);
		if (retRetFlag) return;
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

const void InventoryScene::DrawASCIIDrawing(int yPos, int xPos, int startXPos, int currentLine, bool& retFlag, std::vector<std::vector <char>> asciiDrawing)
{
	retFlag = true;
	std::vector<std::vector <char>> carDrawing = asciiDrawing;
	int yDrawStartPosition = ((m_sceneWidth) * 3 / 4) + 1 - (carDrawing.at(0).size() / 2);

	if (yPos >= yDrawStartPosition && (xPos - startXPos) < carDrawing.size() && (yPos - yDrawStartPosition) < carDrawing.at(currentLine - 1).size()) {
		std::cout << carDrawing.at(xPos - startXPos).at(yPos - yDrawStartPosition);
		return;
	}
	retFlag = false;
}


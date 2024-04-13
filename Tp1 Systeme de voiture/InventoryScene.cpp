#include "InventoryScene.h"
#include <iostream>
#include <algorithm>
#include <cctype>
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
	case'Z':
	case'z':
		EditVehicle();
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

void InventoryScene::EditPrice()
{
	bool isTheValueValid = false;

	while (!isTheValueValid) {
		std::cout << "Enter the new price: " << std::endl;
		std::string newPrice;
		std::cin >> newPrice;

		if (IsNumber(newPrice)) {
			isTheValueValid = IsNumber(newPrice);
			m_company->GetVehicle()->SetPrice(std::stoi(newPrice));
		}
	}
}

void InventoryScene::EditColor()
{
	bool isTheValueValid = false;
	
	while (!isTheValueValid) {
		std::cout << "Enter the new Color (Red, Blue, Green, Violet, Pink, Orange): " << std::endl;
		std::string newColor;
		std::cin >> newColor;

		//Sets the response string to lower case, so it lowers the amount of validations needed
		std::transform(newColor.begin(), newColor.end(), newColor.begin(), [](unsigned char c) { return std::tolower(c); });

		if (M_NamesToColors.count(newColor)) {
			m_company->GetVehicle()->SetColor(M_NamesToColors[newColor]);
			isTheValueValid = true;
		}
	}
}

void InventoryScene::EditMaxCapacity()
{
	bool isTheValueValid = false;

	while (!isTheValueValid) {
		std::cout << "Enter the new Max Capacity: " << std::endl;
		std::string newMaxCapacity;
		std::cin >> newMaxCapacity;

		if (IsNumber(newMaxCapacity)) {
			isTheValueValid = IsNumber(newMaxCapacity);
			Airplane* currentAirplane = (Airplane*)(m_company->GetVehicle());
			currentAirplane->SetMaxCapacity(std::stoi(newMaxCapacity));
		}
	}
}

void InventoryScene::EditLastInspectionDate()
{
	std::cout << "Enter the new Last Inspection Date: " << std::endl;
	std::string newLastInspectionDate;
	std::cin >> newLastInspectionDate;
	Airplane* currentAirplane = (Airplane*)(m_company->GetVehicle());
	currentAirplane->SetLastInspectionDate(newLastInspectionDate);
}

bool InventoryScene::IsNumber(const std::string& string)
{
	return !string.empty() && std::find_if(string.begin(),
		string.end(), [](unsigned char c) { return !std::isdigit(c); }) == string.end();
}

void InventoryScene::EditIsSold()
{
	bool isTheValueValid = false;
	while (isTheValueValid) {
		std::cout << "Enter the new Is Sold value (true, false): " << std::endl;
		std::string newIsSold;
		std::cin >> newIsSold;

		std::transform(newIsSold.begin(), newIsSold.end(), newIsSold.begin(), [](unsigned char c) { return std::tolower(c); });

		if (newIsSold == "true") {
			m_company->GetVehicle()->SetIsSold(true);
			isTheValueValid = true;
			continue;
		}

		if (newIsSold == "false") {
			m_company->GetVehicle()->SetIsSold(false);
			isTheValueValid = true;
			continue;
		}
	}	
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

void InventoryScene::EditVehicle()
{
	std::cout << "What field do you want to change? (price, color," 
		<< ((m_company->GetVehicle()->GetVehicleType()==E_VehicleType::Airplain) ? " max capacity, last inspection date," : "" )
		<< " is sold): "
		<< std::endl;
	std::string response;
	std::cin.ignore();
	std::getline(std::cin, response);
	
	//Sets the response string to lower case, so it lowers the amount of validations needed
	std::transform(response.begin(), response.end(), response.begin(), [](unsigned char c) { return std::tolower(c);});

	if (response.find("price") != std::string::npos) {
		EditPrice();
		return;
	}

	if (response.find("color") != std::string::npos) {
		EditColor();
		return;
	}

	if (response.find("max capacity") != std::string::npos && (m_company->GetVehicle()->GetVehicleType() == E_VehicleType::Airplain)) {
		EditMaxCapacity();
		return;
	}

	if (response.find("last inspection date") != std::string::npos && (m_company->GetVehicle()->GetVehicleType() == E_VehicleType::Airplain)) {
		EditLastInspectionDate();
		return;
	}

	if (response.find("is sold") != std::string::npos) {
		EditIsSold();
		return;
	}
}


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
InventoryScene::InventoryScene(Company* company, CompanyManager* companyManager) {
	SetUpInfoPromp();
	m_company = company;
	m_companyManager = companyManager;
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
		if (m_company->IsLastVehicle() && m_isGettingAllCompanies) { GetNextCompany(); }
		m_company->GetNextVehicle();
		return this;
		break;
	case'A':
	case 'a':
		if (m_company->IsFirstVehicle() && m_isGettingAllCompanies) { GetPreviousCompany(); }
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
	case'C':
	case'c':
		CreateNewVehicle();
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

long InventoryScene::AskPrice()
{
	bool isTheValueValid = false;

	while (!isTheValueValid) {
		std::cout << "Enter the new price: " << std::endl;
		std::string newPrice;
		std::cin >> newPrice;

		if (IsNumber(newPrice)) {
			isTheValueValid = IsNumber(newPrice);
			return(std::stol(newPrice));
		}
	}
}

E_Color InventoryScene::AskColor()
{
	bool isTheValueValid = false;
	
	while (!isTheValueValid) {
		std::cout << "Enter the new Color (Red, Blue, Green, Violet, Pink, Orange): " << std::endl;
		std::string newColor;
		std::cin >> newColor;

		//Sets the response string to lower case, so it lowers the amount of validations needed
		std::transform(newColor.begin(), newColor.end(), newColor.begin(), [](unsigned char c) { return std::tolower(c); });

		if (M_NamesToColors.count(newColor)) {
			return (M_NamesToColors[newColor]);
		}
	}
}

int InventoryScene::AskMaxCapacity()
{
	bool isTheValueValid = false;

	while (!isTheValueValid) {
		std::cout << "Enter the new Max Capacity: " << std::endl;
		std::string newMaxCapacity;
		std::cin >> newMaxCapacity;

		if (IsNumber(newMaxCapacity)) {
			isTheValueValid = IsNumber(newMaxCapacity);
			return std::stoi(newMaxCapacity);
		}
	}
}

std::string InventoryScene::AskLastInspectionDate()
{
	std::cout << "Enter the new Last Inspection Date: " << std::endl;
	std::string newLastInspectionDate;
	std::cin >> newLastInspectionDate;

	return newLastInspectionDate;
}

bool InventoryScene::IsNumber(const std::string& string)
{
	return !string.empty() && std::find_if(string.begin(),
		string.end(), [](unsigned char c) { return !std::isdigit(c); }) == string.end();
}

void InventoryScene::ShowAllCompanies()
{
	m_isGettingAllCompanies = true;
}

void InventoryScene::ShowOneCompany() {
	m_isGettingAllCompanies = false;
}

//I would like to create a UI for this if I have time
//And change the current displayed item to the new one
void InventoryScene::CreateNewVehicle()
{
	Vehicle* newVehicle;

	switch (AskVehicleType()) {
	case(E_VehicleType::Car): {
		newVehicle = new Car();
		newVehicle->SetPrice(AskPrice());
		newVehicle->SetColor(AskColor());
		newVehicle->SetIsSold(AskIsSold());
		break;
	}
	case(E_VehicleType::Airplain): {
		newVehicle = new Airplane();
		Airplane* newAirplane = (Airplane*)(newVehicle);
		newAirplane->SetPrice(AskPrice());
		newAirplane->SetColor(AskColor());
		newAirplane->SetIsSold(AskIsSold());
		newAirplane->SetLastInspectionDate(AskLastInspectionDate());
		newAirplane->SetMaxCapacity(AskMaxCapacity());
		break;
	}
	default:
		return;
	}
	m_company->AddNewVehicle(newVehicle);
}

E_VehicleType InventoryScene::AskVehicleType() {
	while (true) {
		std::cout << "Enter the Vehicle Type (Airplane, Car): " << std::endl;
		std::string newVehicleType;
		std::cin >> newVehicleType;

		std::transform(newVehicleType.begin(), newVehicleType.end(), newVehicleType.begin(), [](unsigned char c) { return std::tolower(c); });

		if (M_NamesToVehicleType.count(newVehicleType)) {
			return (M_NamesToVehicleType[newVehicleType]);
		}
	}
}

bool InventoryScene::AskIsSold()
{
	while (true) {
		std::cout << "Enter the new Is Sold value (true, false): " << std::endl;
		std::string newIsSold;
		std::cin >> newIsSold;

		std::transform(newIsSold.begin(), newIsSold.end(), newIsSold.begin(), [](unsigned char c) { return std::tolower(c); });

		if (newIsSold == "true") {
			m_company->GetVehicle()->SetIsSold(true);
			return true;
		}

		if (newIsSold == "false") {
			return false;
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

//That's an overcomplicated method and should be divided by small methods, but I run low on time, so meh
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
		m_company->GetVehicle()->SetPrice(AskPrice());
		return;
	}

	if (response.find("color") != std::string::npos) {
		m_company->GetVehicle()->SetColor(AskColor());
		return;
	}

	if (response.find("max capacity") != std::string::npos && (m_company->GetVehicle()->GetVehicleType() == E_VehicleType::Airplain)) {
		Airplane* currentAirplane = (Airplane*)(m_company->GetVehicle());
		currentAirplane->SetMaxCapacity(AskMaxCapacity());
		return;
	}

	if (response.find("last inspection date") != std::string::npos && (m_company->GetVehicle()->GetVehicleType() == E_VehicleType::Airplain)) {
		Airplane* currentAirplane = (Airplane*)(m_company->GetVehicle());
		currentAirplane->SetLastInspectionDate(AskLastInspectionDate());
		return;
	}

	if (response.find("is sold") != std::string::npos) {
		m_company->GetVehicle()->SetIsSold(AskIsSold());
		return;
	}
}

void InventoryScene::GetNextCompany() {
	m_company = m_companyManager->GetNextCompanyFromIterator();
}
void InventoryScene::GetPreviousCompany() {
	m_company = m_companyManager->GetPreviousCompanyFromIterator();
}
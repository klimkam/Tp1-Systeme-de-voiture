#include "CompanySelectionScene.h"
#include <iostream>

CompanySelectionScene::CompanySelectionScene(CompanyManager* companyManager)
{
	m_sceneName = "Company Selection Scene";
	m_informationPrompt += " Press B to go Back.";
	m_informationPrompt += " Type Company name to proceed.";

	m_companyManager = companyManager;
}

void CompanySelectionScene::SetInventoryScene(InventoryScene* inventoryScene)
{
	m_inventoryScene = inventoryScene;
	m_inventoryScene->SetPreviousScene(this);
}

Scene* CompanySelectionScene::HandleInput(char input)
{
	switch (input) {
	case('B'):
	case('b'):
		return m_previousScene;
	default:
		return this;
	}
}

Scene* CompanySelectionScene::HandleStringInput(std::string input)
{
	Company* tempCompany = m_companyManager->GetCompany(input);
	if (tempCompany) {
		m_inventoryScene->SetCompany(tempCompany);
		return m_inventoryScene;
	}

	return this;
}

void CompanySelectionScene::SetPreviousScene(Scene* previousScene)
{
	m_previousScene = previousScene;
}

void CompanySelectionScene::DrawMainPage(int xPos, int yPos, int startXPos, bool& retFlag)
{
	retFlag = true;

	int currentLine = 0;
	bool retRetFlag;

	std::vector<std::string> informationToShow = m_companyManager->GetAllCompanyNames();

	int middleXPositionForInformation = (m_sceneHeight - startXPos - informationToShow.size()) / 2 + startXPos - 1;

	for (int i = 0; i < size(informationToShow); i++) {
		PrintVehicleInformation(xPos, middleXPositionForInformation, currentLine, yPos, informationToShow.at(i), retRetFlag);
		if (retRetFlag) return;
	}

	retFlag = false;
}

const void CompanySelectionScene::PrintVehicleInformation(int xPos, int startXPos, int& currentLine, int yPos, std::string& companyInformation, bool& retFlag)
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

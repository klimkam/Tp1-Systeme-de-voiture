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
	return nullptr;
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

void CompanySelectionScene::DrawMainPage(int xPos, int yPos, int startXPos, bool& retFlag)
{
	retFlag = true;

	int currentLine = 0;

	std::vector<std::string> informationToShow = m_companyManager->GetAllCompanyNames();

	int middleXPositionForInformation = (m_sceneHeight - startXPos - informationToShow.size()) / 2 + startXPos - 1;
	bool retRetFlag;
	
	for (int i = 0; i < informationToShow.size(); i++) {
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

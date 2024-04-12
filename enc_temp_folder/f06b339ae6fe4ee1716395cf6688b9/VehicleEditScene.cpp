#include "VehicleEditScene.h"
#include <iostream>

void VehicleEditScene::SetLastScene(Scene* lastScene)
{
	m_lastScene = lastScene;
}

void VehicleEditScene::SetCurrentVahicle(Vehicle* currentVehicle)
{
	m_currentVehicle = currentVehicle;
}

Scene* VehicleEditScene::HandleInput(char input)
{
	switch (input) {
	case 'B':
	case'b':
		return m_lastScene;
		break;
	default:
		return this;
		break;
	}
}


Scene* VehicleEditScene::HandleStringInput(std::string input)
{
	return this;
}

void VehicleEditScene::DrawMainPage(int xPos, int yPos, int startXPos, bool& retFlag)
{
	int currentLine = 0;
	bool retRetFlag = false;

	std::vector<std::string> informationToShow = m_currentVehicle->GetInformation();

	int middleXPositionForInformation = (m_sceneHeight - startXPos - informationToShow.size()) / 2 + startXPos - 1;

	for (int i = 0; i < size(informationToShow); i++) {
		PrintVehicleInformation(xPos, currentLine, middleXPositionForInformation, yPos, informationToShow.at(i), retRetFlag);
		if (retRetFlag) return;
	}

	retFlag = false;
}

const void VehicleEditScene::PrintVehicleInformation(int xPos, int startXPos, int& currentLine, int yPos, std::string& vehicleInformation, bool& retFlag)
{
	retFlag = true;
	if (xPos == startXPos + currentLine && yPos == 1) {
		std::cout << vehicleInformation;
		return;
	}
	if (xPos == startXPos + currentLine && yPos < 1+ vehicleInformation.size()) {
		return;
	}
	++currentLine;
	retFlag = false;
}

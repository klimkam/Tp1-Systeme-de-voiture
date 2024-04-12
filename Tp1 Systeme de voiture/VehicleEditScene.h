#pragma once
#include "Scene.h"
#include "Vehicle.h"

class VehicleEditScene : public Scene
{
	Vehicle* m_currentVehicle;
	Scene* m_lastScene;

public:
	Scene* HandleInput(char input) override;
	Scene* HandleStringInput(std::string input) override;
	void SetLastScene(Scene* lastScene);
	void SetCurrentVahicle(Vehicle* currentVehicle);

private:
	void DrawMainPage(int xPos, int yPos, int startXPos, bool& retFlag) override;
	const void PrintVehicleInformation(int xPos, int startXPos, int& currentLine, int yPos, std::string& companyInformation, bool& retFlag);
};


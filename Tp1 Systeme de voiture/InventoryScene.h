#pragma once
#include "Scene.h"
#include "Company.h"
#include "Enums.h"
#include "Car.h"

#include <vector>

class InventoryScene : public Scene
{
	Scene* m_previousScene;
	std::vector<E_VehicleType> m_companyAvailableVehicles = {E_VehicleType::Car, E_VehicleType::Airplain};
	std::list<Vehicle*> m_vehicleCollection = { new Car(), new Car() , new Car() , new Car() , new Car() , new Car() };
	Company* m_company = new Company("Tesla", m_companyAvailableVehicles, m_vehicleCollection);

public:
	InventoryScene();
	InventoryScene(Scene* previousScene);
	Scene* HandleInput(char input) override;
	void SetPreviousScene(Scene* previousScene);

private:
	void SetUpInfoPromp();
	void DrawMainPage(int xPos, int yPos, bool& retFlag) override;

	const void DrawASCIIDrawing(int yPos, int xPos, int startXPos, int currentLine, bool& retFlag, std::vector<std::vector <char>> asciiDrawing);
	
	const void PrintVehicleInformation(int xPos, int startXPos, int& currentLine, int yPos, std::string& companyInformation, bool& retFlag);
};


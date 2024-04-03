#pragma once
#include "Scene.h"
#include "Company.h"
#include "Enums.h"

#include <vector>

class InventoryScene : public Scene
{
	Scene* m_previousScene;
	Scene* m_thisScene;
	std::vector<E_VehicleType> m_companyAvailableVehicles = {E_VehicleType::Car};
	std::list<Vehicle*> m_vehicleCollection = { new Vehicle(), new Vehicle() , new Vehicle() , new Vehicle() , new Vehicle() , new Vehicle() };
	Company* m_company = new Company("Toyota", m_companyAvailableVehicles, m_vehicleCollection);

public:
	InventoryScene();
	InventoryScene(Scene* previousScene);
	InventoryScene(Scene* thisScene, Scene* previousScene);
	Scene* HandleInput(char input) override;

private:
	void SetUpInfoPromp();
	void DrawMainPage(int xPos, int yPos, bool& retFlag) override;
	void PrintVehicleInformation(int xPos, int startXPos, int& currentLine, int yPos, std::string& companyInformation, bool& retFlag);
};


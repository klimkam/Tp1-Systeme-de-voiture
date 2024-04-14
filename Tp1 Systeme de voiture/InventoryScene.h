#pragma once
#include "Scene.h"
#include "Company.h"
#include "Enums.h"
#include "Car.h"
#include "CompanyManager.h"
#include "Enums.h"

#include <functional>
#include <vector>

class InventoryScene : public Scene
{
	Scene* m_previousScene;
	CompanyManager m_company_manager = CompanyManager();
	Company* m_company;

	CompanyManager* m_companyManager;
	bool m_isGettingAllCompanies;

	//It's better to move this map into Maps.h component, but it causes an error 2005 when I apply Maps.h in multiple places
	class std::map <std::string, E_Color> M_NamesToColors = {
	{"red" ,E_Color::Red},
	{"blue" ,E_Color::Blue},
	{"green" ,E_Color::Green},
	{"violet" ,E_Color::Violet},
	{"pink" ,E_Color::Pink},
	{"orange" ,E_Color::Orange},
	{"count" ,E_Color::Count},
	};

	//That's a bad idea tho, it has to be automatically created using values in Enums.h, but I run low on time, so meh
	class std::map <std::string, E_VehicleType> M_NamesToVehicleType = {
	{"car", E_VehicleType::Car},
	{"airplane", E_VehicleType::Airplain},
	};

public:
	InventoryScene();
	InventoryScene(Scene* previousScene);
	InventoryScene(Company* company);
	InventoryScene(Company* company, CompanyManager* companyManager);
	Scene* HandleInput(char input) override;

	void SetPreviousScene(Scene* previousScene);
	void SetCompany(Company* company);

	void ShowAllCompanies();
	void ShowOneCompany();

private:
	void SetUpInfoPromp();
	void DrawMainPage(int xPos, int yPos, int startXPos, bool& retFlag) override;

	void EditVehicle();
	//price, color, max capacity, last inspection date, is sold
	long AskPrice();
	E_Color AskColor();
	int AskMaxCapacity();
	std::string AskLastInspectionDate();
	bool AskIsSold();
	E_VehicleType AskVehicleType();

	void CreateNewVehicle();

	bool IsNumber(const std::string& string);

	const void DrawASCIIDrawing(int yPos, int xPos, int startXPos, int currentLine, bool& retFlag, std::vector<std::vector <char>> asciiDrawing);
	const void PrintVehicleInformation(int xPos, int startXPos, int& currentLine, int yPos, std::string& companyInformation, bool& retFlag);

	void GetNextCompany();
	void GetPreviousCompany();
};


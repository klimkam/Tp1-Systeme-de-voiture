#pragma once
#include "Scene.h"
#include "Company.h"
#include "Enums.h"
#include "Car.h"
#include "CompanyManager.h"

#include <vector>

class InventoryScene : public Scene
{
	Scene* m_previousScene;
	CompanyManager m_company_manager = CompanyManager();
	Company* m_company;

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

public:
	InventoryScene();
	InventoryScene(Scene* previousScene);
	InventoryScene(Company* company);
	Scene* HandleInput(char input) override;

	void SetPreviousScene(Scene* previousScene);
	void SetCompany(Company* company);

private:
	void SetUpInfoPromp();
	void DrawMainPage(int xPos, int yPos, int startXPos, bool& retFlag) override;
	void EditVehicle();

	//price, color, max capacity, last inspection date, is sold
	void EditPrice();
	void EditColor();
	void EditMaxCapacity();
	void EditLastInspectionDate();
	void EditIsSold();

	bool IsNumber(const std::string& string);

	const void DrawASCIIDrawing(int yPos, int xPos, int startXPos, int currentLine, bool& retFlag, std::vector<std::vector <char>> asciiDrawing);
	const void PrintVehicleInformation(int xPos, int startXPos, int& currentLine, int yPos, std::string& companyInformation, bool& retFlag);
};


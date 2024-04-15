#pragma once
#include<vector>
#include<list>
#include<map>
#include<string>

#include "Enums.h"
#include "Vehicle.h"
#include "Car.h"
#include "Airplane.h"
#include "Company.h"

class CompanyManager
{
	std::map <std::string, Company*> M_Companies;
	std::map <std::string, Company*>::iterator I_M_Companies;

	std::vector<E_VehicleType> m_allAvailableVehicles = { E_VehicleType::Car, E_VehicleType::Airplain };
	std::vector<E_VehicleType> m_CarsAvailable = { E_VehicleType::Car};
	std::vector<E_VehicleType> m_AirplanesAvailable = { E_VehicleType::Airplain };

	//For loading data from file, I can parse data into this object before sending it to M_Companies
	std::map<std::string, std::list<Vehicle*>> M_vehicles = {
		{"Tesla", { new Car(), new Airplane() , new Car() , new Airplane() , new Car() , new Airplane() }}, 
		{"Chevrolet", { new Car(), new Car() , new Car() , new Car() , new Car() , new Car() }},
		{"Toyota", { new Car(), new Car() , new Car() , new Car() , new Car() , new Car() }},
		{"BMW", { new Car(), new Car() , new Car() , new Car() , new Car() , new Car() }},
		{"Volkswagen", { new Car(), new Car() , new Car() , new Car() , new Car() , new Car() }},
		{"Boeing", { new Airplane(), new Airplane() , new Airplane() , new Airplane() , new Airplane() , new Airplane() }},
		{"Airbus", { new Airplane(), new Airplane() , new Airplane() , new Airplane() , new Airplane() , new Airplane() }},
		{"Bombardier", { new Airplane(), new Airplane() , new Airplane() , new Airplane() , new Airplane() , new Airplane() }},
	};

	class std::map <E_VehicleType, std::string> M_VehicleTypeToNames = {
		{E_VehicleType::Car, "Car"},
		{E_VehicleType::Airplain, "Airplain"},
	};

	class std::map <std::string, E_VehicleType> M_NamesToVehicleType = {
		{"Car", E_VehicleType::Car},
		{"Airplain", E_VehicleType::Airplain},
	};

	class std::map <E_Color, std::string> M_ColorToNames = {
		{E_Color::Red, "Red"},
		{E_Color::Blue, "Blue"},
		{E_Color::Green, "Green"},
		{E_Color::Violet, "Violet"},
		{E_Color::Pink, "Pink"},
		{E_Color::Orange, "Orange"},
		{E_Color::Count, "Count"},
	};
	
	class std::map <std::string, E_Color> M_NamesToColor = {
		{"Red", E_Color::Red},
		{"Blue", E_Color::Blue},
		{"Green", E_Color::Green},
		{"Violet", E_Color::Violet},
		{"Pink", E_Color::Pink},
		{"Orange", E_Color::Orange},
		{"Count", E_Color::Count},
	};


public:
	CompanyManager();
	Company* GetCompanyFromName(std::string companyName);
	Company* GetCompanyFromIterator();
	Company* GetNextCompanyFromIterator();
	Company* GetPreviousCompanyFromIterator();
	std::vector<std::string> GetAllCompanyNames();

	void SaveProgram();
	bool LoadProgram();

private:
	std::string GetDataFromFileString(std::string fileLine);
};


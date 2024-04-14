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
	//To store data in file, I can write down this file in JSON format
	/*{[
	* {
		company_name: "CompanyName",
		available_vehicles: [
		{
			vehicle_type: VehicleType,
			vehicle_color: VehicleColor,
			vehicle_price: VehiclePrice
		}
		]
	}
	]}
	But I have no idea how to do it right now, so meh
	*/
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


public:
	CompanyManager();
	Company* GetCompanyFromName(std::string companyName);
	Company* GetCompanyFromIterator();
	Company* GetNextCompanyFromIterator();
	Company* GetPreviousCompanyFromIterator();
	std::vector<std::string> GetAllCompanyNames();
};


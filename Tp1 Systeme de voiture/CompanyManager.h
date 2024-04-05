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

	std::vector<E_VehicleType> m_Tesla_availableVehicles = { E_VehicleType::Car, E_VehicleType::Airplain };
	std::list<Vehicle*> m_Tesla_vehicleCollection = { new Car(), new Airplane() , new Car() , new Airplane() , new Car() , new Airplane() };



public:
	CompanyManager();
	Company* GetCompany(std::string companyName);
};


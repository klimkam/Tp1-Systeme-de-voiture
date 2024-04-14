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

	std::vector<E_VehicleType> m_allAvailableVehicles = { E_VehicleType::Car, E_VehicleType::Airplain };
	std::vector<E_VehicleType> m_CarsAvailable = { E_VehicleType::Car};
	std::vector<E_VehicleType> m_AirplanesAvailable = { E_VehicleType::Airplain };

	//{ "Tesla", new Company("Tesla", m_allAvailableVehicles, m_Tesla_vehicleCollection) },
	//{ "Chevrolet", new Company("Chevrolet", m_CarsAvailable, m_Tesla_vehicleCollection) },
	//{ "Toyota", new Company("Toyota", m_CarsAvailable, m_Tesla_vehicleCollection) },
	//{ "BMW", new Company("BMW", m_CarsAvailable, m_Tesla_vehicleCollection) },
	//{ "Volkswagen", new Company("Volkswagen", m_CarsAvailable, m_Tesla_vehicleCollection) },
	//{ "Boeing", new Company("Boeing", m_AirplanesAvailable, m_Tesla_vehicleCollection) },
	//{ "Airbus", new Company("Airbus", m_AirplanesAvailable, m_Tesla_vehicleCollection) },
	//{ "Bombardier", new Company("Bombardier", m_AirplanesAvailable, m_Tesla_vehicleCollection) },

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
	Company* GetCompany(std::string companyName);
	std::vector<std::string> GetAllCompanyNames();
};


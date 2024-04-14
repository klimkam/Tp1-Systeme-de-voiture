#pragma once
#include "Enums.h"
#include "Vehicle.h"
#include <vector>
#include <list>
#include <string>

class Company
{
	std::string m_companyName;
	std::vector<E_VehicleType> m_availableTypesOfVehicle;
	std::list<Vehicle*> m_vehicleCollection;
	std::list<Vehicle*>::iterator m_vehicleCollectionIterator = m_vehicleCollection.begin();

public:
	Company(std::string companyName, std::vector<E_VehicleType> availableTpesOfVehicle, std::list<Vehicle*> vehicleCollection);

	void AddNewVehicle(Vehicle* vehicle);
	Vehicle* GetVehicle();

	Vehicle* GetNextVehicle();
	Vehicle* GetPreviousVehicle();

	bool IsLastVehicle();
	bool IsFirstVehicle();

	std::string GetCompanyName();
	std::vector<std::string> GetInformation();

	void RemoveVehicle();
};


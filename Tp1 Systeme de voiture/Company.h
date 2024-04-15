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
	std::list<Vehicle*> GetVehicleCollection();
	Vehicle* GetNextVehicle();
	Vehicle* GetPreviousVehicle();

	bool IsLastVehicle();
	bool IsFirstVehicle();

	void IteratorToStart();
	void IteratorToEnd();

	std::string GetCompanyName();
	std::vector<std::string> GetInformation();
	std::vector<E_VehicleType> GetAvailableVehicleTypes();

	void RemoveVehicle();
};


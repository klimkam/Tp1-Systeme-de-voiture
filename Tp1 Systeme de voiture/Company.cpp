#include "Company.h"
#include <list>
#include <vector>
#include <string>
#include "Enums.h"
#include "Vehicle.h"

Company::Company(std::string companyName, std::vector<E_VehicleType> availableTpesOfVehicle, std::list<Vehicle*> vehicleCollection) {
	m_companyName = companyName;
	m_availableTypesOfVehicle = availableTpesOfVehicle;

	for (auto& i : vehicleCollection) {
		AddNewVehicle(i);
	}

	m_vehicleCollectionIterator = m_vehicleCollection.begin();
}

void Company::AddNewVehicle(Vehicle* vehicle)
{
	bool isAbleToAdd = false;

	for (int i = 0; i < m_availableTypesOfVehicle.size(); i++) {
		if (vehicle->GetVehicleType() == m_availableTypesOfVehicle.at(i)) isAbleToAdd = true;
	}

	if (!isAbleToAdd) return;
	m_vehicleCollection.push_front(vehicle);
}

Vehicle* Company::GetVehicle()
{
	return *m_vehicleCollectionIterator;
}

Vehicle* Company::GetNextVehicle()
{
	Vehicle* returnVehicle;
	m_vehicleCollectionIterator++;
	returnVehicle = GetVehicle();
	if (m_vehicleCollectionIterator == m_vehicleCollection.end()) {
		returnVehicle = GetVehicle();
		m_vehicleCollectionIterator = m_vehicleCollection.begin();
	}
	return returnVehicle;
}

std::string Company::GetCompanyName()
{
	return m_companyName;
}

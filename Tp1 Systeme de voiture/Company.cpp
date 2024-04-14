#include "Company.h"
#include <list>
#include <vector>
#include <string>
#include "Enums.h"
#include "Vehicle.h"
#include <iostream>

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

	if (!isAbleToAdd) { 
		std::cout << "Wasn't Able to add" << std::endl;
		std::cin;
		return; 
	}
	m_vehicleCollection.push_front(vehicle);
}

Vehicle* Company::GetVehicle()
{
	return *m_vehicleCollectionIterator;
}

Vehicle* Company::GetNextVehicle()
{
	Vehicle* returnVehicle;
	if (next(m_vehicleCollectionIterator) == m_vehicleCollection.end()) {
		while (m_vehicleCollectionIterator != m_vehicleCollection.begin())
		{
			--m_vehicleCollectionIterator;
		}
		returnVehicle = GetVehicle();
		return returnVehicle;
	}
	m_vehicleCollectionIterator++;
	returnVehicle = GetVehicle();
	return returnVehicle;
}

std::vector<std::string> Company::GetInformation()
{
	std::vector<std::string> tempInfo = GetVehicle()->GetInformation();
	tempInfo.push_back("The Vehicle Company: " + m_companyName);

	return tempInfo;
}

bool Company::IsLastVehicle()
{
	return next(m_vehicleCollectionIterator) == m_vehicleCollection.end();
}

bool Company::IsFirstVehicle()
{
	return m_vehicleCollectionIterator == m_vehicleCollection.begin();
}

void Company::RemoveVehicle()
{
	m_vehicleCollection.erase(m_vehicleCollectionIterator++);
}

Vehicle* Company::GetPreviousVehicle()
{
	Vehicle* returnVehicle;
	if (m_vehicleCollectionIterator == m_vehicleCollection.begin()) {
		while (m_vehicleCollectionIterator != m_vehicleCollection.end())
		{
			++m_vehicleCollectionIterator;
		}
		m_vehicleCollectionIterator--;
		returnVehicle = GetVehicle();
		return returnVehicle;
	}
	m_vehicleCollectionIterator--;
	returnVehicle = GetVehicle();
	return returnVehicle;
}

std::string Company::GetCompanyName()
{
	return m_companyName;
}

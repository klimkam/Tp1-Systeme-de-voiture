#include "Vehicle.h"
#include "Maps.h"
#include <stdlib.h>
#include <iostream>

Vehicle::Vehicle()
{
	m_color = E_Color::Red;
	m_price = 100000;
	m_vehicleId = s_nextAvailableVehicleId++;
}

Vehicle::Vehicle(E_Color color, long price, bool isSold)
{
	SetColor(color);
	SetPrice(price);
	SetIsSold(isSold);
}

E_Color Vehicle::GetColor()
{
	return m_color;
}

std::string Vehicle::GetStringColor() {
	return M_ColorToNames[m_color];
}

void Vehicle::SetColor(E_Color color)
{
	if (color == E_Color::Count) return;
	m_color = color;
}

const E_VehicleType Vehicle::GetVehicleType()
{
	return m_vehicleType;
}

void Vehicle::SetPrice(long newPrice)
{
	if (newPrice < 0) { 
		m_price = 0; 
		return;
	}
	if (newPrice > m_maxPrice) {
		m_price = m_maxPrice;
		return;
	}
	m_price = newPrice;
}

const long Vehicle::GetPrice()
{
	return m_price;
}

void Vehicle::SetIsSold(bool newIsSold)
{
	m_isSold = newIsSold;
}

const bool Vehicle::GetIsSold()
{
	return m_isSold;
}

const int Vehicle::GetVehicleId()
{
	return m_vehicleId;
}

void Vehicle::SetID()
{
	m_vehicleId = s_nextAvailableVehicleId;
	s_nextAvailableVehicleId++;
}

std::vector<std::string> Vehicle::GetInformation() {
	std::string currentVehicleType = M_VehicleTypeToNames[m_vehicleType];

	std::vector<std::string> tempInfo = {
	{"The " + currentVehicleType + " ID: " + std::to_string(GetVehicleId())},
	{"The " + currentVehicleType + " Price: " + std::to_string(GetPrice())},
	{"The " + currentVehicleType + " Color: " + GetStringColor()},
	{GetIsSold() ? "The " + currentVehicleType + " Is Sold" : "The " + currentVehicleType + " Is Not Sold"},
	};

	return tempInfo;
}

#include "Vehicle.h"
#include <stdlib.h>

Vehicle::Vehicle()
{
	m_color = E_Color::Red;
	m_vehicleType = rand() % 2 == 1 ? E_VehicleType::Airplain : E_VehicleType::Car;
	m_price = 100000;
	m_vehicleId = s_nextAvailableVehicleId++;
	SetID();
}

E_Color Vehicle::GetColor()
{
	return m_color;
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

void Vehicle::SetPrice(int newPrice)
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

const int Vehicle::GetPrice()
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

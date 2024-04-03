#include "Vehicle.h"

Vehicle::Vehicle()
{
	m_color = E_Color::Red;
	m_vehicleType = E_VehicleType::Car;
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

E_VehicleType Vehicle::GetVehicleType()
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

int Vehicle::GetPrice()
{
	return m_price;
}

void Vehicle::SetIsSold(bool newIsSold)
{
	m_isSold = newIsSold;
}

bool Vehicle::GetIsSold()
{
	return m_isSold;
}

int Vehicle::GetVehicleId()
{
	return m_vehicleId;
}

void Vehicle::SetID()
{
	m_vehicleId = s_nextAvailableVehicleId;
	s_nextAvailableVehicleId++;
}
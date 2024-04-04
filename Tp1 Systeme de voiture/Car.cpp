#include "Car.h"

Car::Car()
{
	m_color = E_Color::Red;
	m_price = 100000;
	m_vehicleType = E_VehicleType::Car;
	m_vehicleId = s_nextAvailableVehicleId++;
	SetID();
}

#include "Airplane.h"

Airplane::Airplane()
{
	m_color = E_Color::Red;
	m_price = 100000;
	m_vehicleType = E_VehicleType::Airplain;
	m_vehicleId = s_nextAvailableVehicleId++;
	SetID();
}

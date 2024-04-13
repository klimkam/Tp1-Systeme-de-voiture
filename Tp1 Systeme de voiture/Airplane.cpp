#include "Airplane.h"

Airplane::Airplane()
{
	m_color = E_Color::Red;
	m_price = 100000;
	m_vehicleType = E_VehicleType::Airplain;
	m_vehicleId = s_nextAvailableVehicleId++;
	SetID();
}

void Airplane::SetMaxCapacity(int amount)
{
	if (amount < 1) {
		m_maxCapacity = 1;
		return;
	}
	if (amount > 250) {
		m_maxCapacity = 250;
		return;
	}
	m_maxCapacity = amount;
}

void Airplane::SetLastInspectionDate(std::string newInspectionDate)
{
	m_lastInspectionDate = newInspectionDate;
}

std::vector<std::string> Airplane::GetInformation()
{
	std::vector<std::string> tempInfo = {
		{"The Airplane ID: " + std::to_string(GetVehicleId())},
		{"The Airplane Price: " + std::to_string(GetPrice())},
		{"The Airplane Color: " + GetStringColor()},
		{"The Airplane Max Capacity: " + std::to_string(m_maxCapacity)},
		{"The Airplane Last Inspection Date: " + m_lastInspectionDate},
		{GetIsSold() ? "The Airplane Is Sold" : "The Airplane Is Not Sold"},
	};

	return tempInfo;
}

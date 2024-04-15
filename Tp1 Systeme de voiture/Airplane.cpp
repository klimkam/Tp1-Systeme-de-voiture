#include "Airplane.h"

Airplane::Airplane()
{
	m_color = E_Color::Red;
	m_price = 100000;
	m_maxPrice = 50000000;
	m_vehicleType = E_VehicleType::Airplain;
	SetID();
}

Airplane::Airplane(int id, long price, E_Color color, bool isSold, short maxCapacity, std::string lastInspectionDate)
{
	m_vehicleType = E_VehicleType::Airplain;
	m_maxPrice = 50000000;

	m_vehicleId = id;
	SetPrice(price);
	SetColor(color);
	SetIsSold(isSold);
	SetMaxCapacity(maxCapacity);
	SetLastInspectionDate(lastInspectionDate);
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

std::string Airplane::GetLastInspectionDate()
{
	return m_lastInspectionDate;
}

short Airplane::GetMaxCapacity()
{
	return m_maxCapacity;
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

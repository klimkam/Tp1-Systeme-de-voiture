#pragma once
#include "Enums.h"


class Vehicle
{
	static unsigned int s_nextAvailableVehicleId;
	unsigned int m_vehicleId;
	E_Color m_color = E_Color::Count;
	E_VehicleType m_vehicleType = E_VehicleType::Count;
	int m_price = 0;
	int m_maxPrice = 400000;
	bool m_isSold = false;

public:
	Vehicle();

	E_Color GetColor();
	void SetColor(E_Color color);

	E_VehicleType GetVehicleType();

	void SetPrice(int newPrice);
	int GetPrice();

	void SetIsSold(bool newIsSold);
	bool GetIsSold();

	int GetVehicleId();

private:
	void SetID();
};
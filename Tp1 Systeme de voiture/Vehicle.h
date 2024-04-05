#pragma once
#include "Enums.h"


class Vehicle
{
protected:

	static unsigned int s_nextAvailableVehicleId;
	unsigned int m_vehicleId;

	E_Color m_color = E_Color::Count;
	E_VehicleType m_vehicleType = E_VehicleType::Count;
	int m_price = 0;
	long m_maxPrice = 400000;
	bool m_isSold = false;

public:
	Vehicle();
	Vehicle(E_Color color, long price, bool isSold);

	E_Color GetColor();
	void SetColor(E_Color color);

	const E_VehicleType GetVehicleType();

	void SetPrice(long newPrice);
	const long GetPrice();

	void SetIsSold(bool newIsSold);
	const bool GetIsSold();

	const int GetVehicleId();

protected:
	void SetID();
};
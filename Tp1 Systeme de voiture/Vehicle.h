#pragma once
#include "Enums.h"


class Vehicle
{
	E_Color m_color = E_Color::Count;
	E_VehicleType m_vehicleType = E_VehicleType::Count;
	int m_price = 0;
	int m_maxPrice = 400000;
	bool m_isSold = false;

public:
	E_Color GetColor();
	void SetColor(E_Color color);

	void SetPrice(int newPrice);
	int GetPrice();

	void SetIsSold(bool newIsSold);
	bool GetIsSold();
};
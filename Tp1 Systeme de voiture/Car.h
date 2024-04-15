#pragma once
#include "Vehicle.h"
#include "Enums.h"

class Car : public Vehicle
{
public:
	Car();

	Car(int id, long price, E_Color color, bool isSold);
};


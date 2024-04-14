#include "Car.h"
#include <cstdlib>
#include <ctime>

Car::Car()
{
	srand(time(nullptr));
	int randomColorIndex = rand() % (int)E_Color::Count;
	m_color = static_cast<E_Color>(randomColorIndex);
	SetPrice(rand()% (m_maxPrice + 1000) + 1000);
	m_vehicleType = E_VehicleType::Car;
	SetID();
}

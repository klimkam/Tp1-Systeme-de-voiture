#include <iostream>
#include"CarSystem.h"

unsigned int Vehicle::s_nextAvailableVehicleId = 0;

CarSystem* p_carSystem = new CarSystem();

int main() {

	while (true)
	{
		p_carSystem->RenderProgram();

		char input;
		std::cin >> input;

		p_carSystem->HandleInput(input);
	}

	return 0;
}
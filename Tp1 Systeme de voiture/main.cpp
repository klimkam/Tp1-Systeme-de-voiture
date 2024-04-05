#include <iostream>
#include"CarSystem.h"

unsigned int Vehicle::s_nextAvailableVehicleId = 0;

CarSystem* p_carSystem = new CarSystem();

int main() {

	while (true)
	{
		p_carSystem->RenderProgram();

		std::string input;
		std::cin >> input;

		if (input.size() == 1) {
			p_carSystem->HandleInput(input[0]);
			continue;
		}
		p_carSystem->HandleStringInput(input);
	}

	return 0;
}
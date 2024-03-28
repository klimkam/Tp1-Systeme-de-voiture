#include <iostream>
#include"CarSystem.h"

int main() {
	CarSystem* p_carSystem = new CarSystem();

	while (true)
	{
		p_carSystem->RenderProgram();

		char input;
		std::cin >> input;

		p_carSystem->HandleInput(input);
	}

	return 0;
}
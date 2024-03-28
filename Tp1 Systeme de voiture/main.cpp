#include <iostream>
#include"CarSystem.h"

int main() {
	CarSystem* p_carSystem = new CarSystem();

	while (true)
	{
		p_carSystem->RenderProgram();

		std::string input;
		std::cin >> input;
	}

	return 0;
}
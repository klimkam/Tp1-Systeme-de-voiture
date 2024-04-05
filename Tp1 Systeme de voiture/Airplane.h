#pragma once
#include "Vehicle.h"

class Airplane : public Vehicle
{
	short m_maxCapacity = 1;
	std::string m_lastInspectionDate = "Now";

public:
	Airplane();
	void SetMaxCapacity(int amount);

	std::vector<std::string> GetInformation() override;
};


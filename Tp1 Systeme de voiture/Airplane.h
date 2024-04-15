#pragma once
#include "Vehicle.h"

class Airplane : public Vehicle
{
	short m_maxCapacity = 1;
	std::string m_lastInspectionDate = "Now";

public:
	Airplane();
	Airplane(int id, long price, E_Color color, bool isSold, short maxCapacity, std::string lastInspectionDate);

	void SetMaxCapacity(int amount);
	void SetLastInspectionDate(std::string newInspectionDate);

	std::string GetLastInspectionDate();
	short GetMaxCapacity();

	std::vector<std::string> GetInformation() override;
};


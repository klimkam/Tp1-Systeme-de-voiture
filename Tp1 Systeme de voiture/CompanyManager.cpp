#include "CompanyManager.h"

CompanyManager::CompanyManager()
{
	M_Companies = {
		{"Tesla", new Company("Tesla", m_Tesla_availableVehicles, m_Tesla_vehicleCollection)}
	};
}

Company* CompanyManager::GetCompany(std::string companyName)
{
    return M_Companies[companyName];
}

#include "CompanyManager.h"

CompanyManager::CompanyManager()
{
	M_Companies = {
		{"Tesla", new Company("Tesla", m_allAvailableVehicles, M_vehicles["Tesla"])},
		{"Chevrolet", new Company("Chevrolet", m_CarsAvailable, M_vehicles["Chevrolet"])},
		{"Toyota", new Company("Toyota", m_CarsAvailable, M_vehicles["Toyota"])},
		{"BMW", new Company("BMW", m_CarsAvailable, M_vehicles["BMW"])},
		{"Volkswagen", new Company("Volkswagen", m_CarsAvailable, M_vehicles["Volkswagen"])},
		{"Boeing", new Company("Boeing", m_AirplanesAvailable, M_vehicles["Boeing"])},
		{"Airbus", new Company("Airbus", m_AirplanesAvailable, M_vehicles["Airbus"])},
		{"Bombardier", new Company("Bombardier", m_AirplanesAvailable, M_vehicles["Bombardier"])},
	};

	I_M_Companies = M_Companies.begin();
}

Company* CompanyManager::GetCompanyFromName(std::string companyName)
{
	if (M_Companies.find(companyName) == M_Companies.end()) {
		return nullptr;
	}
    return M_Companies[companyName];
}

Company* CompanyManager::GetCompanyFromIterator()
{
	return I_M_Companies->second;
}

Company* CompanyManager::GetNextCompanyFromIterator()
{
	I_M_Companies++;
	return I_M_Companies->second;
}
Company* CompanyManager::GetPreviousCompanyFromIterator()
{
	I_M_Companies--;
	return I_M_Companies->second;
}

std::vector<std::string> CompanyManager::GetAllCompanyNames()
{
	std::vector<std::string> temp_Names;

	for (auto const& imap : M_Companies)
		temp_Names.push_back("" + imap.first);

	return temp_Names;
}

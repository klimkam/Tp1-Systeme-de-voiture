#include "CompanyManager.h"

CompanyManager::CompanyManager()
{
	M_Companies = {
		{"Tesla", new Company("Tesla", m_allAvailableVehicles, m_Tesla_vehicleCollection)},
		{"Chevrolet", new Company("Chevrolet", m_CarsAvailable, m_Tesla_vehicleCollection)},
		{"Toyota", new Company("Toyota", m_CarsAvailable, m_Tesla_vehicleCollection)},
		{"BMW", new Company("BMW", m_CarsAvailable, m_Tesla_vehicleCollection)},
		{"Volkswagen", new Company("Volkswagen", m_CarsAvailable, m_Tesla_vehicleCollection)},
		{"Boeing", new Company("Boeing", m_AirplanesAvailable, m_Tesla_vehicleCollection)},
		{"Airbus", new Company("Airbus", m_AirplanesAvailable, m_Tesla_vehicleCollection)},
		{"Bombardier", new Company("Bombardier", m_AirplanesAvailable, m_Tesla_vehicleCollection)},
	};
}

Company* CompanyManager::GetCompany(std::string companyName)
{
	if (M_Companies.find(companyName) == M_Companies.end()) {
		return nullptr;
	}
    return M_Companies[companyName];
}

std::vector<std::string> CompanyManager::GetAllCompanyNames()
{
	std::vector<std::string> temp_Names;

	for (auto const& imap : M_Companies)
		temp_Names.push_back("" + imap.first);

	return temp_Names;
}

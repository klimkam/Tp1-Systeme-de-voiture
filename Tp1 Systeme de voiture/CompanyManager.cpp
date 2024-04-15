#include "CompanyManager.h"
#include <algorithm>
#include <iostream>
#include <fstream>

CompanyManager::CompanyManager()
{
	//Here I could read the text file and get company information before parsing it into the M_Companies map
	M_Companies = {
		{"tesla", new Company("Tesla", m_allAvailableVehicles, M_vehicles["Tesla"])},
		{"chevrolet", new Company("Chevrolet", m_CarsAvailable, M_vehicles["Chevrolet"])},
		{"toyota", new Company("Toyota", m_CarsAvailable, M_vehicles["Toyota"])},
		{"bmw", new Company("BMW", m_CarsAvailable, M_vehicles["BMW"])},
		{"volkswagen", new Company("Volkswagen", m_CarsAvailable, M_vehicles["Volkswagen"])},
		{"boeing", new Company("Boeing", m_AirplanesAvailable, M_vehicles["Boeing"])},
		{"airbus", new Company("Airbus", m_AirplanesAvailable, M_vehicles["Airbus"])},
		{"bombardier", new Company("Bombardier", m_AirplanesAvailable, M_vehicles["Bombardier"])},
	};

	I_M_Companies = M_Companies.begin();
	SaveProgram();
}

Company* CompanyManager::GetCompanyFromName(std::string companyName)
{
	//Sets the response string to lower case, so it lowers the amount of validations needed
	std::transform(companyName.begin(), companyName.end(), companyName.begin(), [](unsigned char c) { return std::tolower(c); });

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
	if (next(I_M_Companies) == M_Companies.end()) {
		while (I_M_Companies != M_Companies.begin())
		{
			--I_M_Companies;
		}
		return I_M_Companies->second;
	}

	I_M_Companies++;
	return I_M_Companies->second;
}
Company* CompanyManager::GetPreviousCompanyFromIterator()
{
	if (I_M_Companies == M_Companies.begin()) {
		while (I_M_Companies != M_Companies.end())
		{
			++I_M_Companies;
		}
		I_M_Companies--;
		return I_M_Companies->second;
	}
	I_M_Companies--;
	return I_M_Companies->second;
}

std::vector<std::string> CompanyManager::GetAllCompanyNames()
{
	std::vector<std::string> temp_Names;

	for (auto const& imap : M_Companies)
	{
		temp_Names.push_back("" + imap.first);
	}

	return temp_Names;
}

void CompanyManager::SaveProgram()
{
	std::ofstream saveFile("VehicleSystem.txt");

	if (saveFile.is_open()) {
		for (auto const& imap : M_Companies) {
			saveFile << "---\n";
			saveFile << "company_name:" << imap.second->GetCompanyName() << "\n";
			saveFile << "available_vehicles:[\n";
			for (auto const& vehicleTypeItem : imap.second->GetAvailableVehicleTypes()) {
				saveFile << "	{ " <<M_VehicleTypeToNames[vehicleTypeItem] << " },\n";
			}
			saveFile << "]\n";
			saveFile << "vehicles:[\n";
			for (auto const& vehicleItem : imap.second->GetVehicleCollection()) {
				saveFile << "	{\n";
				saveFile << "		vehicle_type:" << M_VehicleTypeToNames[vehicleItem->GetVehicleType()] << "\n";
				saveFile << "		vehicle_id:" << vehicleItem->GetVehicleId() << "\n";
				saveFile << "		vehicle_price:" << vehicleItem->GetPrice() << "\n";
				saveFile << "		vehicle_color:" << M_ColorToNames[vehicleItem->GetColor()] << "\n";
				saveFile << "		vehicle_isSold:" << vehicleItem->GetIsSold() << "\n";
				if (vehicleItem->GetVehicleType() == E_VehicleType::Airplain) {
					Airplane* tempAirplane = (Airplane*)vehicleItem;
					saveFile << "		vehicle_maxCapacity:" << tempAirplane->GetMaxCapacity() << "\n";
					saveFile << "		vehicle_lastInspectionDate:" << tempAirplane->GetLastInspectionDate() << "\n";
				}
				saveFile << "	},\n";
			}
			saveFile << "]\n";
			saveFile << "---\n";
		}

		saveFile.close();
	}
}

//TODO Add some methode to store map into the textFile

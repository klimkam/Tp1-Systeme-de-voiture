#include "CompanyManager.h"
#include <algorithm>
#include <iostream>
#include <fstream>

CompanyManager::CompanyManager()
{
	//Here I could read the text file and get company information before parsing it into the M_Companies map
	if (LoadProgram()) {
		I_M_Companies = M_Companies.begin();
		return;
	}
	//LoadProgram();

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
			saveFile << "	{ \n";

			for (auto const& vehicleTypeItem : imap.second->GetAvailableVehicleTypes()) {
				saveFile << M_VehicleTypeToNames[vehicleTypeItem] << "\n";
			}

			saveFile << "},\n";
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

bool CompanyManager::LoadProgram()
{
	std::ifstream readFile;
	readFile.open("VehicleSystem.txt");

	if (!readFile) { return false; }

	std::string outputString;
	while (true) {
		std::getline(readFile, outputString);
		if (readFile.eof()) { break; }
		if (outputString == "---") {
			std::string company_name;
			std::vector<E_VehicleType> company_availableVehicles;
			std::list<Vehicle*> company_vehicleList;

			std::getline(readFile, outputString);
			company_name = GetDataFromFileString(outputString);
			std::getline(readFile, outputString);
			if (outputString == "available_vehicles:[") {
				std::getline(readFile, outputString);
				while (true) {
					std::getline(readFile, outputString);
					if (outputString.find("},") != std::string::npos) { 
						std::getline(readFile, outputString);
						std::getline(readFile, outputString);
						break; 
					}
					if (M_NamesToVehicleType.find(outputString) != M_NamesToVehicleType.end()) {
						company_availableVehicles.push_back(M_NamesToVehicleType[outputString]);
					}
				}
			}

			if (outputString == "vehicles:[") {
				std::getline(readFile, outputString);
				while (true) {
					std::getline(readFile, outputString);
					if ((outputString.find("]") != std::string::npos) || (outputString.find("---") != std::string::npos)) {
						break;
					}

					E_VehicleType temp_vehicleType;
					int temp_vehicleId;
					long temp_vehiclePrice;
					E_Color temp_vehicleColor;
					bool temp_vehicleIsSold;

					short temp_maxCapacity = 0;
					std::string temp_lastInspectionDate;

					std::string data = GetDataFromFileString(outputString);
					if (M_NamesToVehicleType.find(data) != M_NamesToVehicleType.end()) {
						temp_vehicleType = (M_NamesToVehicleType[data]);
					}

					std::getline(readFile, outputString);
					temp_vehicleId = std::stoi(GetDataFromFileString(outputString));

					std::getline(readFile, outputString);
					data = GetDataFromFileString(outputString);
					temp_vehiclePrice = std::stol(data);

					std::getline(readFile, outputString);
					data = GetDataFromFileString(outputString);
					if (M_NamesToColor.find(data) != M_NamesToColor.end()) {
						temp_vehicleColor = (M_NamesToColor[data]);
					}

					std::getline(readFile, outputString);
					temp_vehicleIsSold = GetDataFromFileString(outputString) == "1";

					if (temp_vehicleType == E_VehicleType::Airplain) {
						std::getline(readFile, outputString);
						temp_vehiclePrice = (short)std::stoi(GetDataFromFileString(outputString));

						std::getline(readFile, outputString);
						temp_lastInspectionDate = (GetDataFromFileString(outputString));
					}
					std::getline(readFile, outputString);
					std::getline(readFile, outputString);

					if (temp_vehicleType == E_VehicleType::Car) {
						Car* temp_car = new Car(temp_vehicleId, temp_vehiclePrice, temp_vehicleColor, temp_vehicleIsSold);
						company_vehicleList.push_back(temp_car);
					}
					else if (temp_vehicleType == E_VehicleType::Airplain) {
						Airplane* temp_airplane = new Airplane(temp_vehicleId, temp_vehiclePrice, temp_vehicleColor, temp_vehicleIsSold, temp_maxCapacity, temp_lastInspectionDate);
						company_vehicleList.push_back(temp_airplane);
					}
				}
			}

			std::string lowkeyCompanyName = company_name;
			std::transform(lowkeyCompanyName.begin(), lowkeyCompanyName.end(), lowkeyCompanyName.begin(), [](unsigned char c) { return std::tolower(c); });
			M_Companies.insert({lowkeyCompanyName, new Company(company_name, company_availableVehicles, company_vehicleList)});
		}

	}

	return true;
}

std::string CompanyManager::GetDataFromFileString(std::string fileLine)
{
	int pos = fileLine.find(":");
	std::string data = fileLine.substr(pos + 1);

	return data;
}

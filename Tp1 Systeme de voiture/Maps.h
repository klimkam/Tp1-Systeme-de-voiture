#pragma once
#include<map>
#include<string>
#include "Enums.h"

class std::map <E_Color, std::string> M_ColorToNames = {
	{E_Color::Red, "Red"},
	{E_Color::Blue, "Blue"},
	{E_Color::Green, "Green"},
	{E_Color::Violet, "Violet"},
	{E_Color::Pink, "Pink"},
	{E_Color::Orange, "Orange"},
	{E_Color::Count, "Count"},
};

class std::map <E_VehicleType, std::string> M_VehicleTypeToNames = {
	{E_VehicleType::Car, "Car"},
	{E_VehicleType::Airplain, "Airplain"},
};
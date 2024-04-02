#pragma once
#include<map>
#include<string>
#include "Enums.h"

std::map <E_Color, std::string> M_ColorToNames = {
	{E_Color::Red, "Red"},
	{E_Color::Blue, "Blue"},
	{E_Color::Green, "Green"},
	{E_Color::Violet, "Violet"},
	{E_Color::Pink, "Pink"},
	{E_Color::Orange, "Orange"},
	{E_Color::Count, "Count"},
};

std::map <std::string, E_Color> M_NamesToColors = {
	{"Red" ,E_Color::Red},
	{"Blue" ,E_Color::Blue},
	{"Green" ,E_Color::Green},
	{"Violet" ,E_Color::Violet},
	{"Pink" ,E_Color::Pink},
	{"Orange" ,E_Color::Orange},
	{"Count" ,E_Color::Count},
};

std::map <E_VehicleType, std::string> M_VehicleTypeToNames = {
	{E_VehicleType::Car, "Car"},
	{E_VehicleType::Airplain, "Airplain"},
};
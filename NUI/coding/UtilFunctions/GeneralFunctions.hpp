#ifndef GERNERALFUNCTIONS_HPP
#define GERNERALFUNCTIONS_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>
#include <string>

using namespace sf;

Color Rainbow(float length, float maxLength);

std::string TruncateDecimals(std::string num, int decimalPlaces);\

#endif
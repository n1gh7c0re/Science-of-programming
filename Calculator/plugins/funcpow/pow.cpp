#include "pch.h"
#include <cmath>
#include <vector>
#include <string>

#ifdef FUNCPOW_EXPORTS
#define POW_API __declspec(dllexport)
#else
#define POW_API __declspec(dllimport)
#endif

extern "C" POW_API double function(std::vector<double> arguments_function) {
	return pow(arguments_function.at(0), arguments_function.at(1));
}

extern "C" POW_API std::string name() {
	return "^";
}

extern "C" POW_API int countOperands() {
	return 2;
}

extern "C" POW_API int priority() {
	return 4;
}
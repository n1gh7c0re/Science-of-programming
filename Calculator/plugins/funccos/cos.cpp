#include "pch.h"
#include <cmath>
#include <vector>
#include <string>

#ifdef FUNCCOS_EXPORTS
#define COS_API __declspec(dllexport)
#else
#define COS_API __declspec(dllimport)
#endif

extern "C" COS_API double function(std::vector<double> arguments_function) {
	return cos(arguments_function.at(0));
}

extern "C" COS_API std::string name() {
	return "cos";
}

extern "C" COS_API int countOperands() {
	return 1;
}

extern "C" COS_API int priority() {
	return 3;
}
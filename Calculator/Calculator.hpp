#pragma once

#include "CalculatorFeatures.hpp"
#include "PluginManager.hpp"

typedef double (*TypeFunc)(std::deque<double>);
typedef std::string(*NameFunc)();
using FunctionsMap = std::map<std::string, std::tuple<TypeFunc, int, int>>;

class Calculator {
private:
	std::unique_ptr<CalcFeatures> _calc_features;
	std::unique_ptr<PluginManager> _plugin_manager;
	std::vector<std::string> TokenizeExpression(const std::string& input_expression);
	std::vector<std::string> ConvertToStandartForm(const std::vector<std::string>& tokens);
	std::stringstream ConvertToRPN(std::vector<std::string> tokens);
	void handleOperator(std::stack<std::string>& operator_stack, std::stringstream& output_stringstream, const std::string& token);
	void handleRightParenthesis(std::stack<std::string>& operator_stack, std::stringstream& output_stringstream);
	void handleRemainingOperators(std::stack<std::string>& operator_stack, std::stringstream& output_stringstream);
public:
	Calculator();
	Calculator(Calculator const&) = delete;
	Calculator(Calculator&&) = delete;
	Calculator operator=(Calculator const&) = delete;
	Calculator operator=(Calculator&&) = delete;
	~Calculator();

	void Solve(std::string input_expression);
};
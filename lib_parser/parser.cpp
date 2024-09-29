// Copyright 2024 Matvey Demidovich

#include "../lib_parser/parser.h"
#include "../lib_stack/stack.h"
#include <string>
#include <stdexcept>

bool _is_correct(const std::string exp){

	Stack<char> stack(exp.length());
	char bracket;

	for (size_t i = 0; i < exp.length(); i++) {
		if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
			stack.push(exp[i]);
		}
		else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
			if (stack.isEmpty()) {
				throw std::logic_error("Missing opening bracket");
				return false;
			}
			bracket = stack.top();
			if (bracket != exp[i]) {
				throw std::logic_error("Missing closing bracket");
				return false;
			}
		}
		else if (exp[i] < '0' || '9' < exp[i] && exp[i] < 'A' || 'Z' < exp[i]
			&& exp[i] < 'a' || 'z' < exp[i] && exp[i] != '*' && exp[i] != '/'
			&& exp[i] != '+' && exp[i] != '-') {
			throw std::logic_error("Unexpect token");
			return false;
		}
		else if (stack.isEmpty()) {
			throw std::logic_error("Expression is missing");
			return false;
		}
		else return true;
	}
}
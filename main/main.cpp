// Copyright 2024 Marina Usova

#define EASY_EXAMPLE
#ifdef EASY_EXAMPLE

#include <iostream>
#include <iomanip>
#include "../lib_easy_example/easy_example.h"
#include "../lib_pair/pair.h"
#include "../lib_list/list.h"

int main() {
	List<int> list;
	list.push_back(56);
	list.push_back(48);
	list.push_back(32);
	list.push_back(52);
}

#endif  // EASY_EXAMPLE

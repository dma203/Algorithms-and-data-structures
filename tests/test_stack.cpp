// Copyright 2024 Matvey Demidovich

#include <gtest.h>
#include "../lib_stack/stack.h"

TEST(libstack, constructorbydeftest) {
	TStack<int> test;
	
	ASSERT_NO_THROW(test);
}

TEST(libstack, isFulltest) {
	TStack<int> test;

	ASSERT_FALSE(test.isFull());
}

TEST(libstack, pushtest) {
	TStack<int> test;

	ASSERT_NO_THROW(test.push(5));
}

TEST(libstack, isEmptytest) {
	TStack<int> test;
	
	ASSERT_TRUE(test.isEmpty());
}

TEST(libstack, poptest) {
	TStack<int> test;

	test.push(5);

	ASSERT_NO_THROW(test.pop());
}
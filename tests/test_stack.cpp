// Copyright 2024 Matvey Demidovich

#include <gtest.h>
#include "../lib_stack/stack.h"

TEST(libstack, constructorbydeftest) {
	ASSERT_NO_THROW(Stack<int> test);
}

TEST(libstack, isNotFulltest) {
	Stack<int> test;
	ASSERT_FALSE(test.isFull());
}

TEST(libstack, isFulltest) {
	Stack<int> test;
	for (int i = 0; i < 20; i++)
	test.push(i);
	ASSERT_TRUE(test.isFull());
}

TEST(libstack, pushtest) {
	Stack<int> test;

	test.push(2);
	test.push(4);

	ASSERT_NO_THROW(test.push(5));
	EXPECT_EQ(test.top(), 5);

}

TEST(libstack, isEmptytest) {
	Stack<int> test;
	
	ASSERT_TRUE(test.isEmpty());
}

TEST(libstack, poptest) {
	Stack<int> test;

	test.push(5);

	ASSERT_NO_THROW(test.pop());
}

TEST(libstack, topThrowtest) {
	Stack<int> test;

	ASSERT_ANY_THROW(test.top());
}

TEST(libstack, isPushFulltest1) {
	Stack<int> test;
	for (int i = 0; i < 20; i++)
		test.push(i);
	ASSERT_ANY_THROW(test.push(1));
}

TEST(libstack, isnotEmptytest1) {
	Stack<int> test;
	test.push(1);

	ASSERT_FALSE(test.isEmpty());
}
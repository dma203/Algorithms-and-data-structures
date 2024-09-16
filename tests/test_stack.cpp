// Copyright 2024 Matvey Demidovich

#include <gtest.h>
#include "../lib_stack/stack.h"

TEST(libstack, constructorbydeftest) {
	ASSERT_NO_THROW(TStack<int> test);
}

TEST(libstack, isNotFulltest) {
	TStack<int> test;
	ASSERT_FALSE(test.isFull());
}

TEST(libstack, isFulltest) {
	TStack<int> test;
	for (int i = 0; i < 20; i++)
	test.push(i);
	ASSERT_TRUE(test.isFull());
}

TEST(libstack, pushtest) {
	TStack<int> test;

	test.push(2);
	test.push(4);

	ASSERT_NO_THROW(test.push(5));
	EXPECT_EQ(test.top(), 5);

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
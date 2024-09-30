// Copyright 2024 Matvey Demidovich

#include <gtest.h>
#include "../lib_queue/queue.h"

TEST(libQueue, constructorbydeftest) {
	ASSERT_NO_THROW(Queue<int> test);
}

TEST(libstack, isNotFulltestq) {
	Queue<int> test;
	ASSERT_FALSE(test.isFull());
}

TEST(libQueue, isFulltest) {
	Queue<int> test;
	for (int i = 0; i < 20; i++)
		test.push(i);
	ASSERT_TRUE(test.isFull());
}

TEST(libQueue, pushtest) {
	Queue<int> test;

	test.push(2);
	test.push(4);

	ASSERT_NO_THROW(test.push(5));
	EXPECT_EQ(test.top(), 5);

}

TEST(libQueue, isEmptytest) {
	Queue<int> test;

	ASSERT_TRUE(test.isEmpty());
}

TEST(libQueue, poptest) {
	Queue<int> test;

	test.push(5);

	ASSERT_NO_THROW(test.pop());
}

TEST(libQueue, topThrowtest) {
	Queue<int> test;

	ASSERT_ANY_THROW(test.top());
}

TEST(libQueue, isPushFulltest) {
	Queue<int> test;
	for (int i = 0; i < 20; i++)
		test.push(i);
	ASSERT_ANY_THROW(test.push(1));
}

TEST(libQueue, isnotEmptytest) {
	Queue<int> test;
	test.push(1);

	ASSERT_FALSE(test.isEmpty());
}

TEST(libQueue, q_sizeisEmptytest) {
	Queue<int> test;

	EXPECT_EQ(test.q_size(), 0);
}

TEST(libQueue, q_sizeisFulltest) {
	Queue<int> test;
	for (int i = 0; i < 20; i++)
		test.push(i);
	ASSERT_TRUE(test.q_size(), 0);
}

TEST(libQueue, q_sizeisnotFulltest) {
	Queue<int> test;
	for (int i = 0; i < 15; i++)
		test.push(i);
	ASSERT_TRUE(test.q_size(), 5);
}

// Copyright 2024 Matvey Demidovich

#include <gtest.h>
#include "../lib_list/list.h"

TEST(lib_list, defaultList) {
	ASSERT_NO_THROW(List<int> test);
}

TEST(lib_list, isEmptyList) {
	List<int> test;

	EXPECT_TRUE(test.is_empty());
}

TEST(lib_list, push_back_test) {
	List<int> test;
    test.push_back(1);

	EXPECT_FALSE(test.is_empty());
}

TEST(lib_list, push_front_test) {
	List<int> test;
	test.push_front(1);

	ASSERT_NO_THROW(test.push_front(2));
	EXPECT_FALSE(test.is_empty());
}

TEST(lib_list, can_insert_in_empty_list_test) {
	List<int> test;
	test.insert(0, 2);

	EXPECT_FALSE(test.is_empty());
}
TEST(lib_list, find_test) {
	List<int> test;
	test.push_back(1);
	EXPECT_EQ(test.find(1), test[0]);
}

TEST(lib_list, can_insert_in_back_test) {
	List<int> test;
	test.push_back(1);
	test.push_back(2);
	ASSERT_NO_THROW(test.insert(2,3));
	EXPECT_EQ(test.find(3), test[2]);
}

TEST(lib_list, can_insert_in_notback_test) {
	List<int> test;
	test.push_back(1);
	test.push_back(2);
	test.push_back(3);
	ASSERT_NO_THROW(test.insert(2, 3));
	EXPECT_EQ(test.find(3), test[2]);
}

TEST(lib_list, remove_first_test) {
	List<int> test;
	test.push_back(1);
	test.remove_first();

	EXPECT_TRUE(test.is_empty());
}

TEST(lib_list, remove_last_test) {
	List<int> test;
	test.push_back(1);
	test.push_back(2);
	test.remove_last();

	EXPECT_EQ(test.find(2),nullptr);
	EXPECT_FALSE(test.is_empty());
}

TEST(lib_list, remove_by_val_test) {
	List<int> test;
	test.push_back(1);
	test.push_back(2);

	ASSERT_NO_THROW(test.remove(1));
	EXPECT_EQ(test.find(1), nullptr);
}

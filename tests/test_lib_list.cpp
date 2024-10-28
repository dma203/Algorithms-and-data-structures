// Copyright 2024 Matvey Demidovich

#include <gtest.h>
#include "../lib_list/list.h"

TEST(lib_list, empty) {
	List<int> ints;
	ASSERT_TRUE(ints.empty());

	ints.push_back(42);
	ASSERT_FALSE(ints.empty());

	ints.pop_back();
	ASSERT_TRUE(ints.empty());
}

TEST(lib_list, size) {
	List<int> ints;
	ASSERT_EQ(ints.size(), 0);

	ints.push_back(42);
	ASSERT_EQ(ints.size(), 1);

	ints.push_back(43);
	ASSERT_EQ(ints.size(), 2);

	ints.pop_back();
	ASSERT_EQ(ints.size(), 1);

	ints.pop_back();
	ASSERT_EQ(ints.size(), 0);
}

TEST(lib_list, front) {
	List<int> ints;
	ASSERT_EQ(ints.front(), 0);

	ints.push_front(42);
	ASSERT_EQ(ints.front(), 42);

	ints.push_front(43);
	ASSERT_EQ(ints.front(), 43);

	List<char> chars;
	ASSERT_EQ(chars.front(), (char)0);
}

TEST(lib_list, back) {
	List<int> ints;
	ASSERT_EQ(ints.back(), 0);

	ints.push_back(42);
	ASSERT_EQ(ints.back(), 42);

	ints.push_back(43);
	ASSERT_EQ(ints.back(), 43);

	List<char> chars;
	ASSERT_EQ(chars.back(), (char)0);
}

TEST(lib_list, push_back) {
	List<int> ints;
	ints.push_back(42);
	ASSERT_EQ(ints.back(), 42);
	ASSERT_EQ(ints.front(), 42);
	ASSERT_EQ(ints.size(), 1);

	ints.push_back(43);
	ASSERT_EQ(ints.back(), 43);
	ASSERT_EQ(ints.front(), 42);
	ASSERT_EQ(ints.size(), 2);
}

TEST(lib_list, push_front) {
	List<int> ints;
	ints.push_front(42);
	ASSERT_EQ(ints.back(), 42);
	ASSERT_EQ(ints.front(), 42);
	ASSERT_EQ(ints.size(), 1);

	ints.push_front(43);
	ASSERT_EQ(ints.back(), 42);
	ASSERT_EQ(ints.front(), 43);
	ASSERT_EQ(ints.size(), 2);
}

TEST(lib_list, pop_back) {
	List<int> ints;
	ints.push_back(42);
	ints.push_back(43);

	ints.pop_back();
	ASSERT_EQ(ints.back(), 42);
	ASSERT_EQ(ints.front(), 42);
	ASSERT_EQ(ints.size(), 1);

	ints.pop_back();
	ASSERT_EQ(ints.back(), 0);
	ASSERT_EQ(ints.front(), 0);
	ASSERT_EQ(ints.size(), 0);
}

TEST(lib_list, pop_front) {
	List<int> ints;
	ints.push_front(42);
	ints.push_front(43);

	ints.pop_front();
	ASSERT_EQ(ints.back(), 42);
	ASSERT_EQ(ints.front(), 42);
	ASSERT_EQ(ints.size(), 1);

	ints.pop_front();
	ASSERT_EQ(ints.back(), 0);
	ASSERT_EQ(ints.front(), 0);
	ASSERT_EQ(ints.size(), 0);
}

TEST(lib_list, insert) {
	List<int> ints;

	auto node43 = ints.insert(100, 43);
	ASSERT_EQ(node43->val, 43);
	ASSERT_EQ(node43->next, nullptr);
	ASSERT_EQ(ints.back(), 43);
	ASSERT_EQ(ints.front(), 43);
	ASSERT_EQ(ints.size(), 1);
	
	auto node41 = ints.insert(0, 41);
	ASSERT_EQ(node41->val, 41);
	ASSERT_EQ(node41->next, node43);
	ASSERT_EQ(ints.back(), 43);
	ASSERT_EQ(ints.front(), 41);
	ASSERT_EQ(ints.size(), 2);

	auto node42 = ints.insert(1, 42);
	ASSERT_EQ(node42->val, 42);
	ASSERT_EQ(node42->next, node43);
	ASSERT_EQ(ints.back(), 43);
	ASSERT_EQ(ints.front(), 41);
	ASSERT_EQ(ints.size(), 3);

	auto node44 = ints.insert(100, 44);
	ASSERT_EQ(node44->val, 44);
	ASSERT_EQ(node44->next, nullptr);
	ASSERT_EQ(ints.back(), 44);
	ASSERT_EQ(ints.front(), 41);
	ASSERT_EQ(ints.size(), 4);
}

TEST(lib_list, find) {
	List<int> ints;
	ints.push_back(42);
	ints.push_back(43);
	ASSERT_EQ(ints.find(42)->val, 42);
	ASSERT_EQ(ints.find(43)->val, 43);
	ASSERT_EQ(ints.find(1), nullptr);
}


TEST(lib_list, remove) {
	List<int> ints;
	ints.push_back(42);
	ints.push_back(43);
	ints.push_back(44);
	ints.push_back(45);

	ints.remove(44);
	ASSERT_EQ(ints.find(44), nullptr);
	ASSERT_EQ(ints.size(), 3);

	ints.remove(45);
	ASSERT_EQ(ints.back(), 43);
	ASSERT_EQ(ints.size(), 2);

	ints.remove(42);
	ASSERT_EQ(ints.front(), 43);
	ASSERT_EQ(ints.size(), 1);
}

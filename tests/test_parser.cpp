// Copyright 2024 Matvey Demidovich

#include <gtest.h>
#include "../lib_parser/parser.h"

TEST(libparser, normal_expression_test) {
	ASSERT_TRUE(_is_correct("(1+2x)/{y-z}*[8t]"));
}
TEST(libparser, russiansymbol_input_test) {
	ASSERT_ANY_THROW(_is_correct("ñ+2"));
}
TEST(libparser, isEmpty_expression_test) {
	ASSERT_ANY_THROW(_is_correct(""));
}
TEST(libparser, incorrect_input_test) {
	ASSERT_ANY_THROW(_is_correct("( )"));
}
TEST(libparser, missing_open_bracket_test) {
	ASSERT_ANY_THROW(_is_correct("){()"));
}
TEST(libparser, brackets_test) {
	ASSERT_ANY_THROW(_is_correct("{([]))"));
}
TEST(libparser, missing_closing_bracket_test) {
	ASSERT_ANY_THROW(_is_correct("(()()"));
}
TEST(libparser, a) {
	ASSERT_TRUE(_is_correct("(()())"));
}
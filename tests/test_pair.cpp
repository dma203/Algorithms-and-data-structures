// Copyright 2024 Matvey Demidovich

#include <gtest.h>
#include <../lib_pair/pair.h>

#define EPSILON 0.000001

TEST(libPair, difftypetest) {
    TPair<int, int> test(52, 34);

    EXPECT_EQ(test.first(), 52);
    EXPECT_EQ(test.second(), 34);
}

TEST(libPair, constructorfunctest) {
    TPair<int, int> test;
    TPair<int, int> test1(2, 4);
    TPair<int, int> test2(test1);

    ASSERT_NO_THROW(test, test1, test2);
}

TEST(libPair, gettfirsttest) {
    TPair<int, int> test(5, 2);

    int _first = test.first();

    EXPECT_EQ(_first, 5);
}

TEST(libPair, gettsecondtest) {
    TPair<bool, int> test(true, 2);

    int _second = test.second();

    EXPECT_EQ(_second, 2);
}

TEST(libPair, settfirsttest) {
    TPair<int, bool> test;

    test.set_first(5);

    EXPECT_EQ(test.first(), 5);
}

TEST(libPair, settsecondtest) {
    TPair<int, bool> test;

    test.set_second(true);

    EXPECT_EQ(test.second(), true);
}

TEST(libPair, operatoreqtest) {
    TPair<char, char> test;
    TPair<char, char> test2('a', 'b');

    test = test2;

    EXPECT_EQ(test.second(), 'b');
    EXPECT_EQ(test.first(), 'a');

}

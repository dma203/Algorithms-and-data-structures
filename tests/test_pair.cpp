// Copyright 2024 Matvey Demidovich

#include <gtest.h>
#include <../lib_pair/pair.h>

#define EPSILON 0.000001

TEST(libPair, difftypetest) {
    TPair<int, int> test(52, 34);
    TPair<int, bool> test3(8, true);
    TPair<int, char> test1(3, 'a');
    TPair<char, double> test5('a', 3.14);
    TPair<char, char> test4('a', 'b');
    TPair<char, bool> test6('a', true);
    TPair<int, double> test2(9, 1.64);
    TPair<double, double> test7(1.12, 2.14);
    TPair<double, bool> test8(3.90, false);
    TPair<bool, bool> test9(true, false);

    ASSERT_NO_THROW(test, test1, test2, test3, test4, test5, test6, test7, test8, test9);
}

TEST(libPair, constructorfunctest) {
    TPair<int, int> test;
    TPair<int, int> test1(2, 4);
    TPair<int, int> test2(test1);

    ASSERT_NO_THROW(test, test1, test2);
}

TEST(libPair, getterstest) {
    TPair<int, int> test(5, 2);

    int _first = test.first();
    int _second = test.second();

    EXPECT_EQ(_first, 5, _second, 2);
}

TEST(libPair, setterstest) {
    TPair<int, bool> test;

    test.set_first(5);
    test.set_second(true);

    EXPECT_EQ(test.first(), 5, test.second(), true);
}

TEST(libPair, operatoreqtest) {
    TPair<char, char> test;
    TPair<char, char> test2('a', 'b');

    test = test2;

    EXPECT_EQ(test.first(), 'a', test.second(), 'b');
}

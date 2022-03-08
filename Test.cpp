//
// Created by User on 06/03/2022.
//

#include <string>
//#include "Test.h"
#include "doctest.h"
#include "mat.hpp"
using namespace ariel;


#include <algorithm>
using namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input) {
    std::erase(input, ' ');
    std::erase(input, '\t');
    std::erase(input, '\n');
    std::erase(input, '\r');
    return input;
}
TEST_CASE("Good input") {
    CHECK(nospaces(mat(9, 7, '@', '-')) == nospaces("@@@@@@@@@\n"
                                                                            "@-------@\n"
                                                                            "@-@@@@@-@\n"
                                                                            "@-@---@-@\n"
                                                                            "@-@@@@@-@\n"
                                                                            "@-------@\n"
                                                                            "@@@@@@@@@"));


    CHECK(nospaces(mat(3, 5, '$', '+')) == nospaces("$$$\n"
                                                    "$+$\n"
                                                    "$+$\n"
                                                    "$+$\n"
                                                    "$$$"));



    CHECK(nospaces(mat(3, 3, '$', '$')) == nospaces("$$$\n"
                                                    "$$$\n"
                                                    "$$$"));



    CHECK(nospaces(mat(7, 1, '&', '-')) == nospaces("&&&&&&&\n"));

    CHECK(nospaces(mat(1, 5, '*', '-')) == nospaces("*\n"
                                                  "*\n"
                                                  "*\n"
                                                  "*\n"
                                                  "*"));



    CHECK(nospaces(mat(13, 5, '@', '-')) == nospaces("@@@@@@@@@@@@@\n"
                                                     "@-----------@\n"
                                                     "@-@@@@@@@@@-@\n"
                                                     "@-----------@\n"
                                                     "@@@@@@@@@@@@@"));



    CHECK(nospaces(mat(1, 1, '@', '-')) == nospaces("@\n"));

    CHECK(nospaces(mat(9, 9, '(', '~')) == nospaces("(((((((((\n"
                                                                            "(~~~~~~~(\n"
                                                                            "(~(((((~(\n"
                                                                            "(~(~~~(~(\n"
                                                                            "(~(~(~(~(\n"
                                                                            "(~(~~~(~(\n"
                                                                            "(~(((((~(\n"
                                                                            "(~~~~~~~(\n"
                                                                            "((((((((("));
    CHECK(nospaces(mat(1, 13, '@', '#')) == nospaces("@\n"
                                                                             "@\n"
                                                                             "@\n"
                                                                             "@\n"
                                                                             "@\n"
                                                                             "@\n"
                                                                             "@\n"
                                                                             "@\n"
                                                                             "@\n"
                                                                             "@\n"
                                                                             "@\n"
                                                                             "@\n"
                                                                             "@"));

    CHECK(nospaces(mat(7, 11, '@', '-')) == nospaces("+++++++\n"
                                                                             "+-----+\n"
                                                                             "+-+++-+\n"
                                                                             "+-+-+-+\n"
                                                                             "+-+-+-+\n"
                                                                             "+-+-+-+\n"
                                                                             "+-+-+-+\n"
                                                                             "+-+-+-+\n"
                                                                             "+-+++-+\n"
                                                                             "+-----+\n"
                                                                             "+++++++"));
    CHECK(nospaces(mat(33, 1, '!', '#')) == nospaces("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n"));
    }


TEST_CASE("Bad input") {
    CHECK_THROWS(mat(10, 5, '$', '%'));
    CHECK_THROWS(mat(10, 0, '^', '#'));
    CHECK_THROWS(mat(0, 5, '$', '%'));
    CHECK_THROWS(mat(3, -5, '$', '%'));
    CHECK_THROWS(mat(2, 5, '$', '%'));
    CHECK_THROWS(mat(4, 4, '$', '%'));
    CHECK_THROWS(mat(44, 12, '!', '%'));
    CHECK_THROWS(mat(6, 3, '^', '('));
    CHECK_THROWS(mat(-4, 4, '$', '%'));
    CHECK_THROWS(mat(-5, -4, '%', '%'));
    CHECK_THROWS(mat(0, 0, '&', '%'));
    /* Add more test here */
}


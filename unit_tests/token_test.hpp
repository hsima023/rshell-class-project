#ifndef TOKEN_TEST_HPP
#define TOKEN_TEST_HPP

#include <gtest/gtest.h>

#include "../src/token.hpp"
#include "../src/tokenizer.h"
#include "../src/poundToken.hpp"
#include "../src/quoteToken.hpp"
#include "../src/andToken.hpp"
#include "../src/orToken.hpp"
#include "../src/cmdToken.cpp"
#include "../src/smcolonToken.hpp"

TEST(cmdExistvalue, TokEvaluate) {
	char *input[2] = { "ls"};
	int index = 0;
	cmdToken cmd;
	EXPECT_EQ(cmd.isExist(input, index), true);
}

TEST(poundExistvalue, TokEvaluate) {
        char *input[2] = { "#" };
        int index = 0;
        poundToken pnd;
        EXPECT_EQ(pnd.isExist(input, index), true);
}

TEST(quoteExistvalue, TokEvaluate) {
        char *input[2] = { "\""};
        int index = 0;
        quoteToken qt;
        EXPECT_EQ(qt.isExist(input, index), true);
}

TEST(andExistvalue, TokEvaluate) {
        char *input[2] = { "&&"};
        int index = 0;
        andToken ntoken;
        EXPECT_EQ(ntoken.isExist(input, index), true);
}

TEST(orExistvalue, TokEvaluate) {
        char *input[2] = { "||"};
        int index = 0;
        orToken ortoken;
        EXPECT_EQ(ortoken.isExist(input, index), true);
}

TEST(smcolonExistvalue, TokEvaluate) {
        char *input[2] = { "ls"};
        int index = 0;
        smcolonToken smcolon;
        EXPECT_EQ(smcolon.isExist(input, index), true);
}

#endif

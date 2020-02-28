#ifndef SHELL_TEST_HPP
#define SHELL_TEST_HPP

#include <gtest/gtest.h>

#include "../src/token.hpp"
#include "../src/tokenizer.h"
#include "../src/poundToken.hpp"
#include "../src/quoteToken.hpp"
#include "../src/andToken.hpp"
#include "../src/orToken.hpp"
#include "../src/cmdToken.cpp"
#include "../src/smcolonToken.hpp"
#include "../src/bracketToken.hpp"
#include "../src/testToken.hpp"
#include "../src/parenToken.hpp"
#include "../src/executor.hpp"
#include <string.h>


TEST(AndOrTest, CmdEvaluate) {
        string input = {"echo A && echo B || echo C"};
        char *arg[1024];
	
        Tokenizer(input, arg);
	andToken nd;
	orToken rt;
	
	bool nvalue = true;
	bool orvalue = true;


        testing::internal::CaptureStdout();
        run(arg, nvalue, orvalue);
        std::string output = testing::internal::GetCapturedStdout();
        EXPECT_EQ(output, "A\nB\n");
}

TEST (ErrorOr, CmdEvaluate) {
	string input = {"ls -j || echo A"};
        char *arg[1024];

        Tokenizer(input, arg);
        orToken rt;

        bool nvalue = true;
        bool orvalue = true;


        testing::internal::CaptureStdout();
        run(arg, nvalue, orvalue);
        std::string output = testing::internal::GetCapturedStdout();
        EXPECT_EQ(output, "A\n");
}

TEST (QuoteComment, CmdEvaluate) {
	string input = {"echo \"Hello # World\" # Good Bye"};
        char *arg[1024];

        Tokenizer(input, arg);

        bool nvalue = true;
        bool orvalue = true;


        testing::internal::CaptureStdout();
        run(arg, nvalue, orvalue);
        std::string output = testing::internal::GetCapturedStdout();
        EXPECT_EQ(output, "Hello # World\n");
}

TEST (ParenAndOr, CmdEvaluate) {
	string input = {"(echo Hello World && ls -j) || echo Good Bye"};
        char *arg[1024];

        Tokenizer(input, arg);

        bool nvalue = true;
        bool orvalue = true;


        testing::internal::CaptureStdout();
        run(arg, nvalue, orvalue);
        std::string output = testing::internal::GetCapturedStdout();
        EXPECT_EQ(output, "Hello World\nGood Bye\n");
}

TEST (ParenSemiOr, CmdEvaluate) {
        string input = {"(echo Hello World; (echo Hi || echo Bye)"};
        char *arg[1024];

        Tokenizer(input, arg);

        bool nvalue = true;
        bool orvalue = true;


        testing::internal::CaptureStdout();
        run(arg, nvalue, orvalue);
        std::string output = testing::internal::GetCapturedStdout();
        EXPECT_EQ(output, "Hello World\nHi\n");
}

TEST (TestParenAnd, CmdEvaluate) {
        string input = {"echo A && (test src/main.cpp && echo B)"};
        char *arg[1024];

        Tokenizer(input, arg);

        bool nvalue = true;
        bool orvalue = true;


        testing::internal::CaptureStdout();
        run(arg, nvalue, orvalue);
        std::string output = testing::internal::GetCapturedStdout();
        EXPECT_EQ(output, "A\n(true)\nB\n");
}

TEST (BracketAnd, CmdEvaluate) {
	string input = {"[ -e src/main.cpp ] && echo B"};
        char *arg[1024];

        Tokenizer(input, arg);

        bool nvalue = true;
        bool orvalue = true;


        testing::internal::CaptureStdout();
        run(arg, nvalue, orvalue);
        std::string output = testing::internal::GetCapturedStdout();
        EXPECT_EQ(output, "(true)\nB\n");
}

TEST (BracketErrorAnd, CmdEvaluate) {
        string input = {"[ -d src/main.cpp ] && echo B)"};
        char *arg[1024];

        Tokenizer(input, arg);

        bool nvalue = true;
        bool orvalue = true;


        testing::internal::CaptureStdout();
        run(arg, nvalue, orvalue);
        std::string output = testing::internal::GetCapturedStdout();
        EXPECT_EQ(output, "(false)\n");
}

TEST (ParenAndOr2, CmdEvaluate) {
	string input = {"echo B || (echo A && echo C)"};
        char *arg[1024];

        Tokenizer(input, arg);

        bool nvalue = true;
        bool orvalue = true;


        testing::internal::CaptureStdout();
        run(arg, nvalue, orvalue);
        std::string output = testing::internal::GetCapturedStdout();
        EXPECT_EQ(output, "B\n");
}

TEST (ParenTestAnd, CmdEvaluate) {
        string input = {"[ -f src/main.cpp ] && (echo A && echo C)"};
        char *arg[1024];

        Tokenizer(input, arg);

        bool nvalue = true;
        bool orvalue = true;


        testing::internal::CaptureStdout();
        run(arg, nvalue, orvalue);
        std::string output = testing::internal::GetCapturedStdout();
        EXPECT_EQ(output, "(true)\nA\nC\n");
}

TEST (ParenTestFailOr, CmdEvaluate) {
	string input = {"[ -d src/main.cpp ] || (echo A && echo C)"};
        char *arg[1024];

        Tokenizer(input, arg);

        bool nvalue = true;
        bool orvalue = true;


        testing::internal::CaptureStdout();
        run(arg, nvalue, orvalue);
        std::string output = testing::internal::GetCapturedStdout();
        EXPECT_EQ(output, "(false)\nA\nC\n");
}

TEST (FailParenAnd, CmdEvaluate) {
        string input = {"ls -j && (echo A && echo C)"};
        char *arg[1024];

        Tokenizer(input, arg);

        bool nvalue = true;
        bool orvalue = true;


        testing::internal::CaptureStdout();
        run(arg, nvalue, orvalue);
        std::string output = testing::internal::GetCapturedStdout();
        EXPECT_EQ(output, "");
}


#endif

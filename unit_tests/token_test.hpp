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
#include "../src/bracketToken.hpp"
#include "../src/testToken.hpp"
#include "../src/parenToken.hpp"
#include "../src/executor.hpp"
#include <string.h>

TEST(cmdExistvalue, TokEvaluate) {
	string get= "ls";
	char *input[2];
	int index = 0;
	Tokenizer(get, input);
	cmdToken cmd;
	EXPECT_EQ(cmd.isExist(input, index), true);
}

TEST(poundExistvalue, TokEvaluate) {
        char *input[2];
	string get = { "#" };
        int index = 0;
	Tokenizer(get, input);
        poundToken pnd;
        EXPECT_EQ(pnd.isExist(input, index), true);
}

TEST(quoteExistvalue, TokEvaluate) {
        char *input[2];
	string get = { "\""};
        int index = 0;
	Tokenizer(get, input);
        quoteToken qt;
        EXPECT_EQ(qt.isExist(input, index), true);
}

TEST(andExistvalue, TokEvaluate) {
        char *input[2];
	string get = { "&&"};
        int index = 0;
	Tokenizer(get, input);
        andToken ntoken;
        EXPECT_EQ(ntoken.isExist(input, index), true);
}

TEST(orExistvalue, TokEvaluate) {
        char *input[2];
	string get = { "||"};
        int index = 0;
	Tokenizer(get, input);
        orToken ortoken;
        EXPECT_EQ(ortoken.isExist(input, index), true);
}

TEST(smcolonExistvalue, TokEvaluate) {
        char *input[2];
	string get = { ";"};
        int index = 0;
	Tokenizer(get, input);
        smcolonToken smcolon;
        EXPECT_EQ(smcolon.isExist(input, index), true);
}

TEST(parenExistvalue, TokEvaluate) {
        char *input[2];
	string get = { "("};
        int index = 0;
	Tokenizer(get, input);
        parenToken paren;
        EXPECT_EQ(paren.isExist(input, index), true);
}

TEST(bracketExistvalue, TokEvaluate) {
        char *input[2];
	string get = {"["};
        int index = 0;
	Tokenizer(get, input);
        bracketToken brack;
        EXPECT_EQ(brack.isExist(input, index), true);
}

TEST(testExistvalue, TokEvaluate) {
        char *input[2];
	string get = {"test"};
        int index = 0;
	Tokenizer(get, input);
        testToken tes;
        EXPECT_EQ(tes.isExist(input, index), true);
}

TEST(tokenizerTest, TokEvaluate) {
        string input = "Hello World";
	char *arg[10];
        Tokenizer(input, arg);
        testing::internal::CaptureStdout();
	cout << arg[0] << " " << arg[1];
	std::string output = testing::internal::GetCapturedStdout();
        EXPECT_EQ(output, "Hello World");
}

TEST(AndLogicTest, TokEvaluate) {
        string input = "Hello && World";
        char *arg[10];
	char *temp[10];
        Tokenizer(input, arg);
	andToken nd;
	nd.logic(arg, temp);
        testing::internal::CaptureStdout();
        cout << arg[0] << " " << temp[0];
        std::string output = testing::internal::GetCapturedStdout();
        EXPECT_EQ(output, "Hello World");
}

TEST(OrLogicTest, TokEvaluate) {
        string input = "Hello || World";
        char *arg[10];
        char *temp[10];
        Tokenizer(input, arg);
        orToken ort;
        ort.logic(arg, temp);
        testing::internal::CaptureStdout();
        cout << arg[0] << " " << temp[0];
        std::string output = testing::internal::GetCapturedStdout();
        EXPECT_EQ(output, "Hello World");
}

TEST(smcolonLogicTest, TokEvaluate) {
        string input = "Hello ; World";
        char *arg[10];
        char *temp[10];
        Tokenizer(input, arg);
        smcolonToken smcolon;
        smcolon.logic(arg, temp);
        testing::internal::CaptureStdout();
        cout << arg[0] << " " << temp[0];
        std::string output = testing::internal::GetCapturedStdout();
        EXPECT_EQ(output, "Hello World");
}

TEST(QuoteLogicTest, TokEvaluate) {
        string input = "\"Hello World\"";
        char *arg[10];
        char *temp[10];
        Tokenizer(input, arg);
        quoteToken qt;
        qt.logic(arg, temp);
        testing::internal::CaptureStdout();
        cout << arg[0] << " " << arg[1];
        std::string output = testing::internal::GetCapturedStdout();
        EXPECT_EQ(output, "Hello World");
}

TEST(PoundLogicTest, TokEvaluate) {
        string input = {"Hello # World"};
        char *arg[10];
        char *temp[10];
        Tokenizer(input, arg);
        poundToken pd;
        pd.logic(arg, temp);
        testing::internal::CaptureStdout();
        cout << arg[0];
        std::string output = testing::internal::GetCapturedStdout();
        EXPECT_EQ(output, "Hello");
}

TEST(ParenLogicTest, TokEvaluate) {
        string input = {"(Hello) World"};
        char *arg[10];
        char *temp[10];
        Tokenizer(input, arg);
        parenToken paren;
        paren.logic(arg, temp);
        testing::internal::CaptureStdout();
        cout << arg[0];
        std::string output = testing::internal::GetCapturedStdout();
        EXPECT_EQ(output, "Hello");
}

TEST(BracketLogicTest, TokEvaluate) {
        string input = {"[ Hello World ]"};
        char *arg[10];
        char *temp[10];
        Tokenizer(input, arg);
        bracketToken brack;
        brack.logic(arg, temp);
        testing::internal::CaptureStdout();
        cout << arg[0] << " " << arg[1] << " " << arg[2];
        std::string output = testing::internal::GetCapturedStdout();
        EXPECT_EQ(output, "test Hello World");
}

TEST(TestFuncTest, TokEvaluate) {
        string input = {"test fakedir"};
        char *arg[10];
        Tokenizer(input, arg);
	testToken tes;
        testing::internal::CaptureStdout();
        tes.test(arg);
        std::string output = testing::internal::GetCapturedStdout();
        EXPECT_EQ(output, "(False)\n");
}

TEST(ExecFuncTest, TokEvaluate) {
        string input = {"echo Hello"};
        char *arg[10];
        Tokenizer(input, arg);
        testing::internal::CaptureStdout();
       	execute(arg);
        std::string output = testing::internal::GetCapturedStdout();
        EXPECT_EQ(output, "Hello\n");
}

TEST(isDirValueTest, TrueEvaluate) {
	string input = {"test -d src"};
	char *arg[1024];
	bool value;

	Tokenizer(input, arg);
	testToken tes;
	value = tes.isDir(arg, 2);
	EXPECT_EQ(value, true);
}

TEST(isDirValueTest, FalseEvaluate) {
        string input = {"test -d README.md"};
        char *arg[1024];
        bool value;

        Tokenizer(input, arg);
        testToken tes;
        value = tes.isDir(arg, 2);
        EXPECT_EQ(value, false);
}

TEST(isFileValueTest, TrueEvaluate) {
        string input = {"test -f README.md"};
        char *arg[1024];
        bool value;

        Tokenizer(input, arg);
        testToken tes;
        value = tes.isFile(arg, 2);
        EXPECT_EQ(value, true);
}

TEST(isFileValueTest, FalseEvaluate) {
        string input = {"test -f src"};
        char *arg[1024];
        bool value;

        Tokenizer(input, arg);
        testToken tes;
        value = tes.isFile(arg, 2);
        EXPECT_EQ(value, false);
}
TEST(isEfileValueTest, TrueEvaluate) {
        string input = {"test -e src"};
        char *arg[1024];
        bool value;

        Tokenizer(input, arg);
        testToken tes;
        value = tes.isEfile(arg, 2);
        EXPECT_EQ(value, true);
}

TEST(isEfileValueTest, FalseEvaluate) {
        string input = {"test -e asdfasj"};
        char *arg[1024];
        bool value;

        Tokenizer(input, arg);
        testToken tes;
        value = tes.isEfile(arg, 2);
        EXPECT_EQ(value, false);
}

TEST(foundValueTest, TrueEvaluate) {
        string input = {"test src"};
        char *arg[1024];
        bool value;

        Tokenizer(input, arg);
        testToken tes;
        value = tes.found(arg);
        EXPECT_EQ(value, true);
}

TEST(foundValueTest, FalseEvaluate) {
        string input = {"test asdfasf"};
        char *arg[1024];
        bool value;

        Tokenizer(input, arg);
        testToken tes;
        value = tes.found(arg);
        EXPECT_EQ(value, false);
}

TEST(tiscorrectValueTest, TrueEvaluate) {
        string input = {"test -e src"};
        char *arg[1024];
        bool value;

        Tokenizer(input, arg);
        testToken tes;
        value = tes.tiscorrect(arg);
        EXPECT_EQ(value, true);
}

TEST(tiscorrectValueTest, FalseEvaluate) {
        string input = {"test -e echo hello"};
        char *arg[1024];
        bool value;

        Tokenizer(input, arg);
        testToken tes;
        value = tes.tiscorrect(arg);
        EXPECT_EQ(value, false);
}

TEST(testValueTest, TrueEvaluate) {
        string input = {"test -e src"};
        char *arg[1024];
        bool value;

        Tokenizer(input, arg);
        testToken tes;
	testing::internal::CaptureStdout();
        tes.test(arg);
        std::string output = testing::internal::GetCapturedStdout();
        EXPECT_EQ(output, "(True)\n");
}

TEST(testValueTest, FalseEvaluate) {
        string input = {"test -e asdfasf"};
        char *arg[1024];
        bool value;

        Tokenizer(input, arg);
        testToken tes;
        testing::internal::CaptureStdout();
        tes.test(arg);
        std::string output = testing::internal::GetCapturedStdout();
        EXPECT_EQ(output, "(False)\n");
}

TEST(isappropriateValueTest, TrueEvaluate) {
        string input = {"[ -e src ]"};
        char *arg[1024];
        bool value;

        Tokenizer(input, arg);
        bracketToken brack;
        value = brack.isappropriate(arg);
        EXPECT_EQ(value, true);
}

TEST(isappropriateValueTest, FalseEvaluate) {
        string input = {"[ -e src && echo hello ]"};
        char *arg[1024];
        bool value;

        Tokenizer(input, arg);
        bracketToken brack;
        value = brack.isappropriate(arg);
        EXPECT_EQ(value, false);
}
#endif

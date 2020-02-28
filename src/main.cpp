#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <string>

#include <boost/tokenizer.hpp>
#include "tokenizer.h"
#include "executor.hpp"
#include "poundToken.hpp"
#include "quoteToken.hpp"
#include "andToken.hpp"
#include "orToken.hpp"
#include "cmdToken.cpp"
#include "smcolonToken.hpp"
#include "parenToken.hpp"
#include "testToken.hpp"
#include "bracketToken.hpp"

using namespace std;
using namespace boost;

int main() {
        string userInput;
        while(1){
                cout << "$ ";
                getline(cin, userInput);
                char *arg[1024];
                Tokenizer(userInput, arg);
		int i = 0;
		bool nvalue = true;
		bool orvalue = true;
		run(arg, nvalue, orvalue);
	}
        return 0;
}

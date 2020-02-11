#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <string>

#include <boost/tokenizer.hpp>
#include "tokenizer.h"

using namespace std;
using namespace boost;

int main() {
	string userInput;
	
	cout << "$ ";
	getline(cin, userInput);	
	
	char* argv[userInput.size()];

	Tokenizer(userInput, argv);

	int i = 0;
        while (argv[i] != NULL) {
                cout << argv[i] << endl;
                i++;
        }

	return 0;
}

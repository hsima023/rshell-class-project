#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <string>

#include <boost/tokenizer.hpp>
#include "tokenizer.h"
#include "executor.hpp"

using namespace std;
using namespace boost;

int main() {
	string userInput;
	while(1){
		cout << "$ ";
		getline(cin, userInput);	
		char** argv = new char*[1024];
		Tokenizer(userInput, argv);
		if (strcmp(argv[0], "exit") == 0){
			exit(EXIT_SUCCESS);
		}
		int i = 0;
        	while (argv[i] != NULL) {
                	cout << argv[i] << endl;
                	i++;
        	}
		Executor ex(argv);
		ex.run(ex, argv);
	}	
	return 0;
}

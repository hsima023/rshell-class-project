#include <iostream>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <boost/tokenizer.hpp>

using namespace std;
using namespace boost;

int main() {
	string test = "./test ./test ./test";
	char* argv[100];
	int i = 0;	
	
	cout << "Start parsing." << endl;

	char_separator<char> space(" ");
	tokenizer<char_separator<char>> token(test, space);

	for (const auto& word : token) {
		
		argv[i] = new char[word.size() + 1];
		strcpy(argv[i], word.c_str());
	
		i++; 
   	}

	argv[i] = NULL;
	
	cout << "Output argv array." << endl;

	i = 0;
	while (argv[i] != NULL) {
		cout << argv[i] << endl;
		i++;
	}
	
	cout << "Parsing complete." << endl;

	pid_t pid = fork();
	//char* argv[] = {"./test", NULL};

	if (pid < 0) {
		cout << "ERROR." << endl;
		exit(1);
	}

	if (pid == 0) {
		execvp(argv[0], argv);
	}
	else if (pid > 0) {
		wait(NULL);
		cout << "Child terminated." << endl;
	}

	return 0;
}

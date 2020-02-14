#ifndef EXECUTOR_H
#define EXECUTOR_H

#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <algorithm>
#include "token.hpp"
#include "poundToken.hpp"
//#include "orToken.hpp"
//#include "andToken.hpp"
#include "quoteToken.hpp"

class Executor {
	public:
	Executor(char *str[]){ };
	void execute(char **str){ 
		pid_t pid;

		int status;
		if((pid = fork()) < 0){
			std::cout << "ERROR: forking process failed\n";
			exit(1);
		}
		else if (pid == 0) {
			if (execvp(*str, str) < 0) {
				std::cout << "ERROR: execvp process failed\n";
				exit(1);
			}
		}
		else {
			while (wait(&status) != pid);
		}
	}

	void run(Executor ex, char **argv) {	

		poundToken pound;

		if (pound.isExist(argv)) {
			pound.logic(argv);
		}


		if (argv[0] == NULL) {
			return;
		}

		char **temp = new char*[1024];
		
		string connector = "NULL";
	
		quoteToken quote;

		int index1 = -1;
                int index2 = -1;

                if (quote.isExist(argv)) {
			quote.findIndex(index1, index2, argv);
			quote.logic(argv);

		}

		const char *Search[] = { "&&", "||", "/;"};

		for (int i = 0; argv[i] != NULL; ++i) {

			for (int j = 0; j < 3; ++j) {
				if (*argv[i] == *Search[j]) {
					if (index1 < i && index2 > i) {
						i = index2;
					}
					argv[i] = NULL;
					i++;
					int k = 0;
					while (argv[i] != NULL) {
						temp[k] = argv[i];
						argv[i] = NULL;
						i++;
						k++;
					}
					temp[k] = NULL;
					connector = Search[j];

					break;		
				}		
			}

			if (connector != "NULL") {
				break;
			}
		}				
		
		ex.execute(argv);

		ex.run(ex, temp);
		delete [] temp;
	}
};	
#endif	

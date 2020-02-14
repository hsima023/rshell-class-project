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

		//Token pound = new poundToken();

		//if (pound.isExist(argv)) {
		//	pound.logic(argv);
		//}


		if (argv[0] == NULL) {
			return;
		}

		char *temp[1024];
		
		string connector = "NULL";
	
		const char *Search[] = { "&&", "||", "/;"};
		
		for (int i = 0; argv[i] != NULL; ++i) {
			for (int j = 0; j < 3; ++j) {
				if (*argv[i] == *Search[j]) {
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
		
		poundToken pound;

                if (pound.isExist(argv)) {
                        pound.logic(argv);
                }

		quoteToken quote;

                if (quote.isExist(argv)) {
                        quote.logic(argv);
                }

		ex.execute(argv);
		
		ex.run(ex, temp);
		
	}
};	
#endif	

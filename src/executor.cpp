#ifndef EXECUTOR_H
#define EXECUTOR_H

#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>

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
};	
#endif	

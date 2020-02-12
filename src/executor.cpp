#include "executor.h"
#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>

Executor::void execute(char **argv){
	pid_t pid;
	int status;
	if((pid = fork()) == -1){
		std::cout << "ERROR: forking process failed\n";
		exit(1);
	}
	else if (pid == 0) {
		if (execvp(*argv, argv) < 0) {
			std::cout << "ERROR: execvp process failed\n";
			exit(1);
		}
	}
	else {
		while (wait(&status != pid);
	}
	}	

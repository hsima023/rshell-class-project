#include "cmdToken.h"
#include "executor.h"
#include <iostream>

void cmdToken::logic(char **argv) 
{ 
	Executor ex(argv);
	for (int i = 0; argv[i] != null; i++){
		if(argv[i] == "ls" || argv[i] == "mkdir" || argv[i] == "echo" ||argv[i] == "git"){
			ex.execute();
		}
		else {
			exit(1);
		}
	}
}



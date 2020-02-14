#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <string>

#include <boost/tokenizer.hpp>
#include "tokenizer.h"
//#include "executor.hpp"
#include "poundToken.hpp"
#include "quoteToken.hpp"
#include "andToken.hpp"
#include "orToken.hpp"
#include "cmdToken.cpp"
#include "smcolonToken.hpp"

using namespace std;
using namespace boost;

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
void run(char **input);
int main() {
        string userInput;
        while(1){
                cout << "$ ";
                getline(cin, userInput);
                char *arg[1024];
                Tokenizer(userInput, arg);
                if (strcmp(arg[0], "exit") == 0){
                        exit(EXIT_SUCCESS);
                }
                int i = 0;
		bool nvalue = true;
		bool orvalue = true;
                while (arg[i] != NULL) {
                        cout << arg[i] << endl;
                        i++;
             	}
		run(arg, nvalue, orvalue);
               
	}
        return 0;
}

void run(char **argv, bool nvalue, bool orvalue)
{
	if (argv[0] == NULL){
		return;
	}
	
	char *temp[1024];
	
	bool nswitch = nvalue;
	bool orswitch = orvalue;

	poundToken pnd;
	quoteToken qt;
	andToken nd;
	orToken rt;
	cmdToken cmd;
	smcolonToken sm;

	if(((cmd.isExist(argv, 0)) == true || (pnd.isExist(argv, 0)) == true)&& (nswitch == true && orswitch == true)){
		for(int i = 0; argv[i] != NULL; ++i){
			if((pnd.isExist(argv, i)) == true){
				pnd.logic(argv, temp);
				execute(argv);
				break;
			}
			if((qt.isExist(argv, i)) == true){
				qt.logic(argv, temp);
				execute(argv);
				break;
			}
			if((nd.isExist(argv, i)) == true){
				nd.logic(argv, temp);
		///		if((cmd.isExist(argv, 0)) == false){
		//			cout << "ERROR: Invalid Command!"<< endl;
		//			break;
		//		}
		//		else {
					execute(argv);
					run(temp, nswitch, orswitch);
					break;
				}
			}
			if((sm.isExist(argv, i)) == true){
				sm.logic(argv, temp);
				execute(argv);
				run(temp, nswitch, orswitch);
				break;
			}
			if((rt.isExist(argv, i)) == true){
				rt.logic(argv, temp);
				execute(argv);
				orswitch = false;
				run(temp, nswitch, orswitch);
				break;
			}
		
		}

		execute(argv);
	}
	else if ((cmd.isExist(argv, 0)) == false || nswitch ==false || orswitch == false){
		int z = 0;
		while(argv[z] != NULL){
			if(rt.isExist(argv, z)){
				rt.logic(argv, temp);
				orswitch = true;
				run (temp, nswitch, orswitch);
				break;
			}
			if(nd.isExist(argv, z){
				nd.logic(argv, temp);
				if(orswitch == false) orswitch = true;
				if((cmd.isExist(argv, z)) == false && nswitch == true) nswitch = false;
				run(temp, nswitch, orswitch);
				break;
			}
			if(sm.isExist(argv, z){
				sm.logic(argv, temp);
				execute(argv);
				run(temp, nswitch, orswitch);
				break;
			}
			z++;
		}
		cout << "ERROR: Invalid Command!"<< endl;
		return;
	}
}









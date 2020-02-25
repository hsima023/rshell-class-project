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
#include "parenToken.hpp"

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
void run(char **input, bool, bool);
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
                /*while (arg[i] != NULL) {
                       cout << arg[i] << endl;
                        i++;
             	}*/
		run(arg, nvalue, orvalue);
               
	}
        return 0;
}

void perror(char **argv)
{
	cout << "-bash: " << argv[0] <<": command not found" << endl;
}

void delarray(char **arr){
	for(int place = 0;arr[place] != NULL; ++place){
		arr[place] = NULL;
	}
}

void run(char **argv, bool nvalue, bool orvalue)
{
	if (argv[0] == NULL){
		return;
	}
	const char *semicolon[] = {";"};
        const char *andsign[] = {"&&"};
        const char *orsign[] = {"||"};
        const char *pound[] = {"#"};
	const char *invalid[] = {"ls","-j"};
	const char *test[] = {"test"};
	char *temp[1024];
	
	bool nswitch = nvalue;
	bool orswitch = orvalue;

	poundToken pnd;
	quoteToken qt;
	andToken nd;
	orToken rt;
	cmdToken cmd;
	smcolonToken sm;
	parenToken paren;

	int i;
	int k;

	if(((cmd.isExist(argv, 0)) == true || (pnd.isExist(argv, 0)) == true || (paren.isExist(argv, 0)) == true) && (nswitch == true && orswitch == true)){
		for(i = 0; argv[i] != NULL; ++i){
			if((pnd.isExist(argv, i)) == true){
				pnd.logic(argv, temp);
				execute(argv);
				return;
			}
			else if ((paren.isExist(argv, i)) == true) {
				paren.logic(argv, temp);
				//execute(argv);
				run(argv, nswitch, orswitch);
				if (temp[0] != NULL) {
					if (nd.isExist(temp, 0) == true) {
                                                nswitch = true;
                                                for (k = 0; temp[k] != NULL; k++) {
                                                        temp[k] = temp[k + 1];
                                                }
                                                temp[k + 1] = NULL;
                                        }
                                        else if (rt.isExist(temp, 0) == true) {
                                                orswitch = false;
                                                for (k = 0; temp[k] != NULL; k++) {
                                                        temp[k] = temp[k + 1];
                                                }
                                                temp[k + 1] = NULL;
                                        }
                                        else if (sm.isExist(temp, 0) == true) {
                                                for (k = 0; temp[k] != NULL; k++) {
                                                        temp[k] = temp[k + 1];
                                                }
                                                temp[k + 1] = NULL;
                                        }
				}
				run(temp, nswitch, orswitch);
				delarray(temp);
				return;
			}
			else if((qt.isExist(argv, i)) == true){
				qt.logic(argv, temp);
	
				if (temp[0] != NULL) {
					if (nd.isExist(temp, 0) == true) {
						nswitch = true;
						for (k = 0; temp[k] != NULL; k++) {
							temp[k] = temp[k + 1];
						}
						temp[k + 1] = NULL;
					}
					else if (rt.isExist(temp, 0) == true) {
						orswitch = false;
						for (k = 0; temp[k] != NULL; k++) {
                                                        temp[k] = temp[k + 1];
                                               	}
						temp[k + 1] = NULL;
					}
					else if (sm.isExist(temp, 0) == true) {
						for (k = 0; temp[k] != NULL; k++) {
                                                        temp[k] = temp[k + 1];
                                                }
						temp[k + 1] = NULL;
					}
				}

				execute(argv);
				run (temp, nswitch, orswitch);
				delarray(temp);
				return;
			}
			else if((nd.isExist(argv, i)) == true){
				nd.logic(argv, temp);
		///		if((cmd.isExist(argv, 0)) == false){
		//			cout << "ERROR: Invalid Command!"<< endl;
		//			break;
		//		}
		//		else {
				execute(argv);
				if(*argv[0] == *invalid[0] && *argv[1] == *invalid[1]){
					nswitch = false;
				}				
				run(temp, nswitch, orswitch);
				delarray(temp);
				return;
			}
			else if((sm.isExist(argv, i)) == true){
				sm.logic(argv, temp);
				execute(argv);
				run(temp, nswitch, orswitch);
				delarray(temp);
				return;
			}
			else if((rt.isExist(argv, i)) == true){
				rt.logic(argv, temp);
				execute(argv);
				orswitch = false;
				if( *argv[0] == *invalid[0] && *argv[1] == *invalid[1]){
                                        orswitch = true;
                                }
				run(temp, nswitch, orswitch);
				delarray(temp);
				return;
			}
		}
		//if (argv[i] = NULL) {
			execute(argv);
		//}
	}
	else if ((cmd.isExist(argv, 0)) == false && nswitch == true && orswitch == true) {
		perror(argv);
		for(int q = 0; argv[q] != NULL; q++){
			if(rt.isExist(argv, q)){
    				rt.logic(argv, temp);
                                run (temp, nswitch, orswitch);
                                delarray(temp);
                                return;
                        }
                        if(nd.isExist(argv, q)){
                                nd.logic(argv, temp);
              			nswitch = false;
                                run(temp, nswitch, orswitch);
                                delarray(temp);
                                return;
                        }
                        if(sm.isExist(argv, q)){
                                sm.logic(argv, temp);
                                run(temp, nswitch, orswitch);
                                delarray(temp);
                                return;
                        }
		}
	}
	else if ((cmd.isExist(argv, 0)) == false || nswitch ==false || orswitch == false){
		int z = 0;
		while(argv[z] != NULL){
			if(rt.isExist(argv, z)){
				rt.logic(argv, temp);
				orswitch = false;
				run (temp, nswitch, orswitch);
				delarray(temp);
				return;
			}
			if(nd.isExist(argv, z)){
				nd.logic(argv, temp);
				if(orswitch == false) orswitch = true;
				if((cmd.isExist(argv, 0)) == false && nswitch == true) nswitch = false;
				run(temp, nswitch, orswitch);
				delarray(temp);
				return;
			}
			if(sm.isExist(argv, z)){
				sm.logic(argv, temp);
				if (orswitch == true) {
					 execute(argv);
				}
				orswitch = true;
				run(temp, nswitch, orswitch);
				delarray(temp);
				return;
			}
			z++;
		}
		if (argv[z] == NULL && (orswitch == false || nswitch == false)) {
		//cout << "ERROR: Invalid Command!"<< endl;
		return;
		}
		//execute(argv);
		k = 0;
		int index = -1;
		for (k = 0; argv[k] != NULL; ++k) {
			if (*argv[k] == *andsign[0] || *argv[k] == *pound[0] || *argv[k] == *semicolon[0] || *argv[k] == *orsign[0]) {
			index = k - 1;
			break;
			
			}
		}

		for(k = index; argv[k] != NULL; ++k){
			k++;
                        int l = 0;
                        while(argv[k] != NULL){
                        	temp[l] = argv[k];
                        	argv[k] = NULL;
                        	k++;	
                        	l++;
                        }
		
                        temp[l] = NULL;
			break;
		}
		k = 0;
		if (temp[0] != NULL) {
                                        if (nd.isExist(temp, 0) == true) {
                                                nswitch = false;
                                                for (k = 0; temp[k] != NULL; k++) {
                                                        temp[k] = temp[k + 1];
                                                }
                                                temp[k + 1] = NULL;
                                        }
                                        else if (rt.isExist(temp, 0) == true) {
                                                orswitch = true;
                                                for (k = 0; temp[k] != NULL; k++) {
                                                        temp[k] = temp[k + 1];
                                                }
                                                temp[k + 1] = NULL;
                                        }
                                        else if (sm.isExist(temp, 0) == true) {
                                                for (k = 0; temp[k] != NULL; k++) {
                                                        temp[k] = temp[k + 1];
                                                }
                                                temp[k + 1] = NULL;
                                        }
                                }
                                execute(argv);
                                run (temp, nswitch, orswitch);
				delarray(temp);
                                return;
			 
	
	}
}









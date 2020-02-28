#ifndef EXECUTOR_HPP
#define EXECUTOR_HPP

#include <sys/types.h>
#include <sys/wait.h>
#include <iostream>
#include <string.h>
#include <string>
#include "poundToken.hpp"
#include "quoteToken.hpp"
#include "andToken.hpp"
#include "orToken.hpp"
#include "cmdToken.cpp"
#include "smcolonToken.hpp"
#include "parenToken.hpp"
#include "testToken.hpp"
#include "bracketToken.hpp"


using namespace std;

void execute(char **str){
                pid_t pid;

                int status;
		
		testToken tok;		

		if (strcmp(str[0], "exit") == 0){
                        exit(EXIT_SUCCESS);
                }
		else if(strcmp(str[0], "test") == 0){
			tok.test(str);
		}
                else if((pid = fork()) < 0){
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
	const char *invalid[] = {"ls", "-j"};
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
	testToken tes;
	bracketToken brack;

	int i;
	int k;

	if(((cmd.isExist(argv, 0)) == true || (pnd.isExist(argv, 0)) == true || (paren.isExist(argv, 0)) == true || (brack.isExist(argv, 0)) == true) && (nswitch == true && orswitch == true)){
		for(i = 0; argv[i] != NULL; ++i){
			if((pnd.isExist(argv, i)) == true){
				pnd.logic(argv, temp);
				if (argv[0] != NULL) {
					execute(argv);
				}
				return;
			}
			else if ((brack.isExist(argv, i)) == true) {
				if(brack.isappropriate(argv) == false) {
					brack.perror();
					brack.logic(argv, temp);
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
					run(temp, nswitch, orswitch);
					delarray(temp);
					return;
				}
				else {	
					brack.logic(argv, temp);
					run(argv, nswitch, orswitch);
					if (temp[0] != NULL) {
                                        	if (nd.isExist(temp, 0) == true) {
                                                	nswitch = true;
							if(argv[1] != NULL) {
								if (strcmp(argv[0], test[0]) == 0 && (tes.found(argv) == false || tes.tiscorrect(argv) == false)) {
                                        				nswitch = false;
                            					}
							}
                                                	for (k = 0; temp[k] != NULL; k++) {
                                                        	temp[k] = temp[k + 1];
                                                	}
                                                	temp[k + 1] = NULL;
                                        	}
                                        	else if (rt.isExist(temp, 0) == true) {
                                                	orswitch = false;
							if(argv[1] != NULL) {
								if (strcmp(argv[0], test[0]) == 0 && (tes.found(argv) == false || tes.tiscorrect(argv) == false)) {
                                        				orswitch = true;
                                				}
							}
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
			//		execute(argv);
					run(temp, nswitch, orswitch);
					delarray(temp);
					return;
				}
			}
			else if ((paren.isExist(argv, i)) == true) {
				paren.logic(argv, temp);
				run(argv, nswitch, orswitch);
				for (int m = 0; argv[m] != NULL; ++m) {
                                        if (argv[m + 1] != NULL) {
                                                if (strcmp(argv[m], invalid[0]) == 0 && strcmp(argv[m + 1], invalid[1]) == 0) {
                                                        nswitch = false;
                                                        orswitch = true;
                                                        break;
                                                }
                                                else if (strcmp(argv[m], test[0]) == 0 && tes.found(argv) == false) {
                                                        nswitch = false;
                                                        orswitch = true;
                                                        break;
                                                }
                                        }
                                }
				if (temp[0] != NULL) {
					if (nd.isExist(temp, 0) == true) {
						for (k = 0; temp[k] != NULL; k++) {
                                                        temp[k] = temp[k + 1];
                                                }
                                                temp[k + 1] = NULL;
                                        }
                                        else if (rt.isExist(temp, 0) == true) {
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
				execute(argv);
				if(argv[1] != NULL) {
					if (strcmp(argv[0], invalid[0]) == 0 && strcmp(argv[1], invalid[1]) == 0) {
						nswitch = false;
					}
					else if (strcmp(argv[0], test[0]) == 0 && tes.found(argv) == false) {
						nswitch = false;
					}
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
				if (argv[1] != NULL) {
					if( strcmp(argv[0], invalid[0]) == 0 && strcmp(argv[1], invalid[1]) == 0){
                                        	orswitch = true;
                                	}
					else if (strcmp(argv[0], test[0]) == 0 && tes.found(argv) == false) {
						orswitch = true;
					}
				}
				run(temp, nswitch, orswitch);
				delarray(temp);
				return;
			}
		}

		execute(argv);
		if (argv[1] != NULL) {
                	if( strcmp(argv[0], invalid[0]) == 0 && strcmp(argv[1], invalid[1]) == 0){
                        	orswitch = true;
                                nswitch = false;
                        }
                       	else if (strcmp(argv[0], test[0]) == 0 && tes.found(argv) == false) {
                         	orswitch = true;
                               	nswitch = false;
                      	}
        	}
		return;
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
				if(nswitch == false){
					orswitch = true;
					nswitch = true;
				}	 
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
			return;
		}
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
#endif

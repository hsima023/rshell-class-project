#ifndef POUND_TOKEN_HPP
#define POUND_TOKEN_HPP

#include "token.hpp"

class poundToken: public Token {
	public:
	bool isExist(char** argv){
		bool equal = false;
	      	for(int i = 0; argv[i] != "\n"; i++){
              		if(argv[i] == '#'){
                      	equal = true;
                      	break;
             		}
      		}
      		return equal;
	}
	void logic(char** argv){
		const char *pound[] = { "#"};
        	for(int i = 0; argv[i] != NULL; i++){
                	if(*argv[i] == *pound[0]){
                        	int j;
                        	for(j = i; argv[j] != NULL; j++){
                                	argv[j] = '\0';
                        	}
                	argv[j] = NULL;
                	break;
                	}
        	}
	}
};

#endif

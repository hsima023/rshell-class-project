#ifndef POUND_TOKEN_HPP
#define POUND_TOKEN_HPP

#include "token.hpp"
#include "quoteToken.hpp"

class poundToken: public Token {
	public:
	poundToken() { }
	bool isExist(char** argv){
		bool equal = false;
	      	for(int i = 0; argv[i] != NULL; i++){
              		if(*argv[i] == '#'){
                      	equal = true;
                      	break;
             		}
      		}
      		return equal;
	}
	void logic(char** argv){
		//const char *pound[] = { "#"};
		quoteToken quo;
		int index = -1;
		int index2 = -1;
        	for(int i = 0; argv[i] != NULL; i++){
			if ((*argv[i] == '\"' || *argv[i] == '\'') && quo.isExist(argv)) {
				index = i;	
			}
			if ((*argv[i] == '\"' || *argv[i] == '\'') && quo.isExist(argv) && index != -1) {
                                index2 = i;
                        }
		}
		for (int j = 0; argv[j] != NULL; j++) {
                	if(*argv[j] == '#'){
                 	       	if (index < j && index2 > j) {
					return;
				}
	
				int k;
                        	for(k = j; argv[k] != NULL; k++){
                                	argv[k] = NULL;
                        	}
                	argv[k] = NULL;
                	break;
                	}
        	}
	}
};

#endif

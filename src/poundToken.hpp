#ifndef POUND_TOKEN_HPP
#define POUND_TOKEN_HPP

#include "token.hpp"
#include "quoteToken.hpp"

class poundToken: public Token {
	public:
	poundToken() { }
	bool isExist(char** argv, int num){
		int i = num;
		bool equal = false;
	      	//for(int i = 0; argv[i] != NULL; i++){
              		if(*argv[i] == '#'){
                      	equal = true;
                //    	break;
             		}
    
      		return equal;
	}
	void logic(char** argv, char** temp){
		//const char *pound[] = { "#"};
		quoteToken quo;
		int index1 = -1;
		int index2 = -1;
		for(int i = 0; argv[i] != NULL; i++){
			if (quo.isExist(argv, i)) {
				quo.findIndex(index1, index2, argv);
			}
		}
		for (int j = 0; argv[j] != NULL; j++) {
			if(*argv[j] == '#'){
                 	       	if (index1 < j && index2 > j) {
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

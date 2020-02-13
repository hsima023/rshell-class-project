#ifndef OR_TOKEN_HPP
#define OR_TOKEN_HPP

#include "token.hpp"

class orToken: public Token {
	public:
	bool isExist()
	{
        	bool equal =false;
        	for (int i = 0;argv[i] != "\n"; i++){
                	if(argv[i] == "||"){
                        	equal = true;
                        	break;
                	}
        	}
        	return equal;
	}
	void logic()
	{
        	char *temp[8];
        	const char *Or[] = { "||"};
        	for(int i = 0; argv[i] != NULL; i++){
                	if(*argv[i] == *Or[0]){
                        	argv[i] = NULL;
                        	i++;
                        	while(argv[i] != NULL){
                                	int j = 0;
                                	temp[j] = argv[i];
                                	argv[i] = NULL;
                                	i++;
                                	j++;
                        	}
                	break;
                	}
        	}
//      if(execute(argv)); then execute(temp);
 	}
};

#endif

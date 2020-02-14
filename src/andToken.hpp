#ifndef AND_TOKEN_HPP
#define AND_TOKEN_HPP

#include "token.hpp"

class andToken: public Token {
	public:
	bool isExist(char **argv)
	{
        	bool equal =false;
        	for (int i = 0;argv[i] != "\n"; i++){
                	if(argv[i] == "&&"){
                        	equal = true;
                        	break;
                	}
        	}
        	return equal;
	}
	void logic(char **argv)
	{
        	char *temp[4];
        	const char *And[] = { "&&"};
        	for(int i = 0; argv[i] != NULL; i++){
                	if(*argv[i] == *And[0]){
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
	}

};

#endif

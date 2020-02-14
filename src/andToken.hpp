#ifndef AND_TOKEN_HPP
#define AND_TOKEN_HPP

#include "token.hpp"

class andToken: public Token {
	public:
	bool isExist(char **argv, int num)
	{
        	bool equal =false;
		int i = num;
		const char *sign[] = { "&&" };
   //     	for (int i = 0;argv[i] != "\n"; i++){
                	if(*argv[i] == *sign[0]){
                        	equal = true;
                        //	break;
                	}
 //       	}
        	return equal;
	}
	void logic(char **argv, char **temp)
	{
        	const char *And[] = { "&&"};
        	for(int i = 0; argv[i] != NULL; ++i){
                	if(*argv[i] == *And[0]){
                        	argv[i] = NULL;
                        	i++;
				int k = 0;
                        	while(argv[i] != NULL){
                                	temp[k] = argv[i];
                                	argv[i] = NULL;
                                	i++;
                                	k++;
                        	}
				temp[k] = NULL;	
                		
				break;
                	}
        	}
	}

};

#endif

#ifndef SMCOLON_TOKEN_HPP
#define SMCOLON_TOKEN_HPP

#include "token.hpp"

class smcolonToken: public Token {
	public:
	bool isExist(char **argv, int num)
	{
		bool equal = false;
		int i = num;
		const char *sign[] = { ";"};
		if(*argv[i] == *sign[0]){
			equal = true;
		}
		return equal;
	}
	void logic(char **argv, char **temp)
	{
		const char *smcln[] = { ";"};
		for(int i = 0; argv[i] != NULL; ++i){
			if(*argv[i] == *smcln[0]){
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

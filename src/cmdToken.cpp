#ifndef CMD_TOKEN_HPP
#define CMD_TOKEN_HPP

#include "token.hpp"
#include <iostream>

class cmdToken: public Token {
	public:
	bool isExist(char **argv, int num)
	{
		bool equal = false;
		const char *Search[] = { "ls" , "mkdir" , "echo" , "git", "rm"};
		const char *invalid[] = { "-j"};
		int ind = num;
		for(int i = 0; i < 5; i++){
			if(*Search[i] == *argv[ind]){
				equal = true;
				break;
			}
		}
		//int j = 0;
		//if((*Search[j] == *argv[ind] && *invalid[j] == *argv[ind++])==0){
		//	equal = false;
	//	}
		return equal;
	}
};

#endif



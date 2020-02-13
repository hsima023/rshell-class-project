#ifndef QUOTE_TOKEN_HPP
#define QUOTE_TOKEN_HPP

#include "token.hpp"

class quoteToken: public Token {
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
        	char *quote[] = *argv[];
        	int count = 0;
        	for(;;){
                	if(*quote == '\'' || *quote == '\"'){
                        	int q = *quote++;
                        	char *start = quote;

                        	while(*quote && *quote != q){
                                	quote++;
                        	}
                        	if(*quote == '\0'){
                                	cout << "ERROR: Unmatched quote!\n";
                        	}
                        	count += token(start, quote);
                        	quote++;
                        }
        	}
	}	
};
#endif

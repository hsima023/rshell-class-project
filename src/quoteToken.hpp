#ifndef QUOTE_TOKEN_HPP
#define QUOTE_TOKEN_HPP

#include "token.hpp"

class quoteToken: public Token {
	public:
	bool isExist(char **argv)
	{
        	bool equal1 = false;
		bool equal2 = false;

		const char* quotation = "\"";

        	for (int i = 0; argv[i] != NULL; i++){
                	if(*argv[i] == *quotation && equal1 == false){
                        	equal1 = true;
                	}
			if (*argv[i] == *quotation && equal1 == true) {
				equal2 = true;
				break;
			}	
        	}
        	return equal2;
	}
	void logic(char **argv)
	{
        	const char* quotation = "\"";
		//char *quote[] = *argv[];
        	int count = 0;
		char *temp;
        	for(int i = 0; argv[i] != NULL; ++i){
                	if(*argv[i] == '\'' || *argv[i] == '\"') {
				for (int j = i + 1; *argv[j] != *quotation; j++) {
					argv[i] = argv[j];
					argv[j] = NULL;
					i++;
					if(argv[j + 1] == NULL){
                                		cout << "ERROR: Unmatched quote!\n";
						return;
                      			}
				}
				//*argv[i] = *temp;
				return;	
                        }
        	}
	}	
};
#endif

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
		char *temp;
		bool mark = false;
        	for(int i = 0; argv[i] != NULL; ++i){
                	if(*argv[i] == '\'' || *argv[i] == '\"') {
				for (int j = i + 1; argv[j] != NULL; j++) {

					argv[i] = argv[j];
					
					if(*argv[i] == '\"' || *argv[i] == '\''){
						mark = true;
					}
					
					while ((*argv[i] == '\"' || *argv[i] == '\'') && argv[++j] != NULL) {
                                                argv[i] = argv[j];
                                        }


					i++;
				}
				if (*argv[i - 1] == '\"' || *argv[i - 1] == '\'') {
					--i;
				}
				while (argv[i] != NULL) {
					argv[i++] = NULL;
				}
	
				if (!mark) {
					cout << "ERROR: Unmatched quote!\n";
                                        return;
                                }

				return;	
                        }
        	}
	}	
	
	void findIndex(int &index1, int &index2, char** argv) {
                for(int i = 0; argv[i] != NULL; i++){
                        if ((*argv[i] == '\"' || *argv[i] == '\'') && index1 < 0) {
		               index1 = i;
                                ++i;
                        }
                        if ((*argv[i] == '\"' || *argv[i] == '\'') && index1 != -1) {
                                index2 = i;
				return;
                        }
                }
	}

	
};
#endif

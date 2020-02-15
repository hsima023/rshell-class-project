#ifndef QUOTE_TOKEN_HPP
#define QUOTE_TOKEN_HPP

#include "token.hpp"

class quoteToken: public Token {
	public:
	bool isExist(char **argv, int num)
	{
		bool equal = false;
		const char* quotation = "\"";

		if (*argv[num] == *quotation) {
			equal = true;
        	}
        	return equal;
	}
	void logic(char **argv, char **temp)
	{
		int index = -1;
		const char *sm[] = {";"};
		const char *nd[] = {"&&"};
		const char *rt[] = {"||"};
		const char *pnd[] = {"#"};
		bool mark = false;
        	for(int i = 0; argv[i] != NULL; ++i){
                	if(*argv[i] == '\'' || *argv[i] == '\"') {
				for (int j = i + 1; argv[j] != NULL; j++) {

					argv[i] = argv[j];
					
					if((*argv[i] == '\"' || *argv[i] == '\'') && index < 0){
						mark = true;
						index = i;
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
	
				/*if (!mark) {
					cout << "ERROR: Unmatched quote!\n";
                                        return;
                                }*/
				
				if (argv[index] != NULL) {

				for (int m = index; argv[m] != NULL; ++m) {
					if (*argv[m] == *nd[0] || *argv[m] == *pnd[0] || *argv[m] == *sm[0] || *argv[m] == *rt[0]) {
						index = m - 1;
					}
				}		

                		for(int k = index; argv[k] != NULL; ++k){
                                	//argv[k] = NULL;
                                	k++;
                                	int l = 0;
                                	while(argv[k] != NULL){
                                        	temp[l] = argv[k];
                                        	argv[k] = NULL;
                                        	k++;
                                        	l++;
                                	}
                                temp[l] = NULL;

				return;	
                        	}
				}
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

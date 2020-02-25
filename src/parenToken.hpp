#ifndef __PARENTOKEN_HPP__
#define __PARENTOKEN_HPP__

#include "token.hpp"
#include <string>

class parenToken : public Token {
	public:
	parenToken() { }
	
	bool isExist(char** argv, int num) {
		const char *sign[] = { "(" };

		if (*argv[num] == *sign[0]) {
			return true;
		}
		
		return false;
	}

	void logic (char **argv, char **temp) {
		const char *sm[] = {";"};
		const char *nd[] = {"&&"};
		const char *rt[] = {"||"};
		const char *pnd[] = {"#"};
		int num = 0;
		int index;
		for (int i = 0; argv[i] != NULL; ++ i) {
			if (*argv[i] == '(') {
				for (int j = i + 1; argv[j] != NULL; j++) {
					argv[i] = argv[j];
					if (*argv[i] == '(') {
						++num; //increment number of open parentheses
					}
					if (*argv[i] == ')') {
						if (num > 0) {
							--num;
						}
						else {
							argv[i] = argv[++j];
							index = i;
						}
					}
					i++;
				}

				while (argv[i] != NULL) {
					argv[i++] = NULL;
				}
				
				for (int m = index; argv[m] != NULL; ++m) {
					if (*argv[m] == *nd[0] || *argv[m] == *pnd[0] || *argv[m] == *sm[0] || *argv[m] == *rt[0]) {
						index = m - 1;
						break;
					}
				}	

				for(int k = index; argv[k] != NULL; ++k){
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
};
#endif

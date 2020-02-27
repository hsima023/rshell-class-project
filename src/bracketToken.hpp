#ifndef BRACKET_TOKEN_HPP
#define BRACKET_TOKEN_HPP

#include "token.hpp"
#include <iostream>
#include "cmdToken.cpp"
#include <string.h>
#include <unistd.h>

class bracketToken: public Token {
        public:
        bool isExist(char **argv, int num)
        {
                bool equal = false;
                const char *Search = "[";
                if(*argv[num] == *Search){
                        equal = true;
                }
                return equal;
        }

        void logic(char **argv, char **temp) {
		const char *bracket_st[] = { "["};
		const char *bracket_end[] = { "]"};
		int mark;
                for(int i = 0; argv[i] != NULL; ++i){
                        if(*argv[i] == *bracket_st[0]){
                                strcpy(argv[i], "test");
			}
                        else if(*argv[i] == *bracket_end[0]){
				int k;
				mark = i;
				for(k = i; argv[k] != NULL; ++k){
					argv[k] = argv [k + 1];
				}
				argv[k + 1] = NULL;
				
                                break;
			}
                }
		//////////////////////////////////////////////////////////	
		for(int z = mark; argv[z] != NULL; ++z){
                       	int l = 0;
                        while(argv[z] != NULL){
                        	temp[l] = argv[z];
                                argv[z] = NULL;
                                z++;
                                l++;
                        }
                        temp[l] = NULL;
		}
		while (argv[mark] != NULL) {
			argv[mark++] = NULL;
		}	
		return;
       }	
       bool isappropriate(char **argv){
		int index;
		const char *bracket_st[] = { "["};
                const char *bracket_end[] = { "]"};

		const char *sm[] = {";"};
                const char *nd[] = {"&&"};
                const char *rt[] = {"||"};
                const char *pnd[] = {"#"};

		for(int i = 0; argv[i] != NULL; ++i)
		{
			if(*argv[i] == *bracket_end[0]){
				index = i;
				break;
			}
		}
		for(int m = 0; m < index; ++m){
			if(*argv[m] == *nd[0] || *argv[m] == *pnd[0] || *argv[m] == *sm[0] || *argv[m] == *rt[0]){
				return false;
			}
		}
		return true;       	
	}
	void perror(){
		std::cout << "-bash: [: missing ']'" << std::endl; 

	}	
};


#endif

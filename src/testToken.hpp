#ifndef TEST_TOKEN_HPP
#define TEST_TOKEN_HPP

#include "token.hpp"
#include <iostream>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>

class testToken: public Token {
        public:
        bool isExist(char **argv, int num){
		bool equal =false;
                int i = num;
                const char *Search[] = { "test" };
                if(*argv[i] == *Search[0]){
                	equal = true;
                }        
                return equal;
        }   
        void logic(char **argv, char **temp) {
        }
	
	bool isDir(char **str, int num )
	{
		bool path = false;
		struct stat buffer;
		if((stat(str[num], &buffer) == 0) && S_ISDIR(buffer.st_mode)){
			path = true;
		}
		return path;
	}
	bool isFile(char **str, int num)
        {
                bool path = false;
                struct stat buffer;
                if((stat(str[num], &buffer) == 0) && S_ISREG(buffer.st_mode)){
                        path = true;
                }
                return path;
        }
	bool isEfile(char **str, int num)
        {
                return isFile(str, num) || isDir(str, num);
        }
	bool found(char **str)
	{
		const char *f[] = {"test" , "-f" };
                const char *d[] = {"test" , "-d" };
                const char *e[] = {"test" , "-e"};
		int two = 2;
		int one = 1;
		if((strcmp(str[0], d[0]) == 0) && (strcmp(str[1], d[1]) == 0)){
			return isDir(str, two);
		}
		else if((strcmp(str[0], f[0]) == 0) && (strcmp(str[1], f[1]) == 0)) {
			return isFile(str, two);
		}
		else if((strcmp(str[0], e[0]) == 0) && (strcmp(str[1], e[1]) == 0)){	
			return isEfile(str, two);
		}
		else if(strcmp(str[0], e[0]) == 0) {
			return isEfile(str, one);
		}
	}
	bool tiscorrect(char **str) {
		cmdToken cmd;
		
		const char *f[] = {"test" , "-f" };
                const char *d[] = {"test" , "-d" };
                const char *e[] = {"test" , "-e"};
		
		if ((strcmp(str[0], e[0]) == 0) && ((strcmp(str[1], d[1]) == 0) || (strcmp(str[1], f[1]) == 0) ||(strcmp(str[1], e[1]) == 0)) && (cmd.isExist(str, 2) == true)) {
                        return false;
                }
                else if ((strcmp(str[0], e[0]) == 0) && (cmd.isExist(str, 1) == true)) {
                        return false;
                }
		return true;	
	}
	void test(char **str){
		
		cmdToken cmd;

		const char *f[] = {"test" , "-f" };
                const char *d[] = {"test" , "-d" };
                const char *e[] = {"test" , "-e"};

		if ((strcmp(str[0], e[0]) == 0) && ((strcmp(str[1], d[1]) == 0) || (strcmp(str[1], f[1]) == 0) ||(strcmp(str[1], e[1]) == 0)) && (cmd.isExist(str, 2) == true)) {
                        cout << "-bash: test: " << str[2] << ": binary operator expected" <<endl;
                }
                else if ((strcmp(str[0], e[0]) == 0) && (cmd.isExist(str, 1) == true)) {
                        cout << "-bash: test: " << str[1] << ": unary operator expected" <<endl;
                }
		else if(found(str)){
			cout << "(True)" <<endl;
		}
		else {
			cout << "(False)" <<endl ;
		}
	}
};

#endif

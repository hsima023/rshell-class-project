#ifndef TOKEN_HPP
#define TOKEN_HPP

class Token {
	public:
	Token() {};	
	virtual bool isExist(char** argv, int num) = 0; 
	virtual void logic(char** argv, char** temp) = 0;

};

#endif

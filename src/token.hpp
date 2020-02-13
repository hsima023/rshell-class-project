#ifndef TOKEN_HPP
#define TOKEN_HPP

Class Token {
	char *argv[];
	public:
	void setvalue(char **arg){
	*argv[] = *arg[];}
	bool isExist() = 0; 
	void logic() = 0;

};

#endif

#ifndef OR_TOKEN_H
#define OR_TOKEN_H
#include "token.h"

class orToken: public Token {
	public:
	orToken(char **argv);
	virtual void logic(char **argv);
};

#endif

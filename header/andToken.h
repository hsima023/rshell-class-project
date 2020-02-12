#ifndef AND_TOKEN_H
#define AND_TOKEN_H
#include "token.h"
#include "executor.h"

class andToken: public Token {
	public:
	andToken(char **argv){ };
	virtual void logic(char **argv);
};
#endif

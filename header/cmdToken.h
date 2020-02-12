#ifndef CMD_TOKEN_H
#define CMD_TOKEN_H
#include "token.h"
#include "executor.h"

class cmdToken: public token {
	public:
	cmdToken(char **argv);
	virtual void logic(char **argv);
};
#endif

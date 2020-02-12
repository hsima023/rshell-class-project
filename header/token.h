#ifndef TOKEN_H
#define TOKEN_H
#include <boost/tokenizer.hpp>
#include "tokenizer.h"

class Token {
	public:
	virtual void logic()=0;
};
#endif

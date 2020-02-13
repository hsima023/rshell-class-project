#ifndef __TOKENIZER_H__
#define __TOKENIZER_H__

#include <boost/tokenizer.hpp>
#include <iostream>

using namespace std;
using namespace boost;

void Tokenizer(string userInput,char **argv) {
	int i = 0;
        char_separator<char> space("\"; ");
        tokenizer<char_separator<char>> token(userInput, space);

	for (const auto& word : token) {

                argv[i] = new char[word.size() + 1];
                strcpy(argv[i], word.c_str());

                i++;
        }

        argv[i] = NULL;
}

#endif

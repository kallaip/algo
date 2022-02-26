#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <string>
#include <iostream>
#include <sstream>
/**
* Class Tokenizer : parsesinput string into "tokens" (functional parts), every call of next() method
* returns the next functionalunit, like parenthesis, operators or operands.
*/

class Tokenizer
{
    public:
        Tokenizer( std::string s );
        virtual ~Tokenizer();
        bool isOperator(char c);
        bool isAlphanum(char c);
        std::string next();

    private:
    std::stringstream inputString;
};

#endif // TOKENIZER_H

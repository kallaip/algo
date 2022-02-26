#include "Tokenizer.h"

Tokenizer::Tokenizer(std::string s)
{
    /** in the constructor we make stringstream (inputString) from the string we get as parameter,
    * this allows us to read the input char-by-char, input data waits for reading while next()
    * isn't called again
    */
    inputString << s;
}

Tokenizer::~Tokenizer()
{
}

bool Tokenizer::isOperator(char c)
{
    return c=='(' || c==')' || c=='+' || c=='-' || c=='*' || c=='/' || c=='^';
}

bool Tokenizer::isAlphanum(char c)
{
    return ( c>='0' && c<= '9') || (c>='a' && c <= 'z') || (c>='A' && c <= 'Z');
}

std::string Tokenizer::next()
{
    char c;
    std::string result("");

    // read bycharacters
    while (inputString >> c)
    {
        // operators or parenthesises are returning as a string, containing the single character
        if (isOperator(c))
        {
            result.push_back(c);
            break;
        }
        // if we find aplhanumeric characters, we collect them until another operator or paren found
        else if( isAlphanum(c) )
        {
            result.push_back(c);
            while( inputString >> c && !isOperator(c))
            {
                //we ignore every other characters, f.g. "hac ker" becomes "hacker"
                if (isAlphanum(c)) result.push_back(c);
            }
            //we have found a character which can be an operator, so put it back to the stream
            inputString.unget();
            break;
        }
        // every other characters are ignored silently
        else
        {
            continue;
        }
    }

    return result;
}

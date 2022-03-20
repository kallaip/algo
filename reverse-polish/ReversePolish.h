#ifndef REVERSEPOLISH_H
#define REVERSEPOLISH_H
#include <string>
#include <sstream>
#include "../stack/Stack.h"
class ReversePolish
{
    public:
        ReversePolish();
        ReversePolish(std::string inp);
        virtual ~ReversePolish();
        void Parse(std::string inp);
        int Solve();
        std::string getParsedString() { return parsedString.str(); }
        void setTrace(bool val) { trace=val; }
        bool isOperand(std::string s);
        bool isOperator(std::string s);
        int pr(std::string s);
        bool leftRightOperator(std::string s);
    protected:

    private:
        Stack<std::string> v;
        std::stringstream parsedString;
        bool trace = false;
};

#endif // REVERSEPOLISH_H

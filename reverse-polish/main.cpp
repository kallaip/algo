#include <iostream>
#include "../stack/Stack.h"
#include "Tokenizer.h"
using namespace std;

bool isOperand(string s);
bool isOperator(string s);
int pr(string s);

int main()
{
    Stack<string> s;


    string be(" (3 + 2)*8 -9 + cat * snail ");

    cout << be << endl;
    Tokenizer t(be);

    string x;

    //beginning of algorithm descibed in the diagram reverse-polish.png
    x = t.next();
    while ( x.length() > 0 )
    {


        if (isOperand(x))
        {
        }


        x = t.next();
    }

    cout << "End!" << endl;
    return 0;
}

bool isOperand(string s)
{
    return s.length()>0 || ( !isOperator(s) && s.compare("(")!=0 && s.compare(")")!=0 );
}

bool isOperator(string s)
{
    return   s.compare("+")==0 || s.compare("-")==0 || s.compare("^")==0 || s.compare("*")==0 || s.compare("/")==0;
}

int pr(string s)
{
    int result = 0;
    if (s.compare("+")==0 || s.compare("-")==0 )  result = 1;
    if (s.compare("*")==0 || s.compare("/")==0 )  result = 2;
    if (s.compare("^")==0) result = 3;
    return result;
}

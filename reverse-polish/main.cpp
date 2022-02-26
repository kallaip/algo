#include <iostream>
#include "../stack/Stack.h"
#include "Tokenizer.h"
using namespace std;

bool isOperand(string s);
bool isOperator(string s);
int pr(string s);
bool leftRightOperator(string s);

int main()
{
    const bool trace = false;


    Stack<string> v;
    string inp("");

    while (true)
    {
        cout << "Type expression ('quit' to quit): ";
        getline(cin, inp);
        if( inp.compare("quit")==0 || inp.compare("QUIT")==0 ) break;

        cout << "Input string: " << inp <<  endl;

        Tokenizer t(inp);
        string x;
        cout << "Translated to reverse polish notation: ";

        // ======= beginning of algorithm described in the diagram reverse-polish.png =========
        x = t.next();
        while ( x.length() > 0 )
        {
            if (isOperand(x))
            {
                if (trace) cerr << "Operand: " << x << endl;
                cout << x << " ";
            }
            else if ( x.compare("(")==0 )
            {
                if (trace) cerr << "Push: " << x << endl;
                v.push(x);
            }
            else if ( x.compare(")")==0 )
            {
                if (trace) cerr << "Closing: " << x  << endl;
                while ( v.top().compare("(") != 0 )
                {
                    cout << v.pop() << " ";
                } // while
                v.pop();
            }
            else if (isOperator(x))
            {

                if (leftRightOperator(x))
                {
                    if (trace) cerr << "Operator left: " << x  << endl;
                    while( !v.isEmpty() && v.top().compare("(") != 0 && pr(v.top()) >= pr(x) )
                        cout << v.pop() << " ";
                    v.push(x);
                }
                else
                { // leftRightOperator(x) = false
                    if (trace) cerr << "Operator Right: " << x  << endl;
                    while( !v.isEmpty() && v.top().compare("(") != 0 && pr(v.top()) > pr(x) )
                        cout << v.pop() << " ";
                    v.push(x);
                }
            } // else if

            x = t.next();
        } // while ( x.length() > 0 )

        while (!v.isEmpty())
            cout <<v.pop() << " ";
        cout << endl << "===============================================================" << endl;

        // ===================== end of algorithm ====================================

    } // while(true)

    cout << endl << "Bye!" << endl;
    return 0;
}

bool isOperand(string s)
{
    return s.length()>1 || ( !isOperator(s) && s.compare("(")!=0 && s.compare(")")!=0 );
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

bool leftRightOperator(string s)
{
    if (s.compare("^")==0) return false;
    return true;
}

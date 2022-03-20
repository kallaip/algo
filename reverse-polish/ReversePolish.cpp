#include "ReversePolish.h"
#include "Tokenizer.h"
using namespace std;

ReversePolish::ReversePolish()
{
}

ReversePolish::ReversePolish(std::string inp)
{
    Parse(inp);
}

ReversePolish::~ReversePolish()
{
}

void ReversePolish::Parse(std::string inp)
{
    Tokenizer t(inp);
    string x;
// ======= beginning of algorithm described in the diagram reverse-polish.png =========
    x = t.next();
    while ( x.length() > 0 )
    {
        if (isOperand(x))
        {
            if (trace) cerr << "Operand: " << x << endl;
            parsedString << x << " ";
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
                parsedString << v.pop() << " ";
            } // while
            v.pop();
        }
        else if (isOperator(x))
        {

            if (leftRightOperator(x))
            {
                if (trace) cerr << "Operator left: " << x  << endl;
                while( !v.isEmpty() && v.top().compare("(") != 0 && pr(v.top()) >= pr(x) )
                    parsedString << v.pop() << " ";
                v.push(x);
            }
            else
            { // leftRightOperator(x) = false
                if (trace) cerr << "Operator Right: " << x  << endl;
                while( !v.isEmpty() && v.top().compare("(") != 0 && pr(v.top()) > pr(x) )
                    parsedString << v.pop() << " ";
                v.push(x);
            }
        } // else if

        x = t.next();
    } // while ( x.length() > 0 )

    while (!v.isEmpty())
        parsedString <<v.pop() << " ";
    // ===================== end of algorithm ====================================
}

int ReversePolish::Solve()
{

return 0;
}

bool ReversePolish::isOperand(string s)
{
    return s.length()>1 || ( !isOperator(s) && s.compare("(")!=0 && s.compare(")")!=0 );
}

bool ReversePolish::isOperator(string s)
{
    return   s.compare("+")==0 || s.compare("-")==0 || s.compare("^")==0 || s.compare("*")==0 || s.compare("/")==0;
}

int ReversePolish::pr(string s)
{
    int result = 0;
    if (s.compare("+")==0 || s.compare("-")==0 )  result = 1;
    if (s.compare("*")==0 || s.compare("/")==0 )  result = 2;
    if (s.compare("^")==0) result = 3;
    return result;
}

bool ReversePolish::leftRightOperator(string s)
{
    if (s.compare("^")==0) return false;
    return true;
}

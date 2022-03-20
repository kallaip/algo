#include <iostream>
#include "../stack/Stack.h"
#include "Tokenizer.h"
#include "ReversePolish.h"
using namespace std;

int main()
{



    string inp("");

    while (true)
    {
        cout << "Usage: Type expression first, 'quit' to quit, " << endl
        << "'trace' to print every step, 'eval' to evaluate." << endl;
        cout << "Type expression or command: ";
        getline(cin, inp);
        if( inp.compare("quit")==0 || inp.compare("QUIT")==0 ) break;

        cout << "Input string: " << inp <<  endl;
        cout << "Translated to reverse polish notation: "<<ReversePolish(inp).getParsedString() << endl ;
        cout << endl << "===============================================================" << endl;


    } // while(true)

    cout << endl << "Bye!" << endl;
    return 0;
}



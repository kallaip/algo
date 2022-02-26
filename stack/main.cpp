#include <iostream>
#include "Stack.h"

using namespace std;

int main()
{
    Stack<int> v;
    v.push(3);
    v.push(4);
    v.push(137);

    try
    {
        cout << "Stack" << endl;
        cout << v.pop()
        << " Empty: " << (v.isEmpty()?"yes ":"no ")
        << v.top() << " "
        << v.pop() << " "
        << v.pop()
        << " Empty: " << (v.isEmpty()?"yes ":"no ")
        << endl;
        v.pop();
    }
    catch( Stack<int>::EmptyStackException * e)
    {
        cout << "Error: stack is empty" << endl;
    };


    return 0;
}

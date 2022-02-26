#ifndef STACK_H
#define STACK_H
#include <vector>
#include <stdbool.h>

// a template annyit tesz, hogy a typename után megadott szimbólum azt a típust veszi fel,
// amit a class alapján definiált változónál a <> jelek közé teszünk.
// pl: Stack<int> s; esetén a buf az intekből álló vector lesz.
// template osztály esetén a metódus definíciókat is az include file-ba tesszük
template <typename T>
class Stack
{
    public:
        class EmptyStackException : std::exception {};
        Stack() { buf = new std::vector<T>; };
        virtual ~Stack(){ delete buf; };

        void push(T element)
        {
            buf->push_back(element);
        };

        T pop()
        {
            if (buf->empty()) throw new EmptyStackException;
            T tmp;
            tmp = buf->back();
            buf->pop_back();
            return tmp;
        };

        T top()
        {
            if (buf->empty()) throw new EmptyStackException;
            return buf->back();
        };

        bool isEmpty()
        {
            return buf->empty();
        };

    private:
        std::vector<T> * buf;

};

#endif // STACK_H

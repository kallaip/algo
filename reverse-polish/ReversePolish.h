#ifndef REVERSEPOLISH_H
#define REVERSEPOLISH_H
#include <string>

class ReversePolish
{
    public:
        ReversePolish();
        virtual ~ReversePolish();
        void Parse(std::string inp);
        int Solve();
    protected:

    private:
};

#endif // REVERSEPOLISH_H

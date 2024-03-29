#ifndef TRANSITION_HPP
#define TRANSITION_HPP

#include "direction.hpp"
#include <string>
using namespace std;

class Transition
{
    private:
        string source;
        char read;
        string destination;
        char write;
        Direction move;
    public:
        Transition(string sourceState, char readChar, string destState, 
                char writeChar, Direction moveDir);
        string sourceState() const;
        char readChar() const;
        string destState() const;
        char writeChar() const;
        Direction moveDir() const;
};

#endif

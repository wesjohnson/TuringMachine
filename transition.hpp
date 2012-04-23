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
        Transition(string sourceState, char readChar, string destinationState, 
                char writeChar, Direction moveDirection);
        string SourceState() const;
        char ReadChar() const;
        string DestinationState() const;
        char WriteChar() const;
        Direction Move() const;
};

#endif

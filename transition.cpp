#include "transition.hpp"
#include "direction.hpp"
#include <string>
using namespace std;

Transition::Transition(string sourceState, char readChar, string 
        destinationState, char writeChar, Direction moveDirection):
    source(sourceState),
    read(readChar),
    destination(destinationState),
    write(writeChar),
    move(moveDirection)
{}

string Transition::sourceState() const
{
    return source;
}

char Transition::readChar() const
{
    return read;
}

string Transition::destState() const
{
    return destination;
}

char Transition::writeChar() const
{
    return write;
}

Direction Transition::moveDir() const
{
    return move;
}

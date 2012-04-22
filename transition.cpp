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

string Transition::SourceState() const
{
    return source;
}

char Transition::ReadChar() const
{
    return read;
}

string Transition::DestinationState() const
{
    return destination;
}

char Transition::WriteChar() const
{
    return write;
}

Direction Transition::Move() const
{
    return move;
}

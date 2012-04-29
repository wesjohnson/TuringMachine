/*  description:
 *      A transition defines what character the Turing machine will write,
 *      what state it will transition do, and what direction the tape head
 *      will move based off of the current state and character being read.
 *  functions:
 *      Transition(string sourceState, char readChar, string destinationState
 *          char writeChar, Direction moveDir)
 *      string sourceState() const
 *      char readChar() const
 *      string destState() const
 *      char writeChar() const
 *      Direction moveDir const
 *  module:
 *      transition
 *  files:
 *      transition.hpp
 *      transition.cpp
 *  language:
 *      C++
 *  computer:
 *      lab computers in West 151
 *  operating system:
 *      Ubuntu 10.04 LTS
 *  course:
 *      CPT S 322 -- Software Engineering
 *  author:
 *      Wes Johnson
 *  date:
 *      04/28/2012
 */
#include "transition.hpp"
#include "direction.hpp"
#include <string>
using namespace std;

Transition::Transition(string sourceState, char readChar, string 
        destinationState, char writeChar, Direction moveDir):
    source(sourceState),
    read(readChar),
    destination(destinationState),
    write(writeChar),
    move(moveDir)
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

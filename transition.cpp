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

/*  name: Transition(string sourceState, char readChar, string destState,
 *                   char writeChar, Direction moveDir)
 *  purpose: class constructor, initialize data members
 */
Transition::Transition(string sourceState, char readChar, string destState, 
        char writeChar, Direction moveDir):
    source(sourceState),
    read(readChar),
    destination(destState),
    write(writeChar),
    move(moveDir)
{}

/*  name: sourceState()
 *  purpose: return the attribute sourceState
 */
string Transition::sourceState() const
{
    return source;
}

/*  name: readChar()
 *  purpose: return the attribute read
 */
char Transition::readChar() const
{
    return read;
}

/*  name: destState()
 *  purpose: return the attribute destination
 */
string Transition::destState() const
{
    return destination;
}

/*  name: writeChar()
 *  purpose: return the attribute write
 */
char Transition::writeChar() const
{
    return write;
}

/*  name: moveDir()
 *  purpose: return the attribute move
 */
Direction Transition::moveDir() const
{
    return move;
}

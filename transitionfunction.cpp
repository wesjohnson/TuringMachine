/*  description:
 *      A transition function defines the behavior of a Turing machine on
 *      an input string. The TransitionFunction class is composed of any
 *      number of individual transitions. In a non deterministic Turing machine,
 *      there can be multiple transitions defined for particular source state
 *      and read character.  This program emulates a deterministic Turing.
 *      It is only valid for there to be a single transition defined for a
 *      particular source state and read character.
 *  functions:
 *      void load(ifstream& definition, bool& valid)
 *      void view() const
 *      int size() const
 *      string sourceState(int index) const
 *      char readChar(int index) const
 *      string destState(int index) const
 *      char writeChar(int index) const
 *      bool isDefintedTransition(string sourceState, char readChar,
 *          string& destinationState, char& writeChar,
 *          Direction& moveDirection) const
 *      bool isSourceState(string state) const
 *  module:
 *      transitionfunction
 *  files:
 *      transitionfunction.hpp
 *      transitionfunction.cpp
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
#include "transitionfunction.hpp"
#include "transition.hpp"
#include "direction.hpp"
#include "utilities.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

/*  name: load(ifstream& definition, bool& valid)
 *  purpose: parse the definition file, load the transitions into the
 *           transition function
 */
void TransitionFunction::load(ifstream& definition, bool& valid)
{
    string sourceState;
    string readChar;
    string destState;
    string writeChar;
    string direction;
    while( (definition >> sourceState) &&
            (Utilities::upperCase(sourceState) != "INITIAL_STATE:") )
    {
        definition >> readChar;
        definition >> destState;
        definition >> writeChar;
        definition >> direction;

        if((Utilities::upperCase(readChar) == "INITIAL_STATE:")
                || (Utilities::upperCase(destState) == "INITIAL_STATE:")
                || (Utilities::upperCase(writeChar) == "INITIAL_STATE:")
                || (Utilities::upperCase(direction) == "INITIAL_STATE:"))
        {
            cout << "Error: incomplete transition specified" << endl;
            valid = false;
            break;
        }
        if( (direction.size() != 1) || ((direction[0] != 'L') 
                    && (direction[0] != 'l') && (direction[0] != 'R')
                    && (direction[0] != 'r')) )
        {
            cout << "Error: invalid direction specified in a transition" 
                 << endl;
            valid = false;
        }

        if((readChar.size() == 1) && (writeChar.size() == 1) 
                && (direction.size() == 1))
        {
            Transition transition( sourceState, readChar[0], destState,
                    writeChar[0], direction[0]);
            transitions.push_back(transition);
        }
    }
}

/*  name: view()
 *  purpose: print the transitions to the screen, one per line
 */
void TransitionFunction::view() const
{
    cout << "( " <<transitions.front().sourceState() << ", " 
         << transitions.front().readChar() << " ) ->"
         << " ( " << transitions.front().destState() << ", "
         << transitions.front().writeChar() << ", "
         << transitions.front().moveDir() << " )" << endl;

    for( int i = 0; i < transitions.size() - 1; i++ )
    {
        cout << "                ( " <<transitions[i].sourceState() << ", " 
             << transitions[i].readChar() << " ) ->"
             << " ( " << transitions[i].destState() << ", "
             << transitions[i].writeChar() << ", "
             << transitions[i].moveDir() << " )" << endl;
    }
    cout << "                ( " <<transitions.back().sourceState() << ", " 
         << transitions.back().readChar() << " ) ->"
         << " ( " << transitions.back().destState() << ", "
         << transitions.back().writeChar() << ", "
         << transitions.back().moveDir() << " ) ";
}

/*  name: size()
 *  purpose: return the number of transitions
 */
int TransitionFunction::size() const
{
    return transitions.size();
}

/*  name: sourceState(int index)
 *  purpose: return the source state of a specific transition
 */
string TransitionFunction::sourceState(int index) const
{
    return transitions[index].sourceState();
}

/*  name: readChar(int index)
 *  purpose: return the read character of a specific transition
 */
char TransitionFunction::readChar(int index) const
{
    return transitions[index].readChar();
}

/*  name: destState(int index)
 *  purpose: return the destination state of a specific transition
 */
string TransitionFunction::destState(int index) const
{
    return transitions[index].destState();
}

/*  name: writeChar(int index)
 *  purpose: return the write character of a specific transition
 */
char TransitionFunction::writeChar(int index) const
{
    return transitions[index].writeChar();
}

/*  name: isDefinedTransition(string sourceState, char readChar,
 *                            string& destState, char& writeChar,
 *                            Direction& moveDir)
 *  purpose: return false if there is no transition for the specified read
 *           character and source state. return true and set the output
 *           parameters to the correct values if there is a matching transition
 */
bool TransitionFunction::isDefinedTransition(string sourceState, char readChar, 
        string& destState, char& writeChar, 
        Direction& moveDir) const
{
    for (int i = 0; i < transitions.size(); i++)
    {
        if ((transitions[i].sourceState() == sourceState) &&
                (transitions[i].readChar() == readChar))
        {
            destState = transitions[i].destState();
            writeChar = transitions[i].writeChar();
            moveDir = transitions[i].moveDir();
            return true;
        }
    }
    return false;
}

/*  name: isSourceState(string state)
 *  purpose: forgot to implement, i don't use it
 */
bool TransitionFunction::isSourceState(string state) const
{
    return false;
}

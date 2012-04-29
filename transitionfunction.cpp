#include "transitionfunction.hpp"
#include "transition.hpp"
#include "direction.hpp"
#include "utilities.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

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

int TransitionFunction::size() const
{
    return transitions.size();
}

string TransitionFunction::sourceState(int index) const
{
    return transitions[index].sourceState();
}

char TransitionFunction::readChar(int index) const
{
    return transitions[index].readChar();
}

string TransitionFunction::destState(int index) const
{
    return transitions[index].destState();
}

char TransitionFunction::writeChar(int index) const
{
    return transitions[index].writeChar();
}

bool TransitionFunction::isDefinedTransition(string sourceState, char readChar, 
        string& destinationState, char& writeChar, 
        Direction& moveDirection) const
{
    for (int i = 0; i < transitions.size(); i++)
    {
        if ((transitions[i].sourceState() == sourceState) &&
                (transitions[i].readChar() == readChar))
        {
            destinationState = transitions[i].destState();
            writeChar = transitions[i].writeChar();
            moveDirection = transitions[i].moveDir();
            return true;
        }
    }
    return false;
}
bool TransitionFunction::isSourceState(string state) const
{
    return false;
}

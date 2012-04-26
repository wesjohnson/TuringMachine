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
    Direction direction;
    while( (definition >> sourceState) &&
            (Utilities::upperCase(sourceState) != "INITIAL_STATE:") )
    {
        definition >> readChar;
        definition >> destState;
        definition >> writeChar;
        definition >> direction;

        Transition transition( sourceState, readChar[0], destState,
                writeChar[0], direction);
        transitions.push_back(transition);
    }
}

void TransitionFunction::view() const
{
    cout << "Transition Function:" << endl;
    for( int i = 0; i < transitions.size(); i++ )
    {
        cout << transitions[i].sourceState() << " " << transitions[i].readChar()
             << " " << transitions[i].destState() << " "
             << " " << transitions[i].writeChar() << " "
             << " " << transitions[i].moveDir() << endl;
    }
    cout << endl << endl;
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

string TransitionFunction::destinationState(int index) const
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

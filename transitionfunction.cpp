#include "transitionfunction.hpp"
#include "transition.hpp"
#include "direction.hpp"
#include <string>
#include <vector>
#include <fstream>
using namespace std;

void TransitionFunction::Load(ifstream& definition, bool& valid)
{}

void TransitionFunction::View() const
{}

int TransitionFunction::Size() const
{
    return transitions.size();
}

string TransitionFunction::SourceState(int index) const
{
    return transitions[index].SourceState();
}

char TransitionFunction::ReadChar(int index) const
{
    return transitions[index].ReadChar();
}

string TransitionFunction::DestinationState(int index) const
{
    return transitions[index].DestinationState();
}

char TransitionFunction::WriteChar(int index) const
{
    return transitions[index].WriteChar();
}

bool TransitionFunction::IsDefinedTransition(string sourceState, char readChar, 
        string& destinationState, char& writeChar, 
        Direction& moveDirection) const
{
    for (int i = 0; i < transitions.size(); i++)
    {
        if ((transitions[i].SourceState() == sourceState) &&
                (transitions[i].ReadChar() == readChar))
        {
            destinationState = transitions[i].DestinationState();
            writeChar = transitions[i].WriteChar();
            moveDirection = transitions[i].Move();
            return true;
        }
    }
    return false;
}
bool TransitionFunction::IsSourceState(string state) const
{
    return false;
}

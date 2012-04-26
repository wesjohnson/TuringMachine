#include "turingmachine.hpp"
#include "tape.hpp"
#include "inputalphabet.hpp"
#include "transitionfunction.hpp"
#include "tapealphabet.hpp"
#include "states.hpp"
#include "finalstates.hpp"
#include "inputstrings.hpp"
#include "utilities.hpp"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

TuringMachine::TuringMachine():
    valid(true),
    used(false),
    invalid(false),
    operating(false),
    accepted(false),
    rejected(false)
{}

TuringMachine::TuringMachine(string definitionFile)
{
    valid = true;
    used = false;
    invalid = false;
    operating = false;
    accepted = false;
    rejected = false;

    ifstream definition((definitionFile + ".def").c_str());

    string value;
    
    while( (definition >> value) && 
            (Utilities::upperCase(value) != "STATES:") )
    {
        description.push_back(value);
    }
    states.load(definition, valid);
    inputAlphabet.load(definition, valid);
    tapeAlphabet.load(definition, valid);
    transitionFunction.load(definition, valid);
    while( (definition >> value) &&
            (Utilities::upperCase(value) != "BLANK_CHARACTER:") )
        initialState = value;
    tape.load(definition, valid);
    finalStates.load(definition, valid);
}

void TuringMachine::ViewDefinition() const
{
    cout << "Description:" << endl;
    for(int i = 0; i < description.size(); i++)
    {
        cout << description[i] << " ";
    }
    cout << endl << endl;
    states.view();
    inputAlphabet.view();
    tapeAlphabet.view();
    transitionFunction.view();
    tape.view();
    finalStates.view();
}

void TuringMachine::TerminateOperation()
{
    operating = false;
    originalInputString = "";
}

bool TuringMachine::IsValid() const
{
    return true;
}

bool TuringMachine::IsUsed() const
{
    return used;
}

bool TuringMachine::IsOperating() const
{
    return operating;
}

bool TuringMachine::IsAcceptedInputString() const
{
    return accepted;
}

bool TuringMachine::IsRejectedInputString() const
{
    return rejected;
}

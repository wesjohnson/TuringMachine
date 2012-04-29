#include "turingmachine.hpp"
#include "tape.hpp"
#include "inputalphabet.hpp"
#include "transitionfunction.hpp"
#include "tapealphabet.hpp"
#include "states.hpp"
#include "finalstates.hpp"
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
    numTransitions = 0;
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
    for(int i = 0; i < inputAlphabet.size(); i++)
    {
        if(!(tapeAlphabet.isElement(inputAlphabet.element(i))))
        {
            cout << "Error: a character in the input alphabet is not in the "
                 << "tape alphabet" << endl;
            valid = false;
        }
    }
    transitionFunction.load(definition, valid);
    for(int i = 0; i < transitionFunction.size(); i++)
    {
        if(!(states.isElement(transitionFunction.sourceState(i))))
        {
            cout << "Error: invalid source state defined in a transition"
                 << endl;
            valid = false;
        }
        if(!(tapeAlphabet.isElement(transitionFunction.readChar(i))))
        {
            cout << "Error: invalid read character defined in a transition"
                 << endl;
            valid = false;
        }
        if(!(states.isElement(transitionFunction.destState(i))))
        {
            cout << "Error: invalid destination state defined in a transition"
                 << endl;
            valid = false;
        }
        if(!(tapeAlphabet.isElement(transitionFunction.writeChar(i))))
        {
            cout << "Error: invalid write character defined in a transition"
                 << endl;
            valid = false;
        }
    }
    bool initialStateSet = false;
    while( (definition >> value) &&
            (Utilities::upperCase(value) != "BLANK_CHARACTER:") )
    {
        if(!(states.isElement(value)))
        {
            cout << "Error: initial state is not a valid state" << endl;
            valid = false;
        }
        if(initialStateSet == false)
        {
            initialState = value;
            initialStateSet = true;
        }
        else
        {
            cout << "Error: multiple initial states specified" << endl;
            valid = false;
        }
    }
    tape.load(definition, valid);
    finalStates.load(definition, valid);
    for(int i = 0; i < finalStates.size(); i++)
    {
        if(!states.isElement(finalStates.element(i)))
        {
            cout << "Error: final state is not a valid state" << endl;
            valid = false;
        }
    }
}

void TuringMachine::viewDefinition() const
{
    cout << "Description:" << endl;
    for(int i = 0; i < description.size(); i++)
        cout << description[i] << " ";
    cout << endl << endl;
    cout << "Formal Definition:" << endl;
    cout << "M = (     Q = { ";
    states.view();
    cout << "}\n      Sigma = { ";
    inputAlphabet.view();
    cout << "}\n      Gamma = { ";
    tapeAlphabet.view();
    cout << "}\n      delta = { ";
    transitionFunction.view();
    cout << "}\n          b = ";
    tape.view();
    cout << "\n         q0 = " << initialState;
    cout << "\n          F = { ";
    finalStates.view();
    cout << " }\n    )" << endl;
}

void TuringMachine::viewInstantaneousDescription(int maxCells) const
{
    cout << tape.left(maxCells);
    cout << '[' << currentState << ']';
    cout << tape.right(maxCells) << endl;
}

void TuringMachine::initialize(string inputString)
{
    originalInputString = inputString;
    tape.initialize(inputString);
    currentState = initialState;
    numTransitions = 0;
    used = true;
    operating = true;
    accepted = false;
    rejected = false;
}

void TuringMachine::performTransitions(int maxTransitions)
{
    string destState;
    char writeChar;
    Direction moveDir;

    for(int i = 0; i < maxTransitions; i++)
    {
        if(transitionFunction.isDefinedTransition( currentState, 
                    tape.currentChar(), destState, writeChar, moveDir ))
        {
            tape.update( writeChar, moveDir );
            ++numTransitions;
            currentState = destState;
            if(finalStates.isElement(destState))
            {
                accepted = true;
                cout << "The input string was accepted" << endl;
                operating = false;
                return;
            }
        }
        else
        {
            rejected = true;
            cout << "The input string was rejected" << endl;
            operating = false;
            return;
        }
    }
}

void TuringMachine::terminateOperation()
{
    operating = false;
}

string TuringMachine::inputString() const
{
    return originalInputString;
}

int TuringMachine::totalTransitions() const
{
    return numTransitions;
}

bool TuringMachine::isValid() const
{
    return valid;
}

bool TuringMachine::isValidInputString(string value) const
{
    for(int i = 0; i < value.size(); i++)
    {
        if(!(inputAlphabet.isElement(value[i])))
            return false;
    }
    return true;
}

bool TuringMachine::isUsed() const
{
    return used;
}

bool TuringMachine::isOperating() const
{
    return operating;
}

bool TuringMachine::isAccepted() const
{
    return accepted;
}

bool TuringMachine::isRejected() const
{
    return rejected;
}

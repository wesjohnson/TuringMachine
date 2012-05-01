/*  description:
 *      A Turing machine processes an input string. The TuringMachine class
 *      provides this functionality to the Turing machine emulator. It is
 *      initialized from a definition file that must exist prior to running
 *      the program.  The TuringMachine class is composed of many other
 *      classes:
 *          Tape, InputAlphabet, TapeAlphabet, TransitionFunction,
 *          States, FinalStates
 *  functions:
 *      TuringMachine(string definitionFile)
 *      void viewDefinition() const
 *      void viewInstantaneousDescription(int maxCells) const
 *      void initialize(string inputString)
 *      void performTransitions(int maxTransitions)
 *      void terminateOperation()
 *      string inputString() const
 *      int totalTransitions() const
 *      bool isValid() const
 *      bool isValidInputString(string value) const
 *      bool isUsed() const
 *      bool isOperating() const
 *      bool isAccepted() const
 *      bool isRejected() const
 *  module:
 *      turingmachine
 *  files:
 *      turingmachine.hpp
 *      turingmachine.cpp
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
#include <cstdlib>

using namespace std;

/*  name: TuringMachine(string definitionFile)
 *  purpose: class constructor. call the load functions for all component
 *           classes, handle some error checking
 */
TuringMachine::TuringMachine(string definitionFile)
{
    numTransitions = 0;
    valid = true;
    used = false;
    operating = false;
    accepted = false;
    rejected = false;

    ifstream definition((definitionFile + ".def").c_str());
    if(!definition)
    {
        cout << "Error: no definition file found" << endl;
        exit(-1);
    }

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

/*  name: viewDefinition()
 *  purpose: print the description and formal definition of the loaded
 *           Turing machine. call the view() methods for component classes
 *           and provide pretty formatting
 */
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

/*  name: viewInstantaneousDescription(int maxCells)
 *  purpose: print a maximum of maxCells to left and right of current
 *           cell of the tape. shows you what the tape looks like when
 *           it is running
 */
void TuringMachine::viewInstantaneousDescription(int maxCells) const
{
    cout << tape.left(maxCells);
    cout << '[' << currentState << ']';
    cout << tape.right(maxCells) << endl;
}

/*  name: initialize(string inputString)
 *  purpose: call the initialize(string inputString) functions of component
 *           classes
 */
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

/*  name: performTransitions(int maxTransitions)
 *  purpose: perform up to maxTransitions number of transitions. if a final
 *           state is reached, stop performing transitions. reject input
 *           string if the Turing machine crashes
 */
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
                cout << "The input string " << originalInputString 
                     << " was accepted in " << numTransitions  << " transitions" 
                     << endl;
                operating = false;
                return;
            }
        }
        else
        {
            rejected = true;
            cout << "The input string " << originalInputString
                 << " was rejected in " << numTransitions << " transitions"
                 << endl;
            operating = false;
            return;
        }
    }
}

/*  name: terminateOperation()
 *  purpose: stop the Turing machine from operating further on an input
 *           string
 */
void TuringMachine::terminateOperation()
{
    operating = false;
}

/*  name: inputString()
 *  purpose: return the original input string, used for Show command
 */
string TuringMachine::inputString() const
{
    return originalInputString;
}

/*  name: totalTransitions()
 *  purpose: return the total transitions performed on the current input string
 */
int TuringMachine::totalTransitions() const
{
    return numTransitions;
}

/*  name: isValid()
 *  purpose: return the attribute valid
 */
bool TuringMachine::isValid() const
{
    return valid;
}

/*  name: isValidInputString(string value)
 *  purpose: check to if every character is either in the input alphabet
 *           or if the string is equl to \ (blank character)
 */
bool TuringMachine::isValidInputString(string value) const
{
    if((value.size() == 1) && (value[0] == '\\'))
        return true;
    for(int i = 0; i < value.size(); i++)
    {
        if(!(inputAlphabet.isElement(value[i])))
            return false;
    }
    return true;
}

/*  name: isUsed()
 *  purpose: return the attribute used
 */
bool TuringMachine::isUsed() const
{
    return used;
}

/*  name: isOperating()
 *  purpose: return the attribute operating
 */
bool TuringMachine::isOperating() const
{
    return operating;
}

/*  name: isAccepted()
 *  purpose: return the attribute accepted
 */
bool TuringMachine::isAccepted() const
{
    return accepted;
}

/*  name: isRejected()
 *  purpose: return the attribute rejected
 */
bool TuringMachine::isRejected() const
{
    return rejected;
}

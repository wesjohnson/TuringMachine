#include "deffile.hpp"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

void DefFile::insertDescription(string value)
{
    description.push_back(value);
}
void DefFile::setStates(vector<string> states)
{
    this->states = states;
}

void DefFile::insertState(string state)
{
    states.push_back(state);
}

void DefFile::setInputAlphabet(vector<char> inputAlphabet)
{
    this->inputAlphabet = inputAlphabet;
}

void DefFile::insertInputAlphabetChar(char inputAlphabetChar)
{
    inputAlphabet.push_back(inputAlphabetChar);
}

void DefFile::setTapeAlphabet(vector<char> tapeAlphabet)
{
    this->tapeAlphabet = tapeAlphabet;
}

void DefFile::insertTapeAlphabetChar(char tapeAlphabetChar)
{
    tapeAlphabet.push_back(tapeAlphabetChar);
}

void DefFile::setTransitionFunction(vector<string> transitionFunction)
{
    this->transitionFunction = transitionFunction;
}

void DefFile::insertTransition(string transition)
{
    transitionFunction.push_back(transition);
}

void DefFile::setInitialState(string initialState)
{
    this->initialState = initialState;
}

void DefFile::setBlankChar(char blankChar)
{
    this->blankChar = blankChar;
}

void DefFile::setFinalStates(vector<string> finalStates)
{
    this->finalStates = finalStates;
}

void DefFile::insertFinalState(string finalState)
{
    finalStates.push_back(finalState);
}

vector<string> DefFile::getStates()
{
    return states;
}

vector<char> DefFile::getInputAlphabet()
{
    return inputAlphabet;
}

vector<char> DefFile::getTapeAlphabet()
{
    return tapeAlphabet;
}

vector<string> DefFile::getTransitionFunction()
{
    return transitionFunction;
}

string DefFile::getInitialState()
{
    return initialState;
}

char DefFile::getBlankChar()
{
    return blankChar;
}

vector<string> DefFile::getFinalStates()
{
    return finalStates;
}

void DefFile::printDef()
{
    cout << "DESCRIPTION" << endl;
    for(int i = 0; i < description.size(); i++)
    {
        cout << description[i] << " ";
    }
    
    cout << endl << "STATES" << endl;
    for(int i = 0; i < states.size(); i++)
    {
        cout << states[i] << " ";
    }

    cout << endl << "INPUT ALPHABET" << endl;
    for(int i = 0; i < inputAlphabet.size(); i++)
    {
        cout << inputAlphabet[i] << " ";
    }

    cout << endl << "TAPE ALPHABET" << endl;
    for(int i = 0; i < tapeAlphabet.size(); i++)
    {
        cout << tapeAlphabet[i] << " ";
    }

    cout << endl << "TRANSITION FUNCTION" << endl;
    for(int i = 0; i < transitionFunction.size(); i++)
    {
        cout << transitionFunction[i] << " " << endl;
    }

    cout << endl << "INITIAL STATE" << endl;
    cout << initialState << endl;

    cout << endl << "BLANK CHARACTER" << endl;
    cout << blankChar << endl;

    cout << endl << "FINAL STATES" << endl;
    for(int i = 0; i < finalStates.size(); i++)
    {
        cout << finalStates[i] << " ";
    }
}

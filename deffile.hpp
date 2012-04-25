#ifndef DEFFILE_HPP
#define DEFFILE_HPP

#include <string>
#include <vector>
using namespace std;

class DefFile
{
    private:
        vector<string> description;
        vector<string> states;
        vector<char> inputAlphabet;
        vector<char> tapeAlphabet;
        vector<string> transitionFunction;
        string initialState;
        char blankChar;
        vector<string> finalStates;
    public:
        void insertDescription(string value);
        void setStates(vector<string> states);
        void insertState(string state);
        void setInputAlphabet(vector<char> inputAlphabet);
        void insertInputAlphabetChar(char inputAlphabetChar);
        void setTapeAlphabet(vector<char> tapeAlphabet);
        void insertTapeAlphabetChar(char tapeAlphabetChar);
        void setTransitionFunction(vector<string> transitionFunction);
        void insertTransition(string transition);
        void setInitialState(string initialState);
        void setBlankChar(char blankChar);
        void setFinalStates(vector<string> finalStates);
        void insertFinalState(string finalState);

        vector<string> getStates();
        vector<char> getInputAlphabet();
        vector<char> getTapeAlphabet();
        vector<string> getTransitionFunction();
        string getInitialState();
        char getBlankChar();
        vector<string> getFinalStates();

        void printDef();
};

#endif

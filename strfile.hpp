#ifndef STRFILE_HPP
#define STRFILE_HPP

#include <string>
#include <vector>

class StrFile
{
    private:
        vector<string> states;
        vector<char> inputAlphabet;
        vector<char> tapeAlphabet;
        vector<string> transitionFunction;
        string initialState;
        char blankChar;
        vector<string> finalStates;
    public:
        void setStates(vector<string> states);
        void setInputAlphabet(vector<char> inputAlphabet);
        void setTapeAlphabet(vector<char> tapeAlphabet);
        void setTransitionFunction(vector<string> transitionFunction);
        void setInitialState(string initialState);
        void setBlankChar(char blankChar);
        void setFinalStates(vector<string> finalStates);

        vector<string> getStates();
        vector<char> getInputAlphabet();
        vector<char> getTapeAlphabet();
        vector<string> getTransitionFunction();
        string getInitialState();
        char getBlankChar();
        vector<string> getFinalStates();
};

#endif

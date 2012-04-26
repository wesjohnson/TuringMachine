#ifndef TURINGMACHINE_HPP
#define TURINGMACHINE_HPP

#include "tape.hpp"
#include "inputalphabet.hpp"
#include "transitionfunction.hpp"
#include "tapealphabet.hpp"
#include "states.hpp"
#include "finalstates.hpp"
#include <string>
#include <vector>
using namespace std;

class TuringMachine
{
    private:
        Tape tape;
        InputAlphabet inputAlphabet;
        TapeAlphabet tapeAlphabet;
        TransitionFunction transitionFunction;
        States states;
        FinalStates finalStates;
        vector<string> description;
        string initialState;
        string currentState;
        string originalInputString;
        int numberOfTransitions;
        bool valid;
        bool used;
        bool invalid;
        bool operating;
        bool accepted;
        bool rejected;

    public:
        TuringMachine();
        TuringMachine(string definitionFile);
        void viewDefinition() const;
        void viewInstantaneousDescription(int maxCells) const;
        void initialize(string inputString);
        void performTransitions(int maxTransitions);
        void terminateOperation();
        string inputString() const;
        int totalNumberOfTransitions() const;
        bool isValid() const;
        bool isValidInputString(string value) const;
        bool isUsed() const;
        bool isOperating() const;
        bool isAcceptedInputString() const;
        bool isRejectedInputString() const;
};

#endif

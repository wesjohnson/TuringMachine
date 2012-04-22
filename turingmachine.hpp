#ifndef TURINGMACHINE_H
#define TURINGMACHINE_H

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
        bool invalid;
        bool operating;
        bool accepted;
        bool rejected;

    public:
        TuringMachine(string definitionFile);
        void ViewDefinition() const;
        void ViewInstantaneousDescription(int maxNumberOfCells) const;
        void Initialize(string inputString);
        void PerformTransitions(int maxNumberOfTransitions);
        void TerminateOperation();
        string InputString() const;
        int TotalNumberOfTransitions() const;
        bool IsValid() const;
        bool IsValidInputString(string value) const;
        bool IsUsed() const;
        bool IsOperating() const;
        bool IsAcceptedInputString() const;
        bool IsRejectedInputString() const;
};

#endif

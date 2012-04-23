#ifndef TRANSITIONFUNCTION_HPP
#define TRANSITIONFUNCTION_HPP

#include "transition.hpp"
#include "direction.hpp"
#include <string>
#include <vector>
#include <fstream>
using namespace std;

class TransitionFunction
{
    private:
        vector<Transition> transitions;
    public:
        void Load(ifstream& definition, bool& valid);
        void View() const;
        int Size() const;
        string SourceState(int index) const;
        char ReadChar(int index) const;
        string DestinationState(int index) const;
        char WriteChar(int index) const;
        bool IsDefinedTransition(string sourceState, char readChar, 
                string& destinationState, char& writeChar, 
                Direction& moveDirection) const;
        bool IsSourceState(string state) const;
};

#endif

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
        void load(ifstream& definition, bool& valid);
        void view() const;
        int size() const;
        string sourceState(int index) const;
        char readChar(int index) const;
        string destinationState(int index) const;
        char writeChar(int index) const;
        bool isDefinedTransition(string sourceState, char readChar, 
                string& destinationState, char& writeChar, 
                Direction& moveDirection) const;
        bool isSourceState(string state) const;
};

#endif

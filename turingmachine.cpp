#include "turingmachine.hpp"
#include "tape.hpp"
#include "inputalphabet.hpp"
#include "transitionfunction.hpp"
#include "tapealphabet.hpp"
#include "states.hpp"
#include "finalstates.hpp"
#include "inputstrings.hpp"
#include <string>
#include <vector>

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

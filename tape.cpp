#include "tape.hpp"
#include "direction.hpp"
#include "utilities.hpp"
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;

Tape::Tape():
    cells(" "),
    currentCell(0),
    blank(' ')
{}

void Tape::load(ifstream& definition, bool& valid)
{
    string value;
    if((definition >> value) && (value.length() == 1) && (value[0] != '\\')
        && (value[0] != '[') && (value[0] != ']') && (value[0] != '<')
        && (value[0] != '>') && (value[0] >= '!') && (value[0] <= '~'))
        blank = value[0];
    else
    {
        cout << "Illegal blank character. \n";
        valid = false;
    }
    
    if ( (!(definition >> value)) || 
            (Utilities::upperCase(value) != "FINAL_STATES:") )
    {
        cout << "Missing keyword after blank character. \n";
        valid = false;
    }
}

void Tape::view() const
{
    cout << "Blank Character:" << endl;
    cout << blank << endl << endl;
}

void Tape::initialize(string inputString)
{
    cells = inputString;
    currentCell = 0;
}

void Tape::update(char writeChar, Direction moveDirection)
{
    cells[currentCell] = writeChar;
    if (moveDirection == 'L')
        --currentCell;
    else
        ++currentCell;
}

char Tape::currentCharacter() const
{
    return cells[currentCell];
}

char Tape::blankCharacter() const
{
    return blank;
}

bool Tape::isFirstCell() const
{
    if(currentCell == 0)
        return true;
    return false;
}

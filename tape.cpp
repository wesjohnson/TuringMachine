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
    cells = inputString + blank;
    currentCell = 0;
}

void Tape::update(char writeChar, Direction moveDir)
{
    cells[currentCell] = writeChar;
    if (moveDir == 'L')
        --currentCell;
    else
    {
        ++currentCell;
        if(currentCell == cells.size())
            cells = cells + blank;
    }
    /*
    for(int i = 0; i < cells.size(); i++)
    {
        cout << cells[i];
    }
    cout << endl;
    */
}

string Tape::left(int maxCells) const
{
    string left;
    if(currentCell < maxCells)
        if(currentCell > 0)
            left = cells.substr(0, currentCell);
        else
            left = "";
    else
        left = cells;
    return left;
}

string Tape::right(int maxCells) const
{
    string right;
    if((currentCell + maxCells) < cells.size())
        right = cells;
    else
        right = cells.substr(currentCell, maxCells);
    return right;
}

char Tape::currentChar() const
{
    return cells[currentCell];
}

char Tape::blankChar() const
{
    return blank;
}

bool Tape::isFirstCell() const
{
    if(currentCell == 0)
        return true;
    return false;
}

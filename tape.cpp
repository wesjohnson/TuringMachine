#include "tape.hpp"
#include "direction.hpp"
#include "utilities.hpp"
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;

/*  name: Tape()
 *  purpose: default constructor
 */
Tape::Tape():
    cells(" "),
    currentCell(0),
    blank(' ')
{}

/*  name: load(ifstream& definition, bool& valid)
 *  purpose: parse the definition file, set the blank character
 */
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

/*  name: view()
 *  purpose: print the blank character to the screen
 */
void Tape::view() const
{
    cout << blank;
}

/*  name: initialize(string inputString)
 *  purpose: set the attribute cells to the inputString or to blank
 */
void Tape::initialize(string inputString)
{
    if((inputString.size() == 1) && (inputString[0] == '\\'))
        cells = blank + blank;
    else
        cells = inputString + blank;
    currentCell = 0;
}

/*  name: update(char writeChar, Direction moveDir)
 *  purpose: update the current cell with a new character, increment
 *           the current cell
 */
void Tape::update(char writeChar, Direction moveDir)
{
    if ( ((moveDir == 'L') || (moveDir == 'l')) && currentCell == 0 )
        return;
    cells[currentCell] = writeChar;
    if (moveDir == 'L')
        --currentCell;
    else
    {
        ++currentCell;
        if(currentCell == cells.size())
            cells = cells + blank;
    }
}

/*  name: left(int maxCells)
 *  purpose: return a string of up to maxCells, contents are the characters
 *           of the tape to the left of the current cell. truncate if there 
 *           are more characters than maxCells
 */
string Tape::left(int maxCells) const
{
    string left;
    if(currentCell < maxCells)
        if(currentCell > 0)
            left = cells.substr(0, currentCell);
        else
            left = "";
    else
        left = "<" + cells.substr((currentCell - maxCells), currentCell);
    return left;
}

/*  name: right(int maxCells)
 *  purpose: return a string of up to maxCells, contents are the characters
 *           of the tape including and to the right of the current cell. 
 *           truncate if there are more characters than maxCells
 */
string Tape::right(int maxCells) const
{
    string right;
    if((currentCell + maxCells) > cells.size())
        right = cells.substr(currentCell, maxCells);
    else
        right = cells.substr(currentCell, maxCells) + ">";
    return right;
}

/*  name: currentChar()
 *  purpose: return the character at the current cell
 */
char Tape::currentChar() const
{
    return cells[currentCell];
}

/*  name: blankChar()
 *  purpose: return the blank character
 */
char Tape::blankChar() const
{
    return blank;
}

/*  name: isFirstCell()
 *  purpose: return true if the current cell is the first one
 */
bool Tape::isFirstCell() const
{
    if(currentCell == 0)
        return true;
    return false;
}

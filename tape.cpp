#include "tape.hpp"
#include "direction.hpp"
#include "uppercase.hpp"
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

void Tape::Load(ifstream& definition, bool& valid)
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
    if ((!(definition >> value)) || (UpperCase(value) != "FINAL_STATES:"))
    {
        cout << "Missing keyword after blank character. \n";
        valid = false;
    }
}

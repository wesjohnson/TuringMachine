/*  description:
 *      The class FinalStates contains a string vector.  Each string in the 
 *      string vector identifies a final state.  If the Turing machine enters 
 *      a final state, the input string that it's currently operating on is
 *      accepted.
 *  functions:
 *      void load(ifstream& definition, bool& valid)
 *      void view() const
 *      void size() const
 *      string element(int index) const
 *      bool isElement(string value) const
 *  module:
 *      finalstates
 *  files:
 *      finalstates.hpp
 *      finalstates.cpp
 *  language:
 *      C++
 *  computer:
 *      lab computers in West 151
 *  operating system:
 *      Ubuntu 10.04 LTS
 *  course:
 *      CPT S 322 -- Software Engineering
 *  author:
 *      Wes Johnson
 *  date:
 *      04/28/2012
 */
#include "finalstates.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

void FinalStates::load(ifstream& definition, bool& valid)
{
    string value;
    while( (definition >> value) )
    {
        names.push_back(value);
    }
}

void FinalStates::view() const
{
    for(int i = 0; i < names.size(); i++)
        cout << names[i] << ", ";
}

int FinalStates::size() const
{
    return names.size();
}

string FinalStates::element(int index) const
{
    return names[index];
}

bool FinalStates::isElement(string value) const
{
    for(int i = 0; i < names.size(); i++)
    {
        if(value == names[i])
            return true;
    }
    return false;
}

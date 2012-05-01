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

/*  name: load(ifstream& definition, bool& valid)
 *  purpose: parse through the final states in the definition file
 */
void FinalStates::load(ifstream& definition, bool& valid)
{
    string value;
    while( (definition >> value) )
    {
        names.push_back(value);
    }
}

/*  name: view()
 *  print the final states to the screen
 */
void FinalStates::view() const
{
    for(int i = 0; i < names.size(); i++)
        cout << names[i] << ", ";
}

/*  name: size()
 *  return the number of final states
 */
int FinalStates::size() const
{
    return names.size();
}

/*  name: element(int index)
 *  purpose: return the state at the given index
 */
string FinalStates::element(int index) const
{
    return names[index];
}

/*  name: isElement(string value)
 *  purpose: determin if the given string is a final state
 */
bool FinalStates::isElement(string value) const
{
    for(int i = 0; i < names.size(); i++)
    {
        if(value == names[i])
            return true;
    }
    return false;
}

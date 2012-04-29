/*  description:
 *      The class States contains a string vector.  Each string in the string
 *      vector identifies a state that the Turing machine can enter.
 *  functions:
 *      void load(ifstream& definition, bool& valid)
 *      void view() const
 *      bool isElement(string value) const
 *  module:
 *      states
 *  files:
 *      states.hpp
 *      states.cpp
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
#include "states.hpp"
#include "utilities.hpp"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

void States::load(ifstream& definition, bool& valid)
{
    string value;
    while ( (definition >> value) && 
            (Utilities::upperCase(value) != "INPUT_ALPHABET:") )
    {
        for(int i = 0; i < value.size(); i++)
        {
            if( !(((value[i] > 64) && (value[i] < 91))
                        || ((value[i] > 96) && (value[i] < 123))
                        || ((value[i] > 47) && (value[i] < 58))
                        || (value[i] == '_')) )
            {
                cout << "Error: illegal character in a state" << endl;
                valid = false;
                break;
            }
        }
        if(isElement(value))
        {
            cout << "Error: duplicate states not allowed" << endl;
            valid = false;
        }
        else
            names.push_back(value);
    }
}

void States::view() const
{
    for(int i = 0; i < names.size(); i++)
    {
        cout << names[i] << ", ";
    }
}

bool States::isElement(string value) const
{
    for(int i = 0; i < names.size(); i++)
    {
        if(value == names[i])
            return true;
    }
    return false;
}

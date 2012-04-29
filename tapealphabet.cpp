/*  description:
 *      The tape alphabet contains a vector that holds all of the characters
 *      that can be written to or read from the Turing machine tape. It must,
 *      at a minimum, contain all of the characters in the input alphabet.
 *      Frequently though it includes other necessary characters.
 *  functions:
 *      void load(ifstream& definition, bool& valid)
 *      void view() const
 *      bool isElement(char value) const
 *  module:
 *      tapealphabet
 *  files:
 *      tapealphabet.hpp
 *      tapealphabet.cpp
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
#include "tapealphabet.hpp"
#include "utilities.hpp"
#include <string>
#include <vector>

void TapeAlphabet::load(ifstream& definition, bool& valid)
{
    string value;

    while( (definition >> value) &&
            (Utilities::upperCase(value) != "TRANSITION_FUNCTION:") )
    {
        if((value.size() == 1) && (value[0] != '\\') && (value[0] != '[') 
                && (value[0] != ']') && (value[0] != '<') && (value[0] != '>'))
            alphabet.push_back(value[0]);
        else
        {
            cout << "Error: illegal character in tape alphabet" << endl;
            valid = false;
        }
    }
}

void TapeAlphabet::view() const
{
    for(int i = 0; i < alphabet.size(); i++)
        cout << alphabet[i] << ", ";
}

bool TapeAlphabet::isElement(char value) const
{
    for(int i = 0; i < alphabet.size(); i++)
    {
        if(value == alphabet[i])
            return true;
    }
    return false;
}

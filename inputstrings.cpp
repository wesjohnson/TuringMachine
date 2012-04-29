/*  description:
 *      The class InputStrings contains a string vector that holds a list
 *      of input strings available for the Turing machine to operate on.
 *      If an input string file exists prior to running the Turing machine,
 *      its contents are loaded into the vector, but it is also valid to run
 *      the program without a pre-existing input string file. If any strings are
 *      added to or removed from the input string vector, the contents are
 *      written to the input string file when the program exits.
 *  functions:
 *      InputStrings(string strfile)
 *      void load(ifstream& str)
 *      void view() const
 *      int size() const
 *      void insert(string value)
 *      void del(int index)
 *      string element(int index) const
 *      bool isElement(string value) const
 *      bool isModified() const
 *  module:
 *      inputstrings
 *  file:
 *      inputstrings.cpp
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
#include "inputstrings.hpp"
#include "inputalphabet.hpp"
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

InputStrings::InputStrings(string strfile)
{
    //fstream str;
    //str.open((strfile + ".str").c_str(), fstream::in);
    ifstream str((strfile + ".str").c_str());
    if(str)
        load(str);
    str.close();
}

void InputStrings::load(ifstream& str)
{
    string value;
    while (str >> value)
    {
        strings.push_back(value);
    }
}

void InputStrings::view() const
{
    cout << "Input Strings:" << endl;
    for(int i = 0; i < strings.size(); i++)
    {
        cout << i + 1 << ":\t" << strings[i] << endl;
    }
}

int InputStrings::size() const
{
    return strings.size();
}

void InputStrings::insert(string value)
{
    strings.push_back(value);
    modified = true;
}

void InputStrings::del(int index)
{
    strings.erase(strings.begin() + index);
    modified = true;
}

string InputStrings::element(int index) const
{
    return(strings[index]);
}

bool InputStrings::isElement(string value) const
{
    for(int i = 0; i < strings.size(); i++)
    {
        if (value == strings[i])
            return true;
    }
    return false;
}

bool InputStrings::isModified() const
{
    return modified;
}

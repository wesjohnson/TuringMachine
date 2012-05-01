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

/*  name: InputStrings()
 *  purpose: default constructor
 */
InputStrings::InputStrings():
    modified(false)
{}

/*  name: load(string value)
 *  purpose: insert the given string into the input string list without
 *           changing the modified attribute to true
 */
void InputStrings::load(string value)
{
    strings.push_back(value);
}

/*  name: view()
 *  purpose: print the list of input strings with indices starting at 1
 */
void InputStrings::view() const
{
    cout << "Input Strings:" << endl;
    for(int i = 0; i < strings.size(); i++)
    {
        cout << i + 1 << ":\t" << strings[i] << endl;
    }
}

/*  name: size()
 *  purpose: return the number of input strings
 */
int InputStrings::size() const
{
    return strings.size();
}

/*  name: insert(string value)
 *  purpose: insert a new string into the list, mark list as modified
 */
void InputStrings::insert(string value)
{
    strings.push_back(value);
    modified = true;
}

/*  name: setModified(bool value)
 *  purpose: change the attribute modified to the given value
 */
void InputStrings::setModified(bool value)
{
    modified = value;
}

/*  name: del(int index)
 *  purpose: remove the input string at the given index from the list,
 *           mark list as modified
 */
void InputStrings::del(int index)
{
    strings.erase(strings.begin() + index);
    modified = true;
}

/*  name: element(int index)
 *  purpose: return the input string at the given index
 */
string InputStrings::element(int index) const
{
    return(strings[index]);
}

/*  name: isElement(string value)
 *  purpose: return true if the given string is already in the list
 */
bool InputStrings::isElement(string value) const
{
    for(int i = 0; i < strings.size(); i++)
    {
        if (value == strings[i])
            return true;
    }
    return false;
}

/*  name: isModified()
 *  purpose: return the value of the attribute modified
 */
bool InputStrings::isModified() const
{
    return modified;
}

#include "inputstrings.hpp"
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

InputStrings::InputStrings(string strfile)
{
    ifstream str((strfile + ".str").c_str());
    if(str)
        load(str);
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
        cout << strings[i] << endl;
    }
}

int InputStrings::size() const
{
    return strings.size();
}

void InputStrings::insert(string value)
{
    strings.push_back(value);
}

void InputStrings::del(int index)
{
    strings.erase(strings.begin() + index);
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

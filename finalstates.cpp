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
    cout << "Final States:" << endl;
    for(int i = 0; i < names.size(); i++)
    {
        cout << names[i] << " ";
    }
    cout << endl;
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

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
        names.push_back(value);
    }
}

void States::view() const
{
    cout << "States:" << endl;
    for(int i = 0; i < names.size(); i++)
    {
        cout << names[i] << " ";
    }
    cout << endl << endl;
}

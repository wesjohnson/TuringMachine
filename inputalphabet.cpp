#include "inputalphabet.hpp"
#include "utilities.hpp"
#include <vector>
#include <iostream>
using namespace std;

void InputAlphabet::load(ifstream& definition, bool& valid)
{
    string value;
    while( (definition >> value) && 
            (Utilities::upperCase(value) != "TAPE_ALPHABET:") )
    {
        if((value.size() == 1) && (value[0] != '\\') && (value[0] != '[') 
                && (value[0] != ']') && (value[0] != '<') && (value[0] != '>'))
            alphabet.push_back(value[0]);
        else
        {
            cout << "Error: illegal character in input alphabet" << endl;
            valid = false;
        }
    }
}

void InputAlphabet::view() const
{
    for(int i = 0; i < alphabet.size(); i++)
    {
        cout << alphabet[i] << ", ";
    }
}

int InputAlphabet::size() const
{
    return alphabet.size();
}

char InputAlphabet::element(int index) const
{
    return alphabet[index];
}

bool InputAlphabet::isElement(char value) const
{
    for(int i = 0; i < alphabet.size(); i++)
    {
        if(alphabet[i] == value)
            return true;
    }
    return false;
}

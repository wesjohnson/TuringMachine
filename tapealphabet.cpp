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

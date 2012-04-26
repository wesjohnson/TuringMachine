#include "inputalphabet.hpp"
#include "utilities.hpp"
#include <vector>
#include <iostream>
using namespace std;

void InputAlphabet::load(ifstream& definition, bool& valid)
{
    //definition.seekg(0, ios::beg);
    string value;
    /*
    while( (definition >> value) && 
            (Utilities::upperCase(value) != "INPUT_ALPHABET:") )
    {}
    */

    while( (definition >> value) && 
            (Utilities::upperCase(value) != "TAPE_ALPHABET:") )
    {
        alphabet.push_back(value[0]);
    }
}

void InputAlphabet::view() const
{
    cout << "Input Alphabet:" << endl;
    for(int i = 0; i < alphabet.size(); i++)
    {
        cout << alphabet[i] << " ";
    }
    cout << endl << endl;
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

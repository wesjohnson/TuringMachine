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
        alphabet.push_back(value[0]);
    }
}

void TapeAlphabet::view() const
{
    cout << "TapeAlphabet:" << endl;
    for(int i = 0; i < alphabet.size(); i++)
    {
        cout << alphabet[i] << " ";
    }
    cout << endl << endl;
}

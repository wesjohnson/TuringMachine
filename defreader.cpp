#include "defreader.hpp"
#include "deffile.hpp"
#include "utilities.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

DefReader::DefReader(string name)
{
    this->name = name + ".def";
    valid = false;

    parse();
    printDef();
}

void DefReader::parse()
{
    input.open(name.c_str());
    if(!input)
    {
        cout << "YOU SUCK" << endl;
        return;
    }
    int progress = 0;
    string value;
    while(input >> value)
    {
        if(Utilities::upperCase(value) == "STATES:")
        {
            progress = 1;
            input >> value;
        }
        if(Utilities::upperCase(value) == "INPUT_ALPHABET:")
        {
            progress = 2;
            input >> value;
        }
        if(Utilities::upperCase(value) == "TAPE_ALPHABET:")
        {
            progress = 3;
            input >> value;
        }
        if(Utilities::upperCase(value) == "TRANSITION_FUNCTION:")
        {
            progress = 4;
            input >> value;
        }
        if(Utilities::upperCase(value) == "INITIAL_STATE:")
        {
            progress = 5;
            input >> value;
        }
        if(Utilities::upperCase(value) == "BLANK_CHARACTER:")
        {
            progress = 6;
            input >> value;
        }
        if(Utilities::upperCase(value) == "FINAL_STATES:")
        {
            progress = 7;
            input >> value;
        }
        
        switch(progress)
        {
            case 0:
                def.insertDescription(value);
                break;
            case 1:
                def.insertState(value);
                break;
            case 2:
                def.insertInputAlphabetChar(value[0]);
                break;
            case 3:
                def.insertTapeAlphabetChar(value[0]);
                break;
            case 4:
                for(int i = 0; i < 4; i++)
                {
                    string trfunc;
                    input >> trfunc;
                    value = value + " " + trfunc;
                }
                def.insertTransition(value);
                break;
            case 5:
                def.setInitialState(value);
                break;
            case 6:
                def.setBlankChar(value[0]);
                break;
            case 7:
                def.insertFinalState(value);
                break;
        }
    }
    /*
    while(getline(input, value, ' '))
    {
        while(Utilities::upperCase(value) != "STATES")
            insertDefinition(value);
        while(Utilities::upperCase(value) != "INPUT_ALPHABET")
            insertState(value);
        while(Utilities::upperCase(value) != "TAPE_ALPHABET")
            insertInputAlphabetChar(value);
        while(Utilities::upperCase(value) != "TRANSITION_FUNCTION")
            insertTapeAlphabetChar(value);
        while(Utilities::upperCase(value) != "INITIAL_STATE")
            insertTransition(value);
        while(Utilities::upperCase(value) != "BLANK_CHARACTER")
            setInitialState(value);
        while(Utilities::upperCase(value) != "FINAL_STATES")
            setBlankChar(value);
        while(Utilities::upperCase(value))
    }
    */
}

void DefReader::printDef()
{
    def.printDef();
}

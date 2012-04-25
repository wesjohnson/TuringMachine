#include "strreader.hpp"
#include "strfile.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

StrReader::StrReader(string name)
{
    this->name = name + ".str";
    valid = false;

    parse();
}

void StrReader::parse()
{
    input.open(name.c_str());
    if(!input)
        cout << "YOU SUCK" << endl;
    else
    {
        string lineread;
        while(getline(input, lineread))
        {
            str.insert(lineread);
        }
    }
}

void StrReader::printStr()
{
    str.printStr();
}

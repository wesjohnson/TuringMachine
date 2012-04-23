#ifndef STRREADER_HPP
#define STRREADER_HPP

#include "strfile.hpp"
#include <string>
#include <iostream>
#include <fstream>

class StrReader
{
    private:
        ifstream input;
        string name;
        StrFile str;
        bool valid;
    public:
        StrReader(ifstream& input, string name);
        void Parse(ifstream& input);
};


#endif

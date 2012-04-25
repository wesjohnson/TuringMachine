#ifndef STRREADER_HPP
#define STRREADER_HPP

#include "strfile.hpp"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class StrReader
{
    private:
        ifstream input;
        string name;
        StrFile str;
        bool valid;
    public:
        StrReader(string name);
        void parse();
        void printStr();
};


#endif

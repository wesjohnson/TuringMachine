#ifndef DEFREADER_HPP
#define DEFREADER_HPP

#include "deffile.hpp"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class DefReader
{
    private:
        ifstream input;
        string name;
        DefFile def;
        bool valid;
    public:
        DefReader(string name);
        void parse();
        void printDef();
};


#endif

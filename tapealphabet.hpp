#ifndef TAPEALPHABET_HPP
#define TAPEALPHABET_HPP

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class TapeAlphabet
{
    private:
        vector<char> alphabet;
    public:
        void load(ifstream& definition, bool& valid);
        void view() const;
        bool isElement(char value) const;
};

#endif

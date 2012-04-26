#ifndef INPUTALPHABET_HPP
#define INPUTALPHABET_HPP

#include <fstream>
#include <vector>
using namespace std;

class InputAlphabet
{
    private:
        vector<char> alphabet;
    public:
        void load(ifstream& definition, bool& valid);
        void view() const;
        int size() const;
        char element(int index) const;
        bool isElement(char value) const;
};

#endif

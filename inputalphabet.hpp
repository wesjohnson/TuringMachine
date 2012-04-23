#ifndef INPUTALPHABET_HPP
#define INPUTALPHABET_HPP

#include<vector>
using namespace std;

class InputAlphabet
{
    private:
        vector<char> alphabet;
    public:
        void Load(ifstream& definition, bool& valid);
        void View() const;
        int Size() const;
        char Element(int index) const;
        bool IsElement(char value) const;
};

#endif

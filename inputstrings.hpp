#ifndef INPUTSTRINGS_HPP
#define INPUTSTRINGS_HPP

#include<string>
#include<vector>
using namespace std;

class InputStrings
{
    private:
        vector<string> strings;
    public:
        void Load(ifstream& definition, bool & valid);
        void View() const;
        int Size() const;
        void Insert(string value);
        void Delete(int index);
        string Element(int index) const;
        bool IsElement(string value) const;
};

#endif

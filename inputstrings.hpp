#ifndef INPUTSTRINGS_HPP
#define INPUTSTRINGS_HPP

#include <string>
#include <vector>
#include <fstream>
using namespace std;

class InputStrings
{
    private:
        vector<string> strings;
        bool modified;
    public:
        InputStrings();
        //InputStrings(string strfile);
        void load(string value);
        void view() const;
        int size() const;
        void insert(string value);
        void setModified(bool value);
        void del(int index);
        string element(int index) const;
        bool isElement(string value) const;
        bool isModified() const;
        //bool isValidInputString(string value) const;
};

#endif

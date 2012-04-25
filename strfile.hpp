#ifndef STRFILE_HPP
#define STRFILE_HPP

#include <string>
#include <vector>
using namespace std;

class StrFile
{
    private:
        vector<string> inputStrings;
        vector<char> inputAlphabet;
        char blankChar;
    public:
        void insert(string newString);
        void setInputAlphabet(vector<char> inputAlphabet);
        void setBlankChar(char blankChar);

        vector<string> getInputStrings();
        vector<char> getInputAlphabet();
        char getBlankChar();

        void printStr();
};

#endif

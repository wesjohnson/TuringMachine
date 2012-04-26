#include "strfile.hpp"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

void StrFile::insert(string newString)
{
    inputStrings.push_back(newString);
}

void StrFile::setInputAlphabet(vector<char> inputAlphabet)
{
    this->inputAlphabet = inputAlphabet;
}

void StrFile::setBlankChar(char blankChar)
{
    this->blankChar = blankChar;
}

vector<string> StrFile::getInputStrings()
{
    return inputStrings;
}

vector<char> StrFile::getInputAlphabet()
{
    return inputAlphabet;
}

char StrFile::getBlankChar()
{
    return blankChar;
}

void StrFile::printStr()
{
    for (int i = 0; i < inputStrings.size(); i++)
    {
        cout << inputStrings[i] << endl;
    }
}

#ifndef TAPE_HPP
#define TAPE_HPP

#include "direction.hpp"
#include <string>
#include <fstream>
using namespace std;

class Tape
{
    private:
        string cells;
        int currentCell;
        char blank;

    public:
        Tape();
        void load(ifstream& definition, bool& valid);
        void view() const;
        void initialize(string inputString);
        void update(char writeChar, Direction moveDir);
        string left(int maxCells) const;
        string right(int maxCells) const;
        char currentChar() const;
        char blankChar() const;
        bool isFirstCell() const;
};

#endif

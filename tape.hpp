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
        void update(char writeChar, Direction moveDirection);
        string left(int maxNumberOfCells) const;
        string right(int maxNumberOfCells) const;
        char currentCharacter() const;
        char blankCharacter() const;
        bool isFirstCell() const;
};

#endif

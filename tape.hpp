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
        void Load(ifstream& definition, bool& valid);
        void View() const;
        void Initialize(string inputString);
        void Update(char writeChar, Direction moveDirection);
        string Left(int maxNumberOfCells) const;
        string Right(int maxNumberOfCells) const;
        char CurrentCharacter() const;
        char BlankCharacter() const;
        bool IsFirstCell() const;
};

#endif

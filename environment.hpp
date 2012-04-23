#ifndef ENVIRONMENT_HPP
#define ENVIRONMENT_HPP

#include "turingmachine.hpp"
#include <string>
using namespace std;

class Environment
{
    private:
        bool toggleHelp;
        bool progRunning;
        string command;
        TuringMachine tm;
        int maxTransitions;
        int maxCells;
    public:
        Environment();
        void Spawn();
        void Help();
        void Show();
        void View();
        void List();
        void Insert();
        void Delete();
        void Set();
        void Truncate();
        void Run();
        void Quit();
        void Exit();
};

#endif

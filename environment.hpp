#ifndef ENVIRONMENT_HPP
#define ENVIRONMENT_HPP

#include "turingmachine.hpp"
#include "inputstrings.hpp"
#include <string>
using namespace std;

class Environment
{
    private:
        string tmName;
        bool toggleHelp;
        bool progRunning;
        string command;
        TuringMachine tm;
        int maxTransitions;
        int maxCells;
        InputStrings inputStrings;
    public:
        Environment(string name);
        void spawn();
        void del();
        void exitApp();
        void help();
        void insert();
        void list();
        void quit();
        void run();
        void set();
        void show();
        void truncate();
        void view();
};

#endif

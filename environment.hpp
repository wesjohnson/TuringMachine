#ifndef ENVIRONMENT_HPP
#define ENVIRONMENT_HPP

#include "turingmachine.hpp"
#include "defreader.hpp"
#include "strreader.hpp"
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
        //DefReader def;
        //StrReader str;
    public:
        Environment();
        Environment(string name);
        void spawn();
        void help();
        void show();
        void view();
        void list();
        void insert();
        void del();
        void set();
        void truncate();
        void run();
        void quit();
        void exitApp();
};

#endif

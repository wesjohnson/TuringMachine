#include "direction.hpp"
#include "transition.hpp"
#include "tape.hpp"
#include "transitionfunction.hpp"
#include "turingmachine.hpp"
#include "environment.hpp"
#include "strreader.hpp"
#include "strfile.hpp"
#include "defreader.hpp"
#include "deffile.hpp"
#include <string>

int main(int argc, char* argv[])
{
    //UserInterface test;// = new UserInterface();
    //TuringMachine test;
    //Environment env;
    //env.Spawn();
    //StrReader stread("tm");
    //stread.printStr();
    Environment env(argv[1]);
    env.spawn();
    //DefReader defread("tm");
    //defread.printDef();
    //stread.Parse();
    return 0;
}

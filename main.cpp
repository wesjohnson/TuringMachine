#include "direction.hpp"
#include "transition.hpp"
#include "tape.hpp"
#include "transitionfunction.hpp"
#include "turingmachine.hpp"
#include "environment.hpp"
#include <string>
#include <iostream>
#include <cstdlib>

int main(int argc, char* argv[])
{
    if(!(argv[1]))
    {
        cout << "Error: must specify a definition file" << endl;
        exit(-1);
    }
    Environment env(argv[1]);
    env.spawn();

    return 0;
}

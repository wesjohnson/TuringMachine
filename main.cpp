#include "direction.hpp"
#include "transition.hpp"
#include "tape.hpp"
#include "transitionfunction.hpp"
#include "turingmachine.hpp"
#include "environment.hpp"
#include <string>

int main(int argc, char* argv[])
{
    Environment env(argv[1]);
    env.spawn();

    return 0;
}

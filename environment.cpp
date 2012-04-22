#include"userinterface.hpp"
#include<iostream>
using namespace std;

UserInterface::UserInterface():
    toggleHelp(false)
{}

void UserInterface::Help()
{
    if (toggleHelp)
        toggleHelp = false;
    else
        toggleHelp = true;

    if (toggleHelp)
        cout << "Help messages are on\n";
}

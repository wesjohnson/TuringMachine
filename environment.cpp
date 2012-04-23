#include"environment.hpp"
#include<iostream>
//#include<sstream>
//#include<stdlib.h>
using namespace std;

Environment::Environment():
    progRunning(true),
    toggleHelp(false),
    command(""),
    maxTransitions(1),
    maxCells(32)
{}

void Environment::Spawn()
{
    cout << string(100, '\n');
    while(progRunning)
    {
        cout << "command: ";
        cin >> command; 
        if ((command == "D") || (command == "d"))
            Delete();
        else if ((command == "X") || (command == "x"))
            Exit();
        else if ((command == "H") || (command == "h"))
            Help();
        else if ((command == "I") || (command == "i"))
            Insert();
        else if ((command == "L") || (command == "l"))
            List();
        else if ((command == "Q") || (command == "q"))
            Quit();
        else if ((command == "R") || (command == "r"))
            Run();
        else if ((command == "E") || (command == "e"))
            Set();
        else if ((command == "W") || (command == "w"))
            Show();
        else if ((command == "T") || (command == "t"))
            Truncate();
        else if ((command == "V") || (command == "v"))
            View();
    }
}

void Environment::Delete()
{
    if (toggleHelp)
    {
        cout << "\nDeletes an input string from the input string list.\n"
             << "Enter the index of the input string you wish to delete.\n"
             << endl;
    }
}

void Environment::Exit()
{
    progRunning = false;
}

void Environment::Help()
{
    if (toggleHelp)
        toggleHelp = false;
    else
        toggleHelp = true;

    if (toggleHelp)
    {
        cout << "\n[D]elete:      delete input string from list\n"
             << "E[x]it:        exit the application\n"
             << "[H]elp:        togle the command help menu\n"
             << "[I]nsert:      insert an input string into list\n"
             << "[L]ist:        list the input string\n"
             << "[Q]uit:        quit the operation of the Turing machine\n"
             << "[R]un:         run Turing machine on input string\n"
             << "S[e]t:         set maximum number of transitions\n"
             << "Sho[w]:        show status of the application\n"
             << "[T]runcate:    truncate instantaneous descriptions\n"
             << "[V]iew:        view Turing machine\n" 
             << endl;
    }
}

void Environment::Insert()
{
    if (toggleHelp)
    {
        cout << "\nEnter an input string containing only characters from the\n"
             << "input alphabet.  If valid, this string will be appended to\n"
             << "the list of input strings.  If the string contains characters\n"
             << "not contained in the input alphabet, it will be discarded and\n"
             << "the input string list will remain unchanged.\n"
             << endl;
    }
}

void Environment::List()
{
    if (toggleHelp)
    {
        cout << "\nDisplays a list of all input strings available for the\n"
             << "Turing machine to run on.\n"
             << endl;
    }
}

void Environment::Quit()
{
    if (toggleHelp)
    {
        cout << "\nTerminates the operation of the Turing machine on the\n"
             << "current input string.  A message will appear informing the\n"
             << "user of the total number of transitions performed and the\n"
             << "original input string.  Operation will not continue from\n"
             << "the last state immediately prior quitting if the Run command\n"
             << "is chosen\n"
             << endl;
    }
    if (tm.IsOperating())
        tm.TerminateOperation();
    else
    {
        cout << "The Turing machine is not running and cannot be quit.\n"
             << endl;
    }
}

void Environment::Run()
{
    if (toggleHelp)
    {
        cout << "\nBegins or resumes the operation of the Turing machine on an\n"
             << "input string.  If the Turing machine is not already running,\n"
             << "a prompt will appear asking for the index of the desired input\n"
             << "string.  The Turing machine will perform the maximum number of\n"
             << "transitions specified by the Set command.\n"
             << endl;
    }
}

void Environment::Set()
{
    if (toggleHelp)
    {
        cout << "\nSets the maximum number of transitions for the Turing\n"
             << "machine to perform when the Run command is called.  The\n"
             << "value is 1.  The new value must be a positive integer.  If\n"
             << "no value is entered, the maximum number of transitions will\n"
             << "remain unchanged.\n"
             << endl;
    }
    cout << "Maximum number of transitions: ";
    //cin >> noskipws >> maxTransitions;
    cin >> maxTransitions;
}

void Environment::Show()
{
    if (toggleHelp)
    {
        cout << "\nDisplays the program's status information.\n"
             << endl;
    }

    cout << "\nCourse:        CPTS 322\n"
         << "Semester:      Spring\n"
         << "Year:          2012\n"
         << "Instructor:    Neil Corrigan, Phd\n"
         << "Author:        Wes Johnson\n"
         << "Version:       1.0\n"
         << "Help:          ";
    if (toggleHelp)
        cout << "Yes\n";
    else
        cout << "No\n";
    cout << "Maximum number of trasnitions: " << maxTransitions << "\n"
         << "Maximum number of left/right cells: " << maxCells << "\n"
         << "Status of Turing machine:\n" << endl;
}

void Environment::Truncate()
{
    string limit;
    char *str = new char;
    if (toggleHelp)
    {
        cout << "\nSets the maximum number of cells displayed to the left and\n"
             << "to the right of the tape head during display of an\n"
             << "instantaneous description.  The default value is 32.  The new\n"
             << "value must be a positive integer.  If no value is entered,\n"
             << "the maximum number of cells displayed will remain unchanged.\n"
             << endl;
    }
    cout << "Maximum number of cells: ";
    cin >> maxCells;
    //cin >> noskipws >> maxCells;
    //cin.get(maxCells, 20);
    //cin.getline(str, 100);
    //getline(cin, limit);
    //maxCells = atoi(str);
}

void Environment::View()
{
    if (toggleHelp)
    {
        cout << "\nDisplays the description of the Turing machine followed by\n"
             << "the formal definition.\n"
             << endl;
    }
}

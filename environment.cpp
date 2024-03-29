/*  description:
 *      The environment provides the user with a text based interface,
 *      handles all of the commands, some of the error checking,
 *      and initializes the TuringMachine and InputString classes
 *  functions:
 *      Environment(string name)
 *      void spawn()
 *      void del()
 *      void exitApp();
 *      void help()
 *      void insert()
 *      void list()
 *      void quit()
 *      void run()
 *      void set()
 *      void show()
 *      void truncate()
 *      void view()
 *  module:
 *      environment
 *  files:
 *      environment.hpp
 *      environment.cpp
 *  language:
 *      C++
 *  computer:
 *      lab computers in West 151
 *  operating system:
 *      Ubuntu 10.04 LTS
 *  course:
 *      CPT S 322 -- Software Engineering
 *  author:
 *      Wes Johnson
 *  date:
 *      04/28/2012
 */
#include "environment.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>
using namespace std;

/*  name: Environment(string name)
 *  purpose: Class constructor
 */
Environment::Environment(string name):
    tmName(name),
    tm(name),
    progRunning(true),
    toggleHelp(false),
    command(""),
    maxTransitions(1),
    maxCells(32)
{
    cout << "Turing machine " << tmName << " loaded" << endl;
    ifstream str((name + ".str").c_str());
    if(str)
    {
        string value;
        while(str >> value)
        {
            if(tm.isValidInputString(value))
                inputStrings.load(value);
            else
            {
                cout << "invalid input string has been discarded" << endl;
                inputStrings.setModified(true);
            }
        }
    }
    str.close();
}

/*  name: spawn()
 *  purpose: continually prompt user for input
 */ 
void Environment::spawn()
{
    if(!tm.isValid())
        exit(-1);
    while(progRunning)
    {
        cout << "command: ";
        getline(cin, command);
        command.erase(remove_if(command.begin(), command.end(), ::isspace), 
                command.end());
        if ((command == "D") || (command == "d"))
            del();
        else if ((command == "X") || (command == "x"))
            exitApp();
        else if ((command == "H") || (command == "h"))
            help();
        else if ((command == "I") || (command == "i"))
            insert();
        else if ((command == "L") || (command == "l"))
            list();
        else if ((command == "Q") || (command == "q"))
            quit();
        else if ((command == "R") || (command == "r"))
            run();
        else if ((command == "E") || (command == "e"))
            set();
        else if ((command == "W") || (command == "w"))
            show();
        else if ((command == "T") || (command == "t"))
            truncate();
        else if ((command == "V") || (command == "v"))
            view();
        else if ((command == ""))
        {}
        else
            cout << "Unrecognized command" << endl;
    }
}

/*  name: del()
 *  purpose: delete an input string from the list
 */
void Environment::del()
{
    if (toggleHelp)
    {
        cout << "\nDeletes an input string from the input string list.\n"
             << "Enter the index of the input string you wish to delete.\n"
             << endl;
    }
    string str;
    int index;
    cout << "index: ";
    getline(cin, str);
    if(str.size() > 0)
    {
        index = atoi(str.c_str());
        if((index > inputStrings.size()) || (index < 0))
            cout << "Not a valid input string index" << endl;
        else
           inputStrings.del((index - 1));
    }
}

/*  name: exitApp()
 *  purpose: write the input string list to a file if it has been modified,
 *           exit the application
 */ 
void Environment::exitApp()
{
    if(inputStrings.isModified())
    {
        ofstream str;
        str.open((tmName + ".str").c_str());
        for(int i = 0; i < inputStrings.size(); i++)
        {
            str << inputStrings.element(i) << '\n';
        }
        str.close();
        cout << "Input string file written" << endl;
    }
    progRunning = false;
}

/*  name: help()
 *  purpose: toggle the display of help messages
 */
void Environment::help()
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

/*  name: insert()
 *  purpose: insert a new string into the input string list
 */
void Environment::insert()
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
    string value;
    cout << "input string: ";
    getline(cin, value);
    if(value.size() > 0)
    {
        if(inputStrings.isElement(value))
            cout << "This string is already in the input string list" << endl;
        else if(tm.isValidInputString(value))
            inputStrings.insert(value);
        else
           cout << "String contains invalid characters" << endl;
    }
}

/*  name: list()
 *  purpose: print the contents of the input string list to the screen
 */
void Environment::list()
{
    if (toggleHelp)
    {
        cout << "\nDisplays a list of all input strings available for the\n"
             << "Turing machine to run on.";
    }
    cout << endl;
    inputStrings.view();
    cout << endl;
}

/*  name: quit()
 *  purpose: if the Turing machine is operating on a string, halt operation
 */
void Environment::quit()
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
    if (tm.isOperating())
    {
        tm.terminateOperation();
        cout << "Operation was terminated after " << tm.totalTransitions()
             << " transitions" << endl;
    }
    else
    {
        cout << "The Turing machine is not running and cannot be quit."
             << endl;
    }
}

/*  name: run()
 *  purpose: perform maxTransitions number of transitions, initialize with
 *           a new input string if Turing machine is not already running
 */
void Environment::run()
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
    if(!tm.isOperating())
    {
        string str;
        int index;
        cout << "index of input string: ";
        getline(cin, str);
        index = atoi(str.c_str());
        if(index <= inputStrings.size())
        {
            tm.initialize(inputStrings.element(index - 1));
            tm.viewInstantaneousDescription(maxCells);
            tm.performTransitions(maxTransitions);
            tm.viewInstantaneousDescription(maxCells);
        }
        else
        {
            cout << "error: invalid input string selected" << endl;
        }
    }
    else
    {
        tm.performTransitions(maxTransitions);
        tm.viewInstantaneousDescription(maxCells);
    }
}

/*  name: set()
 *  purpose: set the maximum number of transitions to perform
 */
void Environment::set()
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
    string str;
    int limit;
    cout << "Maximum number of transitions[" << maxTransitions << "]: ";
    getline(cin, str);
    limit = atoi(str.c_str());
    if(limit > 0)
        maxTransitions = limit;
    else
        cout << "error: invalid setting" << endl;
}

/*  name: show()
 *  purpose: print useful information about the Turing machine and its status
 */
void Environment::show()
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
    cout << "Maximum number of transitions: " << maxTransitions << "\n"
         << "Maximum number of left/right cells: " << maxCells << "\n"
         << "Status of Turing machine:\n";
    if(!(tm.isUsed()))
        cout << "    The Turing machine has not been run" << endl;
    else if (tm.isOperating())
    {
        cout << "    Original input string: " << tm.inputString() << endl;
        cout << "    Total transitions performed: " << tm.totalTransitions() 
             << endl;
    }
    else
    {
        cout << "    Last input string: " << tm.inputString() << endl;
        if ((tm.isAccepted()) && !(tm.isRejected()))
            cout << "    Input string was accepted." << endl;
        else if (!(tm.isAccepted()) && (tm.isRejected()))
            cout << "    Input string was rejected." << endl;
        else
            cout << "    Operation was terminated by the user." << endl;
        cout << "    Total transitions performed: " << tm.totalTransitions() 
             << endl;
    }
    cout << endl;
}

/*  name: truncate()
 *  purpose: set the number of cells to display during an instantaneous
 *           description
 */ 
void Environment::truncate()
{
    if (toggleHelp)
    {
        cout << "\nSets the maximum number of cells displayed to the left and\n"
             << "to the right of the tape head during display of an\n"
             << "instantaneous description.  The default value is 32.  The new\n"
             << "value must be a positive integer.  If no value is entered,\n"
             << "the maximum number of cells displayed will remain unchanged.\n"
             << endl;
    }
    string str;
    int limit;
    cout << "Maximum number of cells[" << maxCells << "]: ";
    getline(cin, str);
    limit = atoi(str.c_str());
    if(limit > 0)
        maxCells = limit;
    else
        cout << "error: invalid setting" << endl;
}

/*  name: view()
 *  purpose: print the description and formal definition of the Turing machine
 */
void Environment::view()
{
    if (toggleHelp)
    {
        cout << "\nDisplays the description of the Turing machine followed by\n"
             << "the formal definition.\n"
             << endl;
    }
    tm.viewDefinition();
    cout << endl;
}

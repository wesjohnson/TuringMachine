#ifndef USERINTERFACE_H
#define USERINTERFACE_H

using namespace std;

class UserInterface
{
    private:
        bool toggleHelp;
    public:
        UserInterface();
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

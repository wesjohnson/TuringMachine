#ifndef STATES_H
#define STATES_H

#include<string>
#include<vector>
using namespace std;

class States
{
    public:
       vector<string> names; 
    private:
       void Load(ifstream& definition, bool& valid);
       void View() const;
       bool IsElement(string value) const;
};

#endif

#ifndef STATES_H
#define STATES_H

#include <string>
#include <vector>
#include <fstream>
using namespace std;

class States
{
    private:
       vector<string> names; 
    public:
       void load(ifstream& definition, bool& valid);
       void view() const;
       bool isElement(string value) const;
};

#endif

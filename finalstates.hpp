#ifndef FINALSTATES_H
#define FINALSTATES_H

#include<string>
#include<vector>
using namespace std;

class FinalStates
{
    public:
        vector<string> names;
    private:
        void Load(ifstream& definition, bool& valid);
        void View() const;
        bool IsElement(string value) const;
};

#endif

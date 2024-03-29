#ifndef FINALSTATES_HPP
#define FINALSTATES_HPP

#include <string>
#include <vector>
using namespace std;

class FinalStates
{
    private:
        vector<string> names;
    public:
        void load(ifstream& definition, bool& valid);
        void view() const;
        int size() const;
        string element(int index) const;
        bool isElement(string value) const;
};

#endif

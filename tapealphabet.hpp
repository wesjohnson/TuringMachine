#ifndef TAPEALPHABET_HPP
#define TAPEALPHABET_HPP


using namespace std;

class TapeAlphabet
{
    private:
        vector<char> alphabet;
    public:
        void Load(ifstream& definition, bool& valid);
        void View() const;
        bool IsElement(char value) const;
};

#endif

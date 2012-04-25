#ifndef UPPERCASE_HPP
#define UPPERCASE_HPP

#include<string>
using namespace std;

string upperCase(string value)
{
    string capitals = value;
    for(int i = 0; i < capitals.size(); i++)
    {
        if( (capitals[i] > 96) && (capitals[i] < 123) )
        {
            capitals[i] += 32;
        }
    }
    return capitals;
}

#endif

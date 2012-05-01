#include "utilities.hpp"
#include <string>
using namespace std;

/*  name: upperCase(string value)
 *  purpose: return a string with the same letters except all upper case
 */
string Utilities::upperCase(string value)
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

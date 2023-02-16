#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <stack>
#include <deque>
#include <queue>
#include <sstream>

using namespace std;

int main()
{
    int x,y,z;
    string junk;
    string num,subnum;
    cin >> x;
    getline(cin,junk);
    int max = 0;
    for(int i=0; i<x; i++)
    {
        cin >> y;
        while(y>0)
        {
            z = __builtin_popcount(y);
            if(z > max)
             max = z;

            y=y/10;
        }
        cout << max << endl;
        max = 0;
    }
    


    return 0;
}

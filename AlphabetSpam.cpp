#include <bits/stdc++.h>

using namespace std;

int main()
{
    //Variables
    string line;
    getline(cin,line);
    double total=0;
    int upper=0,lower=0,symb=0,space=0;
    for(int i=0;i<line.length();i++)
    {
        total++;
        if(line[i]=='_')
            space++;
        else if(isalpha(line[i]))
            if(isupper(line[i]))
                upper++;
            else
                lower++;
        else
            symb++;
    }

    cout << space/total << endl;
    cout << lower/total << endl;
    cout << upper/total << endl;
    cout << symb/total << endl;

    //Code

    return 0;
}
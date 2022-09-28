#include <iostream>

using namespace std;

int main()
{
    char x;
    cin.get(x);
    while(x != '\n')
    {
        if(x=='e')
            cout << x << x;
        else 
            cout << x;
        cin.get(x);
    }

    return 0;
}
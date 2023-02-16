#include <iostream>

using namespace std;

int main()
{
    string month;
    cin >> month;
    int x;
    cin >> x;
    if(month == "OCT" && x ==31)
    {
        cout << "yup" << endl;   
    }
    else if(month == "DEC" && x == 25)
    {
        cout << "yup" << endl;   
    }
    else
        cout << "nope" << endl;

    return 0;
}
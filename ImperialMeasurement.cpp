#include <bits/stdc++.h>


using namespace std;

int convert(string in_stuff)
{
    if( in_stuff == "thou" || in_stuff == "th")
        return 0;
    else if( in_stuff == "inch" || in_stuff == "in")
        return 1;
    else if( in_stuff == "foot" || in_stuff == "ft")
        return 2;
    else if( in_stuff == "yard" || in_stuff == "yd")
        return 3;
    else if( in_stuff == "chain" || in_stuff == "ch")
        return 4;
    else if( in_stuff == "furlong" || in_stuff == "fur")
        return 5;
    else if( in_stuff == "mile" || in_stuff == "mi")
        return 6;
    else if( in_stuff == "league" || in_stuff == "lea")
        return 7;
    else 
        exit(1);
    cout << "error" << endl;
}

int main()
{
    double conversions[8] = {1, 1000, 12, 3, 22, 10, 8, 3};
    double num;
    int u_num1, u_num2;
    string junk, unit1, unit2;

    cin >> num >> unit1 >> junk >> unit2;
    u_num1 = convert(unit1);
    u_num2 = convert(unit2);


    if (u_num1 > u_num2)
    {
        for(int i=u_num1; i>u_num2; i--)
            num = num * conversions[i];
    }
    else
    {
        for(int i=u_num1; i<u_num2; i++)
            num = num / conversions[i+1]; 
    }

    cout << setprecision(10) << num << endl;
    


    return 0;
}
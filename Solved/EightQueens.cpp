#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

int main()
{
    vector<pair<int,int>> queens;
    string x;
    for(int i=0;i<8;i++)
    {
        getline(cin,x);
        for(int j=0; j<8; j++)
        {
            if(x[j] == '*')
            {
                queens.push_back(make_pair(i,j));
            }
        }
    }
    bool valid = true;
    if(queens.size() !=8 )
        valid = false;
    for(int i=0; i< queens.size()-1; i++)
    {
        if(!valid)
            break;
        //Checks rows and columns
        for(int j=i+1; j < queens.size(); j++)
        {
            if((queens[i].first==queens[j].first) || (queens[i].second == queens[j].second))
            {
                valid = false;
                break;
            }
            if(abs(queens[i].first-queens[j].first) == abs(queens[i].second-queens[j].second))
            {
                valid = false;
                break;
            }
        }   
    }
    if(valid)
        cout << "valid";
    else
        cout << "invalid";
    

    return 0;
}
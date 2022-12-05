#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //Variables
    int N,d;
    cin >> N >> d;
    string in_stuff;
    cin.ignore();
    getline(cin,in_stuff);

    stringstream ss(in_stuff);
    int num;
    unordered_map<int,int> mymap;
    unordered_set<int> myset;
    int count = 0;
    for(int i=0;i<N;i++)
    {
        ss >> num;
        if( !myset.insert(num/d).second)
            count++;
    }
    

    cout << count << endl;
    

    //Code

    return 0;
}
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <stack>
#include <deque>
#include <queue>
#include <sstream>
#include <map>
#include <set>


using namespace std;


void show(map<string, set<string> >& mapOfSet)
{
    // Using iterator to access
    // key, value pairs present
    // inside the mapOfSet
    for (auto it = mapOfSet.begin();
         it != mapOfSet.end();
         it++) {
  
        // Key is integer
        cout << it->first << " ";
  
        // Value is a set of string
        set<string> st = it->second;
  
        // Strings will be printed
        // in sorted order as set
        // maintains the order
        for (auto it = st.begin();
             it != st.end(); it++) {
            cout << (*it) << ' ';
        }
        cout << '\n';
    }
}




int main()
{
    int x,y,z;
    string order, name, food;
    bool found;
    map<string, set<string>> myMap;

    cin >> x;
    cin.ignore();
    while(x > 0)
    {
        for(int i=0;i<x;i++)
        {
            getline(cin,order);
            stringstream ss(order);
            ss >> name;
            while(ss >> food)
            {
                myMap[food].insert(name);
            }
        }

        show(myMap);
        cin >> x;
        cin.ignore();
        myMap.clear();
    }


    

    return 0;
}


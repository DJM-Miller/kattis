#include <iostream>
#include <set>
#include <map>


using namespace std;

int main()
{
    map<string, double> trees;
    string atree;
    double tree_count = 0;
    
    pair<map<string,double>::iterator,bool> in_map;
    getline(cin,atree);
    while(!atree.empty())
    {
        tree_count++;
        in_map = trees.insert( pair<string,double> (atree,1) );
        if (in_map.second == false)
        {
            trees[atree]++;
        }
        getline(cin,atree);
    }

    string junk;
    for(auto it = trees.begin();it != trees.end(); it++)
    {
       junk = it->first;
       cout << junk << " " << (it->second/tree_count)*100 << endl;
    }

    return 0;
}




//Exceeded time limit
/*
    multiset<string> trees;
    string tree_name;
    double tree_count = 0;
    getline(cin, tree_name);
    while(!tree_name.empty())
    {
        tree_count++;
        trees.insert(tree_name);
        getline(cin, tree_name);
    }

    string junk;
    for(auto it = trees.begin();it != trees.end(); it++)
    {
       junk = *it;
       cout << junk << " " << (trees.count(junk)/tree_count)*100 << endl;
       for(int i=0;i<trees.count(junk)-1;i++)
            *it++;
    }
*/
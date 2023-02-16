#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
    string str;
    stack<char> mystk;
    cin >> str;
    for(int i=0; i<str.length(); i++)
    {
        if(str[i] != '<')
            mystk.push(str[i]);
        else if(str[i] == '<')
            mystk.pop();
    }

    vector<char> mystrBackward;
    while(!mystk.empty())
    {
        mystrBackward.push_back(mystk.top());
        mystk.pop();
    }

    for(int i=mystrBackward.size()-1; i>=0; i--)
        cout << mystrBackward[i];
    return 0;
}
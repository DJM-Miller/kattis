#include <bits/stdc++.h>


using namespace std;

bool adventure(string line)
{
    stack<char> my_bag;
    for(int i=0; i < line.length(); i++)
    {
        if(line[i] == '$')
            my_bag.push('$');

        else if(line[i] == '|')
            my_bag.push('|');

        else if(line[i] == '*')
            my_bag.push('*');

        else if(line[i] == 't'){
            if(my_bag.empty() || my_bag.top() != '|')
                return false;
            else
                my_bag.pop();
        }
        else if(line[i] == 'j'){
            if(my_bag.empty() || my_bag.top() != '*')
                return false;
            else
                my_bag.pop();
        }
        else if(line[i] == 'b'){
            if(my_bag.empty() || my_bag.top() != '$')
                return false;
            else
                my_bag.pop();
        }
    }
    if(my_bag.empty())
        return true;
    else
        return false;
}

int main()
{
    int N;
    cin >> N;
    cin.ignore();
    for(int i=0; i<N; i++)
    {
        string line;
        getline(cin, line);
        if(adventure(line))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}
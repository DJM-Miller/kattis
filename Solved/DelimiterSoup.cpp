#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

int main()
{
    int Lsize;
    cin >> Lsize;
    string junk;
    getline(cin,junk);
    vector<char> thechars;
    char x;
    for(int i=0; i< Lsize; i++)
    {
        cin.get(x);
        //if(x != ' ')
            thechars.push_back(x);
    }


    int a,b,c;
    a=b=c=0;
    bool pass = true;
    int failpoint;
    stack<char> daStack;
    for(int i=0; i<thechars.size(); i++)
    {
        if(thechars[i] == '(')
            daStack.push(')');
        else if(thechars[i] == '[')
            daStack.push(']');
        else if(thechars[i] == '{')
            daStack.push('}');
       
        else if((thechars[i] == ')') || (thechars[i] == ']') || (thechars[i] == '}'))
        {
            if(daStack.empty())
            {
                failpoint = i;
                pass = false;
                break;
            }
            if(daStack.top() == thechars[i])
                daStack.pop();
            else if(thechars[i] != ' ')
            {
                failpoint = i;
                pass = false;
                break;
            }
        }
    }


/*
    for(int i=0; i<thechars.size(); i++)
    {
        if(thechars[i] == '(')
            a++;
        else if(thechars[i] == ')')
            a--;
        else if(thechars[i] == '[')
            b++;
        else if(thechars[i] == ']')
            b--;
        else if(thechars[i] == '{')
            c++;
        else if(thechars[i] == '}')
            c--;
        if( (a<0) || (b<0) || (c<0) )
        {
            pass = false;
            failpoint = i;
            char x = thechars[i];
            break;
        }
    }

    //At end checks that all 
    if(a<0 || b<0 || c<0)
            {
                pass = false;
                failpoint = thechars.size()-1;
                char x = thechars[failpoint];
            }
*/

    //Output
    if(pass)
        cout << "ok so far" << endl;
    else
        cout << thechars[failpoint] << ' ' << failpoint << endl;



    return 0;
}
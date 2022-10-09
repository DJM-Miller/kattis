///THIS THING IS UGLY!!!!!



#include <iostream>
#include <cstring>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
#include <stack>
#include <deque>
#include <queue>

using namespace std;

void display(deque<int> mydq, bool forward);
deque<int> extractIntegers(string str); 

int main()
{
    int test_cases,y,z;
    string command,x;
    deque<int> mydq;
    int n;
    cin >> test_cases;
    for(int a=0; a<test_cases;a++)
    {
        //initialize
        bool error = false;
        bool forward = true;
        mydq.clear();

        cin >> command;

       // getline(cin,x);//line with size of list
        //Fill initial deque
       // getline(cin,x);//reads list as string
       // mydq = extractIntegers(x);
        cin >> n;
        cin.ignore();
        for(int i = 0; i < n; i++) {
            cin.ignore();
            int t;
            cin >> t;
            mydq.push_back(t);
        }
        cin.ignore();
        if(n == 0) {
            cin.ignore();
        }


        for(int i=0; i<command.length();i++)
        {
            if(command[i] == 'R')
            {
                forward = !forward;
            }
            else if(command[i] == 'D')
            {
                if(mydq.empty())
                {
                    error = true;
                    break;
                }
                else
                {
                    if(forward)
                        mydq.pop_front();
                    else
                        mydq.pop_back();
                }
        
            }
        }
        
        if(error)
            cout << "error" << endl;
        else
        {
            //if(!mydq.empty())
                //display(mydq,forward);
                
             while(!mydq.empty()) {
                if(forward) {
                    cout << mydq.front();
                    mydq.pop_front();
                }
                else {
                    cout << mydq.back();
                    mydq.pop_back();
                }

                if(mydq.size() != 0) {
                    cout << ",";
                }
            }
            cout << "]" << endl;
        } 
    }



    return 0;
}





void display(deque<int> mydq, bool forward)
{
    if(forward)
    {
        cout << '[' << mydq[0];
        for(int i=1;i<mydq.size();i++)
            cout << ',' << mydq[i];
        cout << ']' << endl; 
    }
    else
    {
        cout << '[' << mydq[mydq.size()-1];
        for(int i=mydq.size()-2;i>=0;i--)
            cout << ',' << mydq[i];
        cout << ']' << endl;
    }
}



//https://www.geeksforgeeks.org/extract-all-integers-from-a-given-string/?ref=rp
deque<int> extractIntegers(string str)
{
    deque<int> temp;
    // This variable will store each founded
    // integer temporarily
    string tillNow = "";
    bool negative = false;
    for (int i = 0; i < str.size(); i++) {
        
        // If current character is an integer, then
        // add it to string tillNow
        if (str[i] - '0' >= 0 and str[i] - '0' <= 9) {
            tillNow += str[i];
        }

        else if(str[i] == '-')
            negative = true;
        
        // Otherwise, check if tillNow is empty or not
        // If it isn't then convert tillNow to integer
        // and empty it after printing
        else {
            if (tillNow.size() > 0) 
            {
                if(!negative)
                    temp.push_back(stoi(tillNow));
                else if(negative)
                    temp.push_back(-stoi(tillNow));
                tillNow = "";
                negative = false;
            }
        }
    }
 
    return temp;
}
//End code from https://www.geeksforgeeks.org/extract-all-integers-from-a-given-string/?ref=rp






















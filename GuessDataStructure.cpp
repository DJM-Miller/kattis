#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int main()
{
    int n, action, num;
    stack<int> mystack;
    queue<int> myqueue;
    priority_queue<int> myPQ;
    bool S, Q, P;

    while(cin >> n)
    {
        S = Q = P = true;
        for(int i=0;i<n;i++)
        {
            cin >> action;
            if (action == 1)
            {
                cin >> num;
                mystack.push(num);
                myqueue.push(num);
                myPQ.push(num);
            }
            else if (action == 2)
            {
                if(mystack.empty() && myqueue.empty() && myPQ.empty())
                    S = P = Q = false;
                cin >> num;
                //stack check
                if(!mystack.empty())
                    if(mystack.top() != num)
                    {
                        S=false;
                        mystack.pop();
                    }
                    else 
                        mystack.pop();

                //queue
                if(!myqueue.empty())
                    if(myqueue.front() != num)
                    {
                        Q=false;
                        myqueue.pop();
                    }
                    else
                        myqueue.pop();

                //Pqueue
                if(!myPQ.empty())
                    if(myPQ.top() != num)
                    {
                        P = false;
                        myPQ.pop();
                    }
                    else
                        myPQ.pop();
            }         
        }

        if( S && !Q && !P )
            cout << "Stack" << endl;
        else if(!S && Q && !P)
            cout << "Queue" << endl;
        else if(!S && !Q && P)
            cout << "Priority Queue" << endl;
        else if(!S && !Q && !P)
            cout << "Impossible" << endl;
        else
            cout << "Not Sure" << endl;

        while(!mystack.empty())
        {
            mystack.pop();
        }
        while(!myqueue.empty())
        {
            myqueue.pop();
        }
        while(!myPQ.empty())
        {
            myPQ.pop();
        }
       
    }


    return 0;
}







/*
    int n;
    int action;
    int x, s,q,p;
    stack<int> mystack;
    queue<int> myqueue;
    priority_queue<int> myPqueue;
    bool stk, que, pque;

    while(cin >> n)
    {
        stk = que = pque = true;
        for(int i=0;i<n;i++)
        {
            cin >> action;
            if(action == 1)
            {
                cin >> x;
                mystack.push(x);
                myqueue.push(x);
                myPqueue.push(x);
            }

            else if(action == 2)
            {
                cin >> x;

                if(mystack.top()==x || mystack.empty())
                {
                        stk = false;
                }
                else
                    mystack.pop();
                    
                if(myqueue.front()==x || myqueue.empty())
                {
                        que = false;
                }
                else
                    myqueue.pop();

                if(myPqueue.top()==x || myPqueue.empty())
                {
                        pque = false;
                }
                else
                    myPqueue.pop();
            }
        }
     
        if(stk == true && que != true && pque != true)
        {
            cout << "stack" << endl;
        }
        else if(stk != true && que == true && pque != true)
        {
            cout << "queue" << endl;
        }
        else if(stk != true && que != true && pque == true)
        {
            cout << "priority queue" << endl;
        }
        else if((pque==true&&que==true&&stk!=true)||(que==true&&stk==true&&pque!=true)||(pque==true&&stk==true&&que!=true))
        {
            cout << "not sure" << endl;
        }
        else
        {
            cout << "impossible" << endl;     
        }

        while(!mystack.empty())
            mystack.pop();
        while(!myqueue.empty())
            myqueue.pop();
        while(!myPqueue.empty())
            myPqueue.pop();
            
    }

*/

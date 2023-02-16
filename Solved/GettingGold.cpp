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

//Variables
int x,y,z;
string trash;
char junk;
int rows,columns;
string curr_row;
bool marked[51][51] = {false};
char arr[51][51];
int gold = 0;


int directions = 4; //4->up,down,left,right 8->u,d,l,r and corners
int dr[] = {0,0,1,-1,1,-1,1,-1};    //change in row
int dc[] = {1,-1,0,0,1,1,-1,-1};    //chnage in colum
void mark_neighbors(int r, int c)
{
    //cout << r << '-' << c << endl;
    bool safe = true;
    for(int k=0; k<directions; k++)
    {
        int newr = r + dr[k];
        int newc = c + dc[k];
        if(newr>=0 && newr<rows && newc>=0 && newc<columns)
        {
            if(arr[newr][newc] == 'T' )
            {
                //marked[newr][newc] = true;
                return;
            }
        }
    }

    for(int k=0; k<directions; k++)
    {
        int newr = r + dr[k];
        int newc = c + dc[k];
        if(newr>=0 && newr<rows && newc>=0 && newc<columns)
        if(!marked[newr][newc])
        {
            if(arr[newr][newc] == '#')
                marked[newr][newc] = true;
            else if(arr[newr][newc] == 'G' )
            {
                marked[newr][newc] = true;
                gold++;
                mark_neighbors(newr,newc);
            }
            else if(arr[newr][newc] == '.' )
            {
                marked[newr][newc] = true;
                mark_neighbors(newr,newc);
            }
        }
    }
    
}



int main()
{
  while(cin >> columns)
  {
    gold = 0;
    pair<int,int> pspot;
    cin >> rows;
    cin.ignore();
    for(int i=0;i<rows;i++)
    {
      for(int j=0;j<columns;j++)
      {
        marked[i][j] = false;
        cin.get(arr[i][j]);
        if(arr[i][j] == 'P')
        {
            pspot.first = i;
            pspot.second = j;
        }
      }
      cin.ignore();
    }



    marked[pspot.first][pspot.second] = true;
    mark_neighbors(pspot.first,pspot.second);

    cout << gold << endl;


    
  }


   

    return 0;
}



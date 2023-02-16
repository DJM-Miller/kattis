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


int directions = 4; //4->up,down,left,right 8->u,d,l,r and corners
int dr[] = {0,0,1,-1,1,-1,1,-1};    //change in row
int dc[] = {1,-1,0,0,1,1,-1,-1};    //chnage in colum
void mark_neighbors(int r, int c)
{
  for(int k=0; k<directions; k++)
  {
    int newr = r + dr[k];
    int newc = c + dc[k];
    if(newr>=0 && newr<rows && newc>=0 && newc<columns)
    {
      if(!marked[newr][newc] && (arr[newr][newc] == 'L' || arr[newr][newc] == 'C'))
      {
        marked[newr][newc] = true;
        mark_neighbors(newr,newc);
      }
    }
  }
}



int main()
{
  while(cin >> rows)
  {
    cin >> columns;
    cin.ignore();
    for(int i=0;i<rows;i++)
    {
      for(int j=0;j<columns;j++)
      {
        cin.get(arr[i][j]);
      }
      cin.ignore();
    }

    //Output array
    // for(int i=0; i<rows; i++)
    // {
    //   for(int j=0;j<columns;j++)
    //     cout << arr[i][j];
    //   cout << endl;
    // }
    int islands = 0;
    for(int i=0; i<rows; i++)
    {
      for(int j=0;j<columns;j++)
      {
          if(!marked[i][j] && (arr[i][j]=='L' || arr[i][j]=='C'))
          {
              marked[i][j]=true;
              islands++;
              mark_neighbors(i,j);
          }
      }
    }

    cout << islands <<endl;

  }


   

    return 0;
}



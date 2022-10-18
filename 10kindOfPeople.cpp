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
bool marked[1001][1001] = {false};
int arr[1001][1001];
int zone[1001][1001];
int curr_zone=0;


int directions = 4; //4->up,down,left,right 8->u,d,l,r and corners
int dr[] = {0,0,1,-1,1,-1,1,-1};    //change in row
int dc[] = {1,-1,0,0,1,1,-1,-1};    //chnage in colum
void mark_neighbors(int r, int c, int num)
{
    for(int k=0; k<directions; k++)
    {
        int newr = r + dr[k];
        int newc = c + dc[k];
        if(newr>=0 && newr<rows && newc>=0 && newc<columns)
        if(!marked[newr][newc])
        {
            if(arr[newr][newc]==num)
            {
                marked[newr][newc] = true;
                zone[newr][newc] = curr_zone;
                mark_neighbors(newr,newc,num);
            }
        }
    }
    
}



int main()
{
        cin >> rows;
        cin >> columns;
        cin.ignore();
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<columns;j++)
            {
                marked[i][j] = false;
                cin.get(junk);
                arr[i][j] = (int)junk-48;
            }
            cin.ignore();
        }

        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<columns;j++)
            {
                if(!marked[i][j])
                {
                    marked[i][j] = true;
                    curr_zone++;
                    zone[i][j] = curr_zone;
                    mark_neighbors(i,j,arr[i][j]);                 
                }
            }
        }
        // for(int i=0;i<rows;i++)
        // {
        //     for(int j=0;j<columns;j++)
        //     {
        //         cout << zone[i][j];
        //     }
        //     cout << endl;
        // }

        int n;
        int pos[4];
        cin >> n;
        for(int i=0;i<n;i++)
        {
            cin >> pos[0] >> pos[1] >> pos[2] >> pos[3];
            pos[0]--;
            pos[1]--;
            pos[2]--;
            pos[3]--;
            if(zone[pos[0]][pos[1]] !=  zone[pos[2]][pos[3]])
                cout << "neither" << endl;
            else 
            {
                if(arr[pos[0]][pos[1]] == 1)
                    cout << "decimal" << endl;
                else if(arr[pos[0]][pos[1]] == 0)
                    cout << "binary" <<endl;

            }
        }



    
    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, g, junk;
    vector<int> gnomes;
    int king;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> g;
        for(int j=0;j<g;j++)
        {
            cin >> junk;
            gnomes.push_back(junk);
        }

        for(int k=1;k<g-1;k++)
        {
            if(gnomes[k] < gnomes[k-1] || gnomes[k] > gnomes[k+1])
            {   
                if(gnomes[k] > gnomes[k+1])
                {
                    if(gnomes[k+1] < gnomes[k-1])
                    {
                        king = k+2;
                        break;
                    }
                }
                king = k+1;
                break;
            }
        }

        cout << king << endl;
        gnomes.clear();
    }
    

    return 0;
}
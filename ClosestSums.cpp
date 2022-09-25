/*
#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;



int main()
{
    vector<pair<int,int>> Final;
    string line;
    int case_count =0;
    while(getline(cin, line))
    {
        Final.clear();
        case_count++;
        if(line.empty())
            break;
        int n;
        n = stoi(line);
        
        
        int m, temp;
        vector<int> distinctNums;
        vector<int> compareNums;

        //cin >> n;
        for(int i = 0; i < n; i++)
        {
            cin >> temp;
            distinctNums.push_back(temp);
        }
        cin >> m;
        for(int i = 0; i < m; i++)
        {
            cin >> temp;
            compareNums.push_back(temp);
        }
        
        

        for(int k = 0; k<m; k++)
        {
            int closest = (distinctNums[0] + distinctNums[1]);
            for(int i=0; i<n-1; i++)
            {
                for(int j=1; j<n; j++)
                {
                    if((abs(compareNums[k] - (distinctNums[i] + distinctNums[j]))) < (abs(compareNums[k] - closest)))
                    {
                        closest = distinctNums[i] + distinctNums[j];
                    }
                }
            }
            Final.push_back(make_pair(compareNums[k],closest));
            //cout << "Closest sum to " << compareNums[k] << " is " << closest << endl;
        }
        getline(cin,line);

        cout << "Case " << case_count << ":" << endl;
        for(int i=0; i<Final.size();i++)
        {
        cout << "Closest sum to " << Final[i].first << " is " << Final[i].second << '.' << endl;
        }

    }
    
    

    return 0;
}
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n;
    int count = 1;
    while(cin >> n) {
        cout << "Case " << count << ":" << endl;
        count++;

        vector<int> v;
        v.resize(n);

        for(int i = 0; i < n; i++) {
            cin >> v[i];
        }

        int m;
        cin >> m;

        for(int i = 0; i < m; i++) {
            int target;
            cin >> target;
            int closest = v[0]+v[1];

            for(int j = 0; j < n; j++) {
                for(int k = j+1; k < n; k++) {
                    int sum = v[j] + v[k];
                    if(abs(sum - target) < abs(closest - target)) {
                        closest = sum;
                    }
                }
            }

            cout << "Closest sum to " << target << " is " << closest << "." << endl;
        }
    }
}
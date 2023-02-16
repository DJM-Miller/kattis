#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, t, total, temp;
    cin >> n >> t;
    vector<int> nums;
    for(int i=0;i<n;i++)
    {
        cin >> temp;
        nums.push_back(temp);
    }
    total = 0;
    temp = 0;
    for(int i=0;i<n;i++)
    {
        total += nums[i];
        if(total <= t)
            temp++;
        else
            break;
    }
    cout << temp << endl;

    return 0;
}
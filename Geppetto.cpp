#include <bits/stdc++.h>

using namespace std;



int main()
{

    int n, m, a, b;
	cin >> n >> m;
	unordered_set<int> masks;
	for (int i = 0; i < m; i++) 
	{
		cin >> a >> b;
		a--; b--;
		masks.insert((1 << a) | (1 << b));
	}

	int count = 0;
	for (int i = 0; i < (1 << n); i++) 
	{
		bool notfound = true;
		for (auto m : masks) {
			if ((i & m) == m) {
				notfound = false;
				break;
			}
		}

		if (notfound)
			count++;
	}

	cout << count << endl;


    return 0;
}
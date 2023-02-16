#include <iostream>
#include <string>

using namespace std;

int main()
{
	int x;
	string junk;
	cin >> x;
	cin >> x;
	getline(cin,junk);
	do{
		getline(cin,junk);
	}while(junk != "");
	
	cout << x;
	
	return 0;
}
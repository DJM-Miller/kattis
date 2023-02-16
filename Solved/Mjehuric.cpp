#include <iostream>
#include <string>
#include <iomanip>
#include <vector>


using namespace std;


void printNums(vector<int> nums)
{
	for(int i=0;i<nums.size();i++)
		cout << nums[i] << " ";
	cout << endl;
}

bool checkOrder(vector<int> nums)
{
	for(int i=0;i<nums.size()-1;i++)
	{
		if(nums[i] > nums[i+1])
			return false;
	}
	return true;
}


int main()
{
	
	
	vector<int> nums;
	int temp;
	string input, junk;
	
	//Read input
	getline(cin, input);
	stringstream ss(input);
	
	while(getline(ss,junk,' '))
	{
		nums.push_back(stoi(junk));
	}
	
	
	
	//Sort
	while(!checkOrder(nums))
	{
		for(int i=0; i<nums.size()-1; i++)
		{
			if(nums[i] > nums[i+1])
			{
				//swap
				temp = nums[i];
				nums[i] = nums[i+1];
				nums[i+1] = temp;
				printNums(nums);
			}
		}
	}

	return 0;
}
//"Stolen" from Drake Cullen
// thanks drake 

#include <bits/stdc++.h>

using namespace std;


int main() {
  int p,t,i,j; 

  //Input num P and T
  cin>>p>>t;

  //create vectors
  vector<string> v(p,""); 
  vector<vector<int>> vp(p);

  //Fill vp with input
  while(cin>>i>>j) {
    vp[i-1].push_back(j);
  }
  //Sort trees heard by each person
  for(int i=0; i<p; i++)
    sort(vp[i].begin(),vp[i].end());
  
  //create a string of each vector heard by each person
  for(int i=0; i<vp.size(); i++){
    for(int j=0; j<vp[i].size(); j++)
        v[i] += to_string(vp[i][j]) + "-"; 
  }

  //create a set that will hold each unique string
  set<string> s;
  for(int i=0; i<p; i++)
    s.insert(v[i]);

  cout<<s.size();
  return 0;
}

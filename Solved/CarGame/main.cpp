#include <bits/stdc++.h>

using namespace std;

//TypeDefs


int main()
{
    std::ios::sync_with_stdio(false);

    int N,M;
    cin >> N >> M;
    cin.ignore();
    string words[N];
    string license;
    for(int i=0;i<N;i++){
        cin >> words[i];
        transform(words[i].begin(),words[i].end(), words[i].begin(), ::tolower);
    }
    for(int i=0;i<M;i++){
        cin >> license;
        transform(license.begin(),license.end(),license.begin(), ::tolower);
        bool found = false;
        for(int j=0;j<N;j++){
            int y = 0;
            for(int x=0;x<words[j].length();x++){
                if(words[j][x] == license[y])
                {
                    y++;
                    if(y>=3){
                        found = true;
                        cout << words[j] << endl;
                        break;
                    }
                }
            }
            if(found)
                break;
        }
        if(!found)
            cout << "No valid word" << endl;
    }

    
 
    return 0;
}
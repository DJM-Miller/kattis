#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <stack>
#include <deque>
#include <queue>
#include <sstream>
#include <map>
#include <set>

using namespace std;

vector<int> RabinKarp(string pattern, const char text[], int q)
{
    vector<int> foundat;
    const int d = 10;
    int m = pattern.length();
    int n = strlen(text);
    int i, j;
    int p = 0;
    int t = 0;
    int h = 1;

    for (i = 0; i < m - 1; i++)
        h = (h * d) % q;

    for (i = 0; i < m; i++) 
    {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    for (i = 0; i <= n - m; i++) 
    {
        if (p == t) 
        {
            for (j = 0; j < m; j++) 
            {
                if (text[i + j] != pattern[j])
                {
                    break;
                }
            }
            if (j == m)
                foundat.push_back(i);
        }
        if (i < n - m) 
        {
            t = (d * (t - text[i] * h) + text[i + m]) % q;
            if (t < 0)
                t = (t + q);
        }
    }


    return foundat;

}

void Compute_bmt(const string pattern, pair<char,int>* &bmt, int &bmt_size)
{
    char unique_char[pattern.length()];
    int uni_count=0;
    bool add;

    //Find unique characters in pattern
    for(int i=0;i<pattern.length();i++)
    {
        add = true;
        for(int j=0;j<uni_count;j++)
        {
            if(unique_char[j]==pattern[i])
            {
                add = false;
                break;
            }
        }
        if(add)
        {
            unique_char[uni_count]=pattern[i];
            uni_count++;
        }
    }
    
    bmt = new pair<char,int>[uni_count+1];
    for(int i=0;i<uni_count;i++)
    {
        int furthest_index;
        bool found_once = false;
        for(int j=0;j<pattern.length()-1;j++)
        {
            if(unique_char[i]==pattern[j])
            {
                furthest_index = j;
                found_once = true;
            }
        }
        bmt[i].first = unique_char[i];
        if(found_once)
            bmt[i].second = pattern.length() - furthest_index - 1;
        else
            bmt[i].second = pattern.length();
    }

    bmt[uni_count].first = '*';
    bmt[uni_count].second = pattern.length();
    bmt_size = uni_count+1;
}

vector<int> Horspool(const char* text, const int fsize, const string pattern)
{  
    vector<int> foundat; 
    int bmt_size;
    pair<char,int> *bmt;
    Compute_bmt(pattern,bmt,bmt_size);

    int pat_size = pattern.length();
    int i = pat_size - 1; //text index started at length of pattern
    int j = pat_size - 1; //represents end of pattern index
    int shift;
    bool match;
    while( i < fsize )
    {
        if(text[i] == pattern[j])
        {
            match = true;
            for(int k=1; k<=(pat_size-1); k++)
            {
                if(text[i-k] != pattern[j-k])
                    match = false;
            }
            
        }
        shift = bmt[bmt_size-1].second;
        for(int k=0;k<bmt_size-1;k++)
        {
            if(text[i] == bmt[k].first)
                shift = bmt[k].second;
        }
        
        if(!match || (text[i] != pattern[j]))
        {
            i = i + shift;
        }
        else if(match)
        {
            foundat.push_back(i-(pattern.length()-1));
            i = i + shift;
        } 
    }

    return foundat;
}

void Compute_lps(const string pattern, int lps[])
{ 
    lps[0] = 0;                   
    int len = 0;
    int i=1;
    while (i<pattern.length()){
        if(pattern[i]==pattern[len]){   
            len++;
            lps[i] = len;
            i++;
        }
        else{                   
            if(len==0){         
                lps[i] = 0;
                i++;
            }
            else{              
                len = lps[len-1];
            }
        }
    }
}

vector<int> KMP(const char* text, const int fsize, const string pattern)
{
    int lps[pattern.length()];
    Compute_lps(pattern, lps);

    int n = strlen(text);
    int m = pattern.length();
    int i=0, j=0;

    vector<int> foundat;

    while((n-i) >= (m-j))
    {
        if(pattern[j] == text[i])
        {
            i++;
            j++;
        }
        if(j==m)
        {
            j = lps[j-1];
            foundat.push_back(i-pattern.length());
        }
        else if(i<n && pattern[j] != text[i])
        {
            if(j != 0)
            {
                j = lps[j-1];
            }
            else
                i = i + 1;
        }
    }

    return foundat;
}







int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    
    //Variables
    string pattern;
    string text;
    int fsize;

    //Code
    getline(cin,pattern);
    while(pattern != "")
    {
        getline(cin,text);

        // vector<int> indices = RabinKarp(pattern,text.c_str(),13);
        // for(int i =0;i<indices.size();i++)
        //     cout << indices[i] << " ";
        // cout << endl;
        // indices.clear();

        // vector<int> indices = Horspool(text.c_str(),text.length(),pattern);
        // for(int i =0;i<indices.size();i++)
        //     cout << indices[i] << " ";
        // cout << endl;
        // indices.clear();
        
        vector<int> indices = KMP(text.c_str(),text.length(),pattern);
        for(int i =0;i<indices.size();i++)
            cout << indices[i] << " ";
        cout << endl;
        indices.clear();
        

        getline(cin,pattern);
    }

    return 0;
}


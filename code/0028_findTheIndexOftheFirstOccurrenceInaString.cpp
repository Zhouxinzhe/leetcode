#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;

int strStr(string haystack, string needle) {
    int ans = -1;
    int p1 = 0, p2 = 0;
    int m = haystack.size();
    int n = needle.size();
    while(p1 <= (m - n))
    {
        if(haystack[p1] != needle[0])
        {
            p1++;
            continue;
        }
        else
        {
            while(p2 < n && haystack[p1+p2] == needle[p2]) p2++;
            if(p2 == n)
            {
                ans = p1;
                break;
            }
            else
            {
                p2 = 0;
                p1++;
            }
        }
    }
    return ans;
}

int KMP(string s, string p)
{
    int m = s.size(), n = p.size();
    if(n == 0) return 0;
    vector<int> next(n);
    for(int i = 1, j = 0; i < n; i++)
    {
        while(j && p[i] != p[j]) j = next[j-1];
        if(p[i] == p[j]) 
        {
            j++;
            next[i] = j;
        }
    }
    for(int i = 0, j = 0; i < m; i++)
    {
        while(j && s[i] != p[j]) j = next[j-1];
        if(s[i] == p[j]) j++;
        if(j == n) return i-n+1;
    }
    return -1;
}

int main()
{
    string haystack = "sadbutsad";
    string needle = "sad";
    cout<<KMP(haystack, needle);
    return 0;
}
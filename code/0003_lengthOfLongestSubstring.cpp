#include<cstring>
#include<unordered_map>
#include<vector>
#include<iostream>
using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> hash;
    int head = 0;
    int ans = 0;
    int length = 0;
    cout<<s.length()<<endl;
    for (size_t i = 0; i < s.length(); i++)
    {
        if(hash.find(s[i]) == hash.end() || hash.find(s[i])->second < head){
            length++;
        }
        else if (hash.find(s[i])->second == head)
        {
            if(length > ans) ans = length;
            head = head + 1;
        }
        else
        {
            if(length > ans) ans = length;
            head = hash[s[i]] + 1;
            length = i - head + 1;
        }
        hash[s[i]] = i;
    }
    if(length > ans) ans = length;
    return ans;
}

// official solution
int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> hash;
    int ans = 0, left = 0;
    int i;
    for(i = 0; i < s.length(); ++i){
        char cur = s[i];
        if(hash.count(cur)){
            ans = max(ans, i - left);
            left = max(left, hash[cur] + 1);
        }
        hash[cur] = i;
    }
    return max(ans, i - left);
}

int main()
{
    cout<<lengthOfLongestSubstring("ohvhjdml")<<endl;



    return 0;
}
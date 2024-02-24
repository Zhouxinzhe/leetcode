#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;

vector<int> findSubstring(string s, vector<string>& words) {
    int ls = s.size(), n = words.size(), m = words[0].size();
    unordered_map<string, int> hashtable;
    vector<int> ans;
    for (int i = 0; i < m && i + m*n <= ls; i++)
    {
        hashtable.clear();
        for (int j = 0; j < n; j++)
        {
            hashtable[s.substr(i+j*m, m)]++;
        }
        for (string& word: words)
        {
            hashtable[word]--;
            if(hashtable[word] == 0) hashtable.erase(word);
        }
        for (int j = i; j < ls - m*n + 1; j+=m)
        {
            if (j != i)
            {
                string word = s.substr(j+(n-1)*m, m);
                if(++hashtable[word] == 0) hashtable.erase(word);
                word = s.substr(j-m, m);
                if(--hashtable[word] == 0) hashtable.erase(word);
            }
            if(hashtable.empty()) ans.push_back(j); 
        }
    }
    return ans;
}

int main()
{
    string s = "a";
    vector<string> words = {"a"};
    vector<int> ans = findSubstring(s, words);
    for(int x : ans) cout<<x<<' ';
    return 0;
}
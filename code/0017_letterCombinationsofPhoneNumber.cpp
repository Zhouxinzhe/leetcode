#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;

unordered_map<int, vector<char>> dict;

void createDict()
{
    dict[2] = {'a', 'b', 'c'};
    dict[3] = {'d', 'e', 'f'};
    dict[4] = {'g', 'h', 'i'};
    dict[5] = {'j', 'k', 'l'};
    dict[6] = {'m', 'n', 'o'};
    dict[7] = {'p', 'q', 'r', 's'};
    dict[8] = {'t', 'u', 'v'};
    dict[9] = {'w', 'x', 'y', 'z'};
}

void dfs(string digits, int index, string str, vector<string> &ans)
{
    if(index == digits.length())
    {
        if(str.length() > 0) ans.push_back(str);
        return;
    }
    for (char x : dict[digits[index]-'0'])
    {
        str += x;
        dfs(digits, index+1, str, ans);
        str.pop_back();
    }
}

vector<string> letterCombinations(string digits) {
    createDict();
    vector<string> ans;
    string str = "";
    dfs(digits, 0, str, ans);
    return ans;
}

int main()
{
    string digits = "23456789";
    vector<string> ans = letterCombinations(digits);
    for (string s: ans)
    {
        cout<<s<<' ';
    }
    return 0;
}
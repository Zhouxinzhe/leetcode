#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;

void dfs(int left, int right, int n, string str, vector<string>& ans)
{
    if(left == n && right == n)
    {
        if(str.length()) ans.push_back(str);
        return;
    }
    if(left == right) dfs(left+1, right, n, str+'(', ans);
    if(right < left)
    {
        if(left < n) dfs(left+1, right, n, str+'(', ans);
        dfs(left, right+1, n, str+')', ans);
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> ans;
    dfs(0, 0, n, "", ans);
    return ans;
}

int main()
{
    int n = 8;
    vector<string> ans = generateParenthesis(n);
    cout<<'{';
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<'"'<<ans[i]<<'"';
        if(i != ans.size() - 1) cout<<", ";
    }
    cout<<'}'<<endl;
    return 0;
}
#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<cmath>
#include<cstring>
using namespace std;

bool isMatch(string s, string p) {
    int m = s.size();
    int n = p.size();

    auto matches = [&](int i, int j) {
        if (i == 0) return false;
        if (p[j - 1] == '.') return true;
        return s[i - 1] == p[j - 1];
    };

    vector<vector<bool>> f(m + 1, vector<bool>(n + 1));
    f[0][0] = true;
    for (int i = 0; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (p[j - 1] == '*') {
                if (matches(i, j - 1)) f[i][j] = (f[i - 1][j] || f[i][j - 2]);
                else f[i][j] = f[i][j - 2];
            }
            else 
            {
                if (matches(i, j)) f[i][j] = f[i - 1][j - 1];
            }
        }
    }
    return f[m][n];
}

bool isMatch(string s, string p) {
    return dfs(s, p, s.length()-1, p.length()-1);
}

bool dfs(string s,string p,int i,int j){
    if(i<0 && j<0) return true; //都匹配完了
    if(i<0) return p[j]=='*' ? dfs(s,p,i,j-2) : false; //当s被匹配完时，判断当前p是否为 ‘*’,是的话往左边移动j,否则就是p冗余了，返回false
    if(j<0) return false; //当p用完了，但s还有，直接false
    if(p[j] == '*') //看看p[j-1]是否为'.',是的话可以匹配，否则判断s[i]和p[j-1]是否相同
    {    
        if(p[j-1] =='.' || p[j-1] == s[i]) return dfs(s,p,i,j-2) || dfs(s,p,i-1,j);  //当可以匹配时，我们也可以选择不匹配，所以有两个分支
        else return dfs(s,p,i,j-2);  //无法匹配直接false
    }
    else if(p[j] == '.' || p[j] == s[i]) //s[i]==p[j]
    { 
        return dfs(s,p,i-1,j-1);
    }
    else  //s[i] != p[j]
    {
        return false;
    }
}
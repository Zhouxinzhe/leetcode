#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

// 动态规划
string longestPalindrome(string s) {
    string ans = s.substr(0, 1);
    int n = s.length();
    vector<vector<bool>> dp(n, vector<bool>(n));
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        dp[i][i] = true;
        for (int j = 0; j < i; j++) 
        {
            if(j == i-1) dp[j][i] = (s[j] == s[i]);
            else dp[j][i] = dp[j+1][i-1] && (s[j] == s[i]);
            if(dp[j][i] && i - j + 1 > max) 
            {
                max = i - j + 1;
                ans = s.substr(j, max);
            }
        }
    }
    return ans;
}

int main()
{
    string s = "ac";
    cout<<longestPalindrome(s)<<endl;

    return 0;
}
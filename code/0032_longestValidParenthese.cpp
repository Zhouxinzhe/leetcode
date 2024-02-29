#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<stack>
using namespace std;

int longestValidParentheses(string s) {
    stack<char> stc;
    int left = 0, right = 0;
    int ans = 0;
    int ans1 = 0, ans2 = 0;
    int tmp = 0;
    for (size_t i = 0; i < s.length(); i++)
    {
        char x = s[i];
        if(x == '(')
        {
            stc.push(x);
            left++;
        }
        else
        {
            if(left == right)
            {
                left = 0;
                right = 0;
                ans1 = max(ans1, tmp);
                tmp = 0;
                continue;
            }
            else
            {
                stc.pop();
                tmp += 2;
                right++;
                ans1 = max(ans1, tmp);
            }
        }
    }
    ans1 = max(ans1, tmp);
    tmp = 0;
    left = 0;
    right = 0;
    while(!stc.empty()) stc.pop();
    for (int i = s.length()-1; i >= 0; i--)
    {
        char x = s[i];
        if(x == ')')
        {
            stc.push(x);
            left++;
        }
        else
        {
            if(left == right)
            {
                left = 0;
                right = 0;
                ans2 = max(ans2, tmp);
                tmp = 0;
                continue;
            }
            else
            {
                stc.pop();
                tmp += 2;
                right++;
                ans2 = max(ans2, tmp);
            }
        }
    }
    ans2 = max(ans2, tmp);
    ans = min(ans1, ans2);
    return ans;
}

int main()
{
    string s = "(()(((()";
    cout<<longestValidParentheses(s);
    return 0;
}
#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<cmath>
#include<cstring>
using namespace std;

bool isPalindrome(int x) {
    if(x < 0) return false;
    string s = "";
    while(x > 0)
    {
        s += char('0' + x%10);
        x /= 10;
    }
    int l = (s.length() - 1) / 2;
    int r = s.length() / 2;
    while(l >= 0 && r < s.length() && s[l] == s[r]){l--; r++;}
    if(l == -1) return true;
    return false;
}

int main()
{
    int x = 0;
    cout<<isPalindrome(x)<<endl;
    return 0;
}
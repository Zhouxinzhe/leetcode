#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<stack>
using namespace std;

bool isValid(string s) {
    stack<char> stc;
    auto ismatch = [=](char x, char y){
        if(x == '(' && y == ')' || x == ')' && y == '(') return true;
        if(x == '[' && y == ']' || x == ']' && y == '[') return true;
        if(x == '{' && y == '}' || x == '}' && y == '{') return true;
        return false;
    };
    for (int i = 0; i < s.length(); i++)
    {
        if(s[i] == '(' || s[i] == '[' || s[i] == '{') stc.push(s[i]);
        else
        {
            if(stc.size() == 0) return false;
            char x = stc.top();
            if(ismatch(x, s[i])) stc.pop();
            else return false;
        }    
    }
    if(stc.size()) return false;
    return true;
}

int main()
{
    string s = "}";
    cout<<isValid(s)<<endl;
    return 0;
}
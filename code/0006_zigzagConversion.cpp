#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<cmath>
#include<cstring>
using namespace std;

string convert(string s, int numRows) {
    if(numRows == 1 || numRows >= s.length()) return s;
    string ans = "";
    int line = 0;
    int index1, index2;
    while (line < numRows)
    {
        if(line == 0){index1 = 0; index2 = -1;}
        else{index1 = line; index2 = (2*numRows-2)-line;}
        for (int i = 0; i < s.length(); i+=(2*numRows-2))
        {
            if(index1 + i < s.length()) ans += s[index1 + i];
            if(index2 != -1 && index2 != index1 && index2 + i < s.length()) ans += s[index2 + i];
        }
        line++;
    }
    return ans;
}

int main()
{
    return 0;
}
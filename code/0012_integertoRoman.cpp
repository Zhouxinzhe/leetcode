#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<cmath>
#include<cstring>
using namespace std;

string intToRoman(int num) {
    string ans;
    int i;
    int m = num / 1000;
    for(i = 0; i < m; i++) ans += 'M';
    num -= 1000 * m;
    if (num > 900)
    {
        ans += "CM";
        num -= 900;
    }
    int d = num / 500;
    for(i = 0; i < d; i++) ans += 'D';
    num -= 500 * d;
    if (num > 400)
    {
        ans += "CD";
        num -= 400;
    }
    int c = num / 100;
    for(i = 0; i < c; i++) ans += 'C';
    num -= 100 * c;
    if (num > 90)
    {
        ans += "XC";
        num -= 90;
    }
    int l = num / 50;
    for(i = 0; i < l; i++) ans += 'L';
    num -= 50 * l;
    if (num > 40)
    {
        ans += "XL";
        num -= 40;
    }
    int x = num / 10;
    for(i = 0; i < x; i++) ans += 'X';    
    num -= 10 * x;
    if (num == 9)
    {
        ans += "IX";
        return ans;
    }
    int v = num / 5;
    for(i = 0; i < v; i++) ans += 'V';
    num -= 5 * v;
    if(num == 4)
    {
        ans += "IV";
        return ans;
    }
    for(i = 0; i < num; i++) ans += 'I';
    return ans;
}

int main()
{
    int num = 0;
    cout<<intToRoman(num)<<endl;
    return 0;
}
#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<cmath>
#include<cstring>
using namespace std;

int myAtoi(string s) {
    int ans = 0;
    int index = 0;
    int sign = 1;
    int num;
    while(s[index] == ' ') index++;
    if(s[index] == '-' || s[index] == '+')
    {
        sign = s[index] == '-' ? -1 : 1;
        index++;
    }
    while(index < s.length())
    {
        if(s[index] >= '0' && s[index] <= '9')
        {
            num = int(s[index] - '0');
            if (sign == 1)
            {
                if(ans > INT32_MAX/10) return INT32_MAX;
                if(ans*10 > INT32_MAX - num) return INT32_MAX;
            }
            else
            {
                if(ans > INT32_MAX/10) return INT32_MIN;
                if(ans*10 - 1 >= INT32_MAX - num) return INT32_MIN;
            }
            ans = ans * 10 + num;
        }
        else break;
        index++;
    }
    return ans * sign;
}

int main()
{
    string s = "2147483648";
    cout<<myAtoi(s)<<endl;
    return 0;
}
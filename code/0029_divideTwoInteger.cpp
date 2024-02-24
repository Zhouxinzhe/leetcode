#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;

int divide(int dividend, int divisor) {
    if(dividend == INT32_MIN && divisor == -1) return INT32_MAX;
    if(dividend == 0) return 0;
    auto sign = [](int x){return x >= 0? 1: -1;};
    int s = sign(dividend) == sign(divisor) ? 1 : -1;
    dividend = abs(dividend);
    divisor = abs(divisor);
    int ans = 0;
    while(dividend > 0)
    {
        ans++;
        dividend -= divisor;
    }
    return ans;
}

int main()
{
    int dividend = 0;
    int divisor = 1;
    cout<<divide(dividend, divisor);
    return 0;
}
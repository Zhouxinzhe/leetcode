#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<cmath>
#include<cstring>
using namespace std;

int reverse(int x){
    if(x == INT32_MIN || x == 0) return 0;
    int sign = abs(x)/x;
    int ans = 0;
    x = abs(x);
    vector<int> nums;
    while(x > 0)
    {
        nums.push_back(x%10);
        x /= 10;
    }
    for (int num : nums)
    {
        if(ans > INT32_MAX/10.0) return 0;
        if(ans*10 > INT32_MAX - num) return 0;
        ans = 10*ans + num;
    }
    return ans * sign;
}

int main()
{
    int x = 100011;
    cout<<x<<endl;
    cout<<reverse(x)<<endl;
    return 0;
}
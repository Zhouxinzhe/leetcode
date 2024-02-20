#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    int p1 = 0, p2 = 1;
    int cur = nums[p1];
    while (p2 < nums.size())
    {
        while(p2 < nums.size() && nums[p2] == cur) p2++;
        if(p2 == nums.size()) break;
        p1++;
        nums[p1] = nums[p2];
        cur = nums[p1];
        p2++;
    }
    return p1 + 1;
}

int main()
{
    vector<int> nums = {1,1};
    cout<<removeDuplicates(nums);
    return 0;
}
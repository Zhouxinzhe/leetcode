#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;

int removeElement(vector<int>& nums, int val) {
    int p1 = 0, p2 = 0;
    int cur = nums[p1];
    while(p2 < nums.size())
    {
        while(p2 < nums.size() && nums[p2] == val) p2++;
        if(p2 == nums.size()) break;
        nums[p1] = nums[p2];
        p1++;
        p2++;
    }
    return p1;
}

int main()
{
    vector<int> nums = {3,2,2,3};
    int val = 3;
    cout<<removeElement(nums, val);
    return 0;
}
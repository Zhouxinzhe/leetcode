#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;

void nextPermutation(vector<int>& nums) {
    if(nums.size() == 1) return;
    int p = nums.size() - 1;
    int index;
    p--;
    while(p >= 0)
    {
        if(nums[p] >= nums[p+1]) p--;
        else
        {
            index = p+1;
            while(index < nums.size() && nums[index] > nums[p]) index++;
            index--;
            swap(nums[p], nums[index]);
            break;
        }
    }
    reverse(nums.begin()+p+1, nums.end());
}

int main()
{
    vector<int> nums = {1,2};
    nextPermutation(nums);
    for(int num: nums) cout<<num<<' ';
    return 0;
}
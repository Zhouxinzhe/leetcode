#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int ans = INT16_MAX;
    int d = INT16_MAX;
    for (int i = 0; i < nums.size()-2; i++)
    {
        if(i > 0 && nums[i] == nums[i-1]) continue;
        int j = i+1, k = nums.size()-1;
        while(j < k)
        {
            int sum = nums[i] + nums[j] + nums[k];
            if(abs(sum - target) < d)
            {
                ans = sum;
                d = abs(sum - target);
                if(d == 0) return ans;
            }
            if(sum > target)
            {
                int tmp = nums[k];
                while(j < k && nums[k] == tmp) k--;
            }
            else
            {
                int tmp = nums[j];
                while(j < k && nums[j] == tmp) j++;
            }
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = {4,0,5,-5,3,3,0,-4,-5};
    int target = -2;
    cout<<threeSumClosest(nums, target)<<endl;    
    return 0;
}
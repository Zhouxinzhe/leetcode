#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int l, r, target, index;
    vector<vector<int>> ans;
    for (l = 0; l < nums.size()-2; l++)
    {
        if(l > 0 && nums[l] == nums[l-1]) continue;
        for (r = nums.size()-1; r > l+1; r--)
        {
            if(r < nums.size() - 1 && nums[r] == nums[r+1]) continue;
            target = - (nums[l] + nums[r]);
            index = -1;
            for (int i = l+1; i < r; i++)
            {
                if(nums[i] == target)
                {
                    index = i;
                    break;
                }
                if(nums[i] > target) break;
            }
            if(index != -1) ans.push_back({nums[l], nums[index], nums[r]});
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = {-2,0,1,1,2};
    vector<vector<int>> ans = threeSum(nums);
    for (vector<int> a : ans)
    {
        for (int i : a)
        {
            cout<<i<<' ';
        }
        cout<<endl;
    }
    
    return 0;
}
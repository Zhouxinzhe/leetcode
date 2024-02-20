#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    int n = nums.size();
    for (int i = 0; i < n-3; i++)
    {
        if(i > 0 && nums[i] == nums[i-1]) continue;
        if((long) nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) break;
        if((long) nums[i] + nums[n - 3] + nums[n - 2] + nums[n - 1] < target) continue;
        for (int j = i+1; j < n-2; j++)
        {
            if(j > i+1 && nums[j] == nums[j-1]) continue;
            if((long) nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) break;
            if((long) nums[i] + nums[j] + nums[n - 2] + nums[n - 1] < target) continue;
            int k = j + 1;
            int l = n - 1;
            while(k < l)
            {
                long sum = (long)nums[i] + nums[j] + nums[k] + nums[l];
                if(sum == target) ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                if(sum <= target)
                {
                    int tmp = nums[k];
                    while(k < l && nums[k] == tmp) k++;
                }
                else
                {
                    int tmp = nums[l];
                    while(k < l && nums[l] == tmp) l--;
                }
            }
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = {1000000000,1000000000,1000000000,1000000000};
    int target = 0;
    vector<vector<int>> ans = fourSum(nums, target);
    for (vector<int> num: ans)
    {
        for (int digit : num)
        {
            cout<<digit<<' ';
        }
        cout<<endl;
    }
    
    return 0;
}
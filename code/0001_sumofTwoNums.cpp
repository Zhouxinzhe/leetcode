#include<vector>
#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;

// 哈希，
vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> ans;
    unordered_map<int, pair<int, int>> hash;
    for (int i = 0; i < nums.size(); i++) {
        if (hash.find(nums[i]) != hash.end())
            hash[nums[i]].second = i;
        else
            hash[nums[i]] = pair<int, int>(i, -1);
    }
    int p = 0;
    while (true) {
        if (hash.find(target - nums[p]) == hash.end())
            p++;
        else if (target == 2 * nums[p]) {
            if (hash[nums[p]].second == -1)
                p++;
            else {
                ans.push_back(hash[nums[p]].first);
                ans.push_back(hash[nums[p]].second);
                break;
            }
        } else {
            ans.push_back(hash[nums[p]].first);
            ans.push_back(hash[target - nums[p]].first);
            break;
        }
    }
    return ans;
}

// official solution
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> hashtable;
    for (int i = 0; i < nums.size(); ++i) {
        auto it = hashtable.find(target - nums[i]);
        if (it != hashtable.end()) {
            return {it->second, i};
        }
        hashtable[nums[i]] = i;
    }
    return {};
}

int main()
{
   
    






    return 0;
}
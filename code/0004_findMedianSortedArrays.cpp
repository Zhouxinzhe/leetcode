#include<iostream>
#include<vector>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int total = nums1.size() + nums2.size(); // assume 1~12, the index is 0~11
    int target[2] = {(total-1)/2, total/2}; // target is index, begin from 0
    int res = 0; // the number to find
    int n; // current range length
    int l1, r1; // range in nums1
    int l2, r2; // range in nums2
    int m, tmp;
    int index;
    for (size_t i = 0; i < 2; i++)
    {
        l1 = 0; r1 = nums1.size() - 1;
        l2 = 0; r2 = nums2.size() - 1;
        n = (r1 - l1 + 1) + (r2 - l2 + 1);
        while(true)
        {
            m = n / 2; // 从l开始往后数m个, m>=0
            if(m <= (r1 - l1)) // nums1
            {
                index = l1 + m;
                tmp = nums1[index]; // possible value
                if(index == target[i])
                {
                    if(nums2.size() == 0 || tmp <= nums2[0]) break;
                    else r1 = index - 1;
                }
                else if(index > target[i]) r1 = index - 1;
                else // index < target1, such as 5, 6
                {
                    if(target[i] - index > nums2.size()) l1 = index + 1; 
                    else if(target[i] - index < nums2.size() && tmp > nums2[target[i] - index])  r1 = index - 1;
                    else
                    {
                        if(tmp < nums2[target[i] - index - 1]) l1 = index + 1;
                        else break;
                    }
                }
            }
            else // nums2
            {
                index = m - (r1 -l1) + l2 - 1;
                tmp = nums2[index];
                if(index == target[i])
                {
                    if(nums1.size()==0 || tmp <= nums1[0]) break;
                    else r2 = index - 1;
                }
                else if(index > target[i]) r2 = index - 1;
                else // index < target1
                {
                    if(target[i] - index > nums1.size()) l2 = index + 1;
                    else if(target[i] - index < nums1.size() && tmp> nums1[target[i] - index])  r2 = index - 1;
                    else
                    {
                        if(tmp < nums1[target[i] - index - 1]) l2 = index + 1;
                        else break;
                    }
                }
            }
            n = (r1 - l1 + 1) + (r2 - l2 + 1);
        }
        res += tmp;
    }
    return float(res)/2;
}



// {1, 2, 3, 4, 5}
int binarySearch(vector<int>& nums, int num)
{
    int l = 0, r = nums.size() - 1;
    int m = (l + r) / 2;
    while(l <= r)
    {
        if(nums[m] == num) return m;
        if(nums[m] > num) r = m - 1;
        else l = m + 1;
        m = (l + r) / 2;
    }
    return -1;
}

int main()
{
    vector<int> nums1 = {};
    vector<int> nums2 = {1};
    cout<<findMedianSortedArrays(nums1, nums2)<<endl;
    



    return 0;
}
#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<cmath>
#include<cstring>
using namespace std;

int maxArea(vector<int>& height) {
    int l = 0, r = height.size()-1;
    int area = 0;
    while(r > l)
    {
        area = max(area, (r-l)*min(height[l], height[r]));
        if(height[l] < height[r]) l++;
        else r--;
    }
    return area;
}

int main()
{
    vector<int> height;
    cout<<maxArea(height)<<endl;
    return 0;
}
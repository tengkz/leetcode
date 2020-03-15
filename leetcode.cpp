#include<iostream>
#include<vector>
#include<string>
#include<numeric>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        vector<int> idx(nums.size());
        std::iota(idx.begin(),idx.end(),0);
        sort(idx.begin(),idx.end(),[&nums](int i1,int i2){return nums[i1]<nums[i2];});
        sort(nums.begin(),nums.end());
        for(int i=0,j=nums.size()-1;i<nums.size();i++){
            while(nums[i]+nums[j]>target && i<j)
                j--;
            if(nums[i]+nums[j]==target){
                result.push_back(idx[i]);
                result.push_back(idx[j]);
                return result;
            }
        }
        return result;
    }
};

int main()
{
    Solution s; 
    vector<int> nums{2,7,11,15};
    int target = 9;
    vector<int> result = s.twoSum(nums,target);
    for(int i=0;i<result.size();i++)
        cout<<result[i]<<endl;
    return 0;
}

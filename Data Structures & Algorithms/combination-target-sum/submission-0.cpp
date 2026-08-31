class Solution {
public:

    void func(int ind,int sum,vector<vector<int>>& ans,vector<int>& nums,vector<int>& temp){
        if(sum==0){
            ans.push_back(temp);
            return;
        }

        if(sum<0 || ind==nums.size()) return;

        temp.push_back(nums[ind]);
        func(ind,sum-nums[ind],ans,nums,temp);

        temp.pop_back();

        func(ind+1,sum,ans,nums,temp);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> temp;

        func(0,target,ans,nums,temp);

        return ans;
    }
};

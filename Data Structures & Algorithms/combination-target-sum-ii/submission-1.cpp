class Solution {
public:

    void func(int ind,int sum,vector<vector<int>>& ans,vector<int>& candidates,vector<int>& nums){
        if(sum==0){
            ans.push_back(nums);
            return;
        }

        if(sum<0 || ind==candidates.size()) return;

        nums.push_back(candidates[ind]);

        func(ind+1,sum-candidates[ind],ans,candidates,nums);

        nums.pop_back();

        for(int j=ind+1;j<candidates.size();j++){
            if(candidates[j]!=candidates[ind]){
                func(j,sum,ans,candidates,nums);
                break;
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> nums;

        sort(candidates.begin(),candidates.end());

        func(0,target,ans,candidates,nums);

        return ans;
    }
};

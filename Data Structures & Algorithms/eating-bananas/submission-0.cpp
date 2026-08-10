class Solution {
public:

    int maxim(vector<int>& nums){
        int n=nums.size();
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
        }

        return maxi;
    }

    int maxHour(vector<int>& nums,int hour){
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=(ceil((double)nums[i]/(double)hour));
        }

        return ans;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=maxim(piles);

        while(low<=high){
            int mid=low+(high-low)/2;

            int hour=maxHour(piles,mid);

            if(hour<=h){
                high=mid-1;
            }
            else low=mid+1;
        }

        return low;
    }
};

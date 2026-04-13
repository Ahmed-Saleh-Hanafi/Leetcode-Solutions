class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int n = nums.size();
        int mn = -1;
        for(int i= 0; i < n; i++){
            if(nums[i] == target){
                if(mn == -1) {
                    mn = abs(i - start);
                }
                else {
                    mn = min(mn, abs(i - start));
                }
            }
        }
        return mn;
    }
};
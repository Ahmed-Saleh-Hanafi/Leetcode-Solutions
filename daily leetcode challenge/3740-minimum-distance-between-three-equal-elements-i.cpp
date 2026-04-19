class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        int ans = 1e9;

        for(int i = 0; i < n-2; i++){
            for(int j = i+1; j < n-1; j++){
                for(int k = j+1; k < n; k++){
                    if(nums[i] == nums[j] && nums[j] == nums[k]){
                        int dis = abs(i-j) + abs(j-k) + abs(k-i);
                        ans = min(dis, ans);
                     }
                }
            }
        }

        return (ans == 1e9? -1 : ans);
    }
};
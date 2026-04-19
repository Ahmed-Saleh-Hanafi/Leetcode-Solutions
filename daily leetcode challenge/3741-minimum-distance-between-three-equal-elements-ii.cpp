class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        map<int, vector<int>> mp;

        for(int i = 0; i < n; i++){
            mp[nums[i]].push_back(i);
        }

        int ans = 1e9;

        for(auto &[k, v]: mp){
            if(v.size() < 3) continue;

            for(int i = 0; i + 2 < v.size(); i++){
                int cost = 2 * (v[i+2] - v[i]);
                ans = min(ans, cost);
            }
        }

        return (ans == 1e9 ? -1 : ans);
    }
};
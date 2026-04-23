class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<long long>> mp;
        unordered_map<int,int> mp2;
        for(int i = 0; i < n; i++){
            int v = nums[i];
            mp[v].push_back(i);
            mp2[i] = mp[v].size()-1;
        }
        for(auto &[e, v]: mp){
            for(int i = 1; i < v.size(); i++){
                v[i]+= v[i-1];
            }
        }
        vector<long long> ans(n);
        for(int i = 0; i < n; i++){
            int e = nums[i];
            auto &v = mp[e];
            long long idx = mp2[i];
            long long L = v[v.size()-1] - v[idx] - (i*(v.size()-idx-1));
            long long R = (i*(idx))-(v[idx] - i);
            ans[i] = L + R;
            if(ans[i]< 0) ans[i] = 0;
        }
        return ans;
    }
};
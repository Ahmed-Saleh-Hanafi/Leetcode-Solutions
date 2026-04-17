class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();

        map<int, vector<int>> mp;

        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }

        int ans = 1e9;

        for (int i = 0; i < n - 1; i++) {
            string v = to_string(nums[i]);
            reverse(v.begin(), v.end());
            int x = stoi(v);

            if (mp.count(x) == 0)
                continue;

            auto& arr = mp[x];
            auto it = upper_bound(arr.begin(), arr.end(), i);
            if (it == arr.end())
                continue;

            ans = min(ans, abs(i - (*it)));
        }
        return (ans == 1e9 ? -1 : ans);
    }
};
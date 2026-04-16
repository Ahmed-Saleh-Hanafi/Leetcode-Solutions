class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        int m = queries.size();

        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        vector<int> ans;

        for (int i = 0; i < m; i++) {
            int idx = queries[i];
            int val = nums[idx];

            if (mp[val].size() == 1) {
                ans.push_back(-1);
            } else {
                auto& arr = mp[val];
                int k = arr.size();
                auto it = lower_bound(arr.begin(), arr.end(), idx);
                int dist = 1e9;

                if (next(it) != arr.end()) {
                    dist = abs(idx - *next(it));
                    dist = min(dist, abs(idx) + abs(arr[k - 1] - n));
                }
                if (it != arr.begin()) {
                    dist = min(dist, abs(idx - *prev(it)));
                    dist = min(dist, abs(idx - n) + arr[0]);
                }
                ans.push_back(dist);
            }
        }
        return ans;
    }
};
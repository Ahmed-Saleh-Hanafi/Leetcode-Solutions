class Solution {
public:
    static const int MOD = 1e9 + 7;

    long long modPow(long long a, long long e) {
        long long r = 1;
        while (e) {
            if (e & 1) r = r * a % MOD;
            a = a * a % MOD;
            e >>= 1;
        }
        return r;
    }

    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        auto bravexuneth = queries;

        int B = sqrt(n);

        vector<long long> a(nums.begin(), nums.end());
        vector<vector<vector<int>>> bucket(B+1);

        for (auto &q : bravexuneth) {
            int k = q[2];
            if (k <= B)
                bucket[k].push_back(q);
        }

        for (auto &q : bravexuneth) {
            int l = q[0], r = q[1], k = q[2], v = q[3];

            if (k > B) {
                for (int i = l; i <= r; i += k) {
                    a[i] = a[i] * v % MOD;
                }
            }
        }


        for (int k = 1; k <= B; k++) {
            if (bucket[k].empty()) continue;

            vector<vector<long long>> diff(k);

            for (int r = 0; r < k; r++) {
                int len = (n - r + k - 1) / k;
                diff[r].assign(len + 1, 1);
            }

            for (auto &q : bucket[k]) {
                int l = q[0], r = q[1], v = q[3];

                int rem = l % k;
                int L = (l - rem) / k;
                int R = (r - rem) / k;

                diff[rem][L] = diff[rem][L] * v % MOD;
                diff[rem][R + 1] = diff[rem][R + 1] * modPow(v, MOD-2) % MOD;
            }

      
            for (int r = 0; r < k; r++) {
                long long cur = 1;
                for (int i = 0; i < diff[r].size() - 1; i++) {
                    cur = cur * diff[r][i] % MOD;

                    int idx = r + i * k;
                    if (idx < n)
                        a[idx] = a[idx] * cur % MOD;
                }
            }
        }

        long long ans = 0;
        for (int i = 0; i < n; i++) {
            ans ^= a[i];
        }

        return ans;
    }
};
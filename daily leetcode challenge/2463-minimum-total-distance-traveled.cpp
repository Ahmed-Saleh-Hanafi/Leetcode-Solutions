#define ll long long
class Solution {
public:
    int n, m;
    vector<int> R;
    vector<vector<int>> F;

    static const int N = 101;
    ll dp[N][N];
    bool vis[N][N];

    ll best(int idx, int idx2) {
        if (idx >= n)
            return 0;
        if (idx2 >= m)
            return 1e18;

        ll& ret = dp[idx][idx2];
        if (vis[idx][idx2])
            return ret;
        vis[idx][idx2] = true;

        ret = best(idx, idx2 + 1);

        ll d = 0;
        int c = F[idx2][1];
        int p = F[idx2][0];
        for (int k = 0; k < c; k++) {
            if (idx + k >= n) {
                break;
            }
            d += abs(R[idx + k] - p);
            ret = min(ret, d + best(idx + k + 1, idx2 + 1));
        }
        return ret;
    }
    long long minimumTotalDistance(vector<int>& robot,
                                   vector<vector<int>>& factory) {
        n = robot.size();
        m = factory.size();
        R = robot;
        F = factory;
        sort(R.begin(), R.end());
        sort(F.begin(), F.end());
        memset(vis, false, sizeof(vis));
        return best(0, 0);
    }
};
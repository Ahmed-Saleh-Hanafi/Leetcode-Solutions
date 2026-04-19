#define ll long long
class Solution {
public:
    int n, m;
    vector<vector<int>> g;

    const ll inf = -1e18; 
    ll dp[501][501][3];
    bool vis[501][501][3];

    ll best(int r, int c, int rem){
        if(r >= n || c >= m) return inf;

        if(r == n-1 && c == m-1){
            if(g[r][c] >= 0) return g[r][c];
            else {
                if(rem >= 1) return 0;
                else return g[r][c];
            }
        } 

        ll &ret = dp[r][c][rem];
        if(vis[r][c][rem]) return ret;
        vis[r][c][rem] = true;

        if(g[r][c] >= 0){
            ret = max(best(r+1, c, rem), best(r,c+1, rem)) + g[r][c];
        }
        else {
            if(rem >= 1){
                ret = max({best(r+1, c, rem)+ g[r][c],
                            best(r,c+1,rem) + g[r][c],
                            best(r+1,c, rem-1),
                            best(r,c+1, rem-1),
                });
            }
            else {
                ret = max(best(r+1, c, rem), best(r,c+1, rem)) + g[r][c];
            }
        }
        return ret ;
    }
    int maximumAmount(vector<vector<int>>& coins) {
        g = coins;
        n = coins.size();
        m = coins[0].size();
        return best(0,0,2);
    }
};
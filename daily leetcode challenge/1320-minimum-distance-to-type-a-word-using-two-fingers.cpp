#define ll long long
class Solution {
public:
    int n;
    string w;
    map<char, pair<int, int>> mp;

    static const int N = 301;
    ll dp[N][6][7][6][7];
    bool vis[N][6][7][6][7];

    ll best(int idx, int x1, int y1, int x2, int y2){
        if(idx >= n) return 0;

        ll&ret = dp[idx][x1][y1][x2][y2];
        if(vis[idx][x1][y1][x2][y2]) return ret;
        vis[idx][x1][y1][x2][y2] = true;

        ret = 1e9;
        char cur = w[idx];
        auto [x, y] = mp[cur];

        if(x1 == 5){
            ret = min(best(idx+1,x,y,x2,y2), ret);
        }
        else {
            int cost = abs(x1-x) + abs(y1-y);
            ret = min(ret, best(idx+1,x,y,x2,y2)+cost);
        }
        if(x2 == 5){
            ret = min(best(idx+1,x1,y1,x,y), ret);
        }
        else {
            int cost = abs(x2-x) + abs(y2-y);
            ret = min(ret, best(idx+1,x1,y1,x,y)+cost);
        }
        return ret;
    }
    int minimumDistance(string word) {
        n = word.size();
        w = word;

        int x = 0, y = 0;
        for(char c = 'A'; c <= 'Z'; c++){
            mp[c] = {x,y};
            y++;
            if(y != 0 && y % 6 == 0){
                y = 0;
                x++;
            }
        }
        memset(vis, false, sizeof(vis));
        return best(0,5,6,5,6);
    }
};
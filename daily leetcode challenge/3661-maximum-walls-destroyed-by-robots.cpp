
#define ll long long
const int N = 1e5 + 2;
class Solution {
public:
    int n;
    vector<int> W;
    vector<pair<int, int>> arr;

    ll dp[N][2];
    int get(int l, int r){
        auto L = lower_bound(W.begin(), W.end(), l) ;
        auto R = upper_bound(W.begin(), W.end(), r) ;
        return R - L ;
    }

    int best(int idx, bool last){
        if(idx == n) return 0;

        ll&ret = dp[idx][last];
        if(ret != -1) return ret;

        pair<int,int>prev={0,0};
        if(idx>0)prev=arr[idx-1];
        int res=-1e9;
        if(last){
           int stop_prev = min(prev.second+prev.first,arr[idx].first);
           if(stop_prev==arr[idx].first){
                res=max(res,best(idx+1,0));

                int p1=arr[idx].first+1;
                int p2=min(idx<n-1?arr[idx+1].first:(int)1e9,arr[idx].first+arr[idx].second);
                res=max(res,best(idx+1,1)+get(p1,p2));
           }else{
              int p1=max(stop_prev,arr[idx].first - arr[idx].second);
              if(p1==stop_prev)
                p1++;
              int p2=arr[idx].first;
              res=max(res,best(idx+1,0)+get(p1,p2));

              p1=arr[idx].first;
              p2=min(idx<n-1?arr[idx+1].first:(int)1e9,arr[idx].first+arr[idx].second);
              res=max(res,best(idx+1,1)+get(p1,p2));
           }
        }
        else {
            int p1=max(prev.first+1,arr[idx].first-arr[idx].second);
            if(p1==prev.first)
               p1++;
            int p2=arr[idx].first;
            res=max(res,best(idx+1,0)+get(p1,p2));

            p1=arr[idx].first;
            p2=min(idx<n-1?arr[idx+1].first:(int)1e9,arr[idx].first+arr[idx].second);
            res=max(res,best(idx+1,1)+get(p1,p2));

        }
        return ret=res;
    }
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        memset(dp, -1, sizeof(dp));
        n = robots.size();
        sort(walls.begin(), walls.end());
        W = walls;
        arr.resize(n);
        for(int i= 0; i < n; i++){
            arr[i] = {robots[i], distance[i]};
        }
        sort(arr.begin(), arr.end());
        return best(0,false);
    }
};
class Solution {
public:
    int n ;
    vector<vector<int>> adj;
    vector<int> comidx;
    vector<bool> vis;
    vector<int> com;
    void dfs(int u){
        
        vis[u] = true;
        com.push_back(u);
        for(auto v: adj[u]){
            if(!vis[v])  dfs(v);
        }
    }
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        n = source.size();
        adj.resize(n);
        vis.resize(n);
        comidx.resize(n);
        fill(comidx.begin(), comidx.end(), -1);
        fill(vis.begin(), vis.end(), false);

        for(auto vc: allowedSwaps){
            int u = vc[0], v = vc[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int cidx = 0;
        vector<map<int,int>> comp;
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                map<int,int> mp;
                dfs(i);
                for(int v: com){
                    comidx[v] = cidx;
                    mp[source[v]]++;
                }
                comp.push_back(mp);
                com.clear();
                cidx++;
            }
        }
        int ans = 0;
        for(int i = n-1; i >= 0; i--){
            int cidx = comidx[i];
            if(cidx == -1){
                ans++;
                continue;
            }

            auto &mp = comp[cidx];
            if(mp.count(target[i]) && mp[target[i]] > 0){
                mp[target[i]]--;
            }
            else {
                ans++;
            }
        }
        return ans;
    }
};
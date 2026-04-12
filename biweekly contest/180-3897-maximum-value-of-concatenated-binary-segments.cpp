class Solution {
public:
    static const int mod = 1e9 + 7;

    static bool com (pair<int,int> p1, pair<int,int> p2){
        string s1 = string(p1.first, '1') + string(p1.second, '0');
        string s2 = string(p2.first, '1') + string(p2.second, '0');
        return s1 + s2 > s2 + s1;
    }

    static void add_mod( int &a, int b){
        a+= b;
        if(a >= mod) a-= mod;
    }

    int maxValue(vector<int>& nums1, vector<int>& nums0) {
        vector<pair<int,int>> a;
        for(int i = 0; i < nums1.size(); i++){
            int v1 = nums1[i];
            int v2 = nums0[i];
            a.push_back({v1, v2});
        }

        sort(a.begin(), a.end(), com);
        string ans= "";
        for(auto [v1, v0]: a){
            ans += string(v1, '1');
            ans += string(v0, '0');
        }

        int ret = 0;
        int m = 1;
        for(int i = ans.size()-1; i >= 0; i--){
            m = m % mod;
            add_mod(ret, (ans[i]=='1'? m: 0));
            m = (m *2) %mod;
        }
        
        return ret;
    }
};
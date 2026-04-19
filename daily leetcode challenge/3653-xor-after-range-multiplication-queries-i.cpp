#define ll long long
class Solution {
public:
    const int mod = 1e9 + 7;
    void mul_mod (ll &a, ll b){
        a = (a * b)% mod;
    }
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<ll> nums2(nums.size());
        for(int i = 0; i < nums.size(); i++) nums2[i] = nums[i];
        
        for(auto &q: queries){
            ll l = q[0], r = q[1], k = q[2], v= q[3];
            for(int i = l; i <= r; i+= k){
                mul_mod(nums2[i], v);
            }
        }
        ll ans = nums2[0];
        for(int i = 1;  i < nums.size(); i++){
            ans = ans ^ nums2[i];
        }
        return ans;
    }
};
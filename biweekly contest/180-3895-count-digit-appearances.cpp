class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int ans = 0;
        for(auto e: nums){
            int v = e;
            while(v){
                if((v%10) == digit) ans++;
                v/= 10;
            }
        }
        return ans;
    }
};
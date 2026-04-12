class Solution {
public:
    static const int N = 1e6;
    bool isp [N];
    vector<int> pr;
    void sive(){
        memset(isp, true, sizeof(isp));
        isp[0]= isp[1] = false;
        for(int i = 2; i < N; i++){
            if(isp[i]){
                for(int j = i+i; j < N; j+= i){
                    isp[j] = false;
                }
            }
        }
        for(int i = 2; i < N; i++){
            if(isp[i]){
                pr.push_back(i);
            }
        }
    }
    int minOperations(vector<int>& nums) {
        sive();
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            int v = nums[i];
            if(i % 2 == 0){
                if(isp[v]) continue;

                auto it = lower_bound(pr.begin(), pr.end(), v);
                int ne = *it;
                ans+= ne - v;
            }
            else {
                if(!isp[v]) continue;

                while(isp[v]){
                    v++;
                    ans++;
                }
            }
        }
        return ans;
    }
};
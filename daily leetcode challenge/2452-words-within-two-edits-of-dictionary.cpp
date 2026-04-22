class Solution {
public:
    int comp(string &s1, string &s2){
        int ret = 0;
        for(int i = 0; i < s1.size(); i++){
            if(s1[i] != s2[i]) ret++;
            if(ret > 2) break;
        }
        return ret;
    }
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ret;
        for(auto &s1: queries){
            for(auto &s2: dictionary){
                int c = comp(s1, s2);
                if(c < 3){
                    ret.push_back(s1);
                    break;
                }
            }
        }
        return ret;
    }
};
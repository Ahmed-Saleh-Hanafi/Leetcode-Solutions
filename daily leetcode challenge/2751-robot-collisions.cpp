class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<pair<int, vector<int>>> arr;
        for(int i = 0; i < n; i++){
            vector<int> vc = {i,healths[i], directions[i]};
            arr.push_back(make_pair(positions[i], vc));
        }
        sort(arr.begin(), arr.end());
        stack<int> st;
        for(int i = 0; i < n; i++){
            if(st.empty()){
                st.push(i);
                continue;
            }
            int cur = i;
            while(!st.empty()){
                int idx = st.top();
                st.pop();
                auto [p, vc] = arr[idx];
                auto [p2, vc2] = arr[cur];

                if(vc[2] == 'R' && vc2[2]== 'L'){
                    if(vc[1] == vc2[1]){
                        cur = -1;
                        break;
                    }
                    else if(vc[1] > vc2[1]){
                        cur = idx;
                        arr[idx].second[1]--;
                    }
                    else {
                        cur = i;
                        arr[i].second[1]--;
                    }
                }
                else {
                    st.push(idx);
                    st.push(cur);
                    cur = -1;
                    break;
                }
            }
            if(cur != -1)st.push(cur);
        }
        vector<pair<int, int>> ans ;
        while(!st.empty()){
            int idx = st.top();
            st.pop();
            ans.push_back(make_pair(arr[idx].second[0], arr[idx].second[1]));
        }
        sort(ans.begin(), ans.end());
        vector<int> ret;
        for(auto e: ans){
            ret.push_back(e.second);
        }
        return ret;
    }
};
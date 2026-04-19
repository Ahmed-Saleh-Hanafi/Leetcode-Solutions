class Solution {
public:
    int cur = 0;
    void get_next(){
        cur = (cur + 1) % 4;
    }
    void get_prev(){
        cur = (cur + 3) % 4;
    }
    map<int, set<int>> ox, oy;
    int get_obstacle_x (int y, int x1, int x2){
        auto &se = oy[y];

        if(x1 < x2){ 
            auto it = se.upper_bound(x1);
            if(it != se.end() && *it <= x2)
                return *it - 1;
            return x2;
        }
        else { 
            auto it = se.lower_bound(x1);
            if(it != se.begin()){
                --it;
                if(*it >= x2)
                    return *it + 1;
            }
            return x2;
        }
    }
    int get_obstacle_y (int x, int y1, int y2){
        auto &se = ox[x];

        if(y1 < y2){ 
            auto it = se.upper_bound(y1);
            if(it != se.end() && *it <= y2)
                return *it - 1;
            return y2;
        }
        else { 
            auto it = se.lower_bound(y1);
            if(it != se.begin()){
                --it;
                if(*it >= y2)
                    return *it + 1;
            }
            return y2;
        }
    }

    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        long long x = 0, y = 0;
        long long ans = 0;
        for(auto &e: obstacles){
            ox[e[0]].insert(e[1]);
            oy[e[1]].insert(e[0]);
        }

        for(auto e: commands){
            if(e == -1) get_next();
            else if(e == -2) get_prev();
            else {
                if(cur == 0) { 
                    y = get_obstacle_y(x, y, y + e);
                }
                else if(cur == 1) { 
                    x = get_obstacle_x(y, x, x + e);
                }
                else if(cur == 2) { 
                    y = get_obstacle_y(x, y, y - e);
                }
                else if(cur == 3) { 
                    x = get_obstacle_x(y, x, x - e);
                }
            }
            ans = max(ans,x * x + y * y);
        }

        return ans;
    }
};
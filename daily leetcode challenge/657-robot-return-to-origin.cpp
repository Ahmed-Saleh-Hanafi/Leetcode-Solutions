class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0, y = 0;
        for(auto s: moves){
            if(s == 'U'){
                x++;
            }
            else if(s == 'D'){
                x--;
            }
            else if(s == 'R'){
                y++;
            }
            else if(s == 'L'){
                y--;
            }
        }
        return (x == 0 && y == 0);
    }
};
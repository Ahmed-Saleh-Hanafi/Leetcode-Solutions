class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int c1 = 0, c2 = 0;
        for(auto e: moves){
            if (e == 'R') c1++;
            else if(e == 'L') c2++;
        }
        return abs(c1-c2) + (moves.size()-c1-c2);
    }
};

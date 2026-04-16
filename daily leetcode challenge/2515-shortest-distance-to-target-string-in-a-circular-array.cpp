class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();

        int ans1 = 0;
        bool is = false;

        for(int i = startIndex; ;){
            if(i == startIndex && is) break;
            else is = true;

            if(target == words[i]){
                break;
            }
            ans1++;
            i = (i+1)%n;
        }
        if(ans1 == n) return -1;

        int ans2 = 0;
        is = false;
        for(int i = startIndex; ;){
            if(i == startIndex && is) break;
            else is = true;

            if(target == words[i]){
                break;
            }
            ans2++;
            i = (i-1+n)%n;
        }
        return min(ans1, ans2);

    }
};
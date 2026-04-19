class Robot {
public:
    int x = 0, y = 0;
    vector<string> dir = {"East", "North", "West", "South"};
    int cur = 0;
    int w, h;
    Robot(int width, int height) {
        w = width;
        h = height;
    }
    void nex(){
        cur = (cur+1)%4;
    }
    void step(int num) {
        num = num % ((w*2+h*2)-4);

        if (num == 0) {
            if (x == 0 && y == 0) {
                cur = 3;
            }
            return;
        }
        while(num != 0){
            if(cur == 0){
                x+= num ;
                num = 0;
                if(x >= w){
                    num = x - (w-1);
                    x = w-1;
                    nex();
                }
            }
            else if(cur == 1){
                y+= num;
                num = 0;
                if(y >= h){
                    num = y - (h-1);
                    y = (h-1);
                    nex();
                }
            }
            else if( cur == 2){
                x-= num;
                num = 0;
                if (x < 0){
                    num = -1*(x);
                    x = 0;
                    nex();
                }
            }
            else {
                y-= num;
                num = 0;
                if(y < 0){
                    num = -1*y;
                    y = 0;
                    nex();
                }
            }
        }
    }
    
    vector<int> getPos() {
        vector<int> ret = {x, y};
        return ret;
    }
    
    string getDir() {
        return dir[cur];
    }
};

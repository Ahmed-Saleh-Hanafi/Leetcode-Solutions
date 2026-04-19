class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        if(encodedText == "") return "";
        int col = (encodedText.size()/rows);
        vector<vector<char>> grid(rows, vector<char>(col));

        int k = 0;
        int c = 0;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < col; j++){
                grid[i][j] = encodedText[k];
                if(encodedText[k] != ' ') c++;
                k++;
            }
        }

        string ans = "";

        int c2 = 0;
        int cur = 0;
        int i = 0, j = 0;
        while(true){
            if(i >= rows || j >= col){
                cur++;
                i = 0;
                j = cur;
            }
            ans+= grid[i][j];
            if(grid[i][j] != ' ') c2++;
            if(c == c2) break;
            i++; j++;
        }
        return ans;
    }
};
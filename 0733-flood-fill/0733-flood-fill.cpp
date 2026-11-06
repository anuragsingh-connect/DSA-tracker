class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image,
                                   int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();

        int orgColor = image[sr][sc];

        // Edge case: same color → kuch karne ki zarurat nahi
        if(orgColor == color) return image;

        vector<int> delrow = {0, +1, 0, -1};
        vector<int> delcol  = {-1, 0, +1, 0};

        queue<pair<int,int>> q;
        q.push({sr, sc});
        image[sr][sc] = color;          // source fill karo

        while(!q.empty()) {
            auto [row, col] = q.front(); // fix 4: current node lo
            q.pop();                     // fix 1: yahan pop karo

            for(int i = 0; i < 4; i++) {
                int nrow = row + delrow[i];  // fix 3: [i] lagao
                int ncol  = col + delcol[i];

                if(nrow >= 0 && nrow < n &&  // fix 6: < not <=
                   ncol >= 0 && ncol < m &&
                   image[nrow][ncol] == orgColor) {

                    image[nrow][ncol] = color; // fix 8: color assign
                    q.push({nrow, ncol});       // fix 7: nrow,ncol
                }
            }
        }

        return image;
    }
};
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int initialColor = image[sr][sc];

        if (initialColor == color) return image; // Avoids infinite recursion

        fill(image, sr, sc, initialColor, color);
        return image;
    }

    void fill(vector<vector<int>>& image, int sr, int sc, int initialColor, int color) {
        int n = image.size();
        int m = image[0].size();

        if (sr < 0 || sr >= n || sc < 0 || sc >= m || image[sr][sc] != initialColor) {
            return;
        }

        image[sr][sc] = color;

        // Upper
        fill(image, sr - 1, sc, initialColor, color);
        // Lower
        fill(image, sr + 1, sc, initialColor, color);
        // Left
        fill(image, sr, sc - 1, initialColor, color);
        // Right
        fill(image, sr, sc + 1, initialColor, color);
    }
};

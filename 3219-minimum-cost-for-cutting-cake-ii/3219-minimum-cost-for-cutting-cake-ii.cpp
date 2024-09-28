class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        sort(horizontalCut.begin(),horizontalCut.end(), greater<int>());
        sort(verticalCut.begin(),verticalCut.end(), greater<int>());
        long long total = 0;
        long long horizontal = 1;
        long long vertical = 1;
        long long rowIndex = 0;
        long long colIndex = 0;

        int x = horizontalCut.size();
        int y = verticalCut.size();

        while(rowIndex < x && colIndex < y)
        {
            if(horizontalCut[rowIndex] > verticalCut[colIndex])
            {
                total = total + (horizontalCut[rowIndex] * vertical);
                horizontal++;
                rowIndex++;
            }
            else
            {
                total = total + (verticalCut[colIndex] * horizontal);
                vertical++;
                colIndex++;
            }
        }
        while(rowIndex < x)
        {
            total = total + (horizontalCut[rowIndex] * vertical);
            rowIndex++;
        }
        while(colIndex < y)
        {
            total = total + (verticalCut[colIndex] * horizontal);
            colIndex++;
        }
        return total;
    }
};
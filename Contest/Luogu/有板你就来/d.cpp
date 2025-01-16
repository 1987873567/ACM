#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxTwoPathsSum(const vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();

    // dp1: 从起点到每个点的路径1的最大和
    vector<vector<int>> dp1(rows, vector<int>(cols, -INT_MAX));
    // dp2: 从起点到每个点的路径2的最大和
    vector<vector<int>> dp2(rows, vector<int>(cols, -INT_MAX));

    dp1[0][0] = grid[0][0];
    dp2[0][0] = grid[0][0];

    // 填充 dp1 和 dp2 数组
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (i > 0) {  // 从上方来
                dp1[i][j] = max(dp1[i][j], dp1[i - 1][j] + grid[i][j]);
                dp2[i][j] = max(dp2[i][j], dp2[i - 1][j] + grid[i][j]);
            }
            if (j > 0) {  // 从左方来
                dp1[i][j] = max(dp1[i][j], dp1[i][j - 1] + grid[i][j]);
                dp2[i][j] = max(dp2[i][j], dp2[i][j - 1] + grid[i][j]);
            }
        }
    }

    // 返回两条路径到达终点的最大和
    return dp1[rows - 1][cols - 1] + dp2[rows - 1][cols - 1];
}

int main() {
    // 示例输入
    int n;
    std::cin >> n;
    vector<vector<int>> grid(n, std::vector<int>(n));
    for(int i = 0; i < n; i++){
    	for(int j = 0; j < n; j++){
    		std::cin >> grid[i][j];
    	}
    }
    int result = maxTwoPathsSum(grid);
    cout << "最大路径和: " << result << endl;

    return 0;
}

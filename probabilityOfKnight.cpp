#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

double knightProbability(int n, int k, int r, int c)
{
    int dirs[8][2] = {{2, 1}, {2, -1}, {1, 2}, {1, -2}, {-2, 1}, {-2, -1}, {-1, 2}, {-1, -2}};
    vector<vector<double>> m(n, vector<double>(n, 1));
    while (k--)
    {
        vector<vector<double>> next(n, vector<double>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (auto &dir : dirs)
                {
                    int x = i + dir[0];
                    int y = j + dir[1];
                    if (x < 0 or x >= n or y < 0 or y >= n)
                        continue;
                    next[i][j] += m[x][y];
                }
                next[i][j] /= 8;
            }
        }
        m = next;
    }
    return m[r][c];
}

int main()
{
    int cases;
    cin >> cases;
    while (cases--)
    {
        int n, k, r, c;
        cin >> n >> r >> c >> k;
        cout << fixed << setprecision(6) << knightProbability(n, k, r, c) << endl;
    }
    return 0;
}
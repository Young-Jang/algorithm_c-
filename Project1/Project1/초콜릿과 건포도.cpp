#include<iostream>
#include<algorithm>

#define INF 987654321

using namespace std;
int n, m;
int input[50][50];
int map[50][50];
int dp[51][51][51][51];

int dfs(int y, int x, int h, int w)
{
	if (h == 1 && w == 1)
		return 0;
	if (dp[y][x][h][w]!=INF)
		return dp[y][x][h][w];
	int sum = 0;
	if (y == 0 && x == 0)
	{
		sum = map[h - 1][w - 1];
	}
	else if (y == 0)
	{
		sum = map[h - 1][x + w - 1] - map[h - 1][x - 1];
	}
	else if (x == 0)
	{
		sum = map[y + h - 1][w - 1] - map[y - 1][w - 1];
	}
	else
	{
		sum =map[y+h-1][x+w-1] - map[y+h - 1][x - 1] - map[y - 1][x+w - 1]+map[y-1][x-1];
	}
	int m1 = INF;
	for (int i = 1; i < h; i++)
	{
		if (dp[y][x][i][w]==INF)
			dp[y][x][i][w] = dfs(y, x, i, w);
		
		if (dp[y + i][x][h - i][w]==INF)
			dp[y + i][x][h - i][w] = dfs(y + 1, x, h - i, w);
		m1 = min(m1, dp[y][x][i][w] + dp[y + i][x][h - i][w]);
	}
	for (int i = 1; i < w; i++)
	{
		if (dp[y][x][h][i]==INF)	
			dp[y][x][h][i] = dfs(y, x, h, i);

		if (dp[y][x + i][h][w - i]==INF)
			dp[y][x + i][h][w - i] = dfs(y, x + i, h, w - i);
		m1 = min(m1, dp[y][x][h][i] + dp[y][x + i][h][w - i]);
	}
	if (m1 == INF)
		m1 = 0;
	dp[y][x][h][w] = m1 + sum;
	return dp[y][x][h][w];
}

int main()
{
	int T;
	cin >> T;
	for (int k = 1; k <= T; k++)
	{
		cin >> n >> m;
		for (int i = 0; i <= n; i++)
		{
			for (int j = 0; j <= m; j++)
			{
				for (int l = 0; l <= n; l++)
				{
					for (int q = 0; q <= m; q++)
					{
						dp[i][j][l][q] = INF;
					}
				}
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> input[i][j];
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (i - 1 >= 0 && j - 1 >= 0)
				{
					map[i][j] = map[i - 1][j] + map[i][j - 1] - map[i - 1][j - 1]+input[i][j];
				}
				else if (i - 1 >= 0)
				{
					map[i][j] = map[i - 1][j] + input[i][j];
				}
				else
				{
					map[i][j] = map[i][j - 1] + input[i][j];
				}
			}
		}

		int res = dfs(0, 0, n, m);
		cout << "#" << k << " " << res << "\n";
	}
}
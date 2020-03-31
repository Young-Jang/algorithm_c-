#include<iostream>

using namespace std;

int n, m, c;
int map[51][51];
int dx[2] = { 1,0 };
int dy[2] = { 0,1 };
int dp[51][51][51][51];//y,x,들른오락실갯수,가장 마지막에 들른 오락실 번호
int main()
{
	cin >> n >> m >> c;
	int a, b;
	for (int i = 1; i <= c; i++)
	{
		cin >> a >> b;
		map[a][b] = i;
	}
	if (map[1][1])
	{
		dp[1][1][1][map[1][1]] = 1;
	}
	else
	{
		dp[1][1][0][0] = 1;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (i == 1 && j == 1)
				continue;
			for (int k = 0; k <= c; k++)
			{
				for (int l = 0; l <= c; l++)
				{
					if (dp[i - 1][j][k][l])
					{
						if (l < map[i][j])
						{
							dp[i][j][k + 1][map[i][j]] += dp[i - 1][j][k][l];
							dp[i][j][k + 1][map[i][j]] %= 1000007;
						}
						else if (!map[i][j])
						{
							dp[i][j][k][l] += dp[i - 1][j][k][l];
							dp[i][j][k][l] %= 1000007;
						}
					}
					if (dp[i][j-1][k][l])
					{
						if (l < map[i][j])
						{
							dp[i][j][k + 1][map[i][j]] += dp[i][j-1][k][l];
							dp[i][j][k + 1][map[i][j]] %= 1000007;
						}
						else if (!map[i][j])
						{
							dp[i][j][k][l] += dp[i][j-1][k][l];
							dp[i][j][k][l] %= 1000007;
						}
					}
				}
			}
		}
	}
	for (int k = 0; k <= c; k++)
	{
		int hap = 0;
		for (int l = 0; l <= c; l++)
		{
			if (dp[n][m][k][l])
			{
				hap += dp[n][m][k][l];
				hap %= 1000007;
			}
		}
		cout << hap <<" ";
	}
}
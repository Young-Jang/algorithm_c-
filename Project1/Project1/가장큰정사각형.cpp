#include<iostream>
#include<algorithm>
using namespace std;

int n, m;
int map[1001][1001];
int dp[1001][1001];
int maxs = 0;
char line[1001];
int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("\n%s", line);
		for (int j = 1; j <= m; j++)
			map[i][j] = line[j - 1] - '0';
	}
	/*int rsz = n;
	int csz = m;
	for (int i = 0; i < rsz; i++)
	{
		for (int j = 0; j < csz; j++)
		{
			int w,h;
			if (map[i][j])
			{
				int si = i;
				int sj = j;
				int sz = 1;
				while (1)
				{
					bool flag = true;
					for (int k = 0; k < sz; k++)
					{
						if (!map[si][j + k])
						{
							flag = false;
							break;
						}
					}
					if (!flag)
					{
						if (sz - 1 > maxs)
						{
							maxs = sz - 1;
							rsz = n - maxs;
							csz = m - maxs;
						}
						break;
					}
					for (int k = 0; k < sz-1; k++)
					{
						if (!map[i+k][sj])
						{
							flag = false;
							break;
						}
					}
					if (!flag)
					{
						if (sz - 1 > maxs)
						{
							maxs = sz - 1;
							rsz = n - maxs;
							csz = m - maxs;
						}
						break;
					}
					else
					{
						si++;
						sj++;
						sz++;
					}
				}
			}
		}
	}*/
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (map[i][j])
			{
				dp[i][j] = min(dp[i - 1][j], min(dp[i][j-1],dp[i-1][j-1])) + 1;
				if (dp[i][j] > maxs)
					maxs = dp[i][j];
			}
		}
	}
	cout << maxs*maxs;
}

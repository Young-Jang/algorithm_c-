#include<iostream>

#define INF 987654321

using namespace std;

int n;
int h[2];
int c[2];
int g[10][2];
int check[10];
int d[10][10];
int mins = INF;

int leng(int y1, int x1, int y2, int x2)
{
	return abs(y1 - y2) + abs(x1 - x2);
}

void dfs(int nx, int hap,int cnt)
{
	if (cnt == n)
	{
		int tmp = leng(g[nx][1], g[nx][0], h[1], h[0]);
		if (mins > hap +tmp)
		{
			mins = hap + tmp;
		}
	}
	for (int i = 0; i < n; i++)
	{
		int tmp = leng(g[nx][1], g[nx][0], g[i][1], g[i][0]);
		if (!check[i]&&mins>hap+tmp)
		{
			check[i] = 1;
			dfs(i, hap + tmp, cnt + 1);
			check[i] = 0;
		}
	}
}

int main()
{
	int T;
	cin >> T;
	for (int k = 1; k <= T; k++)
	{
		cin >> n;
		cin >> h[0] >> h[1];
		cin >> c[0] >> c[1];
		mins = INF;
		int res = INF;
		for (int i = 0; i < n; i++)
		{
			cin >> g[i][0] >> g[i][1];
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = i+1; j < n; i++)
			{
				d[i][j]=leng(g[i][1], g[i][0], g[j][1], g[j][0]);
			}
		}
		for (int i = 0; i < n; i++)
		{
			check[i] = 1;
			dfs(i, leng(g[i][1],g[i][0],c[1],c[0]), 1);
			check[i] = 0;
			if (res > mins)
				res = mins;
		}
		cout << "#" << k << " " << mins << "\n";
	}
}


#include<iostream>
#include<string.h>

#define INF 987654321

using namespace std;

int n;
int h[2];
int c[2];
int g[10][2];
int dp[10][1 << 10];
int d[10][10];
int res = INF;

int leng(int y1, int x1, int y2, int x2)
{
	return abs(y1 - y2) + abs(x1 - x2);
}
void dfs(int nx, int hap, int check)
{
	if (check == (1 << n) - 1)
	{
		hap += leng(g[nx][1], g[nx][0], h[1], h[0]);
		if (res > hap)
			res = hap;
	}
	for (int i = 0; i < n; i++)
	{
		if ((1 << i) & check)
			continue;
		int len = 0;
		if (i > nx)
			len = d[nx][i];
		else
			len = d[i][nx];
		
		if (dp[i][check | 1 << i] > dp[nx][check] + len)
		{
			dp[i][check | 1 << i] = dp[nx][check] + len;
			dfs(i, hap + len, check | (1 << i));
		}
	}
}

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	int T;
	cin >> T;
	for (int k = 1; k <= T; k++)
	{
		cin >> n;
		cin >> h[0] >> h[1];
		cin >> c[0] >> c[1];
		res = INF;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < 1 << n; j++)
			{
				dp[i][j] = INF;
			}
		}
		for (int i = 0; i < n; i++)
		{
			cin >> g[i][0] >> g[i][1];
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				d[i][j] = leng(g[i][1], g[i][0], g[j][1], g[j][0]);
			}
		}
		for (int i = 0; i < n; i++)
		{
			dp[i][1 << i] = leng(g[i][1], g[i][0], c[1], c[0]);
			dfs(i, leng(g[i][1], g[i][0], c[1], c[0]), 1 << i);
		}
		cout << "#" << k << " " << res << "\n";
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				d[i][j]=0;
			}
		}
	}
}
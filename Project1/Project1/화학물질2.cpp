#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int n;
int map[100][100];
int m[20][2];
int cnt = 0;
int d[22];
int dp[21][21];

vector<int> v;

void find(int y,int x)
{
	int cx = 1;
	int cy = 1;
	while (map[y][x + cx])
	{
		map[y][x + cx] = 0;
		cx++;
		if (cx+x > n - 1)
			break;
	}
	while (map[y + cy][x])
	{
		map[y + cy][x] = 0;
		cy++;
		if (cy+y > n - 1)
			break;
	}
	for (int i = y; i < y + cy; i++)
	{
		for (int j = x; j < x + cx; j++)
		{
			map[i][j] = 0;
		}
	}
	m[cnt][0] = cy;
	m[cnt++][1] = cx;
}

void nx_matrix(int num)
{
	for (int i = 0; i < cnt; i++)
	{
		if (m[i][0] == num)
		{
			v.push_back(i);
			nx_matrix(m[i][1]);
			break;
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
		cnt = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> map[i][j];
			}
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (map[i][j])
				{
					find(i, j);
				}
			}
		}

		int st = 0;
		for (int i = 0; i < cnt; i++) {
			bool flag = false;
			for (int j = 0; j < cnt; j++)
			{
				if (m[i][0] == m[j][1])
				{
					flag = true;
					break;
				}
			}
			if (!flag)
			{
				st = i;
				break;
			}
		}

		v.push_back(st);
		nx_matrix(m[st][1]);

		d[0] = m[v[0]][0];
		d[1] = m[v[0]][1];
		int sz = cnt;
		for (int i = 2; i < sz+1; i++)
		{
			d[i] = m[v[i - 1]][1];
		}	

		for (int i = 2; i <= sz; i++)
		{
			for (int j = 1; j <= sz - i + 1; j++)
			{
				int t = i + j - 1;
				dp[j][t] = 987654321;
				for (int a = j; a < t; a++)
				{
					dp[j][t] = min(dp[j][t], dp[j][a] + dp[a + 1][t] + d[j - 1] * d[a] * d[t]);
				}
			}
		}
		cout << "#" << k << " " << dp[1][sz] << endl;
		v.clear();
	}
}
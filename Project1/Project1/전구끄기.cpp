#include<iostream>

#define INF 987654321

using namespace std;
int n;
bool map[18][18];
bool tmp[18][18];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
int mins = INF;

void is_over(int cnt)
{
	int c = cnt;
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (map[i - 1][j]) {
				c++;
				map[i][j] = !map[i][j];
				for (int k = 0; k < 4; k++)
				{
					int nx = j + dx[k];
					int ny = i + dy[k];
					if (nx<0 || ny<0 || nx>n - 1 || ny>n - 1)
						continue;
					map[ny][nx] = !map[ny][nx];
				}
			}
		}
	}
	bool flag = true;
	for (int i = 0; i < n; i++)
	{
		if (map[n - 1][i])
		{
			flag = false;
			break;
		}
	}
	if (flag)
	{
		if (mins > c)
			mins = c;
	}
}

void dfs(int sy, int sx,int cnt)
{
	if (sx >= n)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				tmp[i][j] = map[i][j];
			}
		}
		is_over(cnt);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				map[i][j] = tmp[i][j];
			}
		}
		return;
	}
	dfs(sy, sx + 1, cnt);
	map[sy][sx] = !map[sy][sx];
	for (int k = 0; k < 4; k++)
	{
		int nx = sx + dx[k];
		int ny = sy + dy[k];
		if (nx<0 || ny<0 || nx>n - 1 || ny>n - 1)
			continue;
		map[ny][nx] = !map[ny][nx];
	}
	dfs(sy, sx + 1, cnt + 1);
	map[sy][sx] = !map[sy][sx];
	for (int k = 0; k < 4; k++)
	{
		int nx = sx + dx[k];
		int ny = sy + dy[k];
		if (nx<0 || ny<0 || nx>n - 1 || ny>n - 1)
			continue;
		map[ny][nx] = !map[ny][nx];
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
		}
	}
	dfs(0, 0, 0);
	if (mins == INF)
		cout << -1;
	else
		cout << mins;
}
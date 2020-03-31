#include<iostream>

using namespace std;
int map[50][50];
int n,m,l;
int h[2];
int check[50][50][2];
int tx[8][4] = {
	{0},
	{0,1,0,-1},
{0,0},
{1,-1},
{0,1},
{1,0},
{-1,0},
{0,-1}
};
int ty[8][4] = {
	{0},
	{-1,0,1,0},
{-1,1},
{0,0},
{-1,0},
{0,1},
{0,1},
{-1,0}
};

int conn[8][4] = {
	{0},
{1,1,1,1},
{1,0,1,0},
{0,1,0,1},
{0,0,1,1},
{1,0,0,1},
{1,1,0,0},
{0,1,1,0}
};

void dfs(int y,int x,int d,int cnt)
{
	if (cnt == l)
		return;
	int nx = 0, ny = 0;
	if (d == 1)
	{
		for (int i = 0; i < 4; i++)
		{
			nx = x + tx[1][i];
			ny = y + ty[1][i];
			if (nx<0 || ny<0 || nx>m - 1 || ny>n - 1 || !map[ny][nx])
				continue;
			if (check[ny][nx][0] && check[ny][nx][1] < cnt)
				continue;
			if (!conn[map[ny][nx]][i])
				continue;
			check[ny][nx][0] = 1;
			check[ny][nx][1] = cnt;
			dfs(ny, nx, map[ny][nx],cnt+1);
		}
	}
	else
	{
		for (int i = 0; i < 2; i++)
		{
			nx = x + tx[d][i];
			ny = y + ty[d][i];
			if (nx<0 || ny<0 || nx>m - 1 || ny>n - 1 || !map[ny][nx])
				continue;
			if (check[ny][nx][0] && check[ny][nx][1] < cnt)
				continue;
			if (d == 2)
			{
				if (!i)
				{
					if (!conn[map[ny][nx]][0])
						continue;
				}
				else
				{
					if (!conn[map[ny][nx]][2])
						continue;
				}
			}
			else if (d == 3)
			{
				if (!i)
				{
					if (!conn[map[ny][nx]][1])
						continue;
				}
				else
				{
					if (!conn[map[ny][nx]][3])
						continue;
				}
			}
			else if (d == 4)
			{
				if (!i)
				{
					if (!conn[map[ny][nx]][0])
						continue;
				}
				else
				{
					if (!conn[map[ny][nx]][1])
						continue;
				}
			}
			else if (d == 5)
			{
				if (!i)
				{
					if (!conn[map[ny][nx]][1])
						continue;
				}
				else
				{
					if (!conn[map[ny][nx]][2])
						continue;
				}
			}
			else if (d == 6)
			{
				if (!i)
				{
					if (!conn[map[ny][nx]][3])
						continue;
				}
				else
				{
					if (!conn[map[ny][nx]][2])
						continue;
				}
			}
			else
			{
				if (!i)
				{
					if (!conn[map[ny][nx]][0])
						continue;
				}
				else
				{
					if (!conn[map[ny][nx]][3])
						continue;
				}
			}
			check[ny][nx][0] = 1;
			check[ny][nx][1] = cnt;
			dfs(ny, nx, map[ny][nx],cnt+1);
		}
	}
}

int main()
{
	int T;
	cin >> T;
	for (int k = 1; k <= T; k++)
	{
		cin >> n >> m >> h[0] >> h[1] >> l;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> map[i][j];
			}
		}
		check[h[0]][h[1]][0] = 1;
		check[h[0]][h[1]][1] = 1;
		dfs(h[0], h[1], map[h[0]][h[1]],1);
		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (check[i][j][0])
					cnt++;
			}
		}
		cout << "#" << k << " " << cnt << "\n";
		
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				check[i][j][0] = 0;
				check[i][j][1] = 0;
			}
		}
	}
}
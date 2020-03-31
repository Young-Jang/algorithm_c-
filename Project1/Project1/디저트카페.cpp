#include<iostream>

using namespace std;
int n;
int map[20][20];
int check[101];
int dx[4] = { 1,-1,-1,1 };
int dy[4] = { 1,1,-1,-1 };
int maxs = 0;
int sx, sy;

void dfs(int y, int x, int d,int hap)
{
	int nx = x + dx[d];
	int ny = y + dy[d];
	int tx, ty;
	if (d == 0 || d == 1) {
		while (nx >= 0 && ny >= 0 && nx < n && ny < n && !check[map[ny][nx]])
		{
			check[map[ny][nx]] = 1;
			dfs(ny, nx, (d + 1) % 4, hap + 1);
			hap ++;
			nx += dx[d];
			ny += dy[d];
		}
		nx -= dx[d];
		ny -= dy[d];
		while (nx!=x||ny!=y)
		{
			check[map[ny][nx]] = 0;
			nx -= dx[d];
			ny -= dy[d];
		}
	}
	else if (d == 2)
	{
		if (nx<0 || ny<0 || nx>n - 1 || ny>n - 1)
			return;
		while ((nx + ny) != sx + sy)
		{
			if (check[map[ny][nx]]||nx<0 || ny<0 || nx>n - 1 || ny>n - 1)
			{
				while (nx!=x-1||ny!=y-1)
				{
					nx -= dx[d];
					ny -= dy[d];
					check[map[ny][nx]] = 0;
				}
				return;
			}
			check[map[ny][nx]] = 1;
			hap++;
			nx += dx[d];
			ny += dy[d];
			if (nx<0 || ny<0 || nx>n - 1 || ny>n - 1)
			{
				while (nx != x - 1 || ny != y - 1)
				{
					nx -= dx[d];
					ny -= dy[d];
					check[map[ny][nx]] = 0;
				}
				return;
			}
		}
		tx = nx;
		ty = ny;
		while (nx != sx || ny != sy)
		{
			if (check[map[ny][nx]])
			{
				while (nx!=tx||ny!=ty)
				{
					nx -= dx[3];
					ny -= dy[3];
					check[map[ny][nx]] = 0;
				}
				while (nx != x -1 || ny != y-1)
				{
					nx -= dx[d];
					ny -= dy[d];
					check[map[ny][nx]] = 0;
				}
				return;
			}
			check[map[ny][nx]] = 1;
			hap ++;
			nx += dx[3];
			ny += dy[3];
		}
		if (hap > maxs)
			maxs = hap;
		while (nx != tx || ny != ty)
		{
			nx -= dx[3];
			ny -= dy[3];
			check[map[ny][nx]] = 0;
		}
		while (nx != x - 1 || ny != y - 1)
		{
			nx -= dx[d];
			ny -= dy[d];
			check[map[ny][nx]] = 0;
		}
		return;
	}
}
int main()
{
	int T;
	cin >> T;
	for (int k = 1; k <= T; k++)
	{
		maxs = 0;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> map[i][j];
			}
		}
		for (int i = 0; i < n-1; i++)
		{
			for (int j = 1; j < n-1; j++)
			{
				sx = j;
				sy = i;
				check[map[i][j]] = 1;
				dfs(i, j, 0, 1);
				check[map[i][j]] = 0;
			}
		}
		if(maxs)
			cout << "#"<<k << " " << maxs << "\n";
		else
			cout << "#" << k << " " << -1 << "\n";

	}
}
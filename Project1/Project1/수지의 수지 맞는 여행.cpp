#include<iostream>
#include<algorithm>

using namespace std;

int r, c;
char map[20][20];
int check[26];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
int maxs = 0;

void dfs(int y,int x,int cnt)
{
	if (cnt > maxs)
		maxs = cnt;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (nx<0 || ny<0 || nx>c - 1 || ny>r - 1)
			continue;
		int idx = map[ny][nx] - 'A';
		if (!check[idx])
		{
			check[idx] = 1;
			dfs(ny, nx,cnt+1);
			check[idx] = 0;
		}
	}
}

int main()
{
	int T;
	cin >> T;
	for (int k = 1; k <= T; k++)
	{
		maxs = 0;
		cin >> r >> c;
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				cin >> map[i][j];
			}
		}
		int num = map[0][0] - 'A';
		check[num] = 1;
		dfs(0, 0,1);
		check[num] = 0;

		cout << "#" << k << " " << maxs << "\n";
	}
}
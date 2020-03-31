#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>

using namespace std;

int n,k;
int map[8][8];
int check[8][8];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
vector<pair<int, int>> v;

int dfs(int y, int x,  int d)
{
	int tt = 0;
	int h = 0;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx<0 || ny<0 || nx>n - 1 || ny>n - 1||check[ny][nx])
			continue;
		if (map[ny][nx] < map[y][x])
		{
			check[ny][nx] = 1;
			h = max(h, dfs(ny, nx, d));
			check[ny][nx] = 0;
		}
		else
		{
			if (d&&map[ny][nx]-k<map[y][x])
			{
				tt = map[ny][nx];
				check[ny][nx] = 1;
				map[ny][nx] = map[y][x] - 1;
				h = max(h, dfs(ny, nx, 0));
				map[ny][nx] = tt;
				check[ny][nx] = 0;
			}
		}
	}
	h++;
	return h;
}

int main()
{
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		cin >> n >> k;
		int tmp = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> map[i][j];
				if (map[i][j] > tmp)
				{
					v.clear();
					v.push_back({ i,j });
					tmp = map[i][j];
				}
				else if (map[i][j] == tmp)
				{
					v.push_back({ i,j });
				}
			}
		}
		tmp = 0;
		for (int i = 0; i < v.size(); i++)
		{
			check[v[i].first][v[i].second] = 1;
			int res = dfs(v[i].first, v[i].second,1);
			if (res > tmp)
				tmp = res;
			check[v[i].first][v[i].second] = 0;
		}
		cout << "#" << t << " " << tmp << "\n";
		v.clear();
	}
}
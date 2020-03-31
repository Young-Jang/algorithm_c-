#include<iostream>
#include<map>

using namespace std;

int n, m;
int maps[1000][1000];
int check[1000][1000]; //0:group num, 1:cost
map<int,int> max_idx;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
int num = 2;


int dfs(int y, int x)
{
	int hap = 1;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (nx<0 || ny<0 || nx>m - 1 || ny>n - 1 || check[ny][nx]||maps[ny][nx])
			continue;
		check[ny][nx] = num;
		hap+=dfs(ny, nx);
	}
	return hap;
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%1d", &maps[i][j]);
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (!maps[i][j]&&!check[i][j])
			{
				check[i][j] = num;
				max_idx[num] = dfs(i, j);
				num++;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (maps[i][j])
			{
				int tmp[4] = { -1,-1,-1,-1 };
				for (int k = 0; k < 4; k++)
				{
					int y = i + dy[k];
					int x = j + dx[k];
					if (y<0 || x<0 || y>n - 1 || x>m - 1)
						continue;
					bool flag = true;
					for (int l = 0; l < k; l++)
					{
						if (check[y][x] == tmp[l])
						{
							flag = false;
							break;
						}
					}
					if (flag)
					{
						tmp[k] = check[y][x];
						maps[i][j] += max_idx[check[y][x]];
					}
				}
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << maps[i][j]%10;
		}
		cout << "\n";
	}
}
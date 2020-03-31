#include<iostream>

using namespace std;

int map[10][10];
int check[10][10];
int dx[4] = { -1,1,1,-1 };
int dy[4] = { -1,-1,1,1 };
int n;
int maxs = 0;

bool is_put(int y, int x)
{
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		while (ny >= 0 && nx >= 0 && ny < n && nx < n)
		{
			if (check[ny][nx] == 3)
				return false;
			nx += dx[i];
			ny += dy[i];
		}
	}
	return true;
}

void dfs(int y,int x,int cnt)
{
	if (maxs < cnt)
	{
		maxs = cnt;
	}
	int tmp = 0;
	if ((y + x) % 2 == 0)
	{
		tmp = 0;
	}
	else
		tmp = 1;
	for (int i = x; i < n; i+=2)
	{
		if (check[y][i]==1)
		{
			if (is_put(y, i))
			{
				check[y][i] = 3;
				for (int k = 0; k < 4; k++)
				{
					int nx = i + dx[k];
					int ny = y + dy[k];
					while (ny >= 0 && nx >= 0 && ny < n && nx < n)
					{
						if(check[ny][nx]==1)
							check[ny][nx] = 2;
						nx += dx[k];
						ny += dy[k];
					}
				}
				if (i >= n - 2)
				{
					if (i % 2 == 0)
					{
						dfs(y + 1, 1, cnt + 1);
					}
					else
					{
						dfs(y + 1, 0, cnt + 1);
					}
				}
				else
					dfs(y, i + 2, cnt + 1);
				check[y][i] = 1;
				for (int k = 0; k < 4; k++)
				{
					int nx = i + dx[k];
					int ny = y + dy[k];
					while (ny >= 0 && nx >= 0 && ny < n && nx < n)
					{
						if (check[ny][nx]==2)
							check[ny][nx] = 1;
						nx += dx[k];
						ny += dy[k];
					}
				}
			}
		}
	}
	int next = 0;
	for (int i = y+1; i < n; i++)
	{
		if (!tmp)
		{
			if (i % 2 == 0)
				next = 0;
			else
				next = 1;
		}
		else
		{
			if (i % 2 == 0)
				next = 1;
			else
				next = 0;
		}
		for (int j = next; j < n; j+=2)
		{
			if (check[i][j]==1)
			{
				if (is_put(i, j))
				{
					check[i][j] = 3;
					for (int k = 0; k < 4; k++)
					{
						int nx = j + dx[k];
						int ny = i + dy[k];
						while (ny >= 0 && nx >= 0 && ny < n && nx < n)
						{
							if (check[ny][nx]==1)
								check[ny][nx] = 2;
							nx += dx[k];
							ny += dy[k];
						}
					}
					if (j >= n - 2 && i < n - 1)
					{
						if (j % 2 == 0)
						{
							dfs(i + 1, 1, cnt + 1);
						}
						else
						{
							dfs(i + 1, 0, cnt + 1);
						}
					}
					else
						dfs(i, j + 2, cnt + 1);
					check[i][j] = 1;
					for (int k = 0; k < 4; k++)
					{
						int nx = j + dx[k];
						int ny = i + dy[k];
						while (ny >= 0 && nx >= 0 && ny < n && nx < n)
						{
							if (check[ny][nx]==2)
								check[ny][nx] = 1;
							nx += dx[k];
							ny += dy[k];
						}
					}
				}
			}
		}
	}
}

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
			check[i][j] = map[i][j];
		}
	}
	dfs(0,0,0);
	int res = maxs;
	maxs = 0;
	dfs(0, 1, 0);
	res += maxs;
	cout << res;
}

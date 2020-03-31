#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

char map[12][6];
int check[12][6];
vector<pair<int, int>> v;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
int c = 0;
bool flag = false;

int dfs(int y,int x,char c)
{
	int cnt = 1;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx>5 || ny>11||check[ny][nx]||map[ny][nx]!=c)
			continue;
		check[ny][nx] = 1;
		v.push_back({ ny,nx });
		cnt += dfs(ny, nx, c);
	}
	return cnt;
}

int main()
{
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			cin >> map[i][j];
		}
	}
	while (1)
	{
		flag = false;
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				if (map[i][j] != '.')
				{
					check[i][j] = 1;
					int hap = dfs(i, j, map[i][j]);
					if (hap >= 4)
					{
						v.push_back({ i,j });
						flag = true;
						for (int l = v.size()-1; l >=0; l--)
						{
							map[v[l].first][v[l].second] = '.';
						}
					}
					v.clear();
				}
			}
		}
		for (int l = 0; l < 6; l++)
		{
			for (int k = 11; k >= 0; k--)
			{
				if (map[k][l] != '.') {
					int tmp = k + 1;
					while (tmp <= 11 && map[tmp][l] == '.')
					{
						tmp++;
					}
					swap(map[k][l], map[tmp - 1][l]);
				}
			}
		}
		if (!flag)
			break;
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				check[i][j] = 0;
			}
		}
		c++;
	}
	cout << c;
}
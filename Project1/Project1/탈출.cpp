#include<iostream>
#include<queue>

using namespace std;

struct pos {
	int y, x;
};

char map[50][50];
char tmp[50][50];
int check[50][50];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
int n, m;
int tm = 1;
bool flag = true;

queue<pos> q;

void spread()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (tmp[i][j] == '*')
			{
				for (int k = 0; k < 4; k++)
				{
					int ny = i + dy[k];
					int nx = j + dx[k];
					if (nx<0 || ny<0 || nx>m - 1 || ny>n - 1 || map[ny][nx] != '.')
						continue;
					map[ny][nx] = '*';
				}
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			tmp[i][j] = map[i][j];
		}
	}
}

void bfs()
{
	while (!q.empty())
	{
		int y = q.front().y;
		int x = q.front().x;
		q.pop();
		if (check[y][x] == tm)
		{
			spread();
			tm++;
		}
		for (int k = 0; k < 4; k++)
		{
			int ny = y + dy[k];
			int nx = x + dx[k];
			if (map[ny][nx] == 'D')
			{
				while (!q.empty())
					q.pop();
				tm--;
				flag = false;
				break;
			}
			if (nx<0 || ny<0 || nx>m - 1 || ny>n - 1 || map[ny][nx] != '.'||check[ny][nx])
				continue;
			check[ny][nx] = check[y][x] + 1;
			q.push({ ny,nx });
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 'S')
			{
				q.push({ i,j });
				check[i][j] = 1;
				map[i][j] = '.';
			}
			tmp[i][j] = map[i][j];
		}
	}
	bfs();
	if (!flag)
		cout << tm;
	else
		cout << "KAKTUS";
}
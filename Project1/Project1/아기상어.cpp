#include<iostream>
#include<queue>

#define INF 987654321

using namespace std;

struct pos {
	int y,x;
};

int map[20][20];
int check[20][20];
int dy[4] = { -1,0,0,1 };
int dx[4] = { 0,-1,1,0 };
int n;
int tm = 0;
queue<pos> q;

void bfs()
{
	int sz = 2;
	int c = 0;
	int yy, xx;
	while (1)
	{
		yy = INF;
		xx = INF;
		int find = INF;
		while (!q.empty())
		{
			int y = q.front().y;
			int x = q.front().x;
			q.pop();
			if (check[y][x] > find)
			{
				while (!q.empty())
					q.pop();
				map[yy][xx] = 0;
				tm += check[y][x]-1;
				c++;
				continue;
			}
			for (int i = 0; i < 4; i++)
			{
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (nx >= 0 && ny >= 0 && nx < n && ny < n && !check[ny][nx])
				{
					if (map[ny][nx] && map[ny][nx] < sz)
					{
						find = check[y][x];
						if (yy > ny)
						{
							yy = ny;
							xx = nx;
						}
						else if (yy == ny)
						{
							if (xx > nx)
							{
								yy = ny;
								xx = nx;
							}
						}
					}
					else if (map[ny][nx] > sz)
						continue;
					check[ny][nx] = check[y][x]+1;
					q.push({ ny,nx });
				}
			}
		}
		if (c == sz)
		{
			c = 0;
			sz++;
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				check[i][j] = 0;
			}
		}
		if (find == INF)
		{
			break;
		}
		else
		{
			check[yy][xx] = 1;
			q.push({ yy,xx });
		}
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
			if (map[i][j] == 9)
			{
				map[i][j] = 0;
				check[i][j] = 1;
				q.push({ i,j});
			}
		}
	}
	bfs();
	cout << tm;
}
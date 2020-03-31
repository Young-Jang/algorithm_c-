#include<iostream>
#include<queue>

using namespace std;

struct pos {
	int y, x, d,c;
};

char map[50][50];
int check[50][50][5][3];
int n, m;
int posX[4] = { 0,1,0,-1 };
int posY[4] = { -1,0,1,0 };
int t[2][2];

int tm = 0;

bool flag = true;
queue<pos> q;

void bfs()
{
	while (!q.empty())
	{
		int y = q.front().y;
		int x = q.front().x;
		int d = q.front().d;
		int c = q.front().c;
		//cout << y << " " << x << " " << d << " " << check[y][x][d][c] << endl;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			if (d == i)
				continue;
			int nx = x + posX[i];
			int ny = y + posY[i];
			if (ny<0 || nx<0 || nx>m - 1 || ny>n - 1||check[ny][nx][i][c]||map[ny][nx]=='#')
				continue;
			if ((c == 1 && nx == t[0][1] && ny == t[0][0]) || (c == 2 && nx == t[1][1] && ny == t[1][0]))
				continue;
			if (map[ny][nx] == 'C')
			{
				if (!c)
				{
					if (ny == t[0][0] && nx == t[0][1])
					{
						check[ny][nx][i][1] = check[y][x][d][c] + 1;
						q.push({ ny,nx,i,1 });
					}
					else
					{
						check[ny][nx][i][2] = check[y][x][d][c] + 1;
						q.push({ ny,nx,i,2 });
					}
				}
				else
				{
					tm = check[y][x][d][c]+1;
					while (!q.empty())
						q.pop();
					break;
				}
			}
			else {
				check[ny][nx][i][c] = check[y][x][d][c] + 1;
				q.push({ ny,nx,i,c });
			}
		}
	}
}

int main()
{
	cin >> n >> m;
	int tmp = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 'C')
			{
				t[tmp][0] = i;
				t[tmp++][1] = j;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == 'S')
			{
				for (int k = 0; k < 4; k++)
				{
					int nx = j + posX[k];
					int ny = i + posY[k];
					if (ny<0 || nx<0 || nx>m - 1 || ny>n - 1 || map[ny][nx] == '#')
						continue;
					else if (map[ny][nx] == 'C')
					{
						if (ny == t[0][0] && nx == t[0][1])
						{
							check[ny][nx][k][1] = 1;
							q.push({ ny,nx,k,1 });
						}
						else
						{
							check[ny][nx][k][2] = 1;
							q.push({ ny,nx,k,2 });
						}
					}
					else
					{
						check[ny][nx][k][0] = 1;
						q.push({ ny,nx,k,0 });
					}
				}
			}
		}
	}
	bfs();
	if (tm == 0)
		cout << -1;
	else
		cout << tm;
}
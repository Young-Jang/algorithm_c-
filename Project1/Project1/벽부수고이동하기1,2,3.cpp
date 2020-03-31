#include<iostream>
#include<queue>

using namespace std;

struct pos {
	int y, x, c;
	bool d;
};

int n, m,k;
int map[1000][1000];
int check[1000][1000][11][2];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
queue<pos> q;
int mins = 0;

void bfs()
{
	q.push({ 0,0,0,0 });
	for (int i = 0; i <= k; i++)
	{
		check[0][0][i][0] = 1;
		check[0][0][i][1] = 1;
	}
	while (!q.empty())
	{
		int y = q.front().y;
		int x = q.front().x;
		int c = q.front().c;
		bool d = q.front().d;
		if (y == n - 1 && x == m - 1)
		{
			while (!q.empty())
				q.pop();
			mins = check[y][x][c][d];
			break;
		}
		q.pop();
		if (!check[y][x][c][!d])
		{
			check[y][x][c][!d] = check[y][x][c][d]+1;
			q.push({ y,x,c,!d });
		}
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx<0 || ny<0 || nx>m - 1 || ny>n - 1)
				continue;
			if (map[ny][nx] == 1 && c<k&&!d&&!check[ny][nx][c+1][!d])
			{
				check[ny][nx][c+1][!d] = check[y][x][c][d] + 1;
				q.push({ ny,nx,c+1,!d });
			}
			else if(!map[ny][nx]&&!check[ny][nx][c][!d]){
				check[ny][nx][c][!d] = check[y][x][c][d] + 1;
				q.push({ ny,nx,c,!d });
			}
		}
	}
}

int main()
{
	cin >> n >> m>>k;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%1d",&map[i][j]);
		}
	}
	bfs();
	if (!mins)
		mins = -1;
	cout << mins;
}
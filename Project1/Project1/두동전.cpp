#include<iostream>
#include<queue>

using namespace std;

struct pos {
	int x1, y1;
	int x2, y2;
	int cnt;
};

char map[20][20];
int posX[4] = { 0,1,0,-1 };
int posY[4] = { -1,0,1,0 };
int check[20][20][3];
int n, m;
int res = 0;
queue<pos> q;

void bfs()
{
	while (!q.empty())
	{
		int x1 = q.front().x1;
		int y1 = q.front().y1;
		int x2 = q.front().x2;
		int y2 = q.front().y2;
		int cnt = q.front().cnt;
		if (cnt > 10)
		{
			while (!q.empty())
				q.pop();
			break;
		}
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx1 = x1 + posX[i];
			int ny1 = y1 + posY[i];
			int nx2 = x2 + posX[i];
			int ny2 = y2 + posY[i];
			int out = 0;
			if (ny1<0 || nx1>m - 1 || ny1 > n - 1 || nx1 < 0)
			{
				out++;
			}
			else if (map[ny1][nx1] == '#')
			{
				ny1 = y1;
				nx1 = x1;				
			}

			if (ny2<0 || nx2>m - 1 || ny2 > n - 1 || nx2 < 0)
			{
				out++;
			}
			else if (map[ny2][nx2] == '#')
			{
				ny2 = y2;
				nx2 = x2;
			}
			
			if (out == 2)
				continue;
			else if (out == 1)
			{
				while (!q.empty())
					q.pop();
				res = cnt;
				break;
			}
			else
			{
				if (nx1 == nx2 && ny1 == ny2)
					continue;
				if (check[ny1][nx1][0]&&check[ny1][nx1][1]==ny2&&check[ny1][nx1][2]==nx2)
					continue;
				check[ny1][nx1][0] = 1;
				check[ny1][nx1][1] = ny2;
				check[ny1][nx1][2] = nx2;
				q.push({ nx1,ny1,nx2,ny2,cnt + 1 });
			}
		}
	}
}

int main()
{
	cin.ignore(0);
	cin.sync_with_stdio(0);
	cin >> n >> m;
	int t1=-1, t2=0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 'o')
			{
				if (t1 == -1)
				{
					t1 = i;
					t2 = j;
				}
				else
				{
					check[t1][t2][0] = 1;
					check[t1][t2][1] = i;
					check[t1][t2][2] = j;
					q.push({ t2,t1,j,i ,1});
				}
			}
		}
	}
	bfs();
	if (!res)
		res = -1;
	cout << res;
}
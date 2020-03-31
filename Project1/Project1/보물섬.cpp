#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int posX[4] = { 0,1,0,-1 };
int posY[4] = { -1,0,1,0 };

char map[50][50];
int check[50][50];
int r, c;
int maxs = 0;

queue<pair<int, int>> q; //y,x,cnt
int bfs(int a, int b)
{
	int local_max = 0;
	check[a][b] = 1;
	q.push(make_pair(a, b));
	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = y + posY[i];
			int nx = x + posX[i];
			if (ny<0 || nx<0 || nx>c - 1 || ny>r - 1)
				continue;
			if (map[ny][nx] == 'L' && !check[ny][nx])
			{
				check[ny][nx] = check[y][x] + 1;
				q.push(make_pair(ny, nx));
			}
		}
	}
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (check[i][j] > local_max)
				local_max = check[i][j];
			check[i][j] = 0;
		}
	}
	
return local_max;
}

int main()
{
	cin >> r >> c;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (map[i][j] == 'L')
			{
				maxs = max(maxs, bfs(i, j));
			}
		}
	}
	cout << maxs-1;
}
#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

int map[5][5][5][4];
int num[5];
int rot[5];
int check[5][5][5];
int tmp[5][5][5];

int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };

int start[5];//0: 처음 마지막 가능, 1: 불가능
int mins = 987654321;

struct pos {
	int y, x, layer;
};

queue<pos> q;

void rotate(int idx)
{
	if (idx == 5)
	{
		for (int k = 0; k < 5; k++) {
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					check[k][i][j] = 0;
					tmp[k][i][j] = map[num[k]][i][j][rot[k]];
				}
			}
		}
		check[0][0][0] = 1;
		q.push({ 0,0,0});
		while (!q.empty())
		{

			int y = q.front().y;
			int x = q.front().x;
			int layer = q.front().layer;
			q.pop();
			if (mins <= check[layer][y][x])
			{
				while (!q.empty())
				{
					q.pop();
				}
				break;
			}
			if (layer == 4 && y == 4 && x == 4)
			{
				if (mins > check[4][4][4])
				{
					mins = check[4][4][4];
				}
				while (!q.empty())
				{
					q.pop();
				}
				break;
			}
			int nx, ny;
			for (int i = 0; i < 4; i++)
			{
				nx = x + dx[i];
				ny = y + dy[i];
				if (nx < 0 || ny < 0 || nx>4 || ny>4 ||!tmp[layer][ny][nx]||check[layer][ny][nx])
					continue;
				check[layer][ny][nx] = check[layer][y][x] + 1;
				q.push({ ny, nx, layer});
			}
			if (layer > 0 && tmp[layer - 1][y][x]&&!check[layer-1][y][x])
			{
				check[layer - 1][y][x] = check[layer][y][x] + 1;
				q.push({ y,x,layer - 1 });
			}
			if (layer < 4 && tmp[layer + 1][y][x] && !check[layer + 1][y][x])
			{
				check[layer + 1][y][x] = check[layer][y][x] + 1;
				q.push({ y,x,layer + 1 });
			}
		}
		return;
	}
	for (int k = 0; k < 4; k++)
	{
		if ((!idx&&!map[num[idx]][0][0][k])|| (idx==4 && !map[num[idx]][4][4][k]))
			continue;
		if (mins == 13)
			return;
		rot[idx] = k;
		rotate(idx + 1);
	}
}

int main()
{
	for (int k = 0; k < 5; k++) {
		num[k] = k;
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				cin >> map[k][i][j][0];
			}
		}
		if (!map[k][0][0][0] && !map[k][4][0][0] && !map[k][0][4][0] && !map[k][4][4][0])
			start[k] = 1;
		else
			start[k] = 0;
	}
	for (int l = 1; l < 4; l++)
	{
		for (int k = 0; k < 5; k++) {
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					map[k][j][4-i][l] = map[k][i][j][l - 1];
				}
			}
		}
	}
	do {
		if (start[num[0]]|| start[num[4]])
			continue;
		rotate(0);
		if (mins == 13)
			break;
	} while (next_permutation(num, num + 5));
	if (mins == 987654321)
		cout << -1;
	else
		cout << mins-1;
}
#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int h,w;
char map[1000][1000];
int dx[8] = { 0,1,1,1,0,-1,-1,-1 };
int dy[8] = { -1,-1,0,1,1,1,0,-1 };
queue<pair<int,pair<int, int>>> q;

int flag = 0;

void bfs()
{
	while (!q.empty())
	{
		int c = q.front().first;
		int y = q.front().second.first;
		int x = q.front().second.second;
		q.pop();
		flag=c;
		for (int t = 0; t < 8; t++)
		{
			int ny = y + dy[t];
			int nx = x + dx[t];
			if (ny<0 || nx<0 || ny>h - 1 || nx>w - 1 || map[ny][nx] == '.' || map[ny][nx] == '0')
				continue;
			map[ny][nx]--;
			if (map[ny][nx]=='0')
			{
				q.push({ c + 1,{ny,nx} });
			}
		}
	}
}

int main()
{
	cin.sync_with_stdio(0);
	int T;
	cin >> T;
	char tmp;
	for (int k = 1; k <= T; k++)
	{
		flag = 0;
		cin >> h >> w;
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> map[i][j];
			}
		}
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (map[i][j] == '.')
				{
					for (int t = 0; t < 8; t++)
					{
						int ny = i + dy[t];
						int nx = j + dx[t];
						if (ny<0 || nx<0 || ny>h - 1 || nx>w - 1 || map[ny][nx]=='.'||map[ny][nx]=='0')
							continue;
						map[ny][nx]--;
						if (map[ny][nx]=='0')
						{
							q.push({1,{ ny,nx }});
						}
					}
				}
			}
		}
		bfs();
		cout << "#" << k << " " <<flag << "\n";
	}
}
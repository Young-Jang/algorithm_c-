#include<iostream>
#include<queue>
#include<vector>
#include<string.h>

using namespace std;

struct pos {
	int y, x;
};

int n, m;
int dx[2] = { 1,0 };
int dy[2] = { 0,1 };
char map[2000][2000];
int check[2000][2000];
vector<pos> v;
queue<pos> q;

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	int T;
	cin >> T;
	for (int k = 1; k <= T; k++)
	{
		memset(check, 0, sizeof(check));
		string str = "";
		cin >> n>>m;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> map[i][j];
			}
		}
		str = str + map[0][0];
		check[0][0] = 1;
		q.push({ 0,0 });
		char tmp = '{';
		while (!q.empty())
		{
			int y = q.front().y;
			int x = q.front().x;
			q.pop();
			if (y == n - 1 && x == m - 1)
			{
				while (!q.empty())
					q.pop();
				break;
			}
			for (int i = 0; i < 2; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx<0 || ny<0 || nx>m - 1 || ny>n - 1||check[ny][nx])
					continue;
				check[ny][nx] = 1;
				if (tmp > map[ny][nx])
				{
					v.clear();
					tmp = map[ny][nx];
					v.push_back({ ny,nx });
				}
				else if (tmp == map[ny][nx])
				{
					v.push_back({ ny,nx });
				}
			}
			if (q.empty())
			{
				str += tmp;
				tmp = '{';
				for (int i = 0; i < v.size(); i++)
				{
					q.push({ v[i].y,v[i].x});
				}
			}
		}
		cout << "#" << k << " " << str << "\n";
	}
}
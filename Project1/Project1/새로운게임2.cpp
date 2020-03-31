#include<iostream>
#include<vector>

using namespace std;

struct pos {
	int y;
	int x;
	int d;
};

int n, k;
int map[13][13];
vector<int> check[13][13];
pos h[11];
int posX[5] = { 0,1,-1,0,0 };
int posY[5] = { 0,0,0,-1,1 };
int tm = 0;

int swidir(int d)
{
	if (d == 1)
		return 2;
	else if (d == 2)
		return 1;
	else if (d == 3)
		return 4;
	else
		return 3;
}

int main()
{
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> map[i][j];
		}
	}
	for (int i = 1; i <= k; i++)
	{
		cin >> h[i].y >> h[i].x >> h[i].d;
		check[h[i].y][h[i].x].push_back(i);
	}
	int tmp = 0;
	int res = 0;
	while (tmp <= 1000)
	{
		tmp++;
		for (int i = 1; i <= k; i++)
		{
			int y = h[i].y;
			int x = h[i].x;
			int d = h[i].d;
			int nx = x + posX[d];
			int ny = y + posY[d];
			int idx = 0;
			/*cout << i << " " << d <<" "<< check[y][x].size()<< endl;
			for (int i = 1; i <= n; i++)
			{
				for (int j = 1; j <= n; j++)
				{
					if (check[i][j].size())
						cout << check[i][j][0] << " ";
					else
						cout << 0 << " ";
				}
				cout << endl;
			}
			cout << endl;*/
			while (i != check[y][x][idx])
			{
				idx++;
			}
			if(nx<1 || ny<1 || nx>n || ny>n || map[ny][nx] == 2){
				int nd = swidir(d);
				h[i].d = nd;
				nx = x + posX[nd];
				ny = y + posY[nd];
				if (nx<1 || ny<1 || nx>n || ny>n || map[ny][nx] == 2)
					continue;
				else
				{
					i--;
					continue;
				}
			}
			else if (!map[ny][nx])
			{
				if (check[y][x].size() + check[ny][nx].size() - idx >= 4)
				{
					res = tmp;
					tmp = 1001;
					break;
				}
				else
				{
					for (int j = idx; j < check[y][x].size(); j++)
					{
						h[check[y][x][j]].y = ny;
						h[check[y][x][j]].x = nx;
						check[ny][nx].push_back(check[y][x][j]);
					}
					check[y][x].erase(check[y][x].begin()+idx,check[y][x].end());
				}
			}
			else if (map[ny][nx] == 1)
			{
				if (check[y][x].size() + check[ny][nx].size()-idx >= 4)
				{
					res = tmp;
					tmp = 1001;
					break;
				}
				else
				{
					for (int j = check[y][x].size() - 1; j >= idx; j--)
					{
						h[check[y][x][j]].y = ny;
						h[check[y][x][j]].x = nx;
						check[ny][nx].push_back(check[y][x][j]);
					}
					check[y][x].erase(check[y][x].begin() + idx, check[y][x].end());
				}
			}
		}
	}
	if (!res)
		cout << -1;
	else
		cout << res;
}
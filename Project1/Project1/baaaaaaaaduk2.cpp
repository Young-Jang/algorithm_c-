//#include<iostream>
//#include<vector>
//#include<queue>
//
//using namespace std;
//
//int n, m;
//int map[20][20];
//int check[20][20];
//int touch[400];
//int dx[4] = { 0,1,0,-1 };
//int dy[4] = { -1,0,1,0 };
//int maxs = 0;
//
//vector<int>t;
//
//vector<pair<int, int>> v;
//
//vector<pair<int, int>>black[400];
//queue<pair<int, int>>q;
//
//int erase(int i)
//{
//	int cnt = 0;
//	for (int k = 0; k < 4; k++)
//	{
//		int nx = v[i].second + dx[k];
//		int ny = v[i].first + dy[k];
//		if (nx<0 || ny<0 || nx>m - 1 || ny>n - 1 || !check[ny][nx] || touch[check[ny][nx]])
//			continue;
//		int idx = check[ny][nx];
//		touch[idx] = 1;
//		t.push_back(idx);
//		int tmp = black[idx].size();
//		bool flag = true;
//		for (int l = 0; l < tmp; l++)
//		{
//			for (int t = 0; t < 4; t++)
//			{
//				int nnx = black[idx][l].second + dx[t];
//				int nny = black[idx][l].first + dy[t];
//				if (nnx<0 || nny<0 || nnx>m - 1 || nny>n - 1 || map[nny][nnx] != 0)
//					continue;
//				flag = false;
//				break;
//			}
//			if (!flag)
//				break;
//		}
//		if (flag)
//			cnt += tmp;
//	}
//	return cnt;
//}
//
//int main()
//{
//	cin >> n >> m;
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			cin >> map[i][j];
//		}
//	}
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			if (map[i][j]==2)
//			{
//				for (int k = 0; k < 4; k++)
//				{
//					int nx = j + dx[k];
//					int ny = i + dy[k];
//					if (nx<0 || ny<0 || nx>m - 1 || ny>n - 1 ||check[ny][nx]||map[ny][nx])
//						continue;
//					check[ny][nx] = 1;
//				}
//			}
//		}
//	}
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			if (check[i][j])
//			{
//				v.push_back({ i,j });
//				check[i][j] = 0;
//			}
//		}
//	}
//	int idx = 1;
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			if (map[i][j]==2&&!check[i][j])
//			{
//				q.push({ i,j });
//				check[i][j] = idx;
//				black[idx].push_back({ i,j });
//				int cnt = 1;
//				while (!q.empty())
//				{
//					int y = q.front().first;
//					int x = q.front().second;
//					q.pop();
//					for (int k = 0; k < 4; k++)
//					{
//						int nx = x + dx[k];
//						int ny = y + dy[k];
//						if (nx<0 || ny<0 || nx>m - 1 || ny>n - 1 || map[ny][nx] != 2 || check[ny][nx])
//							continue;
//						check[ny][nx] = idx;
//						black[idx].push_back({ ny,nx });
//						q.push({ ny,nx });
//					}
//				}
//				idx++;
//			}
//		}
//	}
//
//	int sz = v.size();
//	for (int i = 0; i < sz; i++)
//	{
//		for (int j = i+1; j < sz; j++)
//		{
//			int cnt = 0;
//			map[v[i].first][v[i].second] = 1;
//			map[v[j].first][v[j].second] = 1;
//			cnt += erase(i);
//			cnt += erase(j);
//			if (cnt > maxs)
//				maxs = cnt;
//			int ssz = t.size();
//			for (int k = ssz-1; k >= 0; k--)
//			{
//				touch[t[k]] = 0;
//				t.pop_back();
//			}
//			map[v[i].first][v[i].second] = 0;
//			map[v[j].first][v[j].second] = 0;
//		}
//	}
//	cout << maxs;
//}

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;


struct pos {
	int block;
	int cnt;
	int y1, x1, y2, x2;
};

int n, m;
int map[1000][1000];
int check[1000][1000];
vector<pos> touch; //0 그룹 몇개 막아야하는지(-1,1,2), 1 그룹내 갯수
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
int maxs = 0;

queue<pair<int, int>>q;
int p[2][2];

void find(int i,int j)
{
	q.push({ i,j });
	check[i][j] = 1;
	int ncnt = 1;
	int cnt = 0;
	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++)
		{
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx<0 || ny<0 || nx>m - 1 || ny>n - 1 || check[ny][nx] || map[ny][nx] == 1)
				continue;
			if (!map[ny][nx])
			{
				cnt++;
				if (cnt > 2)
				{
					continue;
				}
				p[cnt-1][0] = ny;
				p[cnt-1][1] = nx;
				check[ny][nx] = 1;
			}
			else {
				ncnt++;
				check[ny][nx] = 1;
				q.push({ ny,nx });
			}
		}
	}
	if (cnt == 2)
	{
		touch.push_back({ 2,ncnt,p[0][0],p[0][1],p[1][0],p[1][1] });
		check[p[0][0]][p[0][1]] = 0;
		check[p[1][0]][p[1][1]] = 0;
 	}
	else if (cnt == 1)
	{
		touch.push_back({ 1,ncnt,p[0][0],p[0][1],-1,-1 });
		check[p[0][0]][p[0][1]] = 0;
	}
	else
	{
		check[p[0][0]][p[0][1]] = 0;
		check[p[1][0]][p[1][1]] = 0;
	}
}

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == 2 && !check[i][j])
			{
				find(i, j);
				p[0][0] = 0;
				p[0][1] = 0;
				p[1][0] = 0;
				p[1][1] = 0;
			}
		}
	}

	int sz = touch.size();
	for (int i = 0; i < sz; i++)
	{
		for (int j = i+1; j < sz; j++)
		{
			if (touch[i].block < touch[j].block)
				swap(touch[i], touch[j]);
		}
	}
	bool flag = false;
	for (int i = 0; i < sz; i++)
	{
		int hap = touch[i].cnt;
		if (touch[i].block == 2)
		{
			for (int j = i + 1; j < sz; j++)
			{
				if (touch[j].block == 2)
				{
					if (touch[i].x1 == touch[j].x1 && touch[i].x2 == touch[j].x2 && touch[i].y1 == touch[j].y1 && touch[i].y2 == touch[j].y2)
					{
						hap += touch[j].cnt;
						touch[j].block = -1;
					}
					else if (touch[i].x1 == touch[j].x2 && touch[i].x2 == touch[j].x1 && touch[i].y1 == touch[j].y2 && touch[i].y2 == touch[j].y1)
					{
						hap += touch[j].cnt;
						touch[j].block = -1;
					}
				}
				else if (touch[j].block == 1)
				{
					if ((touch[i].x1 == touch[j].x1 && touch[i].y1 == touch[j].y1) || (touch[i].y2 == touch[j].y1 && touch[i].x2 == touch[j].x1))
					{
						hap += touch[j].cnt;
					}
				}
			}
		}
		else if(touch[i].block==1)
		{
			if (!flag) {
				for (int j = i; j < sz; j++)
				{
					for (int l = j+1; l < sz; l++)
					{
						if (touch[j].x1 == touch[l].x1 && touch[j].y1 == touch[l].y1)
						{
							touch[j].cnt += touch[l].cnt;
							touch[l].cnt = 0;
						}
					}
				}
				flag = true;
				hap = touch[i].cnt;
			}
			for (int j = i + 1; j < sz; j++)
			{
				if (touch[j].cnt + hap > maxs)
					maxs = touch[j].cnt + hap;
			}
		}
		if (maxs < hap)
			maxs = hap;
	}
	cout << maxs;
}

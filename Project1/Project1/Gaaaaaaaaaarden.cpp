#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct pos {
	int y, x, c, num;
};

int map[50][50];
int tmp[50][50];
int sp[50][50];
int check[10]; //¹è¾ç¾× »Ñ¸±¼ö ÀÖ´Â ¶¥
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
int n, m, g, r;
int maxs = 0;

vector<pair<int, int>> v;
vector<int>r_idx;
vector<int>g_idx;

vector<pair<int, int>> nidx;

queue<pos> q;

int spread()
{
	int idx = 0;
	int hap = 0;
	for (int i = 0; i < r_idx.size(); i++)
	{
		tmp[v[r_idx[i]].first][v[r_idx[i]].second] = 3;
		q.push({ v[r_idx[i]].first,v[r_idx[i]].second,1 ,0 });
	}
	for (int i = 0; i < g_idx.size(); i++)
	{
		tmp[v[g_idx[i]].first][v[g_idx[i]].second] = 3;
		q.push({ v[g_idx[i]].first,v[g_idx[i]].second,2,0 });
	}
	while (!q.empty())
	{
		int y = q.front().y;
		int x = q.front().x;
		int c = q.front().c;
		int num = q.front().num;
		q.pop();
		if (tmp[y][x] == 4)
			continue;
		if (idx != num)
		{
			idx = num;
			for (int i = 0; i < nidx.size(); i++)
			{
				if (sp[nidx[i].first][nidx[i].second])
				{
					tmp[nidx[i].first][nidx[i].second] = 3;
					sp[nidx[i].first][nidx[i].second] = 0;
				}
			}
							nidx.clear();
		}
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx<0 || ny<0 || nx>m - 1 || ny>n - 1 || tmp[ny][nx] == 3 || tmp[ny][nx] == 0 || tmp[ny][nx] == 4)
				continue;

			if ((sp[ny][nx] == 1 && c == 2) || (sp[ny][nx] == 2 && c == 1))
			{
				hap++;
				tmp[ny][nx] = 4;
				sp[ny][nx] = 0;
			}
			else if (!sp[ny][nx])
			{
				q.push({ ny,nx,c,num + 1 });
				sp[ny][nx] = c;
				nidx.push_back({ ny,nx });
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			tmp[i][j] = map[i][j];
			sp[i][j] = 0;
		}
	}
	return hap;
}

void select(int start, int gcnt, int rcnt)
{

	int range = r + g;
	int hap = gcnt + rcnt;
	if (hap == range)
	{
		int res = spread();
		if (res > maxs)
			maxs = res;
		return;
	}
	int sz = v.size();
	for (int i = start; i < sz; i++)
	{
		if (check[i])
			continue;
		if (hap + sz - i < range)
			return;
		if (rcnt < r) {
			check[i] = 1;
			r_idx.push_back(i);
			select(i + 1, gcnt, rcnt + 1);
			r_idx.pop_back();
			check[i] = 0;
		}
		if (gcnt < g) {
			check[i] = 1;
			g_idx.push_back(i);
			select(i + 1, gcnt + 1, rcnt);
			g_idx.pop_back();
			check[i] = 0;
		}
	}
}

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cin >> n >> m >> g >> r;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
			tmp[i][j] = map[i][j];
			if (map[i][j] == 2)
				v.push_back({ i,j });
		}
	}
	select(0, 0,0);
	cout << maxs;
}

//#include<iostream>
//#include<vector>
//#include<queue>
//#include<algorithm>
//
//
//using namespace std;
//
//struct pos {
//	int y, x, c, num;
//};
//
//int map[50][50];
//int tmp[50][50];
//int sp[50][50];
//int check[10]; //¹è¾ç¾× »Ñ¸±¼ö ÀÖ´Â ¶¥
//int dx[4] = { 0,1,0,-1 };
//int dy[4] = { -1,0,1,0 };
//int n, m, g, r;
//int maxs = 0;
//int color[11];
//int ssz = 0;
//
//vector<pair<int, int>> v;
//vector<int>r_idx;
//vector<int>g_idx;
//
//vector<pair<int, int>> nidx;
//
//queue<pos> q;
//
//int spread()
//{
//	int idx = 0;
//	int hap = 0;
//	bool flag[3] = {false, false ,false};
//
//	for (int i = 0; i < ssz; i++)
//	{
//		if (color[i] == 1)
//		{
//			tmp[v[i].first][v[i].second] = 3;
//			q.push({ v[i].first,v[i].second,1,0 });
//		}
//		else if (color[i] == 2)
//		{
//			tmp[v[i].first][v[i].second] = 3;
//			q.push({ v[i].first,v[i].second,2,0 });
//		}
//	}
//	while (!q.empty())
//	{
//		int y = q.front().y;
//		int x = q.front().x;
//		int c = q.front().c;
//		int num = q.front().num;
//		q.pop();
//		if (tmp[y][x] == 4)
//			continue;
//		if (idx != num)
//		{
//			idx = num;
//			if (!flag[1] || !flag[2])
//			{
//				while (!q.empty())
//					q.pop();
//				break;
//			}
//			for (int i = 0; i < nidx.size(); i++)
//			{	
//				if (sp[nidx[i].first][nidx[i].second])
//				{
//					tmp[nidx[i].first][nidx[i].second] = 3;
//					sp[nidx[i].first][nidx[i].second] = 0;
//				}
//			}
//			nidx.clear();
//			flag[2] = false;
//			flag[1] = false;
//		}
//		for (int i = 0; i < 4; i++)
//		{
//			int nx = x + dx[i];
//			int ny = y + dy[i];
//			if (nx<0 || ny<0 || nx>m - 1 || ny>n - 1 || tmp[ny][nx] == 3 || tmp[ny][nx] == 0 || tmp[ny][nx] == 4)
//				continue;
//			if ((sp[ny][nx] == 1 && c == 2) || (sp[ny][nx] == 2 && c == 1))
//			{
//				hap++;
//				tmp[ny][nx] = 4;
//				sp[ny][nx] = 0;
//			}
//			else if (!sp[ny][nx])
//			{
//				q.push({ ny,nx,c,num + 1 });
//				sp[ny][nx] = c;
//				nidx.push_back({ ny,nx });
//				flag[c] = true;
//			}
//		}
//	}
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			tmp[i][j] = map[i][j];
//			sp[i][j] = 0;
//		}
//	}
//	return hap;
//}
//int main()
//{
//	cin.tie(0);
//	cin.sync_with_stdio(0);
//	cin >> n >> m >> g >> r;
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			cin >> map[i][j];
//			tmp[i][j] = map[i][j];
//			if (map[i][j] == 2)
//				v.push_back({ i,j });
//		}
//	}
//	ssz = v.size();
//	for (int i = 0; i < ssz -r-g; i++)
//	{
//		color[i] = 0;
//	}
//	for (int i = 0; i < r; i++)
//	{
//		color[i+ ssz - r - g] = 1;
//	}
//	for (int i = 0; i < g; i++)
//	{
//		color[i+ ssz - g] = 2;
//	}
//	do {
//		int res = spread();
//		if (maxs < res)
//			maxs = res;
//	} while (next_permutation(color, color + ssz));
//	cout << maxs;
//}




//#include<iostream>
//#include<vector>
//#include<queue>
//#include<time.h>
//
//using namespace std;
//
//struct pos {
//	int y, x, c, num;
//};
//
//int map[50][50];
//int tmp[50][50];
//int sp[50][50];
//int check[10]; //¹è¾ç¾× »Ñ¸±¼ö ÀÖ´Â ¶¥
//int dx[4] = { 0,1,0,-1 };
//int dy[4] = { -1,0,1,0 };
//int n, m, g, r;
//int maxs = 0;
//
//vector<pair<int, int>> v;
//vector<int>r_idx;
//vector<int>g_idx;
//
//queue<pos> q;
//
//int spread()
//{
//	int idx = 0;
//	int hap = 0;
//	for (int i = 0; i < r_idx.size(); i++)
//	{
//		tmp[v[r_idx[i]].first][v[r_idx[i]].second] = 3;
//		q.push({ v[r_idx[i]].first,v[r_idx[i]].second,1 ,0 });
//	}
//	for (int i = 0; i < g_idx.size(); i++)
//	{
//		tmp[v[g_idx[i]].first][v[g_idx[i]].second] = 3;
//		q.push({ v[g_idx[i]].first,v[g_idx[i]].second,2,0 });
//	}
//	while (!q.empty())
//	{
//		int y = q.front().y;
//		int x = q.front().x;
//		int c = q.front().c;
//		int num = q.front().num;
//		q.pop();
//		if (tmp[y][x] == 4)
//			continue;
//		if (idx != num)
//		{
//			idx = num;
//			for (int i = 0; i < n; i++)
//			{
//				for (int j = 0; j < m; j++)
//				{
//					if (sp[i][j])
//					{
//						tmp[i][j] = 3;
//						sp[i][j] = 0;
//					}
//				}
//			}
//		}
//		for (int i = 0; i < 4; i++)
//		{
//			int nx = x + dx[i];
//			int ny = y + dy[i];
//			if (nx<0 || ny<0 || nx>m - 1 || ny>n - 1 || tmp[ny][nx] == 3 || tmp[ny][nx] == 0 || tmp[ny][nx] == 4)
//				continue;
//
//			if ((sp[ny][nx] == 1 && c == 2) || (sp[ny][nx] == 2 && c == 1))
//			{
//				hap++;
//				tmp[ny][nx] = 4;
//				sp[ny][nx] = 0;
//			}
//			else if (!sp[ny][nx])
//			{
//				q.push({ ny,nx,c,num + 1 });
//				sp[ny][nx] = c;
//			}
//		}
//	}
//
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			tmp[i][j] = map[i][j];
//			sp[i][j] = 0;
//		}
//	}
//	return hap;
//}
//
//void select_green(int start, int cnt)
//{
//	if (cnt == g)
//	{
//		int res = spread();
//		if (res > maxs)
//			maxs = res;
//		return;
//	}
//	int sz = v.size();
//	for (int i = start; i < sz; i++)
//	{
//		if (check[i])
//			continue;
//		check[i] = 1;
//		g_idx.push_back(i);
//		select_green(i + 1, cnt + 1);
//		g_idx.pop_back();
//		check[i] = 0;
//	}
//}
//void select_red(int start, int cnt)
//{
//	if (cnt == r)
//	{
//		select_green(0, 0);
//		return;
//	}
//	int sz = v.size();
//	for (int i = start; i < sz; i++)
//	{
//		if (check[i])
//			continue;
//		if (cnt + sz - i < r)
//			return;
//		check[i] = 1;
//		r_idx.push_back(i);
//		select_red(i + 1, cnt + 1);
//		r_idx.pop_back();
//		check[i] = 0;
//	}
//}
//
//int main()
//{
//	cin.tie(0);
//	cin.sync_with_stdio(0);
//	clock_t s = clock();
//	cin >> n >> m >> g >> r;
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			cin >> map[i][j];
//			tmp[i][j] = map[i][j];
//			if (map[i][j] == 2)
//				v.push_back({ i,j });
//		}
//	}
//	select_red(0, 0);
//	cout << maxs;
//	clock_t e = clock();
//	cout << (double)(e - s);
//}
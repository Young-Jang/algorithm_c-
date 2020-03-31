#include<iostream>
#include<queue>
#include<algorithm>

#define INF 987654321

using namespace std;

int n, e;
int map[801][801];
int tmp[801][801];
long long mins[801];
long long leng[3][4];
int pt[2];

struct pos {
	long long len;
	int num;
};

struct cmp {
	bool operator()(pos a, pos b)
	{
		return a.len > b.len;
	}
};

priority_queue<pos, vector<pos>, cmp> q;

void dijkstra(int k)
{
	while (!q.empty())
	{
		long long v = q.top().len;
		int num = q.top().num;
		q.pop();
		if (v > mins[num])
			continue;
		for (int i = 1; i <= n; i++)
		{
			if (mins[i] > mins[num] + map[i][num])
			{
				mins[i] = mins[num] + map[i][num];
				map[i][num] = INF;
				map[num][i] = INF;
				q.push({ mins[i],i });
			}
		}
	}
	leng[k][0] = mins[1];
	leng[k][1] = mins[pt[0]];
	leng[k][2] = mins[pt[1]];
	leng[k][3] = mins[n];
	for (int i = 1; i <= n; i++)
	{
		mins[i] = INF;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			map[i][j] = tmp[i][j];
		}
	}
}

int main()
{
	cin >> n >> e;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			map[i][j] = INF;
			tmp[i][j] = INF;
		}
	}
	long long a, b, c;
	for (int i = 0; i < e; i++)
	{
		cin >> a >> b >> c;
		map[a][b] = c;
		map[b][a] = c;
		tmp[a][b] = c;
		tmp[b][a] = c;
	}

	for (int i = 1; i <= n; i++)
	{
		mins[i] = INF;
	}
	cin >> pt[0] >> pt[1];
	for (int j = 1; j <= n; j++)
	{
		if (map[1][j] != INF)
		{
			mins[j] = map[1][j];
			q.push({ map[1][j],j });
			map[j][1] = INF;
			map[1][j] = INF;
		}
	}
	dijkstra(0);
	for (int j = 1; j <= n; j++)
	{
		if (map[pt[0]][j] != INF)
		{
			mins[j] = map[pt[0]][j];
			q.push({ map[pt[0]][j],j });
			map[j][pt[0]] = INF;
			map[pt[0]][j] = INF;
		}
	}
	dijkstra(1);
	for (int j = 1; j <= n; j++)
	{
		if (map[pt[1]][j] != INF)
		{
			mins[j] = map[pt[1]][j];
			q.push({ map[pt[1]][j],j });
			map[j][pt[1]] = INF;
			map[pt[1]][j] = INF;
		}
	}
	dijkstra(2);
	long long res = 0;
	if (pt[0] == 1)
	{
		if (pt[1] == n)
		{
			res = leng[0][3];
		}
		else {
			res = leng[0][2] + leng[2][3];
		}
	}
	else if (pt[1] == 1)
	{
		if (pt[0] == n)
		{
			res = leng[0][3];
		}
		else {
			res = leng[0][1] + leng[1][3];
		}
	}
	else if (pt[0] == n)
	{
		if (pt[1] == 1)
		{
			res = leng[0][3];
		}
		else {
			res = leng[0][2] + leng[2][3];
		}
	}
	else if (pt[1] == n)
	{
		if (pt[0] == 1)
		{
			res = leng[0][3];
		}
		else {
			res = leng[0][1] + leng[1][3];
		}
	}
	else
	{
		a = leng[0][1] + leng[1][2] + leng[2][3];
		b = leng[0][2] + leng[2][1] + leng[1][3];
		res = min(a, b);
	}
	if (res >= INF||res<=0)
		cout << -1;
	else
		cout << res;
}

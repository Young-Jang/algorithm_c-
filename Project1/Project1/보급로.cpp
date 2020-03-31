//#include<iostream>
//#include<queue>
//
//using namespace std;
//
//priority_queue <pair<int, pair<int, int>>> pq;
//int map[100][100];
//int leng[100][100];
//int dx[4] = { 0,1,0,-1 };
//int dy[4] = { -1,0,1,0 };
//int n;
//
//void dijkstra()
//{
//	while (!pq.empty())
//	{
//		int y = pq.top().second.first;
//		int x = pq.top().second.second;
//		int v = -pq.top().first;
//		pq.pop();
//		if (y == n - 1 && x == n - 1)
//		{
//			while (!pq.empty())
//				pq.pop();
//			break;
//		}
//		if (leng[y][x] < v)
//			continue;
//		for (int i = 0; i < 4; i++)
//		{
//			int nx = x + dx[i];
//			int ny = y + dy[i];
//			if (nx<0 || ny<0 || nx>n - 1 || ny>n - 1)
//				continue;
//			if (leng[ny][nx] > v + map[ny][nx])
//			{
//				leng[ny][nx] = v + map[ny][nx];
//				pq.push({ -leng[ny][nx], { ny,nx } });
//			}
//		}
//	}
//}
//
//int main()
//{
//	int T;
//	cin >> T;
//	for (int k = 1; k <= T;k++)
//	{
//		cin >> n;
//		for (int i = 0; i < n; i++)
//		{
//			for (int j = 0; j < n; j++)
//			{
//				scanf("%1d",&map[i][j]);
//				leng[i][j] = 111111;
//			}
//		}
//		leng[0][0] = 0;
//		pq.push({ -map[1][0],{1,0} });
//		leng[1][0] = map[1][0];
//		leng[0][1] = map[0][1];
//		pq.push({ -map[0][1],{0,1} });
//		dijkstra();
//		cout << "#" << k << " " << leng[n - 1][n - 1] << "\n";
//	}
//}

#include<iostream>

#define INF 987654321

using namespace std;

int map[100][100];
int check[100][100];
int dp[100][100];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
int n;
int mins = INF;

void dfs(int y, int x, int hap)
{
	if (y == n - 1 && x == n - 1)
	{
		if (mins > hap)
			mins = hap;
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx<0 || ny<0 || nx>n - 1 || ny>n - 1 || check[ny][nx])
			continue;
		int tmp = hap + map[ny][nx];
		if (tmp < mins && dp[ny][nx] > tmp)
		{
			check[ny][nx] = 1;
			dp[ny][nx] = tmp;
			dfs(ny, nx, hap + map[ny][nx]);
			check[ny][nx] = 0;
		}
	}
}

int main()
{
	int T;
	cin >> T;
	for (int k = 1; k <= T; k++)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				scanf("%1d", &map[i][j]);
				dp[i][j] = INF;
			}
		}
		int tx = 0;
		int ty = 0;
		int th = 0;
		while ((tx!=n-1)||(ty!=n-1))
		{
			if (tx == n - 1)
			{
				while (ty != n - 1)
				{
					ty++;
					th += map[ty][tx];
				}
			}
			else if (ty == n - 1)
			{
				while (tx != n - 1)
				{
					tx++;
					th += map[ty][tx];
				}
			}
			else
			{
				if (map[ty + 1][tx] > map[ty][tx + 1])
				{
					tx++;
					th += map[ty][tx];
				}
				else
				{
					ty++;
					th += map[ty][tx];
				}
			}
		}
		mins = th;

		check[0][0] = 1;
		dfs(0, 0,0);
		cout << "#" << k << " " << mins << "\n";
	}
}
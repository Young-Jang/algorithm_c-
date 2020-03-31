#include<iostream>

using namespace std;

int n, m;
int graph[11][11];
int check[11];

int dfs(int a)
{
	int mm=1;
	check[a] = 1;
	for (int i = 1; i <= n; i++)
	{
		if (!check[i] && graph[a][i])
		{
			int cnt = dfs(i)+1;
			if (mm < cnt)
				mm = cnt;
		}
	}
	check[a] = 0;
	return mm;
}

int main()
{
	int T;
	cin >> T;
	for (int k = 1; k <= T; k++)
	{
		cin >> n >> m;
		int a, b;
		int res = 0;
		for (int i = 0; i < m; i++)
		{
			cin >> a >> b;
			graph[a][b] = 1;
			graph[b][a] = 1;
		}
		for (int i = 1; i <= n; i++)
		{
			int c = dfs(i);
			if (c > res)
				res = c;
		}
		cout << "#" << k << " " << res << "\n";
		for (int i = 1; i <= n; i++)
		{
			check[i] = 0;
			for (int j = 1; j <= n; j++)
			{
				graph[i][j] = 0;
			}
		}
	}
}

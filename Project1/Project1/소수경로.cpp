#include<iostream>
#include<queue>
#include<cmath>

using namespace std;

int sosu[10000];
int check[10000];
int n1, n2;
int res = 0;

queue<pair<int,int>> q;

void bfs()
{
	while (!q.empty())
	{
		int n = q.front().first;
		int c = q.front().second;
		q.pop();
		int tmp = n;
		for (int i = 0; i < 4; i++)
		{
			int nx = pow(10, i);
			tmp = n;
			for (int j = 0; j <= 9; j++)
			{
				if (i == 3 && j == 0)
					continue;
				tmp = tmp - (((tmp/nx)%10)*nx);
				tmp += nx * j;
				if (!check[tmp]&&!sosu[tmp])
				{
					if (tmp == n2)
					{
						i = 4;
						while (!q.empty())
							q.pop();
						res = c + 1;
						break;
					}
					check[tmp] = 1;
					q.push({ tmp,c + 1 });
				}
			}
		}
	}
}

int main()
{
	sosu[0] = 1;
	sosu[1] = 1;
	for (int i = 2; i < 10000; i++)
	{
		if (!sosu[i]) {
			for (int j = 2; j < 5000; j++)
			{
				if (i * j >= 10000)
					break;
				sosu[i * j] = 1;
			}
		}
	}
	int T;
	cin >> T;
	for (int k = 1; k <= T; k++)
	{
		res = 0;
		cin >> n1 >> n2;
		if (n1 == n2)
		{
			cout << 0 << "\n";
			continue;
		}
		q.push({ n1,0 });
		check[n1] = 1;
		bfs();
		if (!res)
			cout << "Impossible" << "\n";
		else
			cout << res << "\n";
		for (int i = 1000; i < 10000; i++)
			check[i] = 0;
	}
}
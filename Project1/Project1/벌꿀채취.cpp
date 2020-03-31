#include<iostream>

using namespace std;

int n, m,c;
int map[10][10];
int d[10][10];
int maxs = 0;
int tmp = 0;

void max_num(int sy,int sx,int sz,int hap,int mm)
{
	if (sz <= sx)
	{
		if (tmp < mm)
			tmp = mm;
		return;
	}
	for (int i = sx; i < sz; i++)
	{
		if (hap + map[sy][i] <= c)
			max_num(sy, i + 1, sz, hap + map[sy][i],mm+(map[sy][i]*map[sy][i]));
		else
			max_num(sy, i + 1, sz, hap,mm);
	}
}

void find(int y, int x)
{
	int hap = d[y][x];
	for (int j = x + m; j < n - m + 1; j++)
	{
		if (hap + d[y][j] > maxs)
			maxs = hap + d[y][j];
	}
	for (int i = y+1; i < n; i++)
	{
		for (int j = 0; j < n - m + 1; j++)
		{
			if (hap + d[i][j] > maxs)
				maxs = hap + d[i][j];
		}
	}
}

int main()
{
	int T;
	cin >> T;
	for (int k = 1; k <= T; k++)
	{
		maxs = 0;
		cin >> n >> m>>c;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> map[i][j];
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n-m+1; j++)
			{
				max_num(i, j,j+m,0,0);
				d[i][j] = tmp;
				tmp = 0;
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n - m + 1; j++)
			{
				find(i, j);
			}
		}
		cout << "#" << k << " " << maxs << "\n";

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n - m + 1; j++)
			{
				d[i][j] = 0;
			}
		}
	}
}
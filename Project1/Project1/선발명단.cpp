#include<iostream>

using namespace std;

int m[11][11];
int maxs = 0;

void dfs(int nx,int check,int hap)
{
	if(check == (1<<11)-1)
	{
		if (maxs < hap)
			maxs = hap;
	}
	for (int i = 0; i < 11; i++)
	{
		if (check & 1 << i || !m[nx][i])
			continue;
		dfs(nx + 1, check | 1 << i,hap+m[nx][i]);
	}
}
int main()
{
	int T;
	cin >> T;
	for (int k = 0; k < T; k++)
	{
		maxs = 0;
		for (int i = 0; i < 11; i++)
		{
			for (int j = 0; j < 11; j++)
			{
				cin >> m[i][j];
			}
		}
		dfs(0, 0, 0);
		cout << maxs << "\n";
	}
}
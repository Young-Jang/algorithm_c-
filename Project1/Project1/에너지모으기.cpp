#include<iostream>

using namespace std;

int n;
int e[10];
int maxs = 0;

void dfs(int cnt, int hap)
{
	if (cnt == n - 2)
	{
		if (maxs < hap)
			maxs = hap;
		return;
	}
	int low = 0;
	int high = 0;
	for (int i = 1; i < n - 1; i++)
	{
		if (!e[i])
			continue;
		int tmp1 = i-1;
		int tmp2 = i+1;
		while (tmp1>=0&&!e[tmp1])
		{
			tmp1--;
		}
		if (tmp1 < 0)
			continue;
		low = e[tmp1];
		while (tmp2 <= n-1 && !e[tmp2])
		{
			tmp2++;
		}
		if (tmp2 > n-1)
			continue;
		high = e[tmp2];
		tmp1 = e[i];
		e[i] = 0;
		dfs(cnt + 1, hap + (high * low));
		e[i] = tmp1;
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> e[i];
	dfs(0, 0);
	cout << maxs;
}
#include<iostream>

using namespace std;

int egg[8][2];
int check[8];
int n;
int maxs = 0;

void crash(int idx)
{
	if (idx == n)
	{
		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			if (egg[i][0]<=0)
				cnt++;
		}
		if (maxs < cnt)
			maxs = cnt;
		return;
	}
	if (egg[idx][0] <= 0)
	{
		crash(idx + 1);
		return;
	}
	bool flag = false;
	for (int i = 0; i < n; i++)
	{
		if (idx == i)
			continue;
		if (egg[i][0]>0)
		{
			egg[idx][0] -= egg[i][1];
			egg[i][0] -= egg[idx][1];
			crash(idx + 1);
			egg[idx][0] += egg[i][1];
			egg[i][0] += egg[idx][1];
			flag = true;
		}
	}
	if (!flag)
		crash(idx + 1);
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> egg[i][0] >> egg[i][1];
	}
	crash(0);
	cout << maxs;
}
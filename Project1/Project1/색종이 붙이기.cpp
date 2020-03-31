#include<iostream>

using namespace std;

int map[10][10];
int p[6] = { 0,5,5,5,5,5 };
int mins = 987654321;

bool fill(int n,int y,int x)
{
	if (x + n > 10 || y + n > 10)
		return false;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!map[y+i][x+j])
			{
				return false;
			}
		}
	}
	return true;
}
void dfs(int y,int x,int cnt)
{
	for (int k = 1; k <= 5; k++)
	{
		if (p[k]>0 && fill(k, y, x))
		{
			bool flag = false;
			p[k]--;
			for (int i = 0; i < k; i++)
			{
				for (int j = 0; j < k; j++)
				{
					map[y + i][x + j] = 0;
				}
			}
			for (int i = y; i < 10; i++)
			{
				for (int j = 0; j < 10; j++)
				{
					if (map[i][j])
					{
						dfs(i, j, cnt + 1);
						i = 10;
						flag = true;
						break;
					}
				}
			}
			for (int i = 0; i < k; i++)
			{
				for (int j = 0; j < k; j++)
				{
					map[y + i][x + j] = 1;
				}
			}
			p[k]++;
			if (!flag)
			{
				if (mins > cnt)
					mins = cnt;
			}
		}
	}
}

int main()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (map[i][j])
			{
				dfs(i, j, 1);
				i = 10;
				break;
			}
		}
	}
	if (mins == 987654321)
	{
		bool flag = false;
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if (map[i][j])
				{
					flag = true;
					i = 10;
					break;
				}
			}
		}
		if (!flag)
			cout << 0;
		else
			cout << -1;
	}
	else
		cout << mins;
}
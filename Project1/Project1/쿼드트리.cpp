#include<iostream>

using namespace std;

int n;
int map[65][65];
int num = 0;

bool same(int y, int x, int s)
{
	bool flag = true;
	int ys = y + s;
	int xs = x + s;
	num = map[y][x];
	for (int i = y; i < ys; i++)
	{
		for (int j = x; j < xs; j++)
		{
			if (map[i][j] != num)
			{
				flag = false;
				break;
			}
		}
		if (!flag)
			break;
	}
	if (flag)
		return true;
	else
		return false;
}

void divide(int y,int x,int sz)
{
	cout << "(";
	int h = sz / 2;
	if (same(y, x, h))
	{
		cout <<num;
	}
	else
	{
		divide(y, x, h);
	}
	if (same(y, x + h, h))
	{
		cout << num;
	}
	else
	{
		divide(y, x+h, h);
	}
	if (same(y+h, x, h))
	{
		cout << num;
	}
	else
	{
		divide(y+h, x, h);
	}
	if (same(y+h, x + h, h))
	{
		cout << num;
	}
	else
	{
		divide(y + h, x+h, h);
	}
	cout << ")";
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			scanf("%1d", &map[i][j]);
		}
	}
	if (same(1,1,n))
		cout << map[1][1];
	else
		divide(1, 1, n);
}
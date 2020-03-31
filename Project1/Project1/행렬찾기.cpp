#include<iostream>
#include<algorithm>

using namespace std;

int n;
int map[100][100];
int cnt = 0;
int m[20][2];

void find(int y, int x)
{
	int cx = 1;
	int cy = 1;
	while (map[y][x+cx])
	{
		map[y][x + cx] = 0;
		cx++;
		if (cx > n - 1)
			break;
	}
	while (map[y+cy][x])
	{
		map[y + cy][x] = 0;
		cy++;
		if (cy > n - 1)
			break;
	}
	for (int i = y+1; i < y + cy; i++)
	{
		for (int j = x+1; j <x + cx; j++)
		{
			map[i][j] = 0;
		}
	}
	m[cnt][0]=cy;
	m[cnt++][1] = cx;
}

int main()
{
	cin.ignore(0);
	cin.sync_with_stdio(0);
	int T;
	cin >> T;
	for (int k = 1; k <= 10; k++)
	{
		cin >> n;
		cnt = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> map[i][j];
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (map[i][j])
				{
					find(i, j);
				}
			}
		}
		for (int i = 0; i < cnt; i++)
		{
			for (int j = i + 1; j < cnt; j++)
			{
				if ((m[i][0] * m[i][1]) > (m[j][0] * m[j][1]))
				{
					swap(m[i], m[j]);
				}
				else if((m[i][0] * m[i][1]) == (m[j][0] * m[j][1]))
				{
					if (m[i][0] > m[j][0])
						swap(m[i], m[j]);
				}
			}
		}
		cout << "#" << k << " " << cnt << " ";
		for (int i = 0; i < cnt; i++)
		{
			cout << m[i][0] << " " << m[i][1] << " ";
		}
		cout << "\n";
	}
}
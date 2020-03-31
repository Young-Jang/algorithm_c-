#include<iostream>
#include<algorithm>

using namespace std;

int st[100][10][10][4];
int sz[100][2];
int map[40][40];
int n, m, k;
int res = 0;

void rotate(int idx)
{
	int tmp = 1;
	while (tmp < 4)
	{
		if (tmp&1)
		{
			for (int i = 0; i < sz[idx][0]; i++)
			{
				for (int j = 0; j < sz[idx][1]; j++)
				{
					st[idx][j][sz[idx][0] - 1 - i][tmp] = st[idx][i][j][tmp - 1];
				}
			}
		}
		else
		{
			for (int i = 0; i < sz[idx][0]; i++) //2
			{
				for (int j = 0; j < sz[idx][1]; j++) //5
				{
					st[idx][i][sz[idx][1] - 1 - j][tmp] = st[idx][j][i][tmp - 1];
				}
			}
		}
		tmp++;
	}
}

int main()
{
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> sz[i][0] >> sz[i][1];
		for (int j = 0; j < sz[i][0]; j++)
		{
			for (int t = 0; t < sz[i][1]; t++)
			{
				cin >> st[i][j][t][0];
			}
		}
		rotate(i);
	}
	int tmp = 0;
	while (tmp < k)
	{

		bool en = false;
		for (int t = 0; t < 4; t++)
		{
			for (int y = 0; y < n; y++)
			{
				for (int x = 0; x < m; x++)
				{
					bool flag = false;
					if (t & 1) {
						if (y + sz[tmp][1] > n || x + sz[tmp][0] > m)
							continue;
						for (int i = 0; i < sz[tmp][1]; i++)
						{
							for (int j = 0; j < sz[tmp][0]; j++)
							{
								if (map[y + i][x + j] & st[tmp][i][j][t])
								{
									flag = true;
									break;
								}
							}
							if (flag)
								break;
						}
					}
					else
					{
						if (y + sz[tmp][0] > n || x + sz[tmp][1] > m)
							continue;
						for (int i = 0; i < sz[tmp][0]; i++)
						{
							for (int j = 0; j < sz[tmp][1]; j++)
							{
								if (map[y + i][x + j] & st[tmp][i][j][t])
								{
									flag = true;
									break;
								}
							}
							if (flag)
								break;
						}
					}
					if (!flag)
					{
						if (t & 1) {
							for (int i = 0; i < sz[tmp][1]; i++)
							{
								for (int j = 0; j < sz[tmp][0]; j++)
								{
									if(!map[y+i][x+j]&&st[tmp][i][j][t])
										map[y + i][x + j] = 1;
								}
							}
						}
						else
						{
							for (int i = 0; i < sz[tmp][0]; i++)
							{
								for (int j = 0; j < sz[tmp][1]; j++)
								{
									if (!map[y + i][x + j] && st[tmp][i][j][t])
										map[y + i][x + j] = 1;
								}
							}
						}
						en = true;
						break;
					}
				}
				if (en)
					break;
			}
			if (en)
				break;
		}
		tmp++;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++) {
			if (map[i][j])
				res++;
		}
	}

	cout << res;
}

//for (int l = 0; l < 4; l++)
//{
//	for (int j = 0; j < 10; j++)
//	{
//		for (int t = 0; t < 10; t++)
//		{
//			cout << st[i][j][t][l] << " ";
//		}
//		cout << "\n";
//	}
//	cout << "\n";
//}
//cout << "\n"; cout << "\n"; */
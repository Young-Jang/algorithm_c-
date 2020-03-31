#include<iostream>

using namespace std;

int n, m,k;
int map[1000][1000];
int cnt[1001][1001][3];

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cin >> n >> m;
	cin >> k;
	char tmp;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> tmp;
			if (tmp == 'J')
			{
				cnt[i][j][0] = cnt[i - 1][j][0] + cnt[i][j - 1][0] - cnt[i - 1][j - 1][0]+1;
				cnt[i][j][1] = cnt[i - 1][j][1] + cnt[i][j - 1][1] - cnt[i - 1][j - 1][1];
				cnt[i][j][2] = cnt[i - 1][j][2] + cnt[i][j - 1][2] - cnt[i - 1][j - 1][2];
			}
			else if (tmp == 'O')
			{
				cnt[i][j][0] = cnt[i - 1][j][0] + cnt[i][j - 1][0] - cnt[i - 1][j - 1][0];
				cnt[i][j][1] = cnt[i - 1][j][1] + cnt[i][j - 1][1] - cnt[i - 1][j - 1][1]+1;
				cnt[i][j][2] = cnt[i - 1][j][2] + cnt[i][j - 1][2] - cnt[i - 1][j - 1][2];
			}
			else
			{
				cnt[i][j][0] = cnt[i - 1][j][0] + cnt[i][j - 1][0] - cnt[i - 1][j - 1][0];
				cnt[i][j][1] = cnt[i - 1][j][1] + cnt[i][j - 1][1] - cnt[i - 1][j - 1][1];
				cnt[i][j][2] = cnt[i - 1][j][2] + cnt[i][j - 1][2] - cnt[i - 1][j - 1][2]+1;
			}
		}
	}
	int a, b, c, d;
	for (int i = 0; i < k; i++)
	{
		cin >> a >> b >> c >> d;
		cout << cnt[c][d][0] - cnt[c][b - 1][0] - cnt[a - 1][d][0] + cnt[a - 1][b - 1][0] << " ";
		cout << cnt[c][d][1] - cnt[c][b - 1][1] - cnt[a - 1][d][1] + cnt[a - 1][b - 1][1] << " ";
		cout << cnt[c][d][2] - cnt[c][b - 1][2] - cnt[a - 1][d][2] + cnt[a - 1][b - 1][2] << "\n";
	}
}

#include<iostream>

using namespace std;

int n, m, k;
int map[1000][1000];
int cnt[1000][1000][3];

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cin >> n >> m;
	cin >> k;
	char tmp;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> tmp;
			if (tmp == 'J')
			{
				map[i][j] = 0;
			}
			else if (tmp == 'O')
			{
				map[i][j] = 1;
			}
			else
			{
				map[i][j] = 2;
			}
		}
	}
	cnt[0][0][map[0][0]]++;
	for (int j = 1; j < m; j++)
	{
		cnt[0][j][0] = cnt[0][j - 1][0];
		cnt[0][j][1] = cnt[0][j - 1][1];
		cnt[0][j][2] = cnt[0][j - 1][2];
		cnt[0][j][map[0][j]]++;
	}
	for (int i = 1; i < n; i++)
	{
		cnt[i][0][0] = cnt[i - 1][0][0];
		cnt[i][0][1] = cnt[i - 1][0][1];
		cnt[i][0][2] = cnt[i - 1][0][2];
		cnt[i][0][map[i][0]]++;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cnt[i][j][0] = cnt[i - 1][j][0] + cnt[i][j - 1][0] - cnt[i - 1][j - 1][0];
			cnt[i][j][1] = cnt[i - 1][j][1] + cnt[i][j - 1][1] - cnt[i - 1][j - 1][1];
			cnt[i][j][2] = cnt[i - 1][j][2] + cnt[i][j - 1][2] - cnt[i - 1][j - 1][2];
			cnt[i][j][map[i][j]]++;
		}
	}
	int a, b, c, d;
	for (int i = 0; i < k; i++)
	{
		cin >> a >> b >> c >> d;
		cout << cnt[c-1][d-1][0] - cnt[c-1][b - 2][0] - cnt[a - 2][d-1][0] + cnt[a - 2][b - 2][0] << " ";
		cout << cnt[c-1][d-1][1] - cnt[c-1][b - 2][1] - cnt[a - 2][d-1][1] + cnt[a - 2][b - 2][1] << " ";
		cout << cnt[c-1][d-1][2] - cnt[c-1][b - 2][2] - cnt[a - 2][d-1][2] + cnt[a - 2][b - 2][2] << "\n";
	}
}
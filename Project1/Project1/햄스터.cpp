#include<iostream>

using namespace std;

int n, x,m;
int cage[7];
int max_cnt[7];
int sum[10][3];

int maxs = 0;
int res = 0;
bool flag = true;

void dfs(int idx)
{
	if (idx == 0)
	{
		bool tt = false;
		int tmp = 0;
		for (int i = 0; i < m; i++)
		{
			tmp = 0;
			for (int j = sum[i][0]; j <= sum[i][1]; j++)
			{
				tmp += cage[j];
			}
			if (tmp != sum[i][2])
				return;
		}
		tmp = 0;
		for (int i = 1; i <= n; i++)
			tmp += cage[i];
		if (tmp > maxs)
		{
			for (int i = 1; i <= n; i++)
				max_cnt[i] = cage[i];
			maxs = tmp;
		}
		flag = false;
		return;
	}
	for (int i = x; i >= 0; i--)
	{
		cage[idx] = i;
		dfs(idx-1);
	}
}

int main()
{
	int T;
	cin >> T;
	for (int k = 1; k <= T; k++) {
		res = 0;
		maxs = 0;
		flag = true;
		cin >> n >> x >> m;
		for (int i = 0; i < m; i++)
		{
			cin >> sum[i][0] >> sum[i][1] >> sum[i][2];
		}
		dfs(n);
		cout << "#" << k << " ";
		if (!flag) {
			for (int i = 1; i <= n; i++)
				cout << max_cnt[i] << " ";
			cout << "\n";
		}
		else
			cout << -1 << "\n";
		for (int i = 1; i <= n; i++)
		{
			cage[i] = 0;
			max_cnt[i] = 0;
		}
	}
}
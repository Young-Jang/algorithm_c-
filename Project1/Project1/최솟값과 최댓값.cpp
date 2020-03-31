#include<iostream>
#include<algorithm>

#define INF 1000000001

using namespace std;

int n,m;
int num[400000][2];

void cmp(int idx1, int idx2)
{
	int m1=INF, m2=INF;
	int x1 = 0, x2 = 0;
	while (idx1 <= idx2)
	{
		if (idx1 % 2 == 1)
		{
			m1 = min(m1, num[idx1][0]);
			x1 = max(x1, num[idx1][1]);
		}
		if (idx2 % 2 == 0)
		{
			m2 = min(m2, num[idx2][0]);
			x2 = max(x2, num[idx2][1]);
		}
		idx1 = (idx1 + 1) / 2;
		idx2 = (idx2 - 1) / 2;
	}
	cout << min(m1, m2) << " " << max(x1, x2)<<"\n";
}

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cin >> n >> m;
	int st = 0;
	while (1<<st <= n)
	{
		st++;
	}
	st = 1 << st;
	for (int i = st; i < st+n; i++)
	{
		cin >> num[i][0];
		num[i][1] = num[i][0];
	}
	for (int i = st-1; i >= 1; i--)
	{
		if (num[i * 2 + 1][0])
			num[i][0] = min(num[i * 2][0], num[i * 2 + 1][0]);
		else
			num[i][0] = num[i * 2][0];
		num[i][1]=max(num[i * 2][1], num[i * 2 + 1][1]);
	}

	int a, b;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		cmp(a - 1 + st, b - 1 + st);
	}
}
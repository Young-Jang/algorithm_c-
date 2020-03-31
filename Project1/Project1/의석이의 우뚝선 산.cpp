#include<iostream>

using namespace std;

int n;
int num[50001];
int c1 = 0;
int c2 = 0;

void dfs(int nm,int d)
{
	if (nm == n-1)
		return;
	if (!d)
	{
		if (num[nm] < num[nm + 1])
		{
			c1++;
			dfs(nm + 1, d);
		}
		else
			dfs(nm, 1);
	}
	else if(d==1)
	{
		if (num[nm] > num[nm + 1])
		{
			dfs(nm + 1, d);
			c2++;
		}
	}
}
int main()
{
	int T;
	cin >> T;
	for (int k = 1; k <= T; k++)
	{
		int res = 0;
		bool flag = false;
		int c1 = 0;
		int c2 = 0;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			scanf("%d",&num[i]);
		}
		for (int i = 0; i < n-1; i++)
		{
			if (!flag&&num[i + 1] > num[i])
			{
				c1++;
			}
			else if(flag&&num[i+1]>num[i])
			{
				res += c1 * c2;
				c1 = 1;
				c2 = 0;
				flag = false;
			}
			else if (!flag && num[i + 1] < num[i])
			{
				flag = true;
				c2++;
			}
			else
			{
				c2++;
			}
		}
		res += c1 * c2;
		cout << "#" << k << " " << res << "\n";
	}
}
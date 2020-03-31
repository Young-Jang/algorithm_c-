#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

#define INF 987654321

using namespace std;
int num[10];
vector<int> v;
int dp[1000001];
int X;

int yaksu(int n)
{
	if (dp[n]!=INF)
		return dp[n];
	bool flag = false;
	int cnt = 0;
	int tmp = n;
	while (tmp)
	{
		if (!num[tmp % 10])
		{
			flag = true;
			cnt = 0;
			break;
		}
		tmp /= 10;
		cnt++;
	}
	if (!flag)
	{
		v.push_back(n);
		return dp[n] = cnt;
	}
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)
		{
			if (dp[i] == INF)
			{
				v.push_back(i);
				dp[i] = yaksu(i);
			}
			
			if (dp[n / i] == INF)
			{
				v.push_back(n/i);
				dp[n / i] = yaksu(n / i);
			}
			dp[n] = min(dp[n], dp[i] + dp[n / i] + 1);
		}
	}
	return dp[n];
}

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	int T;
	cin >> T;
	for (int i = 0; i < 1000001; i++)
	{
		dp[i] = INF;
	}
	for (int k = 1; k <= T; k++)
	{
		for (int i = 0; i < 10; i++)
		{
			cin >> num[i];
		}
		cin >> X;
		int res = yaksu(X);
		if(res==INF)
			cout << "#" << k << " " << -1 << "\n";
		else
			cout << "#" << k << " " << res+1 << "\n";
		for (int i = v.size() - 1; i >= 0; i--)
		{
			dp[v[i]] = INF;
			v.pop_back();
		}
	}
}
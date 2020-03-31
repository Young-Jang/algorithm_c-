#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int n;
double dp[501][501];

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	int T;
	cin >> T;
	for (int k = 1; k <= T; k++)
	{

		string a, b; 
		cin >> n;
		cin >> a >> b;
		for (int i = 1;i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (a[i-1] == b[j-1])
					dp[i][j] = dp[i - 1][j - 1] + 1;
				else
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
		double res = (dp[n][n] / n) * 100;
		cout.setf(ios::fixed);
		cout.precision(2);
		cout << "#" << k << " " << res << "\n";
	}
}
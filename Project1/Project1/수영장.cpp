#include<iostream>
#include<algorithm>

#define INF 987654321

using namespace std;

int m[13];
int cost[4];
int dp[13];

int main()
{
	int T;
	cin >> T;
	for (int k = 1; k <= T; k++)
	{
		cin >> cost[0] >> cost[1] >> cost[2] >> cost[3];
		for (int i = 1; i <= 12; i++)
		{
			cin >> m[i];
			dp[i] = INF;
		}
		dp[1] = min(cost[1], cost[0] * m[1]);
		dp[2]= min(cost[2],dp[1]+min(cost[1], cost[0] * m[2]));
		dp[3]= min(cost[2],dp[2]+min(cost[1], cost[0] * m[3]));
		for (int i = 4; i <= 12; i++)
		{
			int c = min(cost[1], cost[0] * m[i]);
			dp[i] = min(dp[i], c + dp[i - 1]);
			dp[i] = min(dp[i], dp[i - 3] + cost[2]);
		}
		dp[12] = min(dp[12], cost[3]);
		cout << "#" << k << " " << dp[12] << "\n";
	}
}
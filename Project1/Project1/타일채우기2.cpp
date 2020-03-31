#include<iostream>
using namespace std;

int dp[501][13];
int n;

int bitmask(int nx, int bit)
{
	if (nx < 0)
		return 0;
	else if (nx < 1)
	{
		if (bit == 0)
			return 1;
		else
			return 0;
	}
	if (dp[nx][bit]!=-1)
		return dp[nx][bit];

	dp[nx][bit] = 0;
	if (bit == 0)
	{
		dp[nx][bit] += bitmask(nx - 1, 0);
		dp[nx][bit] += bitmask(nx - 1, 3);
		dp[nx][bit] += bitmask(nx - 1, 6);
		dp[nx][bit] += bitmask(nx - 1, 12);
		dp[nx][bit] += bitmask(nx - 2, 0);
	}
	else if (bit == 3)
	{
		dp[nx][bit] += bitmask(nx - 1, 0);
		dp[nx][bit] += bitmask(nx - 1, 12);
	}
	else if (bit == 6)
	{
		dp[nx][bit] += bitmask(nx - 1, 9);
		dp[nx][bit] += bitmask(nx - 1, 0);
	}
	else if (bit == 9)
	{
		dp[nx][bit] += bitmask(nx - 1, 6);
	}
	else if (bit == 12)
	{
		dp[nx][bit] += bitmask(nx - 1, 0);
		dp[nx][bit] += bitmask(nx - 1, 3);
	}
	return dp[nx][bit];
}

int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < 501; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			dp[i][j] = -1;
		}
	}
	for (int k = 1; k <= T; k++)
	{
		cin >> n;
		cout << bitmask(n, 0)<<"\n";
	}
}
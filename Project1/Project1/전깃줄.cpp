#include<iostream>
#include<algorithm>

using namespace std;
int n;

pair<int,int> arr[100];
int dp[100];

int main()
{
	cin >> n;
	int a, b;
	int maxs = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		arr[i] = { a,b };
		dp[i] = 1;
	}
	sort(arr, arr + n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[j].second < arr[i].second)
			{
				if (dp[i] < dp[j] + 1)
					dp[i] = dp[j] + 1;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (maxs < dp[i])
			maxs = dp[i];
	}
	cout << n - maxs;
}
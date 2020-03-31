#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string dp[1001][1001];

int main()
{
	string a, b;
	cin >> a >>b;
	int na = a.length();
	int nb = b.length();
	for (int i = 1; i <= na; i++)
	{
		for (int j = 1; j <= nb; j++)
		{
			if (a[i - 1] == b[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + a[i - 1];
			}
			else
			{
				if (dp[i][j - 1].length() < dp[i - 1][j].length())
				{
					dp[i][j] = dp[i - 1][j];
				}
				else
				{
					dp[i][j] = dp[i][j - 1];
				}
			}
		}
	}
	for (int i = 1; i <= na; i++)
	{
		for (int j = 1; j <= nb; j++)
		{

		}
	}
	cout << dp[na][nb].length()<<"\n"<<dp[na][nb];
}
//
//#include<iostream>
//#include<string>
//#include<algorithm>
//using namespace std;
//
//int dp[1001][1001];
//
//int main()
//{
//	string a, b;
//	cin >> a >> b;
//	int sz1 = a.length();
//	int sz2 = b.length();
//
//	for (int i = 1; i <= sz1; i++)
//	{
//		for (int j = 1; j <= sz2; j++)
//		{
//			if (a[i - 1] == b[j - 1])
//				dp[i][j] = dp[i - 1][j - 1] + 1;
//			else
//				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
//		}
//	}
//	cout << dp[sz1][sz2];
//}
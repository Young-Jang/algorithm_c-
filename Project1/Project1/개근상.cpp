#include<iostream>

using namespace std;

int n;
long long cnt[1001][4];

int main()
{
	cin >> n;
	long long res = 0;
	cnt[1][0] = 0;
	cnt[1][1] = 1;
	cnt[1][2] = 1;
	cnt[1][3] = 2;
	cnt[2][0] = 1;
	cnt[2][1] = 1;
	cnt[2][2] = 2;
	cnt[2][3] = 4;
	for (int i = 3; i <= n; i++)
	{
		cnt[i][0] = cnt[i - 1][1]%1000000;
		cnt[i][1] = cnt[i - 1][2]%1000000;
		cnt[i][2] = (cnt[i - 1][0] + cnt[i - 1][1] + cnt[i - 1][2])%1000000;
		cnt[i][3]= (cnt[i][0] + cnt[i][1] + cnt[i][2])%1000000;
	}
	res = cnt[n][3]+(cnt[n-1][3]*2)%1000000;
	for (int i = 1; i < n / 2; i++)
	{
		res = (res+(cnt[i][3] * cnt[n - i - 1][3])*2%1000000)%1000000;
	}
	if (n & 1)
	{
		res = (res+cnt[n/ 2][3]* cnt[n / 2][3])%1000000;
	}
	cout << res%1000000;
}

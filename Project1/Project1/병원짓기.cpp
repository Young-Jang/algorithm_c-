#include<iostream>
#include<algorithm>

#define INF 987654321

using namespace std;
int n;
int map[22][22];
pair<int,int> c[22];
int check[22];
int mins = INF;
//
//void cost(int idx)
//{
//	int hap1 = 0; //
//	int hap2 = 0; //자기 미포함
//	bool flag = false;
//	for (int i = 0; i < n; i++)
//	{
//		if (map[idx][i]&&!check[i])
//		{
//			check[i] = 1;
//			cost(i);
//			hap1 += min(dp[i][0], dp[i][1]);
//			hap2 += dp[i][0];
//			flag = true;
//		}
//	}
//	dp[idx][0] = hap1 + c[idx];
//	dp[idx][1] = hap2;
//}


int main()
{
	int T;
	cin >> T;
	for (int k = 1; k <= T; k++)
	{
		cin >> n;
		mins = INF;
		int tmp = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> tmp;
			c[i] = { tmp,i };
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> map[i][j];
			}
		}
		sort(c, c + n);
		int mins = 0;
		for (int i = 0; i < n; i++)
		{
			int idx = c[i].second;
			if (check[idx])
				continue;
			mins += c[i].first;
			check[idx] = 1;
			for (int j = 0; j< n; j++)
			{
				if (map[idx][j])
				{
					check[j] = 1;
				}
			}
		}
		cout << "#" << k << " " << mins << "\n";
		for (int i = 0; i < n; i++)
			check[i] = 0;
	}
}

//2 
//5 
//100 70 50 80 10 
//0 1 0 1 0
//1 0 1 0 1
//0 1 0 0 0
//1 0 0 0 0
//0 1 0 0 0
//3
//10 20 30
//0 1 1
//1 0 1
//1 1 0

#include<iostream>
#include<vector>
#include<queue>
#include<time.h>
#include<algorithm>

#define INF 98765

using namespace std;
int n;
int map[1000][1000];
int mins = INF;


int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	clock_t start = clock();
	freopen("input.txt", "r", stdin);
	int T;
	cin >> T;
	for (int k = 1; k <= T; k++)
	{
		cin >> n;
		int tmp = 0;
		int hap = 0;
		mins = INF;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> map[i][j];
				if (i!=j&&!map[i][j])
					map[i][j] = INF;
			}
		}
		for (int t = 0; t < n; t++) {
			for (int i = 0; i < n; i++)
			{
				if (i == t)continue;
				for (int j = 0; j < n; j++)
				{
					if (i == j || t == j)continue;
					if (map[i][j] > map[i][t] + map[t][j])
					{
						map[i][j] = map[i][t] + map[t][j];
					}
				} 
			}
		}
		for (int i = 0; i < n; i++) {
			hap = 0;
			for (int j = 0; j < n; j++)
			{
				hap += map[i][j];
				if (mins < hap)
				{
					hap = INF;
					break;
				}
			}
			mins = min(mins, hap);
		}
		cout << "#" << k << " " << mins << "\n";
	}
	cout << (float)(clock() - start) / CLOCKS_PER_SEC;
}
//
//#include<iostream>
//#include<vector>
//#include<queue>
//#include<time.h>
//#include<algorithm>
//
//#define INF 987654321
//
//using namespace std;
//int n;
//int check[1000];
//int map[1000][1000];
//int leng[1000];
//int mins = INF;
//
//priority_queue<pair<int,int>> pq;
//
//int main()
//{
//	cin.tie(0);
//	cin.sync_with_stdio(0);
//	clock_t start = clock();
//	freopen("input.txt", "r", stdin);
//	int T;
//	cin >> T;
//	for (int k = 1; k <= T; k++)
//	{
//		cin >> n;
//		int tmp = 0;
//		int hap = 0;
//		mins = INF;
//		for (int i = 0; i < n; i++)
//		{
//			for (int j = 0; j < n; j++)
//			{
//				cin >> map[i][j];
//			}
//			leng[i] = INF;
//		}
//		tmp = 0;
//		for (int j = 0; j < n; j++) {
//			leng[j] = 0;
//			pq.push({ 0,j });
//			while (!pq.empty())
//			{
//				int idx = pq.top().second;
//				int v = -pq.top().first;
//				pq.pop();
//				if (v > leng[idx])
//					continue;
//				for (int t = 0; t < n; t++)
//				{
//					if (!map[idx][t])
//						continue;
//					if (leng[t] > v + 1)
//					{
//						leng[t] = v + 1;
//						pq.push({ -leng[t], t });
//					}
//				}
//			}
//			for (int i = 0; i < n; i++)
//			{
//				hap += leng[i];
//				leng[i] = INF;
//			}
//			if (hap < mins)
//				mins = hap;
//			hap = 0;
//		}
//		cout << "#" << k << " " << mins << "\n";
//	}
//	cout << (float)(clock() - start) / CLOCKS_PER_SEC;
//}

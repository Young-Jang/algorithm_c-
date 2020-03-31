#include<iostream>
#include<algorithm>

#define INF 987654321

using namespace std;
int n;
int map[22][22];
pair<int, int> c[22];
int check[22];
int mins = INF;

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
		sort(c, c + n); //오름차순으로 노드 정렬
		int mins = 0;
		for (int i = 0; i < n; i++) //값이 작은 노드들부터 병원 짓기, 그리드 방법
		{
			int idx = c[i].second;
			if (check[idx])
				continue;
			mins += c[i].first;
			check[idx] = 1;
			for (int j = 0; j < n; j++) //병원지은 노드 주변 노드들 check
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

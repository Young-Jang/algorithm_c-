#include<iostream>
#include<queue>

using namespace std;

int n;
int cost[1001][1001];
long long leng;
int parent[1001];
int cnt = 0;

priority_queue<pair<int,pair<int, int>>> pq;

int find(int n)
{
	if (n == parent[n])
		return n;
	else
		return parent[n]=find(parent[n]);
}

void merge(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a == b)
		return;
	parent[a] = b;
}

void kruskal()
{
	while (!pq.empty())
	{
		int c = -pq.top().first;
		int idx1 = pq.top().second.first;
		int idx2 = pq.top().second.second;
		pq.pop();
		if (find(idx1) != find(idx2))
		{
			merge(idx1, idx2);
			leng += c;
			cnt++;
		}
		if (cnt == n - 1)
		{
			break;
		}
	}
}

int main()
{
	cin.ignore(0);
	cin.sync_with_stdio(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		parent[i] = i;
		for (int j = 1; j <= n; j++)
		{
			cin >> cost[i][j];
			if (cost[i][j]&&i>j)
				pq.push(make_pair(-cost[i][j], make_pair(i, j)));
		}
	}
	kruskal();
	cout << leng;
}
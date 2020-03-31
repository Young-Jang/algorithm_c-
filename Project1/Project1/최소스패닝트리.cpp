#include<iostream>
#include<queue>

using namespace std;

int v, e;
int parent[10001];
long long mins = 0;
priority_queue<pair<int, pair<int,int>>,vector<pair<int, pair<int, int>>>,greater<pair<int, pair<int, int>>>>pq;

int find(int u)
{
	if (parent[u] == u)
		return u;
	return parent[u] = find(parent[u]);
}

void merge(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a != b)
		parent[b] = a;
}

void kruskal()
{
	while (!pq.empty())
	{
		int i1 = pq.top().second.first;
		int i2 = pq.top().second.second;
		int cost = pq.top().first;
		pq.pop();
		if (find(i1) != find(i2))
		{
			merge(i1, i2);
			mins += cost;
		}
	}
}

int main()
{
	cin >> v >> e;
	int a, b, c;
	for (int i = 0; i < e; i++)
	{
		cin >> a >> b >> c;
		pq.push({ c,{a,b} });
	}
	for (int i = 1; i <= v; i++)
	{
		parent[i] = i;
	}
	kruskal();
	cout << mins;
}
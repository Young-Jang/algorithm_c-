#include<iostream>
#include<queue>
#include<vector>

#define INF 987654321

using namespace std;

int v, e,k;
priority_queue<pair<int, int>> pq;
vector <pair<int, int>> d[20001];
int dist[20001];

void dijkstra()
{
	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();
		if (dist[here] < cost)
			continue;
		dist[here] = cost;
		for (int i = 0; i < d[here].size(); i++)
		{
			int nx = d[here][i].first;
			int nxc = d[here][i].second;
			if (dist[nx] > cost+nxc)
			{
				dist[nx] = cost + nxc;
				pq.push({ -dist[nx],nx });
			}
		}
	}
}

int main()
{
	cin.ignore(0);
	cin.sync_with_stdio(0);
	cin >> v >> e;
	cin >> k;
	int a, b, c;
	for (int i = 1; i <= v; i++)
		dist[i] = INF;
	for (int i = 0; i < e; i++)
	{
		cin >> a >> b >> c;
		d[a].push_back({ b,c});
	}
	for (int i = 0; i < d[k].size(); i++)
	{
		dist[d[k][i].first] = d[k][i].second;
		pq.push({ -d[k][i].second,d[k][i].first });
	}
	dijkstra();
	for (int i = 1; i <= v; i++)
	{
		if (i == k)
			cout << 0 << "\n";
		else if (dist[i] == INF)
			cout << "INF" << "\n";
		else
			cout << dist[i] << "\n";
	}
}
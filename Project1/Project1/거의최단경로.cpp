#include<iostream>
#include<queue>
#include<vector>

#define INF 987654321

using namespace std;

int n, m,s,p;
priority_queue<pair<int, int>> pq;
vector <pair<int, int>> d[500];
int dist[500];
vector<int> touch[500];
int check[500][500];
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
			if (dist[nx] > cost + nxc)
			{
				while (!touch[nx].empty())
					touch[nx].pop_back();
				dist[nx] = cost + nxc;
				touch[nx].push_back(here);
				pq.push({ -dist[nx],nx });
			}
			else if (dist[nx] == cost + nxc)
			{
				touch[nx].push_back(here);
			}
		}
	}
}

void dijkstra2()
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
			if (!check[here][nx]&&dist[nx] > cost + nxc)
			{
				dist[nx] = cost + nxc;
				pq.push({ -dist[nx],nx });
			}
		}
	}
}

queue<int> q;
void erase_road()
{
	q.push(p);
	while (!q.empty())
	{
		int idx = q.front();
		q.pop();
		if (idx == s)
		{
			continue;
		}
		for (int i = 0; i < touch[idx].size(); i++)
		{
			check[touch[idx][i]][idx] = 1;
			q.push(touch[idx][i]);
		}
	}
}

int main()
{
	cin.ignore(0);
	cin.sync_with_stdio(0);
	while (1) {
		cin >> n >> m;
		if (n == 0 && m == 0)
			break;
		cin >> s >> p;
		int a, b, c;
		for (int i = 0; i < n; i++)
		{
			dist[i] = INF;
			while (!d[i].empty())
			{
				d[i].pop_back();
			}
		}
		for (int i = 0; i < m; i++)
		{
			cin >> a >> b >> c;
			d[a].push_back({ b,c });
		}
		for (int i = 0; i < d[s].size(); i++)
		{
			touch[d[s][i].first].push_back(s);
			dist[d[s][i].first] = d[s][i].second;
			pq.push({ -d[s][i].second,d[s][i].first });
		}
		dijkstra();
		erase_road();
		for (int i = 0; i < n; i++)
			dist[i] = INF;
		for (int i = 0; i < d[s].size(); i++)
		{
			if (check[s][d[s][i].first])
				continue;
			dist[d[s][i].first] = d[s][i].second;
			pq.push({ -d[s][i].second,d[s][i].first });
		}
		dijkstra2();
		if (dist[p] == INF)
			cout << -1 << '\n';
		else
			cout << dist[p]<<'\n';
		for (int i = 0; i < n; i++)
		{
			while (!touch[i].empty())
				touch[i].pop_back();
			for (int j = 0; j < n; j++)
			{
				check[i][j] = 0;
			}
		}
	}
}
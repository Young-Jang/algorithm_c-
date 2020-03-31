#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<queue>

using namespace std;
map<string, int> m;
vector<int> v[201];
queue<pair<int, int>> q;

int n;
bool flag = false;
int team[201];

void bfs()
{
	while (!q.empty())
	{
		int num = q.front().first;
		int idx = q.front().second;
		q.pop();
		int nx_num = 0;
		if (num == 1)
			nx_num = 2;
		else
			nx_num = 1;
		for (int i = 0; i < v[idx].size(); i++)
		{
			if (team[v[idx][i]] == num)
			{
				flag = true;
				while (!q.empty())
					q.pop();
				break;
			}
			else if(team[v[idx][i]]==nx_num)
			{
				continue;
			}
			else
			{
				team[v[idx][i]] = nx_num;
				q.push({ nx_num,v[idx][i] });
			}
		}
	}
}

int main()
{
	int T;
	cin >> T;
	for (int k = 1; k <= T; k++)
	{
		flag = false;
		int idx = 1;
		cin >> n;
		string s1, s2;
		for (int i = 0; i < n; i++)
		{
			cin >> s1 >> s2;
			if (!m[s1])
			{
				m[s1] = idx++;
			}
			if (!m[s2])
			{
				m[s2] = idx++;
			}
			v[m[s1]].push_back(m[s2]);
			v[m[s2]].push_back(m[s1]);
		}
		team[1] = 1;
		q.push({ 1,1 });
		bfs();
		m.clear();
		for (int i = 1; i < idx; i++)
		{
			v[i].clear();
			team[i] = 0;
		}
		if (flag)
			cout << "#" << k << " " << "No" << "\n";
		else
			cout << "#" << k << " " << "Yes" << "\n";
	}
}
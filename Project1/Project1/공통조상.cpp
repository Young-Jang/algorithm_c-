#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct node {
	vector<int> parent;
	vector<int> child;
};

int v, e, n1, n2;
node tree[10001];
queue<int>q1;
queue<int>q2;

int dfs(int idx)
{
	int hap = tree[idx].child.size();
	for (int i = 0; i < tree[idx].child.size(); i++)
	{
		hap+=dfs(tree[idx].child[i]);
	}
	return hap;
}

int main()
{
	int T;
	int res = -1;
	cin >> T;
	for (int k = 1; k <= T; k++)
	{
		cin >> v >> e >> n1 >> n2;
		int t1, t2;
		for (int i = 0; i < e; i++)
		{
			cin >> t1 >> t2;
			tree[t1].child.push_back(t2);
			tree[t2].parent.push_back(t1);
		}
		q1.push(n1);
		while (!q1.empty())
		{
			q2.push(n2);
			int tmp2 = q1.front();
			q1.pop();
			bool flag = true;
			for (int j = 0; j < tree[tmp2].parent.size(); j++) {
				q1.push(tree[tmp2].parent[j]);
				while (!q2.empty())
				{
					int tmp = q2.front();
					q2.pop();
					for (int i = 0; i < tree[tmp].parent.size(); i++)
					{
						if (tree[tmp].parent[i] == tree[tmp2].parent[j])
						{
							flag = false;
							res = tree[tmp2].parent[j];
							break;
						}
						q2.push(tree[tmp].parent[i]);
					}
					if (!flag)
					{
						while (!q2.empty())
							q2.pop();
						break;
					}
				}
			}
			if (!flag)
			{
				while (!q1.empty())
					q1.pop();
				break;
			}
		}
		cout<<"#"<<k<<" "<<res<<" "<<dfs(res)+1<<"\n";
		for (int i = 0; i < v; i++)
		{
			tree[i].child.clear();
			tree[i].parent.clear();
		}
	}
}
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct rel {
	vector<int> child;
};

int n;
rel v[200001];
int energe[200001];
int dp[200001][2]; //0:자신포함 1:자신빼고
int maxs = 0;

void dfs(int num)
{
	if (!v[num].child.size())
		return;
	for (int i = 0; i < v[num].child.size(); i++)
	{
		if(v[v[num].child[i]].child.size())
			dfs(v[num].child[i]);
	}
	int hap = 0;
	for (int j = 0; j < v[num].child.size(); j++)
	{	
		hap += max(dp[v[num].child[j]][1], dp[v[num].child[j]][0]);
	}
	for (int i = 0; i < v[num].child.size(); i++)
	{
		dp[num][0] = max(dp[num][0], dp[v[num].child[i]][1] + energe[num] * energe[v[num].child[i]]+hap-max(dp[v[num].child[i]][1], dp[v[num].child[i]][0]));
		dp[num][1] += max(dp[v[num].child[i]][0], dp[v[num].child[i]][1]);
	}
}

int main()
{
	cin.ignore(0);
	cin.sync_with_stdio(0);
	cin >> n;
	for (int i = 2; i <= n; i++)
	{
		int tmp;
		cin >> tmp;
		v[tmp].child.push_back(i);
	}
	for (int i = 1; i <= n; i++)
		cin >> energe[i];
	dfs(1);
	cout << max(dp[1][0],dp[1][1]);
}
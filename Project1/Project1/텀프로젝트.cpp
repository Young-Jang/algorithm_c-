#include<iostream>
#include<vector>

using namespace std;

int n;
int choice[100001];
int check[100001];
int tt[100001];
int cnt = 0;

void dfs(int idx)
{
	check[idx] = 1;
	if (!check[choice[idx]])
	{
		dfs(choice[idx]);
	}
	else if (!tt[choice[idx]])
	{
		int tmp = choice[idx];
		cnt++;
		while (choice[tmp] != choice[idx])
		{
			cnt++;	
			tmp = choice[tmp];
		}
	}
	tt[idx] = 1;
}

int main()
{
	int T;
	cin >> T;
	for (int k = 0; k < T; k++)
	{
		cin >> n;
		cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			cin >> choice[i];
		}
		for (int i = 1; i <= n; i++)
		{
			if (!check[i])
			{
				dfs(i);
			}
		}
		cout << n - cnt << "\n";
		for (int i = 1; i <= n; i++)
		{
			tt[i] = 0;
			check[i] = 0;
		}
	}
}

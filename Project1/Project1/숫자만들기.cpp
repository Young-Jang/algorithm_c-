#include<iostream>

using namespace std;

int num[12];
int op[4];
int maxs = -987654321;
int mins = 987654321;
int n;

void dfs(int c,int hap)
{
	if (c == n)
	{
		if (hap > maxs)
			maxs = hap;
		if (hap < mins)
			mins = hap;
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		if (op[i])
		{
			op[i]--;
			switch (i)
			{
				case 0:
					dfs(c+1, hap + num[c]);
					break;
				case 1:
					dfs(c + 1, hap - num[c]);
					break;
				case 2:
					dfs(c + 1, hap * num[c]);
					break;
				case 3:
					dfs(c + 1, hap / num[c]);
					break;
			}
			op[i]++;
		}
	}
}

int main()
{
	int T;
	cin >> T;
	for (int k = 1; k <= T; k++)
	{
		cin >> n;
		mins = 987654321;
		maxs = -987654321;
		for (int i = 0; i < 4; i++)
		{
			cin >> op[i];
		}
		for (int i = 0; i < n; i++)
		{
			cin >> num[i];
		}
		dfs(1, num[0]);
		cout <<"#"<<k<<" "<< maxs - mins << "\n";
	}
}
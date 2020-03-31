#include<iostream>
#include<algorithm>

#define INF 987654321

using namespace std;

int n;
int m[16][16];
int v[16];
int mins = INF;
int hap[2];

void combination(int st,int cnt)
{
	if (cnt == n/2)
	{
		hap[0] = 0;
		hap[1] = 0;
		//1,2 1,3 ,1,4
		for (int i = 0; i < n; i++)
		{
			if (v[i])
			{
				for (int j = 0; j < n; j++)
				{
					if (i == j)
						continue;
					if (v[j])
						hap[0] += m[i][j];
				}
			}
			else
			{
				for (int j = 0; j < n; j++)
				{
					if (i == j)
						continue;
					if (!v[j])
						hap[1] += m[i][j];
				}
			}
		}
		mins = min(mins,abs(hap[1] -hap[0]));
	}
	for (int i = st; i < n; i++)
	{
		if (n - st + cnt < n/2)
			return;
		v[i] = 1;
		combination(i + 1, cnt + 1);
		v[i] = 0;
	}
}

int main()
{
	int T;
	cin >> T;
	for (int k = 1; k <= T; k++)
	{
		cin >> n;
		mins = INF;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> m[i][j];
			}
		}
		combination(0, 0);
		cout << "#" << k << " " << mins << "\n";
	}
}

//16C4 4C2
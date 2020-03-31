#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>

#define INF 987654321

using namespace std;

int map[10][10];
int n;
int s[2][3]; //y, x, leng
int leng[10][2];
vector<pair<int, int>> v;

vector<int> v1;
vector<int> v2;

int mins = INF;

int main()
{
	int T;
	cin >> T;
	for (int k = 1; k <= T; k++)
	{
		cin >> n;
		mins = INF;
		int tmp = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> map[i][j];
				if (map[i][j] == 1)
				{
					v.push_back({ i,j });
				}
				else if (map[i][j] != 0)
				{
					s[tmp][0] = i;
					s[tmp][1] = j;
					s[tmp][2] = map[i][j];
					tmp++;
				}
			}
		}

		for (int j = 0; j < 1 << v.size(); j++)
		{
			int c1 = 0;
			int c2 = 0;
			for (int i = 0; i < v.size(); i++)
			{
				if (j & 1 << i)
				{
					v1.push_back(abs(s[1][0] - v[i].first) + abs(s[1][1] - v[i].second));
				}
				else
				{
					v2.push_back(abs(s[0][0] - v[i].first) + abs(s[0][1] - v[i].second));
				}
			}
			sort(v1.begin(), v1.end());
			sort(v2.begin(), v2.end());
			if (v1.size() > 3)
			{
				for (int a = 3; a < v1.size(); a++)
				{
					if (v1[a - 3] + s[1][2] >= v1[a])
						v1[a] = v1[a - 3] + s[1][2];
				}
				c1 = v1[v1.size() - 1]+s[1][2];
			}
			else if(v1.size()!=0)
				c1 = v1[v1.size() - 1]+s[1][2];

			if (v2.size() > 3)
			{
				for (int a = 3; a < v2.size(); a++)
				{
					if (v2[a - 3] + s[0][2] >= v2[a])
						v2[a] = v2[a - 3] + s[0][2];
				}
				c2 = v2[v2.size() - 1]+s[0][2];
			}
			else if(v2.size()!=0)
				c2 = v2[v2.size() - 1]+s[0][2];

			mins = min(mins, max(c1, c2));
			v1.clear();
			v2.clear();
		}
		cout << "#" << k << " "<<mins+1<<"\n";
		v.clear();
	}
}
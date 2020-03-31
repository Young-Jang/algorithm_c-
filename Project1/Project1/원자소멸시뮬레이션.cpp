#include<iostream>
#include<vector>
#include<queue>

using namespace std;
struct pos {
	int x, y, d,e;
};
int n;
vector<pos> v;
int check[2001][2001][3][2];

priority_queue<pair<int, pair<int, int>>> pq;

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	int T;
	cin >> T;
	for (int k = 1; k <= T; k++)
	{
		cin >> n;
		int x, y, d, e;
		for (int i = 0; i < n; i++)
		{
			cin >> x >> y >> d >> e;
			v.push_back({ x,y,d,e });
		}
		for (int i = 0; i < v.size(); i++)
		{
			x = v[i].x;
			y = v[i].y;
			d = v[i].d;
			e = v[i].e;

		}
	}
}
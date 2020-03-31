#include<iostream>
#include<vector>

using namespace std;

int n;
vector<pair<int, int>> v;

void hanoi(int c,int from, int by, int to)
{
	if (c == 1)
	{
		v.push_back({ from,to });
	}
	else
	{
		hanoi(c -1, from, to, by);
		v.push_back({ from,to });
		hanoi(c -1, by, from, to);
	}
}

int main()
{
	cin >> n;
	hanoi(n, 1, 2, 3);
	int sz = v.size();
	cout << sz<<"\n";
	for (int i = 0; i < sz; i++)
	{
		cout << v[i].first << " " << v[i].second << "\n";
	}
}
#include<iostream>
#include<string>
#include<map>

using namespace std;

int n;
string p[1000];
string o[1000];
map<string,int> c;

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> p[i];
	for (int i = 0; i < n; i++)
		cin >> o[i];
	int cnt = 0;
	int idx = 0;
	int tmp = 1;
	for (int i = 0; i < n; i++)
	{
		if (p[i - idx] != o[i])
		{
			if (c[p[i - idx]])
			{
				idx--;
				i--;
			}
			else
			{
				cnt++;
				c[o[i]] = cnt;
				idx++;
			}
		}
	}
	cout << cnt;
}

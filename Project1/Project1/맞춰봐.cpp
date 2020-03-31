#include<iostream>
#include<string>

using namespace std;

int n;
char h[10][10];
int sign[10];
int res[10];
bool over = false;
string s = "";

void dfs(int idx)
{
	if (idx == n+1)
	{
		for (int i = 0; i < n; i++)
		{
			cout << res[i] << " ";
		}
		over = true;
		return;
	}
	for (int j = 0; j <= 10; j++) {
		bool flag = true;
		for (int i = 0; i < idx; i++)
		{
			int tmp = idx-2;
			int hap = 0;
			while (tmp >= i)
			{
				hap += res[tmp--];
			}
			if (h[i][idx - 1 - i] == '-')
			{
				if (hap + (j * sign[idx - 1]) >= 0)
				{
					flag = false;
					break;
				}
			}
			else if (h[i][idx - 1 - i] == '+')
			{
				if (hap + (j * sign[idx - 1]) <= 0)
				{
					flag = false;
					break;
				}
			}
			else
			{
				if (hap + (j * sign[idx - 1]) != 0)
				{
					flag = false;
					break;
				}
			}
		}
		if (flag)
		{
			res[idx-1] = j * sign[idx - 1];
			dfs(idx + 1);
			if (over)
				return;
		}
	}
}

int main()
{
	cin >> n;
	int tmp = (n * (n + 1)) / 2;
	cin >> s;
	int idx = 0;
	int idx2 = n;
	while (idx < tmp)
	{
		for (int i = 0; i < idx2; i++)
		{
			h[n - idx2][i] = s[i + idx];
		}
		if (s[idx] == '-')
		{
			sign[n - idx2] = -1;
		}
		else
		{
			sign[n - idx2] = 1;
		}
		idx += idx2;
		idx2--;
	}
	dfs(1);

}
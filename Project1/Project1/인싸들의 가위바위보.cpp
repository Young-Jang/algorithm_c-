#include<iostream>

using namespace std;

int n, k;
int m[10][10];
int wc[3]; //Áö¿ì,°æÈñ,¹ÎÈ£

int ji[9];
int mi[20];
int ky[20];
int res = 0;
int idx;
int i1;
int i2;

int winner(int a,int b)
{
	if (!a)
	{
		idx++;
		if (b == 1)
		{
			i1++;
			if (!m[ky[i1]][ji[idx]])
			{
				return 0;
			}
			else
			{
				return 1;
			}
		}
		else
		{
			i2++;
			if (!m[mi[i2]][ji[idx]])
			{
				return 0;
			}
			else
			{
				return 2;
			}
		}
	}
	else if (a == 1)
	{
		i1++;
		if (!b)
		{
			idx++;
			if (!m[ky[i1]][ji[idx]])
			{
				return 0;
			}
			else {
				return 1;		
			}
		}
		else
		{
			i2++;
			if (!m[mi[i2]][ky[i1]])
			{
				return 1;
			}
			else
			{
				return 2;
			}
		}
	}
	else
	{
		i2++;
		if (!b)
		{
			idx++;
			if (!m[mi[i2]][ji[idx]])
			{
				return 0;
			}
			else
			{
				return 2;
			}
		}
		else
		{
			i1++;
			if (!m[mi[i2]][ky[i1]])
			{
				return 1;
			}
			else
			{
				return 2;
			}
		}
	}
}

void dfs(int st)
{
	if (st == n)
	{
		idx = -1;
		i1 = -1;
		i2 = -1;
		int nw = 1;
		int nx = 1;
		int win = 0;
		for (int j = 0; j < 3; j++)
		{
			wc[j] = 0;
		}
		while(1)
		{
			if (idx >= n-1||i1>=19||i2>=19)
				return;
			nw = nx;
			for (int j = 0; j < 3; j++)
			{
				if (j != win && j != nw)
				{
					nx = j;
					break;
				}
			}
			win = winner(nw, win);
			wc[win]++;
			for (int j = 0; j < 3; j++)
			{
				if (wc[j] >= k)
				{
					if (j == 0)
					{
						res = 1;
						return;
					}
					else
						return;
				}
			}
		}
		return;
	}
	for (int i = st; i < n; i++)
	{
		if (res)
			return;
		swap(ji[st], ji[i]);
		dfs(st+1);
		swap(ji[st], ji[i]);
	}
}

int main()
{
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> m[i][j];
		}
	}
	for (int i = 0; i < 20; i++)
	{
		cin >> ky[i];
	}

	for (int i = 0; i < 20; i++)
	{
		cin >> mi[i];
	}
	for (int i = 0; i < n; i++)
		ji[i] = i + 1;
	dfs(0);
	cout << res;
}
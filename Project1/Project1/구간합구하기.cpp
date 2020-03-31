//#include<iostream>
//
//using namespace std;
//
//int n, m,k;
//long long num[1<<22];
//int tmp = 0;
//
//void change(int i, int v)
//{
//	while (i)
//	{
//		num[i] += v;
//		i /= 2;
//	}
//}
//
//long long summ(int idx1, int idx2)
//{
//	long long h = 0;
//	if (idx1 == idx2)
//		return num[idx1];
//	while (idx1 <= idx2)
//	{
//		if (idx1 % 2 == 1)
//		{
//			h += num[idx1];
//		}
//		if (idx2%2==0)
//		{
//			h += num[idx2];
//		}
//		idx1 =(idx1+1)/2;
//		idx2 =(idx2-1)/2;
//	}
//	return h;
//}
//
//int main()
//{
//	cin.tie(0);
//	cin.sync_with_stdio(0);
//
//	cin >> n >> m >> k;
//
//	while (1 << tmp <= n)
//	{
//		tmp++;
//	}
//	
//	for (int i = 1<<tmp; i < (1<<tmp)+n; i++)
//		cin >> num[i];
//
//	for (int i = (1<<tmp)-1; i >= 1; i--)
//	{
//		num[i] = num[i * 2] + num[i * 2 + 1];
//	}
//	int a, b, c;
//	int tt = 1 << tmp;
//	for (int i = 0; i < m + k; i++)
//	{
//		cin >> a >> b >> c;
//		if (a == 1)
//		{
//			change(tt+b-1, c-num[tt+b-1]);
//		}
//		else
//		{
//			long long r = summ(tt+b-1, tt+c-1);
//			cout << r << "\n";
//		}
//	}
//}


#include<iostream>

using namespace std;

typedef long long ll;

int n, m, k;
ll tree[1 << 22];
ll input[1000000];

ll init(int idx, int start, int end)
{
	if (start == end)
		tree[idx] = input[start];
	else
	{
		int mid = (start + end) / 2;
		tree[idx] = init(idx * 2 + 1, start, mid) + init(idx * 2 + 2, mid + 1, end);
	}
	return tree[idx];
}

ll sum(int idx, int start, int end, int left, int right)
{
	if (start > right || end < left)
		return 0;
	else if (start >= left && end <= right)
		return tree[idx];
	else
	{
		int mid = (start + end) / 2;
		return sum(idx * 2 + 1, start, mid, left, right) + sum(idx * 2 + 2, mid + 1, end, left, right);
	}
}

void update(int c_idx, ll diff, int idx, int start, int end)
{
	if (c_idx<start || c_idx>end)
		return;
	tree[idx] += diff;
	if (start != end)
	{
		int mid = (start + end) / 2;
		update(c_idx, diff, idx * 2 + 1, start, mid);
		update(c_idx, diff, idx * 2 + 2, mid + 1, end);
	}
}

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	cin >> n >> m >> k;
	ll a;
	for (int i = 0; i < n; i++)
	{
		cin >> input[i];
	}
	init(0, 0, n - 1);
	int sz = m + k;
	int q, w, e,r;
	for (int i = 0; i < sz; i++)
	{
		cin >> q;
		if (q == 1)
		{
			cin >> w >> e >> r;
			for(int i=w-1;i<e;i++)
				update(i, r, 0, 0, n - 1);
		}
		else
		{
			cin >> w >> e;
			cout << sum(0, 0, n - 1, w - 1, e - 1) << "\n";
		}
	}
}
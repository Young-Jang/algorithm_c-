//mergesort 이용
//#include<iostream>
//
//using namespace std;
//
//int n;
//int p[500001][2];
//int t[500001][2];
//int c[500001];
//
//void merge(int s, int e,int mid)
//{
//	int sidx = s;
//	int eidx = mid + 1;
//	int cnt = 0;
//	int lcnt = 0;
//	while (sidx <= mid && eidx <= e)
//	{
//
//		if (p[sidx][1] > p[eidx][1])
//		{
//			t[cnt][0] = p[eidx][0];
//			t[cnt][1] = p[eidx][1];
//			c[p[eidx][0]] += lcnt;
//			eidx++;
//			cnt++;
//		}
//		else
//		{
//			t[cnt][0] = p[sidx][0];
//			t[cnt][1] = p[sidx][1];
//			sidx++;
//			cnt++;
//			lcnt++;
//		}
//	}
//	while (sidx <= mid)
//	{
//		t[cnt][0] = p[sidx][0];
//		t[cnt][1] = p[sidx][1];
//		sidx++;
//		cnt++;
//		lcnt++;
//	}
//	while (eidx <= e)
//	{
//		t[cnt][0] = p[eidx][0];
//		t[cnt][1] = p[eidx][1];
//		c[p[eidx][0]] += lcnt;
//		eidx++;
//		cnt++;
//	}
//	for (int i = 0; i < cnt; i++)
//	{
//		p[s + i][0] = t[i][0];
//		p[s + i][1] = t[i][1];
//	}
//}
//
//void mergesort(int s,int e)
//{
//	if (s < e)
//	{
//		int mid = (s + e) / 2;
//		mergesort(s, mid);
//		mergesort(mid + 1, e);
//		merge(s, e,mid);
//	}
//}
//
//int main()
//{
//	cin >> n;
//	for(int i=1;i<=n;i++)
//	{
//		cin >> p[i][1];
//		p[i][0] = i;
//	}
//	mergesort(1, n);
//
//	for (int i = 1; i <= n; i++)
//	{
//		cout << i-c[i] << "\n";
//	}
//}


//segment tree이용
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct pos {
	int v, idx;
};

pos arr[500000];//실력, 위치
int tree[2000000];

int update(int node, int value, int start, int end) {
	if (value < start || end < value) return tree[node]; 
	else if (start == end) return tree[node] = 1;

	int mid = (start + end) / 2;
	return tree[node] = update(node * 2, value, start, mid) + update(node * 2 + 1, value, mid + 1, end);
}

int update(int node, int value, int start, int end)
{
	if (value < start || end < value) return tree[node];
	else if (start == end) return tree[node] = 1;

	int mid = (start + end) / 2;
	return tree[node] = update(node *2, value,start,mid)
}

int query(int node, int value, int start, int end) {
	if (value < start) return tree[node];
	else if (end < value || start == end) return 0;
	int mid = (start + end) / 2;
	return query(node * 2, value, start, mid) + query(node * 2 + 1, value, mid + 1, end);
}

bool cmp(pos a, pos b) {
	return a.idx < b.idx;
}

bool cmp1(pos a, pos b) {
	return a.v < b.v;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i].v;
		arr[i].idx = i;
	}

	sort(arr, arr + n,cmp1);

	for (int i = 0; i < n; i++) arr[i].v = i;

	sort(arr, arr + n, cmp);

	for (int i = 0; i < n; i++) {
		cout << 1 + query(1, arr[i].v, 0, n - 1) << '\n';
		update(1, arr[i].v, 0, n - 1);
	}
	return 0;
}

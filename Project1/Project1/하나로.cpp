#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int n;
double e;
int island[1000][2];
int cnt = 0;

struct pp {
	int y, x; //정점
	long long v; //정점간 거리
};

bool cmp(pp a, pp b) //정점 정렬 함수
{
	if (a.v > b.v)
		return true;
	else
		return false;
}

vector<pp>v;

int p[1000]; //parent
int r[1000]; //rank
long long res = 0;

int find(int u)
{
	if (u == p[u])
		return u;
	else
		return p[u] = find(p[u]);
}

void merge(int n1, int n2)
{
	n1 = find(n1);
	n2 = find(n2);
	if (n1 != n2)
	{
		if (r[n1] < r[n2])
			p[n1] = n2;
		else
		{
			p[n2] = n1;
			if (r[n1] == r[n2])
				r[n1]++;
		}
	}
}

long long leng(int y1, int x1, int y2, int x2) //두 점사이 길이의 제곱
{
	long long a = abs(y1 - y2);
	long long b = abs(x1 - x2);
	return a * a + b * b;
}

int main()
{
	int T;
	cin >> T;
	for (int k = 1; k <= T; k++)
	{
		cin >> n;
		res = 0;
		cnt = 0;
		for (int i = 0; i < n; i++) //x값 입력
		{
			p[i] = i;
			r[i] = 0;
			cin >> island[i][0];
		}
		for (int i = 0; i < n; i++)
		{
			cin >> island[i][1];
		}
		cin >> e;
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (i == j)
					continue;
				long long len = leng(island[i][1], island[i][0], island[j][1], island[j][0]); //정점간 길이
				v.push_back({ i,j,len }); //정점 2개, 길이
			}
		}
		sort(v.begin(), v.end(), cmp); //정점 정렬
		for (int i = v.size() - 1; i >= 0; i--)
		{
			long long val = v[i].v;
			int y = v[i].y;
			int x = v[i].x;
			if (find(y) != find(x)) //같은 집합에 속하지 않을때
			{
				merge(y, x); //union
				cnt++;
				res += val; //길이 누적
				if(cnt==n-1)
					break;
			}
			v.pop_back();
		}
		v.clear();
		double tmp = (double)res * e;
		printf("#%d %.0lf\n", k, tmp);
	}
}
#include<iostream>
#include<queue>
#include<vector>

using namespace std;

struct pos {
	int ry, rx;
	int by, bx;
	int c;
	vector<int> d;
};

char map[10][10];
char dir[4] = { 'U','R','D','L' };

int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };
int r[2];
int b[2];
int n, m;
int f = 0; //0red 1blue
bool ff = false;

queue<pos> q;

void first_move(int i,int rx,int ry,int bx,int by)
{
	if (!i)
	{
		if (ry < by)
			f = 0;
		else
			f = 1;
	}
	else if (i == 1)
	{
		if (rx > bx)
			f = 0;
		else
			f = 1;
	}
	else if (i == 2)
	{
		if (ry > by)
			f = 0;
		else
			f = 1;
	}
	else
	{
		if (rx < bx)
			f = 0;
		else
			f = 1;
	}
}

void bfs()
{
	while (!q.empty())
	{
		int ry = q.front().ry;
		int rx = q.front().rx;
		int by = q.front().by;
		int bx = q.front().bx;
		int c = q.front().c;
		if (c >= 10)
		{
			while (!q.empty())
				q.pop();
			cout << -1;
			ff = true;
			break;
		}
		int pre_d = q.front().d[c];
		vector<int> dd = q.front().d;
		q.front().d.clear();
		/*for (int i = 0; i < d.size(); i++)
			cout << d[i] << ",";
		cout << endl;*/
		q.pop();
		bool rf = true;
		bool bf = true;
		for (int i = 0; i < 4; i++)
		{
			if (pre_d!=-1&&i == (pre_d+2)%4)
				continue;
			first_move(i,rx,ry,bx,by);
			rf = true;
			bf = true;
			if (!f)
			{
				int rny = ry;
				int rnx = rx;
				while (map[rny][rnx] != '#' && (by != rny || bx != rnx))
				{
					rny += dy[i];
					rnx += dx[i];
					if (map[rny][rnx] == 'O')
					{
						rny = -1;
						rnx = -1;
						rf = false;
						break;
					}
				}
				rny -= dy[i];
				rnx -= dx[i];
				int bny = by;
				int bnx = bx;
				while (map[bny][bnx] != '#'&&(bny!=rny||bnx!=rnx))
				{
					bny += dy[i];
					bnx += dx[i];
					if (map[bny][bnx] == 'O')
					{
						bf = false;
						break;
					}
				}
				bny -= dy[i];
				bnx -= dx[i];
				if (!bf)
				{
					continue;
				}
				else if (!rf)
				{
					ff = true;
					cout << c+1 << "\n";
					for (int j = 1; j <= c; j++)
					{
						cout << dir[dd[j]];
					}
					cout << dir[i];
					while (!q.empty())
					{
						q.pop();
					}
					break;
				}
				else
				{
					if (rny == ry && rnx == rx && bny == by && bnx == bx) {
						continue;
					}
					dd.push_back(i);
					q.push({ rny,rnx,bny,bnx,c + 1,dd });
					dd.erase(dd.end() - 1);
				}
			}
			else
			{
				int bny = by;
				int bnx = bx;
				while (map[bny][bnx] != '#' && (bny != ry || bnx != rx))
				{
					bny += dy[i];
					bnx += dx[i];
					if (map[bny][bnx] == 'O')
					{
						bf = false;
						break;
					}
				}
				bny -= dy[i];
				bnx -= dx[i];
				if (!bf)
				{
					continue;
				}
				int rny = ry;
				int rnx = rx;
				while (map[rny][rnx] != '#' && (bny != rny || bnx != rnx))
				{
					rny += dy[i];
					rnx += dx[i];
					if (map[rny][rnx] == 'O')
					{
						rf = false;
						break;
					}
				}
				rny -= dy[i];
				rnx -= dx[i];
				if (!rf)
				{
					ff = true;
					cout << c+1 << "\n";
					for (int j = 1; j <= c; j++)
					{
						cout <<dir[dd[j]];
					}
					cout << dir[i];
					while (!q.empty())
					{
						q.pop();
					}
					break;
				}
				else
				{
					if (rny == ry && rnx == rx && bny == by && bnx == bx) {
						continue;
					}
					dd.push_back(i);
					q.push({ rny,rnx,bny,bnx,c + 1,dd });
					dd.erase(dd.end() - 1);
				}
			}
		}
	}
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 'R')
			{
				map[i][j] = '.';
				r[0] = i;
				r[1] = j;
			}
			else if (map[i][j] == 'B')
			{
				map[i][j] = '.';
				b[0] = i;
				b[1] = j;
			}
		}
	}
	vector<int> v;
	v.push_back(-1);
	q.push({ r[0],r[1],b[0],b[1],0,v});
	bfs();
	if (!ff)
		cout << -1;
}
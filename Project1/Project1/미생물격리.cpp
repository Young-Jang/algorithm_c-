#include<iostream>
#include<vector>
#include<string.h>

using namespace std;

struct pos {
    int y, x, d, c;
};

int map[100][100][2];
vector<pos>v;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int n, m, k;

int main()
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        memset(map, -1, sizeof(map));
        cin >> n >> m >> k;
        int a, b, c, d;
        for (int i = 0; i < k; i++)
        {
            cin >> a >> b >> c >> d;
            v.push_back({ a,b,d-1,c });
        }
        while (m)
        {
            m--;
            for (int i = 0; i < v.size(); i++)
            {
                if (v[i].c <= 0)
                    continue;
                int nx = v[i].x + dx[v[i].d];
                int ny = v[i].y + dy[v[i].d];
                v[i].x = nx;
                v[i].y = ny;
                if (ny == 0 || nx == 0 || ny == n - 1 || nx == n - 1)
                {
                    if (v[i].d == 0)
                        v[i].d = 1;
                    else if (v[i].d == 1)
                        v[i].d = 0;
                    else if (v[i].d == 2)
                        v[i].d = 3;
                    else
                        v[i].d = 2;
                    v[i].c /= 2;
                    map[ny][nx][1] = v[i].c;
                }
                else if (map[ny][nx][0] != -1)
                {
                    int idx = map[ny][nx][0];
                    map[ny][nx][1] += v[i].c;
                    if (v[idx].c < v[i].c)
                    {
                        map[ny][nx][0] = i;
                        v[idx].c = 0;
                    }
                    else
                    {
                        v[i].c = 0;
                    }
                }
                else
                {
                    map[ny][nx][0] = i;
                    map[ny][nx][1] = v[i].c;
                }
            }
            for (int i = 0; i < v.size(); i++)
            {
                map[v[i].y][v[i].x][0] = -1;
                if (v[i].c != 0)
                {
                    v[i].c = map[v[i].y][v[i].x][1];
                    map[v[i].y][v[i].x][1] = 0;
                }
            }
        }
        int res = 0;
        for (int i = 0; i < v.size(); i++)
        {
            res += v[i].c;
        }
        cout << "#" << t << " " << res << "\n";
        v.clear();
    }
}
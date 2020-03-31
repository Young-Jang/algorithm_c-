#include <iostream>
#include <cstring>
#include <vector>
#include<algorithm>

#define MAX 10001
using namespace std;

int V[MAX];
int C[MAX];
int K[MAX];
int dp[MAX];
int N, M;
vector<pair<int, int> > thing;

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> V[i] >> C[i] >> K[i];
    }


    for (int j = 0; j < N; j++) {
        for (int i = K[j]; i > 0; i >>= 1) {
            int num = i - (i >> 1);
            thing.push_back({ V[j] * num, C[j] * num });
        }
    }

    for (int i = 0; i < thing.size(); i++) {
        int v = thing[i].first;
        int c = thing[i].second;
        for (int j = M; j >= v; j--) {
            dp[j] = max(dp[j], dp[j - v] + c);
        }
    }
    cout << dp[M];

    return 0;
}
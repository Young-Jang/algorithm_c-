#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 22

int T, n, c[MAX + 2], r[MAX + 2][MAX + 2], min = 0x7fffffff, v[MAX + 2], dp[MAX + 2][(1 << MAX) + 1], count, count2, min2 = 0x7fffffff;
void solve(int node, int visit, int sum);
void solve2(int node, int visit, int sum);

int main(void) {
    freopen("input1.txt", "r", stdin);
    int tmp;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &c[i]);            //cost �迭
            r[i][0] = 0;               //��������Ʈ �ʱ�ȭ
            v[i] = (1 << i);            //v[i]�� �ڱ��ڽ����� �ʱ�ȭ
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &tmp);
                if (tmp) {
                    r[i][++r[i][0]] = j;   //��������Ʈ ����
                    v[i] |= (1 << j);      //�ֺ� ������ ��� ����
                }
            }
        }
        for (int i = 0; i < n; i++) solve(i, v[i], c[i]);   //�� ��忡�� ����

        for (int i = 0; i < n; i++) {
            solve2(i, v[i], c[i]);   //�� ��忡�� ����
            if (dp[i][v[i]])   min2 = min2 < dp[i][v[i]] ? min2 : dp[i][v[i]];
        }

        printf("#%d %d %d %d %d\n", t, min, min2, count, count2);
        min2 = 0x7fffffff, min = 0x7fffffff, count = count2 = 0;
    }
    return 0;
}
void solve(int node, int visit, int sum) {
    count++;
    if (visit == (1 << n) - 1) min = min < sum ? min : sum;   //visit�� ���δ� �湮�ѰŸ� sum�̶� min ��
    else if (node == n - 1 || sum > min) return;   //node�� n-1�̶� �������ų�(���̻� �湮�Ұ� ����), sum�� min�� ������ ����
    else {
        for (int i = node + 1; i < n; i++)
            solve(i, visit | v[i], sum + c[i]);   //���� ������ �湮
    }
}
void solve2(int node, int visit, int sum) {
    count2++;
    if (visit == (1 << n) - 1) {
        dp[node][visit] = c[node];
        return;
    }
    else if (node == n - 1 || sum > min2) return;   //node�� n-1�̶� �������ų�(���̻� �湮�Ұ� ����), sum�� min�� ������ ����
    else if (dp[node][visit]) return;
    else {
        int m = 0x7fffffff;
        for (int i = node + 1; i < n; i++) {
            solve2(i, visit | v[i], sum + c[i]);   //���� ������ �湮
            int tmp = dp[i][visit | v[i]];
            if (tmp)   m = m < tmp ? m : tmp;
        }
        if (m != 0x7fffffff) dp[node][visit] = m + c[node];
    }
}
#define  _CRT_SECURE_NO_WARNINGS 1
// 冗余路径
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//const int N = 5010, M = 20010;
//int n, m;
//int h[N], e[M], ne[M], idx;
//int dfn[N], low[N], timestamp;
//int stk[N], top;
//int id[N], dcc_cnt;
//bool is_bridge[M];
//int d[N];
//void add(int a, int b)
//{
//	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
//}
//void tarjan(int u, int from)
//{
//	dfn[u] = low[u] = ++timestamp;
//	stk[++top] = u;
//	for (int i = h[u];~i;i = ne[i])
//	{
//		int j = e[i];
//		if (!dfn[j])
//		{
//			tarjan(j, i);
//			low[u] = min(low[u], low[j]);
//			if (dfn[u] < low[j])
//				is_bridge[i] = is_bridge[i ^ 1] = true;
//		}
//		else if (i != (from ^ 1))
//			low[u] = min(low[u], dfn[j]);
//	}
//	if (dfn[u] == low[u])
//	{
//		++dcc_cnt;
//		int y;
//		do {
//			y = stk[top--];
//			id[y] = dcc_cnt;
//		} while (y != u);
//	}
//}
//int main()
//{
//	cin >> n >> m;
//	memset(h, -1, sizeof h);
//	while (m--)
//	{
//		int a, b;
//		cin >> a >> b;
//		add(a, b), add(b, a);
//	}
//	tarjan(1, -1);
//	for (int i = 0;i < idx;i++)
//		if (is_bridge[i])
//			d[id[e[i]]]++;
//	int cnt = 0;
//	for (int i = 1;i <= dcc_cnt;i++)
//		if (d[i] == 1)
//			cnt++;
//	cout << (cnt + 1) / 2 << endl;
//}





//电力
//#include <cstdio>
//#include <cstring>
//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//const int N = 10010, M = 30010;
//
//int n, m;
//int h[N], e[M], ne[M], idx;
//int dfn[N], low[N], timestamp;
//int root, ans;
//
//void add(int a, int b)
//{
//    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
//}
//
//void tarjan(int u)
//{
//    dfn[u] = low[u] = ++timestamp;
//
//    int cnt = 0;
//    for (int i = h[u]; ~i; i = ne[i])
//    {
//        int j = e[i];
//        if (!dfn[j])
//        {
//            tarjan(j);
//            low[u] = min(low[u], low[j]);
//            if (low[j] >= dfn[u]) cnt++;
//        }
//        else low[u] = min(low[u], dfn[j]);
//    }
//
//    if (u != root) cnt++;
//
//    ans = max(ans, cnt);
//}
//
//int main()
//{
//    while (scanf("%d%d", &n, &m), n || m)
//    {
//        memset(dfn, 0, sizeof dfn);
//        memset(h, -1, sizeof h);
//        idx = timestamp = 0;
//
//        while (m--)
//        {
//            int a, b;
//            scanf("%d%d", &a, &b);
//            add(a, b), add(b, a);
//        }
//
//        ans = 0;
//        int cnt = 0;
//        for (root = 0; root < n; root++)
//            if (!dfn[root])
//            {
//                cnt++;
//                tarjan(root);
//            }
//
//        printf("%d\n", ans + cnt - 1);
//    }
//
//    return 0;
//}
//




//矿场搭建
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef unsigned long long ULL;

const int N = 1010, M = 1010;

int n, m;
int h[N], e[M], ne[M], idx;
int dfn[N], low[N], timestamp;
int stk[N], top;
int dcc_cnt;
vector<int> dcc[N];
bool cut[N];
int root;

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void tarjan(int u)
{
    dfn[u] = low[u] = ++timestamp;
    stk[++top] = u;

    if (u == root && h[u] == -1)
    {
        dcc_cnt++;
        dcc[dcc_cnt].push_back(u);
        return;
    }

    int cnt = 0;
    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if (!dfn[j])
        {
            tarjan(j);
            low[u] = min(low[u], low[j]);
            if (dfn[u] <= low[j])
            {
                cnt++;
                if (u != root || cnt > 1) cut[u] = true;
                ++dcc_cnt;
                int y;
                do {
                    y = stk[top--];
                    dcc[dcc_cnt].push_back(y);
                } while (y != j);
                dcc[dcc_cnt].push_back(u);
            }
        }
        else low[u] = min(low[u], dfn[j]);
    }
}

int main()
{
    int T = 1;
    while (cin >> m, m)
    {
        for (int i = 1; i <= dcc_cnt; i++) dcc[i].clear();
        idx = n = timestamp = top = dcc_cnt = 0;
        memset(h, -1, sizeof h);
        memset(dfn, 0, sizeof dfn);
        memset(cut, 0, sizeof cut);

        while (m--)
        {
            int a, b;
            cin >> a >> b;
            n = max(n, a), n = max(n, b);
            add(a, b), add(b, a);
        }

        for (root = 1; root <= n; root++)
            if (!dfn[root])
                tarjan(root);

        int res = 0;
        ULL num = 1;
        for (int i = 1; i <= dcc_cnt; i++)
        {
            int cnt = 0;
            for (int j = 0; j < dcc[i].size(); j++)
                if (cut[dcc[i][j]])
                    cnt++;

            if (cnt == 0)
            {
                if (dcc[i].size() > 1) res += 2, num *= dcc[i].size() * (dcc[i].size() - 1) / 2;
                else res++;
            }
            else if (cnt == 1) res++, num *= dcc[i].size() - 1;
        }

        printf("Case %d: %d %llu\n", T++, res, num);
    }

    return 0;
}

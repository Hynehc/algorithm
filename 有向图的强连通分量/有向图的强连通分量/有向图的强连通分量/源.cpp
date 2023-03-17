//#define  _CRT_SECURE_NO_WARNINGS 1
////受欢迎的牛
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//const int N = 10010, M = 50010;
//int n, m;
//int h[N], e[M], ne[M], idx;
//int dfn[N], low[N], timestamp;
//int stk[N], top;
//bool in_stk[N];
//int id[N], scc_cnt, sz[N];//每个强连通分的节点个数
//int dout[N];
//void add(int a, int b)
//{
//	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
//}
//void tarjan(int u)
//{
//	dfn[u] = low[u] = ++timestamp;//u的时间戳
//	stk[++top] = u, in_stk[u] = true;//把当前点加到栈中  当前点在栈中
//	for (int i = h[u];~i;i = ne[i])
//	{
//		int j = e[i];
//		if (!dfn[j])
//		{
//			tarjan(j);
//			low[u] = min(low[u], low[j]);
//			//j也许存在反向边到达比u还高的层,所以用j能到的最小dfn序(最高点)更新u能达到的(最小dfn序)最高点
//		}
//		else if (in_stk[j]) low[u] = min(low[u], dfn[j]);
//		//j点在栈中  说明还没出栈 是dfs序比当前点u小的
//		//则其 1要么是横插边(左边分支的点)
//		//         o
//		//        / \
//        //       j ← u    
//		//     2要么是u的祖宗节点
//		//         j
//		//      ↗/ 
//		//       u    
//		//    两种情况u的dfs序都比j大 所以用dfn[j]更新low[u]
//	}
//	if (dfn[u] == low[u])
//	{
//		++scc_cnt;//强连通分量总数+1
//		int y;
//		do {
//			y = stk[top--];
//			in_stk[y] = false;
//			id[y] = scc_cnt;
//			sz[scc_cnt]++;//第scc_cnt个连通块点数+1
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
//		add(a, b);
//	}
//	for (int i = 1;i <= n;i++)
//		if (!dfn[i])
//			tarjan(i);
//	for(int i=1;i<=n;i++)//统计新图中点的出度 
//		for (int j = h[i];~j;j = ne[j])
//		{
//			int k = e[j];
//			int a = id[i], b = id[k];//a,b不为一个连通分量
//			if (a != b) dout[a]++;//a出度+1  dout[a] += i→k
//		}
//	int zeros = 0, sum = 0;//sum 存的所有出度为0的强连通分量的点的数量
//	for (int i = 1;i <= scc_cnt;i++)
//		if (!dout[i])//如果第i个强连通分量出度==0
//		{
//			zeros++;
//			sum += sz[i];//则加上第i个强连通分量的点的个数
//			if (zeros > 1)//如果有k>1个出度为0的 则会存在k-1头牛不被所有牛欢迎
//			{
//				sum = 0;
//				break;
//			}
//		}
//	cout << sum << endl;
//}




// 学校网络
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//const int N = 110, M = 10010;
//int n;
//int h[N], e[M], ne[M], idx;
//int dfn[N], low[N], timestamp;
//int stk[N], top;
//bool in_stk[N];
//int id[N], scc_cnt, din[N], dout[N];
//void add(int a, int b)
//{
//	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
//}
//void tarjan(int u)
//{
//	dfn[u] = low[u] = ++timestamp;
//	stk[++top] = u, in_stk[u] = true;
//	for (int i = h[u];~i;i = ne[i])
//	{
//		int j = e[i];
//		if (!dfn[j])
//		{
//			tarjan(j);
//			low[u] = min(low[u], low[j]);
//		}
//		else if (in_stk[j])
//			low[u] = min(low[u], dfn[j]);
//	}
//	if (dfn[u] == low[u])
//	{
//		++scc_cnt;
//		int y;
//		do
//		{
//			y = stk[top--];
//			in_stk[y] = false;
//			id[y] = scc_cnt;
//		} while (y != u);
//	}
//}
//int main()
//{
//	cin >> n;
//	memset(h, - 1, sizeof h);
//	for (int i = 1;i <= n;i++)
//	{
//		int t;
//		while (cin >> t, t) add(i, t);
//	}
//	for (int i = 1;i <= n;i++)
//		if (!dfn[i])
//			tarjan(i);
//	for(int i=1;i<=n;i++)
//		for (int j = h[i];~j;j = ne[j])
//		{
//			int k = e[j];
//			int a = id[i], b = id[k];
//			if (a != b)
//			{
//				dout[a]++;
//				din[b]++;
//			}
//		}
//	int a = 0, b = 0;
//	for (int i = 1;i <= scc_cnt;i++)
//	{
//		if (!din[i]) a++;
//		if (!dout[i]) b++;
//	}
//	cout << a << endl;
//	if (scc_cnt == 1) cout << 0 << endl;
//	else cout << max(a, b) << endl;
//}



//最大半连通子图
//#include <cstdio>
//#include <cstring>
//#include <iostream>
//#include <algorithm>
//#include <unordered_set>
//
//using namespace std;
//
//typedef long long LL;
//
//const int N = 100010, M = 2000010;
//
//int n, m, mod;
//int h[N], hs[N], e[M], ne[M], idx;
//int dfn[N], low[N], timestamp;
//int stk[N], top;
//bool in_stk[N];
//int id[N], scc_cnt, scc_size[N];
//int f[N], g[N];
//
//void add(int h[], int a, int b)
//{
//    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
//}
//
//void tarjan(int u)
//{
//    dfn[u] = low[u] = ++timestamp;
//    stk[++top] = u, in_stk[u] = true;
//
//    for (int i = h[u]; ~i; i = ne[i])
//    {
//        int j = e[i];
//        if (!dfn[j])
//        {
//            tarjan(j);
//            low[u] = min(low[u], low[j]);
//        }
//        else if (in_stk[j]) low[u] = min(low[u], dfn[j]);
//    }
//
//    if (dfn[u] == low[u])
//    {
//        ++scc_cnt;
//        int y;
//        do {
//            y = stk[top--];
//            in_stk[y] = false;
//            id[y] = scc_cnt;
//            scc_size[scc_cnt] ++;
//        } while (y != u);
//    }
//}
//
//int main()
//{
//    memset(h, -1, sizeof h);
//    memset(hs, -1, sizeof hs);
//
//    scanf("%d%d%d", &n, &m, &mod);
//    while (m--)
//    {
//        int a, b;
//        scanf("%d%d", &a, &b);
//        add(h, a, b);
//    }
//
//    for (int i = 1; i <= n; i++)
//        if (!dfn[i])
//            tarjan(i);
//
//    unordered_set<LL> S;    // (u, v) -> u * 1000000 + v
//    for (int i = 1; i <= n; i++)
//        for (int j = h[i]; ~j; j = ne[j])
//        {
//            int k = e[j];
//            int a = id[i], b = id[k];
//            LL hash = a * 1000000ll + b;
//            if (a != b && !S.count(hash))
//            {
//                add(hs, a, b);
//                S.insert(hash);
//            }
//        }
//
//    for (int i = scc_cnt; i; i--)
//    {
//        if (!f[i])
//        {
//            f[i] = scc_size[i];
//            g[i] = 1;
//        }
//        for (int j = hs[i]; ~j; j = ne[j])
//        {
//            int k = e[j];
//            if (f[k] < f[i] + scc_size[k])
//            {
//                f[k] = f[i] + scc_size[k];
//                g[k] = g[i];
//            }
//            else if (f[k] == f[i] + scc_size[k])
//                g[k] = (g[k] + g[i]) % mod;
//        }
//    }
//
//    int maxf = 0, sum = 0;
//    for (int i = 1; i <= scc_cnt; i++)
//        if (f[i] > maxf)
//        {
//            maxf = f[i];
//            sum = g[i];
//        }
//        else if (f[i] == maxf) sum = (sum + g[i]) % mod;
//
//    printf("%d\n", maxf);
//    printf("%d\n", sum);
//
//    return 0;
//}
//





//银河
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 100010, M = 600010;
int n, m;
typedef long long ll;
int h[N], hs[N], e[M], ne[M], w[M], idx;
int dfn[N], low[N], timestamp, stk[N], top;
bool in_stk[N];
int id[N], scc_cnt, sz[N];
int dist[N];
void add(int h[],int a, int b, int c)
{
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}
void tarjan(int u)
{
	dfn[u] = low[u] = ++timestamp;
	stk[++top] = u, in_stk[u] = true;
	for (int i = h[u];~i;i = ne[i])
	{
		int j = e[i];
		if (!dfn[j])
		{
			tarjan(j);
			low[u] = min(low[u], low[j]);
		}
		else if (in_stk[j]) low[u] = min(low[u], dfn[j]);
	}
	if (dfn[u] == low[u])
	{
		++scc_cnt;
		int y;
		do {
			y = stk[top--];
			in_stk[y] = false;
			id[y] = scc_cnt;
			sz[scc_cnt]++;
		} while (y != u);
	}
}
int main()
{
	cin >> n >> m;
	memset(h, -1, sizeof h);
	memset(hs, -1, sizeof hs);
	for (int i = 1;i <= n;i++) add(h, 0, i, 1);
	while (m--)
	{
		int t, a, b;
		cin >> t >> a >> b;
		if (t == 1) add(h, a, b, 0), add(h, b, a, 0);
		else if (t == 2) add(h, a, b, 1);
		else if (t == 3) add(h, b, a, 0);
		else if (t == 4) add(h, b, a, 1);
		else add(h, a, b, 0);
	}
	tarjan(0);
	bool s = true;
	for (int i = 0;i <= n;i++)
	{
		for (int j = h[i];~j;j = ne[j])
		{
			int k = e[j];
			int a = id[i], b = id[k];
			if (a == b)
			{
				if (w[j] > 0)
				{
					s = false;
					break;
				}
			}
			else add(hs, a, b, w[j]);
		}
		if (!s) break;
	}
	if (!s) cout << -1 << endl;
	else
	{
		for (int i = scc_cnt;i;i--)
		{
			for (int j = hs[i];~j;j = ne[j])
			{
				int k = e[j];
				dist[k] = max(dist[k], dist[i] + w[j]);
			}
		}
		ll res = 0;
		for (int i = 1;i <= scc_cnt;i++) res += (ll)dist[i] * sz[i];
		cout << res << endl;
	}
}
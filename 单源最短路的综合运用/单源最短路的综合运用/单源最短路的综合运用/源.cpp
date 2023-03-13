#define  _CRT_SECURE_NO_WARNINGS 1
//新年好
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<queue>
//#include<cstdio>
//using namespace std;
//typedef pair<int, int>PII;
//const int N = 50010, M = 200010, INF = 0x3f3f3f3f;
//int n, m;
//int h[N], e[M], w[M], ne[M], idx;
//int q[N], dist[6][N];
//int source[6];
//bool st[N];
//void add(int a, int b, int c)
//{
//	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
//}
//void dijkstra(int start, int dist[])
//{
//	memset(dist, 0x3f, N * 4);
//	dist[start] = 0;
//	memset(st, 0, sizeof st);
//	priority_queue<PII, vector<PII>, greater<PII>> heap;
//	heap.push({ 0,start });// 距离，点
//	while (heap.size())
//	{
//		auto t = heap.top();
//		heap.pop();
//		int ver = t.second;
//		if (st[ver]) continue;
//		st[ver] = true;
//		for (int i = h[ver];~i;i = ne[i])
//		{
//			int j = e[i];
//			if (dist[j] > dist[ver] + w[i])
//			{
//				dist[j] = dist[ver] + w[i];
//				heap.push({ dist[j],j });
//			}
//		}
//	}
//}
//// 枚举每种拜访次序，求出最小距离
//// 拜访了u个人，自己是第1个人；当前起点是source[start]，当前走过的距离是distance
//int dfs(int u, int start, int distance)
//{
//	if (u > 5) return distance;
//	int res = INF;// res存距离最短的分支
//	for(int i=1;i<=5;i++)
//		if (!st[i])
//		{
//			int next = source[i];
//			st[i] = true;
//			res = min(res, dfs(u + 1, i, distance + dist[start][next]));
//			st[i] = false;
//		}
//	return res;
//}
//int main()
//{
//	scanf("%d%d", &n, &m);
//	source[0] = 1;
//	for (int i = 1;i <= 5;i++) scanf("%d", &source[i]);
//	memset(h, -1, sizeof h);
//	while (m--)
//	{
//		int a, b, c;
//		scanf("%d%d%d", &a, &b, &c);
//		add(a, b, c), add(b, a, c);
//	}
//	for (int i = 0;i < 6;i++) dijkstra(source[i], dist[i]);
//	memset(st, 0, sizeof st);
//	printf("%d\n", dfs(1, 0, 0));
//}






//通信线路
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<deque>
//using namespace std;
//const int N = 1010, M = 20010;
//int n, m, k;
//int h[N], e[M], w[M], ne[M], idx;
//deque<int>q;
//int dist[N];
//bool st[N];
//void add(int a, int b, int c)
//{
//	e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
//}
//bool check(int bound)
//{
//	memset(st, 0, sizeof st);
//	memset(dist, 0x3f, sizeof dist);
//	dist[1] = 0;
//	q.push_back(1);
//	while (q.size())
//	{
//		int t = q.front();
//		q.pop_front();
//		if (st[t]) continue;
//		st[t] = true;
//		for (int i = h[t];~i;i = ne[i])
//		{
//			int j = e[i], v = w[i] > bound;
//			if (dist[j] > dist[t] + v)
//			{
//				dist[j] = dist[t] + v;
//				if (!v) q.push_front(j);
//				else q.push_back(j);
//			}
//		}
//	}
//	return dist[n] <= k;
//}
//int main()
//{
//	cin >> n >> m >> k;
//	memset(h, -1, sizeof h);
//	while (m--)
//	{
//		int a, b, c;
//		cin >> a >> b >> c;
//		add(a, b, c), add(b, a, c);
//	}
//	int l = 0, r = 1e6 + 1;
//	while (l < r)
//	{
//		int mid = l + r >> 1;
//		if (check(mid)) r = mid;
//		else l = mid + 1;
//	}
//	if (r == 1e6 + 1) r = -1;
//	cout << r << endl;
//}



//道路与航线
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<queue>
//#include<vector>
//#include<cstdio>
//#define x first
//#define y second
//using namespace std;
//typedef pair<int, int>PII;
//const int N = 25010, M = 150010, INF = 0x3f3f3f3f;
//int n, mr, mp, s;
//int h[N], e[M], w[M], ne[M], idx, id[N], dist[N], din[N];
//bool st[N];
//vector<int>block[N];
//int bcnt;
//queue<int>q;
//void add(int a, int b, int c)
//{
//	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
//}
//void dfs(int u, int bid)
//{
//	id[u] = bid;
//	block[bid].push_back(u);
//	for (int i = h[u];~i;i = ne[i])
//	{
//		int j = e[i];
//		if (!id[j]) dfs(j, bid);
//	}
//}
//void dijkstra(int bid)
//{
//	priority_queue<PII, vector<PII>, greater<PII>> heap;
//	for (auto ver : block[bid]) heap.push({ dist[ver],ver });
//	while (heap.size())
//	{
//		auto t = heap.top();
//		heap.pop();
//		int ver = t.y, dstance = t.x;
//		if (st[ver]) continue;
//		st[ver] = true;
//		for (int i = h[ver];~i;i = ne[i])
//		{
//			int j = e[i];
//			if (dist[j] > dist[ver] + w[i])
//			{
//				dist[j] = dist[ver] + w[i];
//				if (id[j] == id[ver]) heap.push({ dist[j],j });
//			}
//			if (id[j] != id[ver] && --din[id[j]] == 0) q.push(id[j]);
//		}
//	}
//}
//void topsort()
//{
//	memset(dist, 0x3f, sizeof dist);
//	dist[s] = 0;
//	for (int i = 1;i <= bcnt;i++)
//		if (!din[i])
//			q.push(i);
//	while (q.size())
//	{
//		int t = q.front();
//		q.pop();
//		dijkstra(t);
//	}
//}
//int main()
//{
//	scanf("%d%d%d%d", &n, &mr, &mp, &s);
//	memset(h, -1, sizeof h);
//	while (mr--)
//	{
//		int a, b, c;
//		scanf("%d%d%d", &a, &b, &c);
//		add(a, b, c), add(b, a, c);
//	}
//	for (int i = 1;i <= n;i++)
//		if (!id[i])
//			dfs(i, ++bcnt);
//	while (mp--)
//	{
//		int a, b, c;
//		scanf("%d%d%d", &a, &b, &c);
//		add(a, b, c);
//		din[id[b]]++;
//	}
//	topsort();
//	for (int i = 1;i <= n;i++)
//		if (dist[i] > INF / 2) puts("NO PATH");
//		else printf("%d\n", dist[i]);
//}




//最优贸易
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
const int N = 100010, M = 2000010;
int n, m;
int w[N];
int hs[N], ht[N], e[M], ne[M], idx;
int dmin[N], dmax[N];
int q[N];
bool st[N];
void add(int h[], int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
void spfa(int h[], int dist[], int type)
{
	int hh = 0, tt = 1;
	if (type == 0)
	{
		memset(dist, 0x3f, sizeof dmin);
		dist[1] = w[1];
		q[0] = 1;
	}
	else
	{
		memset(dist, -0x3f, sizeof dmax);
		dist[n] = w[n];
		q[0] = n;
	}
	while (hh != tt)
	{
		int t = q[hh++];
		if (hh == N) hh = 0;
		st[t] = false;
		for (int i = h[t];~i;i = ne[i])
		{
			int j = e[i];
			if (type == 0 && dist[j] > min(dist[t], w[j]) || type == 1 && dist[j] < max(dist[t], w[j]))
			{
				if (type == 0) dist[j] = min(dist[t], w[j]);
				else dist[j] = max(dist[t], w[j]);
				if (!st[j])
				{
					q[tt++] = j;
					if (tt == N) tt = 0;
					st[j] = true;
				}
			}
		}
	}
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1;i <= n;i++) scanf("%d", &w[i]);
	memset(hs, -1, sizeof hs);
	memset(ht, -1, sizeof ht);
	while (m--)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		add(hs, a, b), add(ht, b, a);
		if (c == 2) add(hs, b, a), add(ht, a, b);
	}
	spfa(hs, dmin, 0);
	spfa(ht, dmax, 1);
	int res = 0;
	for (int i = 1;i <= n;i++) res = max(res, dmax[i] - dmin[i]);
	cout << res << endl;
}
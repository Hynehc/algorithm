#define  _CRT_SECURE_NO_WARNINGS 1
//选择最佳线路
//#include<iostream>
//#include<cstring>
//#include<cstdio>
//#include<algorithm>
//using namespace std;
//const int N = 1010, M = 21010, INF = 0x3f3f3f3f;
//int n, m, T;
//int h[N], e[M], ne[M], w[M], idx;
//int dist[N], q[N];
//bool st[N];
//void add(int a, int b, int c)
//{
//	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
//}
//int spfa()
//{
//	memset(dist, 0x3f, sizeof dist);
//	dist[0] = 0;
//	int hh = 0, tt = 1;
//	q[0] = 0;
//	while (hh != tt)
//	{
//		int t = q[hh++];
//		if (hh == N) hh = 0;
//		st[t] = false;
//		for (int i = h[t];~i;i = ne[i])
//		{
//			int j = e[i];
//			if (dist[j] > dist[t] + w[i])
//			{
//				dist[j] = dist[t] + w[i];
//				if (!st[j])
//				{
//					q[tt++] = j;
//					if (tt == N) tt = 0;
//					st[j] = true;
//				}
//			}
//		}
//	}
//	if (dist[T] == INF) return -1;
//	return dist[T];
//}
//int main()
//{
//	while (scanf("%d%d%d", &n, &m, &T) != -1)
//	{
//		memset(h, -1, sizeof h);
//		idx = 0;
//		while (m--)
//		{
//			int a, b, c;
//			cin >> a >> b >> c;
//			add(a, b, c);
//		}
//		int s;
//		cin >> s;
//		while (s--)
//		{
//			int ver = 0;
//			cin >> ver;
//			add(0, ver, 0);
//		}
//		cout << spfa() << endl;
//	}
//}






//拯救大兵瑞恩
//#include<iostream>
//#include<cstring>
//#include<deque>
//#include<set>
//#include<algorithm>
//using namespace std;
//#define x first
//#define y second
//typedef pair<int, int>PII;
//const int N = 11, M = N * N, E = 400, P = 1 << 10;
//int n, m, p, k;
//int h[M], e[E], ne[E], w[E], idx;
//int g[N][N], key[M];
//int dist[M][P];
//bool st[M][P];
//set<PII>edges;
//void add(int a, int b, int c)
//{
//	e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
//}
//void build()
//{
//	int dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 };
//	for(int i=1;i<=n;i++)
//		for(int j=1;j<=m;j++)
//			for (int u = 0;u < 4;u++)
//			{
//				int x = i + dx[u], y = j + dy[u];
//				if (!x || x > n || !y || y > m) continue;
//				int a = g[i][j], b = g[x][y];
//				if (edges.count({ a,b }) == 0) add(a, b, 0);
//			}
//}
//int bfs()
//{
//	memset(dist, 0x3f, sizeof dist);
//	dist[1][0] = 0;
//	deque<PII>q;
//	q.push_back({ 1,0 });
//	while (q.size())
//	{
//		auto t = q.front();
//		q.pop_front();
//		if (st[t.x][t.y]) continue;
//		st[t.x][t.y] = true;
//		if (t.x == n * m) return dist[t.x][t.y];
//		if (key[t.x])
//		{
//			int state = t.y | key[t.x];
//			if (dist[t.x][state] > dist[t.x][t.y])
//			{
//				dist[t.x][state] = dist[t.x][t.y];
//				q.push_front({ t.x,state });
//			}
//		}
//		for (int i = h[t.x];~i;i = ne[i])
//		{
//			int j = e[i];
//			if (w[i] && !(t.y >> w[i] - 1 & 1)) continue;
//			if (dist[j][t.y] > dist[t.x][t.y] + 1)
//			{
//				dist[j][t.y] = dist[t.x][t.y] + 1;
//				q.push_back({ j,t.y });
//			}
//		}
//	}
//	return -1;
//}
//int main()
//{
//	cin >> n >> m >> p >> k;
//	for (int i = 1, t = 1;i <= n;i++)
//		for (int j = 1;j <= m;j++)
//			g[i][j] = t++;
//	memset(h, -1, sizeof h);
//	while (k--)
//	{
//		int x1, y1, x2, y2, c;
//		cin >> x1 >> y1 >> x2 >> y2 >> c;
//		int a = g[x1][y1], b = g[x2][y2];
//		edges.insert({ a,b }), edges.insert({ b,a });
//		if (c) add(a, b, c), add(b, a, c);
//	}
//	build();
//	int s;
//	cin >> s;
//	while (s--)
//	{
//		int x, y, id;
//		cin >> x >> y >> id;
//		key[g[x][y]] |= 1 << id - 1;
//	}
//	cout << bfs() << endl;
//}






//最短路计数
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<cstdio>
//using namespace std;
//const int N = 100010, M = 400010, mod = 100003;
//int n, m;
//int h[N], e[M], ne[M], idx;
//int dist[N], cnt[N];
//int q[N];
//void add(int a, int b)
//{
//	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
//}
//void bfs()
//{
//	memset(dist, 0x3f, sizeof dist);
//	dist[1] = 0, cnt[1] = 1;
//	int hh = 0, tt = 0;
//	q[0] = 1;
//	while (hh <= tt)
//	{
//		int t = q[hh++];
//		for (int i = h[t];~i;i = ne[i])
//		{
//			int j = e[i];
//			if (dist[j] > dist[t] + 1)
//			{
//				dist[j] = dist[t] + 1;
//				cnt[j] = cnt[t];
//				q[++tt] = j;
//			}
//			else if (dist[j] == dist[t] + 1)
//			{
//				cnt[j] = (cnt[j] + cnt[t]) % mod;
//			}
//		}
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
//	bfs();
//	for (int i = 1;i <= n;i++) cout << cnt[i] << endl;
//}






//观光
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int N = 1010, M = 20010;
struct Ver
{
	int id, type, dist;
	bool operator > (const Ver& W) const
	{
		return dist > W.dist;
	}
};
int n, m, s, t;
int h[N], e[M], w[M], ne[M], idx;
int dist[N][2], cnt[N][2];
bool st[N][2];
void add(int a, int b, int c)
{
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}
int dijkstra()
{
	memset(st, 0, sizeof st);
	memset(dist, 0x3f, sizeof dist);
	memset(cnt, 0, sizeof cnt);
	dist[s][0] = 0, cnt[s][0] = 1;
	priority_queue<Ver, vector<Ver>, greater<Ver>>heap;
	heap.push({ s,0,0 });
	while (heap.size())
	{
		Ver t = heap.top();
		heap.pop();
		int ver = t.id, type = t.type, distance = t.dist, count = cnt[ver][type];
		if (st[ver][type]) continue;
		st[ver][type] = true;
		for (int i = h[ver];~i;i = ne[i])
		{
			int j = e[i];
			if (dist[j][0] > distance + w[i])
			{
				dist[j][1] = dist[j][0], cnt[j][1] = cnt[j][0];
				heap.push({ j,1,dist[j][1] });
				dist[j][0] = distance + w[i], cnt[j][0] = count;
				heap.push({ j,0,dist[j][0] });
			}
			else if (dist[j][0] == distance + w[i]) cnt[j][0] += count;
			else if (dist[j][1] > distance + w[i])
			{
				dist[j][1] = distance + w[i], cnt[j][1] = count;
				heap.push({ j,1,dist[j][1] });
			}
			else if (dist[j][1] == distance + w[i]) cnt[j][1] += count;
		}
	}
	int res = cnt[t][0];
	if (dist[t][0] + 1 == dist[t][1]) res += cnt[t][1];
	return res;
}
int main()
{
	int cases;
	cin >> cases;
	while (cases--)
	{
		cin >> n >> m;
		memset(h, -1, sizeof h);
		idx = 0;
		while (m--)
		{
			int a, b, c;
			cin >> a >> b >> c;
			add(a, b, c);
		}
		cin >> s >> t;
		cout << dijkstra() << endl;
	}
}
#define  _CRT_SECURE_NO_WARNINGS 1
//热浪
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//const int N = 2510, M = 6200 * 2 + 10;
//int n, m, s, t;
//int h[N], e[M], ne[M], w[M], idx;
//int dist[N], q[N];
//bool st[N];
//void add(int a, int b, int c)
//{
//	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
//}
//void spfa()
//{
//	memset(dist, 0x3f, sizeof dist);
//	dist[s] = 0;
//	int hh = 0, tt = 1;
//	q[0] = s, st[s] = true;
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
//}
//int main()
//{
//	cin >> n >> m >> s >> t;
//	memset(h, -1, sizeof h);
//	for (int i = 0;i < m;i++)
//	{
//		int a, b, c;
//		cin >> a >> b >> c;
//		add(a, b, c), add(b, a, c);
//	}
//	spfa();
//	cout << dist[t] << endl;
//}




//信使
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//const int N = 110, INF = 0x3f3f3f3f;
//int n, m;
//int d[N][N];
//int main()
//{
//	cin >> n >> m;
//	memset(d, 0x3f, sizeof d);
//	for (int i = 0;i < m;i++)
//	{
//		int a, b, c;
//		cin >> a >> b >> c;
//		d[a][b] = d[b][a] = min(d[a][b], c);
//	}
//	for (int k = 1;k <= n;k++)
//		for (int i = 1;i <= n;i++)
//			for (int j = 1;j <= n;j++)
//				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
//	int res = 0;
//	for (int i = 2;i <= n;i++)
//		if (d[1][i] == INF)
//		{
//			res = -1;
//			break;
//		}
//		else res = max(res, d[1][i]);
//	cout << res << endl;
//}





//香甜的黄油
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//const int N = 810, M = 3000, INF = 0x3f3f3f3f;
//int n, m, p;
//int id[N], h[N], e[M], w[M], ne[M], idx;
//int dist[N], q[N];
//bool st[N];
//void add(int a, int b, int c)
//{
//	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
//}
//int spfa(int start)
//{
//	memset(dist, 0x3f, sizeof dist);
//	dist[start] = 0;
//	int hh = 0, tt = 1;
//	q[0] = start, st[start] = true;
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
//	int res = 0;
//	for (int i = 0;i < n;i++)
//	{
//		int j = id[i];
//		if (dist[j] == INF) return INF;
//		res += dist[j];
//	}
//	return res;
//}
//int main()
//{
//	cin >> n >> p >> m;
//	for (int i = 0;i < n;i++) cin >> id[i];
//	memset(h, -1, sizeof h);
//	for (int i = 0;i < m;i++)
//	{
//		int a, b, c;
//		cin >> a >> b >> c;
//		add(a, b, c), add(b, a, c);
//	}
//	int res = INF;
//	for (int i = 1;i <= p;i++) res = min(res, spfa(i));
//	cout << res << endl;
//}






//最小花费
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<cstdio>
//using namespace std;
//const int N = 2010;
//int n, m, s, t;
//double g[N][N];
//double dist[N];
//bool st[N];
//void dijkstra()
//{
//	dist[s] = 1;
//	for (int i = 1;i <= n;i++)
//	{
//		int t = -1;
//		for (int j = 1;j <= n;j++)
//			if (!st[j] && (t == -1 || dist[t] < dist[j]))
//				t = j;
//		st[t] = true;
//		for (int j = 1;j <= n;j++)
//			dist[j] = max(dist[j], dist[t] * g[t][j]);
//	}
//}
//int main()
//{
//	scanf("%d%d", &n, &m);
//	while (m--)
//	{
//		int a, b, c;
//		scanf("%d%d%d", &a, &b, &c);
//		double z = (100.0 - c) / 100;
//		g[a][b] = g[b][a] = max(g[a][b], z);
//	}
//	cin >> s >> t;
//	dijkstra();
//	printf("%.8lf\n", 100 / dist[t]);
//}





// 最优乘车
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<sstream>
//using namespace std;
//const int N = 510;
//int n, m;
//bool g[N][N];
//int dist[N];
//int stop[N];
//int q[N];
//void bfs()
//{
//	int hh = 0, tt = 0;
//	memset(dist, 0x3f, sizeof dist);
//	q[0] = 1;
//	dist[1] = 0;
//	while (hh <= tt)
//	{
//		int t = q[hh++];
//		for(int i = 1;i <= n;i++)
//			if (g[t][i] && dist[i] > dist[t] + 1)
//			{
//				dist[i] = dist[t] + 1;
//				q[++tt] = i;
//			}
//	}
//}
//int main()
//{
//	cin >> m >> n;
//	string line;
//	getline(cin, line);
//	while (m--)
//	{
//		getline(cin, line);
//		stringstream ssin(line);
//		int cnt = 0, p;
//		while (ssin >> p) stop[cnt++] = p;
//		for (int j = 0;j < cnt;j++)
//			for (int k = j + 1;k < cnt;k++)
//				g[stop[j]][stop[k]] = true;
//	}
//	bfs();
//	if (dist[n] == 0x3f3f3f3f) puts("NO");
//	else cout << max(0, dist[n] - 1) << endl;
//}





//昂贵的聘礼
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 110, INF = 0x3f3f3f3f;
int n, m;
int w[N][N], level[N];
int dist[N];
bool st[N];
int dijkstra(int down, int up)
{
	memset(dist, 0x3f, sizeof dist);
	memset(st, 0, sizeof st);
	dist[0] = 0;
	for (int i = 1;i <= n;i++)
	{
		int t = -1;
		for (int j = 0;j <= n;j++)
			if (!st[j] && (t == -1 || dist[t] > dist[j]))
				t = j;
		st[t] = true;
		for (int j = 1;j <= n;j++)
			if (level[j] >= down && level[j] <= up)
				dist[j] = min(dist[j], dist[t] + w[t][j]);
	}
	return dist[1];
}
int main()
{
	cin >> m >> n;
	memset(w, 0x3f, sizeof w);
	for (int i = 1;i <= n;i++) w[i][i] = 0;
	for (int i = 1;i <= n;i++)
	{
		int price, cnt;
		cin >> price >> level[i] >> cnt;
		w[0][i] = min(price, w[0][i]);
		while (cnt--)
		{
			int id, cost;
			cin >> id >> cost;
			w[id][i] = min(w[id][i], cost);
		}
	}
	int res = INF;
	for (int i = level[1] - m;i <= level[1];i++) res = min(res, dijkstra(i, i + m));
	cout << res << endl;
}
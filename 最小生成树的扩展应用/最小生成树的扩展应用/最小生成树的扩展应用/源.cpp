#define  _CRT_SECURE_NO_WARNINGS 1
//新的开始
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//const int N = 310;
//int n;
//int w[N][N];
//int dist[N];
//bool st[N];
//int prim()
//{
//	memset(dist, 0x3f, sizeof dist);
//	dist[0] = 0;
//	int res = 0;
//	for (int i = 0;i < n + 1;i++)
//	{
//		int t = -1;
//		for (int j = 0;j < n + 1;j++)
//			if (!st[j] && (t == -1 || dist[t] > dist[j]))
//				t = j;
//		st[t] = true;
//		res += dist[t];
//		for (int j = 0;j < n + 1;j++) dist[j] = min(dist[j], w[t][j]);
//	}
//	return res;
//}
//int main()
//{
//	cin >> n;
//	for (int i = 1;i <= n;i++)
//	{
//		cin >> w[0][i];
//		w[i][0] = w[0][i];
//	}
//	for (int i = 1;i <= n;i++)
//		for (int j = 1;j <= n;j++)
//			cin >> w[i][j];
//	cout << prim() << endl;
//}






//北极通讯网络
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<cmath>
//using namespace std;
//#define x first
//#define y second
//typedef pair<int, int>PII;
//const int N = 510, M = N * N / 2;
//int n, k, m;
//struct Edge
//{
//	int a, b;
//	double w;
//	bool operator< (const Edge& t)const
//	{
//		return w < t.w;
//	}
//}e[M];
//PII q[N];
//int p[N];
//double get_dist(PII a, PII b)
//{
//	int dx = a.x - b.x;
//	int dy = a.y - b.y;
//	return sqrt(dx * dx + dy * dy);
//}
//int find(int x)
//{
//	if (x != p[x]) p[x] = find(p[x]);
//	return p[x];
//}
//int main()
//{
//	cin >> n >> k;
//	for (int i = 0;i < n;i++) cin >> q[i].x >> q[i].y;
//	for (int i = 0;i < n;i++)
//		for (int j = 0;j < i;j++)
//			e[m++] = { i,j,get_dist(q[i],q[j]) };
//	sort(e, e + m);
//	for (int i = 0;i < n;i++) p[i] = i;
//	int cnt = n;
//	double res = 0;
//	for (int i = 0;i < m;i++)
//	{
//		if (cnt <= k) break;
//		int a = find(e[i].a), b = find(e[i].b);
//		double w = e[i].w;
//		if (a != b)
//		{
//			p[a] = b;
//			cnt--;
//			res = w;
//		}
//	}
//	printf("%.2lf\n", res);
//}






//走廊泼水节
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//const int N = 6010;
//int n;
//struct Edge
//{
//	int a, b, w;
//	bool operator< (const Edge& t)const
//	{
//		return w < t.w;
//	}
//}e[N];
//int p[N];
//int sz[N];
//int find(int x)
//{
//	if (p[x] != x) p[x] = find(p[x]);
//	return p[x];
//}
//int main()
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		cin >> n;
//		for (int i = 0;i < n - 1;i++)
//		{
//			int a, b, w;
//			cin >> a >> b >> w;
//			e[i] = { a,b,w };
//		}
//		sort(e, e + n - 1);
//		for (int i = 1;i <= n;i++) p[i] = i, sz[i] = 1;
//		int res = 0;
//		for (int i = 0;i < n - 1;i++)
//		{
//			int a = find(e[i].a), b = find(e[i].b), w = e[i].w;
//			if (a != b)
//			{
//				res += (sz[a] * sz[b] - 1) * (w + 1);
//				p[a] = b;
//				sz[b] += sz[a];
//			}
//		}
//		cout << res << endl;
//	}
//}






//秘密的牛奶运输
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N = 510, M = 10010;
int n, m;
struct Edge
{
	int a, b, w;
	bool f;
	bool operator<(const Edge& t) const
	{
		return w < t.w;
	}
}edge[M];
int p[N];
int dist1[N][N], dist2[N][N];
int h[N], e[N * 2], w[N * 2], ne[N * 2], idx;
void add(int a, int b, int c)
{
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}
int find(int x)
{
	if (x != p[x]) p[x] = find(p[x]);
	return p[x];
}
void dfs(int u, int fa, int maxd1, int maxd2, int d1[], int d2[])
{
	d1[u] = maxd1, d2[u] = maxd2;
	for (int i = h[u];~i;i = ne[i])
	{
		int j = e[i];
		if (j != fa)
		{
			int td1 = maxd1, td2 = maxd2;
			if (w[i] > td1) td2 = td1, td1 = w[i];
			else if (w[i]<td1 && w[i]>td2) td2 = w[i];
			dfs(j, u, td1, td2, d1, d2);
		}
	}
}
int main()
{
	cin >> n >> m;
	memset(h, -1, sizeof h);
	for (int i = 0;i < m;i++)
	{
		int a, b, w;
		cin >> a >> b >> w;
		edge[i] = { a,b,w };
	}
	sort(edge, edge + m);
	for (int i = 1;i <= n;i++) p[i] = i;
	ll sum = 0;
	for (int i = 0;i < m;i++)
	{
		int a = edge[i].a, b = edge[i].b, w = edge[i].w;
		int pa = find(a), pb = find(b);
		if (pa != pb)
		{
			p[pa] = pb;
			sum += w;
			add(a, b, w), add(b, a, w);
			edge[i].f = true;
		}
	}
	for (int i = 1;i <= n;i++) dfs(i, -1, -1e9, -1e9, dist1[i], dist2[i]);
	ll res = 1e18;
	for(int i=0;i<m;i++)
		if (!edge[i].f)
		{
			int a = edge[i].a, b = edge[i].b, w = edge[i].w;
			ll t;
			if (w > dist1[a][b])
				t = sum + w - dist1[a][b];
			else if (w > dist2[a][b])
				t = sum + w - dist2[a][b];
			res = min(res, t);
		}
	cout << res << endl;
}
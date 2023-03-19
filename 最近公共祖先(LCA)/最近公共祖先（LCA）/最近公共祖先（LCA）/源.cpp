#define  _CRT_SECURE_NO_WARNINGS 1
// 祖孙询问
//#include<iostream>
//#include<algorithm>
//#include<cstring>
//using namespace std;
//const int N = 40010, M = N * 2;
//int n, m;
//int h[N], e[M], ne[M], idx;
//int depth[N], fa[N][16];
//int q[N];
//void add(int a, int b)
//{
//	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
//}
//void bfs(int root)
//{
//	memset(depth, 0x3f, sizeof depth);
//	depth[0] = 0, depth[root] = 1;
//	int hh = 0, tt = 0;
//	q[0] = root;
//	while (hh <= tt)
//	{
//		int t = q[hh++];
//		for (int i = h[t];~i;i = ne[i])
//		{
//			int j = e[i];
//			if (depth[j] > depth[t] + 1)
//			{
//				depth[j] = depth[t] + 1;
//				q[++tt] = j;
//				fa[j][0] = t;
//				for (int k = 1;k <= 15;k++)
//					fa[j][k] = fa[fa[j][k - 1]][k - 1];
//			}
//		}
//	}
//}
//int lca(int a, int b)
//{
//	if (depth[a] < depth[b]) swap(a, b);
//	for (int k = 15;k >= 0;k--)
//		if (depth[fa[a][k]] >= depth[b])
//			a = fa[a][k];
//	if (a == b) return a;
//	for (int k = 15;k >= 0;k--)
//		if (fa[a][k] != fa[b][k])
//			a = fa[a][k], b = fa[b][k];
//	return fa[a][0];
//}
//int main()
//{
//	cin >> n;
//	int root = 0;
//	memset(h, -1, sizeof h);
//	for (int i = 0;i < n;i++)
//	{
//		int a, b;
//		cin >> a >> b;
//		if (b == -1) root = a;
//		else add(b, a), add(a, b);
//	}
//	bfs(root);
//	cin >> m;
//	while (m--)
//	{
//		int a, b;
//		cin >> a >> b;
//		int p = lca(a, b);
//		if (p == a) puts("1");
//		else if (p == b) puts("2");
//		else puts("0");
//	}
//}




//距离
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<vector>
//using namespace std;
//typedef pair<int, int>PII;
//const int N = 20010, M = N * 2;
//int n, m;
//int h[N], e[M], ne[M], w[M], idx;
//int dist[N];
//int p[N];
//int res[N];
//int st[N];
//vector<PII>query[N];
//void add(int a, int b, int c)
//{
//	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
//}
//int find(int x)
//{
//	if (x != p[x]) p[x] = find(p[x]);
//	return p[x];
//}
//void dfs(int u, int fa)
//{
//	for (int i = h[u];~i;i = ne[i])
//	{
//		int j = e[i];
//		if (j == fa) continue;
//		dist[j] = dist[u] + w[i];
//		dfs(j, u);
//	}
//}
//void tarjan(int u)
//{
//	st[u] = 1;
//	for (int i = h[u];~i;i = ne[i])
//	{
//		int j = e[i];
//		if (!st[j])
//		{
//			tarjan(j);
//			p[j] = u;
//		}
//	}
//	for (auto item:query[u])
//	{
//		int y = item.first, id = item.second;
//		if (st[y] == 2)
//		{
//			int anc = find(y);
//			res[id] = dist[u] + dist[y] - dist[anc] * 2;
//		}
//	}
//	st[u] = 2;
//}
//int main()
//{
//	cin >> n >> m;
//	memset(h, -1, sizeof h);
//	for (int i = 0;i < n - 1;i++)
//	{
//		int a, b, c;
//		cin >> a >> b >> c;
//		add(a, b, c), add(b, a, c);
//	}
//	for (int i = 0;i < m;i++)
//	{
//		int a, b;
//		cin >> a >> b;
//		if (a != b)
//		{
//			query[a].push_back({ b,i });
//			query[b].push_back({ a,i });
//		}
//	}
//	for (int i = 1;i <= n;i++) p[i] = i;
//	dfs(1, -1);
//	tarjan(1);
//	for (int i = 0;i < m;i++) cout << res[i] << endl;
//}






//次小生成树
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//const int N = 100010, M = 300010, INF = 0x3f3f3f3f;
//int n, m;
//typedef long long ll;
//struct Edge
//{
//	int a, b, w;
//	bool used;
//	bool operator< (const Edge& t)const
//	{
//		return w < t.w;
//	}
//}edge[M];
//int p[N];
//int h[N], e[M], ne[M], w[M], idx;
//int depth[N], fa[N][17], d1[N][17], d2[N][17];
//int q[N];
//void add(int a, int b, int c)
//{
//	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
//}
//int find(int x)
//{
//	if (x != p[x]) p[x] = find(p[x]);
//	return p[x];
//}
//ll kruskal()
//{
//	for (int i = 1;i <= n;i++) p[i] = i;
//	sort(edge, edge + m);
//	ll res = 0;
//	for (int i = 0;i < m;i++)
//	{
//		int a = find(edge[i].a), b = find(edge[i].b), w = edge[i].w;
//		if (a != b)
//		{
//			p[a] = b;
//			res += w;
//			edge[i].used = true;
//		}
//	}
//	return res;
//}
//void build()
//{
//	memset(h, -1, sizeof h);
//	for(int i=0;i<m;i++)
//		if (edge[i].used)
//		{
//			int a = edge[i].a, b = edge[i].b, w = edge[i].w;
//			add(a, b, w), add(b, a, w);
//		}
//}
//void bfs()
//{
//	memset(depth, 0x3f, sizeof depth);
//	depth[0] = 1, depth[1] = 1;
//	q[0] = 1;
//	int hh = 0, tt = 0;
//	while (hh <= tt)
//	{
//		int t = q[hh++];
//		for (int i = h[t];~i;i = ne[i])
//		{
//			int j = e[i];
//			if (depth[j] > depth[t] + 1)
//			{
//				depth[j] = depth[t] + 1;
//				q[++tt] = j;
//				fa[j][0] = t;
//				d1[j][0] = w[i], d2[j][0] = -INF;
//				for (int k = 1;k <= 16;k++)
//				{
//					int anc = fa[j][k - 1];
//					fa[j][k] = fa[anc][k - 1];
//					int distance[4] = { d1[j][k - 1],d2[j][k - 1],d1[anc][k - 1],d2[anc][k - 1] };
//					d1[j][k] = d2[j][k] = -INF;
//					for (int u = 0;u < 4;u++)
//					{
//						int d = distance[u];
//						if (d > d1[j][k]) d2[j][k] = d1[j][k], d1[j][k] = d;
//						else if (d != d1[j][k] && d > d2[j][k]) d2[j][k] = d;
//					}
//				}
//			}
//		}
//	}
//}
//int lca(int a, int b, int w)
//{
//	static int distance[N * 2];
//	int cnt = 0;
//	if (depth[a] < depth[b]) swap(a, b);
//	for (int k = 16;k >= 0;k--)
//	{
//		if (depth[fa[a][k]] >= depth[b])
//		{
//			distance[cnt++] = d1[a][k];
//			distance[cnt++] = d2[a][k];
//			a = fa[a][k];
//		}
//	}
//	if (a != b)
//	{
//		for(int k=16;k>=0;k--)
//			if (fa[a][k] != fa[b][k])
//			{
//				distance[cnt++] = d1[a][k];
//				distance[cnt++] = d2[a][k];
//				distance[cnt++] = d1[b][k];
//				distance[cnt++] = d2[b][k];
//				a = fa[a][k], b = fa[b][k];
//			}
//		distance[cnt++] = d1[a][0];
//		distance[cnt++] = d1[b][0];
//	}
//	int dist1 = -INF, dist2 = -INF;
//	for (int i = 0;i < cnt;i++)
//	{
//		int d = distance[i];
//		if (d > dist1) dist2 = dist1, dist1 = d;
//		else if (d != dist1 && d > dist2) dist2 = d;
//	}
//	if (w > dist1) return w - dist1;
//	if (w > dist2) return w - dist2;
//	return INF;
//}
//int main()
//{
//	cin >> n >> m;
//	for (int i = 0;i < m;i++)
//	{
//		int a, b, c;
//		cin >> a >> b >> c;
//		edge[i] = { a,b,c };
//	}
//	ll sum = kruskal();
//	build();
//	bfs();
//	ll res = 1e18;
//	for (int i = 0;i < m;i++)
//		if (!edge[i].used)
//		{
//			int a = edge[i].a, b = edge[i].b, w = edge[i].w;
//			res = min(res, sum + lca(a, b, w));
//		}
//	cout << res << endl;
//}




//闇の連鎖
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 100010, M = N * 2;
int n, m;
int h[N], e[M], ne[M], idx;
int depth[N], fa[N][17];
int d[N], q[N], ans;
void add(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
void bfs()
{
	memset(depth, 0x3f, sizeof depth);
	depth[0] = 0, depth[1] = 1;
	int hh = 0, tt = 0;
	q[0] = 1;
	while (hh <= tt)
	{
		int t = q[hh++];
		for (int i = h[t];~i;i = ne[i])
		{
			int j = e[i];
			if(depth[j]>depth[t]+1)
			{
				depth[j] = depth[t] + 1;
				q[++tt] = j;
				fa[j][0] = t;
				for (int k = 1;k <= 16;k++)
					fa[j][k] = fa[fa[j][k - 1]][k - 1];
			}
		}
	}
}
int lca(int a, int b)
{
	if (depth[a] < depth[b]) swap(a, b);
	for (int k = 16;k >= 0;k--)
		if (depth[fa[a][k]] >= depth[b])
			a = fa[a][k];
	if (a == b) return a;
	for (int k = 16;k >= 0;k--)
		if (fa[a][k] != fa[b][k])
			a = fa[a][k], b = fa[b][k];
	return fa[a][0];
}
int dfs(int u, int father)
{
	int res = d[u];
	for (int i = h[u];~i;i = ne[i])
	{
		int j = e[i];
		if (j != father)
		{
			int s = dfs(j, u);
			if (s == 0) ans += m;
			else if (s == 1) ans++;
			res += s;
		}
	}
	return res;
}
int main()
{
	cin >> n >> m;
	memset(h, -1, sizeof h);
	for (int i = 0;i < n - 1;i++)
	{
		int a, b;
		cin >> a >> b;
		add(a, b), add(b, a);
	}
	bfs();
	for (int i = 0;i < m;i++)
	{
		int a, b;
		cin >> a >> b;
		int p = lca(a, b);
		d[a]++, d[b]++, d[p] -= 2;
	}
	dfs(1, -1);
	cout << ans << endl;
}
#define  _CRT_SECURE_NO_WARNINGS 1
//求最短路
//Dijkstra--朴素--O(n^2)
/*
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 510;
int g[N][N];//为稠密阵所以用邻接矩阵存储
int dist[N];//记录每一个点到第一个点的距离
bool st[N];//用于记录该点的最短距离是否已经确定
int n, m;
int Dijkstra()
{
	memset(dist, 0x3f, sizeof dist);//距离初始化
	dist[1] = 0;//第一个点到自己为0
	for (int i = 0;i < n;i++)//n个点，进行n次迭代
	{
		int t = -1;//t储存当前访问的点
		for (int j = 1;j <= n;j++)
			if (!st[j] && (t == -1 || dist[t] > dist[j])) // 该步骤即寻找还未确定最短路的点中路径最短的点
				t = j;
		st[t] = true;
		for (int j = 1;j <= n;j++)//更新距离,每一个都更新一遍
			dist[j] = min(dist[j], dist[t] + g[t][j]);
	}
	if (dist[n] == 0x3f3f3f3f) return -1;
	return dist[n];
}
int main()
{
	cin >> n >> m;
	memset(g, 0x3f, sizeof g);
	while (m--)
	{
		int x, y, z;
		cin >> x >> y >> z;
		g[x][y] = min(g[x][y], z);//如果重边则保留最短边--x->y
	}
	cout << Dijkstra() << endl;
	return 0;
}*/






////Dijkstra--堆优化--O(m*logn)
/*
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
typedef pair<int, int>PII;
const int N = 150010;
int h[N], w[N], e[N], ne[N], idx;//w[N]存权重
int dist[N];//记录每一个点到第一个点的距离
bool st[N];//用于记录该点的最短距离是否已经确定
int n, m;
void add(int a, int b, int c)
{
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}
int Dijkstra()
{
	memset(dist, 0x3f, sizeof dist);//距离初始化
	dist[1] = 0;//第一个点到自己为0

	priority_queue <PII, vector<PII>, greater<PII>> heap;//小根堆
	heap.push({ 0,1 });//插入距离和节点编号
	while (heap.size())
	{
		PII k = heap.top();//取距离源点最近的点
		heap.pop();
		int ver = k.second, distance = k.first;//ver:节点编号，distance:源点距离ver 的距离
		if (st[ver]) continue;
		st[ver] = true;
		for (int i = h[ver];i != -1;i = ne[i])//更新ver所指向的节点距离
		{
			int j = e[i];// i只是个下标，e中在存的是i这个下标对应的点。
			if (dist[j] > distance + w[i])
			{
				dist[j] = distance + w[i];
				heap.push({ dist[j],j });//距离变小，则入堆
			}
		}
	}
	if (dist[n] == 0x3f3f3f3f) return -1;
	return dist[n];
}
int main()
{
	cin >> n >> m;
	memset(h,-1,sizeof h);
	while (m--)
	{
		int x, y, z;
		cin >> x >> y >> z;
		add(x, y, z);
	}
	cout << Dijkstra() << endl;
	return 0;
}
*/







//Bellman-Ford---O(nm)
//有边数限制的最短路
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//const int N = 510, M = 1e5 + 10;
//struct Edge
//{
//	int a, b, w;
//}edges[M];
//int n, m, k;
//int dist[N], backup[N];
//int bellman_ford()
//{
//	memset(dist, 0x3f, sizeof dist);
//	dist[1] = 0;
//	for (int i = 0;i < k;i++)//遍历k次
//	{
//		memcpy(backup, dist, sizeof dist);//复制dist到backup中
//		for (int j = 0;j < m;j++)
//		{
//			int a = edges[j].a, b = edges[j].b, w = edges[j].w;
//			dist[b] = min(dist[b], backup[a] + w);
//		}
//	}
//	if (dist[n] == 0x3f3f3f3f) return -1;
//	else return dist[n];
//}
//int main()
//{
//	cin >> n >> m >> k;
//	for (int i = 0;i < m;i++)
//	{
//		int a, b, w;
//		cin >> a >> b >> w;
//		edges[i] = { a,b,w };
//	}
//	bellman_ford();
//	if (dist[n] > 0x3f3f3f3f / 2) puts("impossible");
//	else cout << dist[n] << endl;
//	return 0;
//}




//spfa--一般O(m),特殊O(nm)
//最短路
/*
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
typedef pair<int, int>PII;
const int N = 150010;
int h[N], w[N], e[N], ne[N], idx;//w[N]存权重
int dist[N];//记录每一个点到第一个点的距离
bool st[N];//用于记录该点的最短距离是否已经确定
int n, m;
void add(int a, int b, int c)
{
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}
int spfa()
{
	memset(dist, 0x3f, sizeof dist);//距离初始化
	dist[1] = 0;//第一个点到自己为0
	queue<int>q;
	q.push(1);
	st[1] = true;
	while (q.size())
	{
		int t = q.front();
		q.pop();
		st[t] = false;
		for (int i = h[t];i != -1;i = ne[i])
		{
			int j = e[i];
			if (dist[j] > dist[t] + w[i])
			{
				dist[j] = dist[t] + w[i];
				if (!st[j])
				{
					q.push(j);
					st[j] = true;
				}
			}
		}
	}
	return dist[n];
}
int main()
{
	cin >> n >> m;
	memset(h,-1,sizeof h);
	while (m--)
	{
		int x, y, z;
		cin >> x >> y >> z;
		add(x, y, z);
	}
	int t = spfa();
	if (t == 0x3f3f3f3f) puts("impossible");
	else cout << t << endl;
	return 0;
}*/



//spfa--判断负环
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
typedef pair<int, int>PII;
const int N = 150010;
int h[N], w[N], e[N], ne[N], idx;//w[N]存权重
int dist[N];//记录每一个点到第一个点的距离
int cnt[N];//用来判断边数，是否存在负环
bool st[N];//用于记录该点的最短距离是否已经确定
int n, m;
void add(int a, int b, int c)
{
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}
bool spfa()
{
	queue<int>q;
	for (int i = 1;i <= n;i++)//加入所有点判断
	{
		st[i] = true;
		q.push(i);
	}
	while (q.size())
	{
		int t = q.front();
		q.pop();
		st[t] = false;
		for (int i = h[t];i != -1;i = ne[i])
		{
			int j = e[i];
			if (dist[j] > dist[t] + w[i])
			{
				dist[j] = dist[t] + w[i];
				cnt[j] = cnt[t] + 1;
				if (cnt[j] >= n) return true;
				if (!st[j])
				{
					q.push(j);
					st[j] = true;
				}
			}
		}
	}
	return false;
}
int main()
{
	cin >> n >> m;
	memset(h, -1, sizeof h);
	while (m--)
	{
		int x, y, z;
		cin >> x >> y >> z;
		add(x, y, z);
	}
	if (spfa()) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}






//Floyd O(n^3)
//最短路
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//const int N = 210, INF = 1e9;
//int n, m, Q;
//int d[N][N];
//void floyd()
//{
//	for (int k = 1;k <= n;k++)
//		for (int i = 1;i <= n;i++)
//			for (int j = 1;j <= n;j++)
//				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
//}
//int main()
//{
//	cin >> n >> m >> Q;
//	for(int i=1;i<=n;i++)
//		for (int j = 1;j <= n;j++)
//		{
//			if (i == j) d[i][j] = 0;
//			else d[i][j] = INF;
//		}
//	while (m--)
//	{
//		int a, b, c;
//		cin >> a >> b >> c;
//		d[a][b] = min(d[a][b], c);
//	}
//	floyd();
//	while (Q--)
//	{
//		int a, b;
//		cin >> a >> b;
//		int t = d[a][b];
//		if (t > INF / 2) cout << "impossible" << endl;
//		else cout << t << endl;
//	}
//	return 0;
//}






//Prim--O(n^2)
//求最小生成树
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//const int N = 510, INF = 0x3f3f3f3f;
//int n, m;
//int g[N][N];
//int dist[N];
//bool st[N];
//int prim()
//{
//	memset(dist, 0x3f, sizeof dist);
//	int res = 0;
//	for (int i = 0;i < n;i++)
//	{
//		int t = -1;
//		for (int j = 1;j <= n;j++)
//			if (!st[j] && (t == -1 || dist[t] > dist[j]))
//				t = j;
//		if (i && dist[t] == INF) return INF;
//		//不是第一个取出的节点，并且当前节点的距离为INF,则表示没有和集合中点相连的边。
//		if (i) res += dist[t];
//		//不是第一个取出的节点，是其他点与集合中的连接线（最小边）
//		st[t] = true;
//		for (int j = 1;j <= n;j++) dist[j] = min(dist[j], g[t][j]);
//	}
//	return res;
//}
//int main()
//{
//	cin >> n >> m;
//	memset(g, 0x3f, sizeof g);
//	while (m--)
//	{
//		int a, b, c;
//		cin >> a >> b >> c;
//		g[a][b] = g[b][a] = min(g[a][b], c);
//	}
//	int t = prim();
//	if (t == 0x3f3f3f3f) cout << "impossible" << endl;
//	else cout << t << endl;
//}
//



//Kruskal--O(mlogm)
//最小生成树
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//const int N = 1e5 + 10, M = 2e5 + 10, INF = 0x3f3f3f3f;
//int n, m;
//int p[N];
//struct Edge
//{
//	int a, b, w;
//	bool operator< (const Edge& W)const
//	{
//		return w < W.w;
//	}
//}edges[M];
//int find(int x)
//{
//	if (p[x] != x) p[x] = find(p[x]);
//	return p[x];
//}
//int kruskal()
//{
//	sort(edges, edges + m);
//	for (int i = 1;i <= n;i++) p[i] = i;
//	int res = 0, cnt = 0;
//	for (int i = 0;i < m;i++)
//	{
//		int a = edges[i].a, b = edges[i].b, w = edges[i].w;
//		a = find(a), b = find(b);
//		if (a != b)
//		{
//			p[a] = b;
//			res += w;
//			cnt++;
//		}
//	}
//	if (cnt < n - 1) return INF;
//	return res;
//}
//int main()
//{
//	cin >> n >> m;
//	for (int i = 0;i < m;i++)
//	{
//		int a, b, w;
//		cin >> a >> b >> w;
//		edges[i] = { a,b,w };
//	}
//	int t = kruskal();
//	if (t == INF) puts("impossible");
//	else cout << t << endl;
//	return 0;
//}







//染色法判定二分图--O(m+n)
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 1e5 + 10, M = 2e5 + 10;
int n, m;//点和边
int h[N], e[M], ne[M], idx;//邻接表存储图
int color[N];//保存各个点的颜色，0 未染色，1 是红色，2 是黑色
void add(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
bool dfs(int u, int c)
{
	color[u] = c;//u的点成 c 染色
	for (int i = h[u];i != -1;i = ne[i])//遍历和 u 相邻的点
	{
		int j = e[i];
		if (!color[j])//相邻的点没有颜色,则递归处理这个相邻点
		{
			if (!dfs(j, 3 - c)) return false;
		}
		else if (color[j] == c) return false;
	}
	return true;
}
int main()
{
	cin >> n >> m;
	memset(h, -1, sizeof h);
	while (m--)//读入边
	{
		int a, b;
		cin >> a >> b;
		add(a, b), add(b, a);
	}
	bool flag = true;
	for (int i = 1;i <= n;i++)
		if (!color[i])//如果没染色
			if (!dfs(i, 1))//染色该点，并递归处理和它相邻的点
			{
				flag = false;
				break;
			}
	if (flag) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}




//匈牙利算法--O(nm)
//二分图的最大匹配
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 510, M = 1e5 + 10;
int n1, n2, m;
int h[N], e[M], ne[M], idx;
int match[N];
bool st[N];
void add(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
bool find(int x)
{
	for (int i = h[x];i != -1;i = ne[i])
	{
		int j = e[i];
		if (!st[j])
		{
			st[j] = true;
			if (match[j] == 0 || find(match[j]))
			{
				match[j] = x;
				return true;
			}
		}
	}
	return false;
}
int main()
{
	cin >> n1 >> n2 >> m;
	memset(h, -1, sizeof h);
	while (m--)
	{
		int a, b;
		cin >> a >> b;
		add(a, b);
	}
	int res = 0;
	for (int i = 1;i <= n1;i++)
	{
		memset(st, false, sizeof st);
		if (find(i)) res++;
	}
	cout << res << endl;
	return 0;
}
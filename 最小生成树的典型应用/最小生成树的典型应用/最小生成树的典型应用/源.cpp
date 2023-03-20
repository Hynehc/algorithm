#define  _CRT_SECURE_NO_WARNINGS 1
//最短网络
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//const int N = 110;
//int n;
//int w[N][N];
//int dist[N];
//bool st[N];
//int prim()
//{
//	int res = 0;
//	memset(dist, 0x3f, sizeof dist);
//	dist[1] = 0;
//	for (int i = 0;i < n;i++)
//	{
//		int t = -1;
//		for (int j = 1;j <= n;j++)
//			if (!st[j] && (t == -1 || dist[t] > dist[j]))
//				t = j;
//		res += dist[t];
//		st[t] = true;
//		for (int j = 1;j <= n;j++) dist[j] = min(dist[j], w[t][j]);
//	}
//	return res;
//}
//int main()
//{
//	cin >> n;
//	for (int i = 1;i <= n;i++)
//		for (int j = 1;j <= n;j++)
//			cin >> w[i][j];
//	cout << prim() << endl;
//
//}




// 局域网
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//const int N = 110, M = 210;
//int n, m;
//struct Edge
//{
//	int a, b, w;
//	bool operator< (const Edge& t)const
//	{
//		return w < t.w;
//	}
//}e[M];
//int p[N];
//int find(int x)
//{
//	if (x != p[x]) p[x] = find(p[x]);
//	return p[x];
//}
//int main()
//{
//	cin >> n >> m;
//	for (int i = 1;i <= n;i++) p[i] = i;
//	for (int i = 0;i < m;i++)
//	{
//		int a, b, w;
//		cin >> a >> b >> w;
//		e[i] = { a,b,w };
//	}
//	sort(e, e + m);
//	int res = 0;
//	for (int i = 0;i < m;i++)
//	{
//		int a = find(e[i].a), b = find(e[i].b), w = e[i].w;
//		if (a != b) p[a] = b;
//		else res += w;
//	}
//	cout << res << endl;
//}





//繁忙的都市
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//int n, m;
//const int N = 310, M = 10010;
//struct Edge
//{
//	int a, b, w;
//	bool operator< (const Edge& t)const
//	{
//		return w < t.w;
//	}
//}e[M];
//int p[N];
//int find(int x)
//{
//	if (p[x] != x) p[x] = find(p[x]);
//	return p[x];
//}
//int main()
//{
//	cin >> n >> m;
//	for (int i = 1;i <= n;i++) p[i] = i;
//	for (int i = 0;i < m;i++)
//	{
//		int a, b, w;
//		cin >> a >> b >> w;
//		e[i] = { a,b,w };
//	}
//	sort(e, e + m);
//	int res = 0;
//	for (int i = 0;i < m;i++)
//	{
//		int a = find(e[i].a), b = find(e[i].b), w = e[i].w;
//		if (a != b)
//		{
//			p[a] = b;
//			res = w;
//		}
//	}
//	cout << n - 1 << " " << res << endl;
//}





//联络员
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//const int N = 2010, M = 10010;
//int n, m;
//struct Edge
//{
//	int a, b, w;
//	bool operator<(const Edge& t)const
//	{
//		return w < t.w;
//	}
//}e[M];
//int p[N];
//int find(int x)
//{
//	if (p[x] != x) p[x] = find(p[x]);
//	return p[x];
//}
//int main()
//{
//	cin >> n >> m;
//	for (int i = 1;i <= n;i++) p[i] = i;
//	int res = 0, k = 0;
//	for (int i = 0;i < m;i++)
//	{
//		int t, a, b, w;
//		cin >> t >> a >> b >> w;
//		if (t == 1)
//		{
//			res += w;
//			p[find(a)] = find(b);
//		}
//		else e[k++] = { a,b,w };
//	}
//	sort(e, e + k);
//	for (int i = 0;i < k;i++)
//	{
//		int a = find(e[i].a), b = find(e[i].b), w = e[i].w;
//		if (a != b)
//		{
//			p[a] = b;
//			res += w;
//		}
//	}
//	cout << res << endl;
//}




//连接格点
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 1010, M = N * N, K = 2 * N * N;
int n, m, k;
int ids[N][N];
struct Edge
{
	int a, b, w;
}e[K];
int p[M];
int find(int x)
{
	if (p[x] != x) p[x] = find(p[x]);
	return p[x];
}
void get_edges()
{
	int dx[4] = { -1,0,1,0 }, dy[4] = { 0, 1, 0, -1 }, dw[4] = { 1,2,1,2 };
	for(int z=0;z<2;z++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				for(int u=0;u<4;u++)
					if (u % 2 == z)
					{
						int x = i + dx[u], y = j + dy[u], w = dw[u];
						if (x && x <= n && y && y <= m)
						{
							int a = ids[i][j], b = ids[x][y];
							if (a < b) e[k++] = { a,b,w };
						}
					}
}
int main()
{
	cin >> n >> m;
	for (int i = 1, t = 1;i <= n;i++)
		for (int j = 1;j <= m;j++, t++)
			ids[i][j] = t;
	for (int i = 1;i <= n * m;i++) p[i] = i;
	int x1, y1, x2, y2;
	while (cin >> x1 >> y1 >> x2 >> y2)
	{
		int a = ids[x1][y1], b = ids[x2][y2];
		p[find(a)] = find(b);
	}
	get_edges();
	int res = 0;
	for (int i = 0;i < k;i++)
	{
		int a = find(e[i].a), b = find(e[i].b), w = e[i].w;
		if (a != b)
		{
			p[a] = b;
			res += w;
		}
	}
	cout << res << endl;
}
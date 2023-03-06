#define  _CRT_SECURE_NO_WARNINGS 1
// 牛的旅行
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<math.h>
//using namespace std;
//#define x first
//#define y second
//typedef pair<double, double> PDD;
//const int N = 155;
//const double INF = 1e20;
//int n;
//PDD q[N];
//char g[N][N];
//double d[N][N], maxd[N];
//double get_dist(PDD a, PDD b)
//{
//	double dx = a.x - b.x, dy = a.y - b.y;
//	return sqrt(dx * dx + dy * dy);
//}
//int main()
//{
//	cin >> n;
//	for (int i = 0;i < n;i++) cin >> q[i].x >> q[i].y;
//	for (int i = 0;i < n;i++) cin >> g[i];
//	for (int i = 0;i < n;i++) 
//		for (int j = 0;j < n;j++)
//			if (i != j)
//			{
//				if (g[i][j] == '1') d[i][j] = get_dist(q[i], q[j]);
//				else d[i][j] = INF;
//			}
//	for (int k = 0;k < n;k++)
//		for (int i = 0;i < n;i++)
//			for (int j = 0;j < n;j++)
//				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
//	for (int i = 0;i < n;i++)
//		for (int j = 0;j < n;j++)
//			if (d[i][j] < INF)
//				maxd[i] = max(maxd[i], d[i][j]);
//	double r1 = 0;
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//			if (d[i][j] < INF / 2)
//				maxd[i] = max(maxd[i], d[i][j]);
//		r1 = max(r1, maxd[i]);
//	}
//
//	double r2 = INF;
//	for (int i = 0; i < n; i++)
//		for (int j = 0; j < n; j++)
//			if (d[i][j] > INF / 2)
//				r2 = min(r2, maxd[i] + maxd[j] + get_dist(q[i], q[j]));
//
//	printf("%.6lf\n", max(r1, r2));
//
//
//}





//排序
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//const int N = 26;
//int n, m;
//int g[N][N], d[N][N];
//bool st[N];
//void floyd()
//{
//	memcpy(d, g, sizeof d);
//	for (int k = 0;k < n;k++)
//		for (int i = 0;i < n;i++)
//			for (int j = 0;j < n;j++)
//				d[i][j] |= d[i][k] && d[k][j];
//}
//int check()
//{
//	for (int i = 0;i < n;i++)
//		if (d[i][i])
//			return 2;
//	for (int i = 0;i < n;i++)
//		for (int j = 0;j < i;j++)
//			if (!d[i][j] && !d[j][i])
//				return 0;
//	return 1;
//}
//char get_min()
//{
//	for(int i=0;i<n;i++)
//		if (!st[i])
//		{
//			bool f = true;
//			for(int j=0;j<n;j++)
//				if (!st[j] && d[j][i])
//				{
//					f = false;
//					break;
//				}
//			if (f)
//			{
//				st[i] = true;
//				return 'A' + i;
//			}
//		}
//}
//int main()
//{
//	while (cin >> n >> m, n || m)
//	{
//		memset(g, 0, sizeof g);
//		int type = 0, t;
//		for (int i = 1;i <= m;i++)
//		{
//			char str[5];
//			cin >> str;
//			int a = str[0] - 'A', b = str[2] - 'A';
//			if (!type)
//			{
//				g[a][b] = 1;
//				floyd();
//				type = check();
//				if (type) t = i;
//			}
//		}
//		if(!type) puts("Sorted sequence cannot be determined.");
//		else if (type == 2) printf("Inconsistency found after %d relations.\n", t);
//		else
//		{
//			memset(st, 0, sizeof st);
//			printf("Sorted sequence determined after %d relations: ", t);
//			for (int i = 0; i < n; i++) printf("%c", get_min());
//			printf(".\n");
//		}
//	}
//}





//观光之旅
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//const int N = 110, INF = 0x3f3f3f3f;
//int n, m;
//int d[N][N], g[N][N];
//int pos[N][N]; // pos存的是中间点k
//int path[N], cnt; // path 当前最小环的方案, cnt环里面的点的数量
//void get_path(int i, int j)// 递归处理环上节点
//{
//	if (pos[i][j] == 0) return;// i到j的最短路没有经过其他节点
//	int k = pos[i][j];// 否则,i ~ k ~ j的话,递归处理 i ~ k的部分和k ~ j的部分
//	get_path(i, k);
//	path[cnt++] = k;// k点放进去
//	get_path(k, j);
//}
//int main()
//{
//	cin >> n >> m;
//	memset(g, 0x3f, sizeof g);
//	for (int i = 1;i <= n;i++) g[i][i] = 0;
//	while (m--)
//	{
//		int a, b, c;
//		cin >> a >> b >> c;
//		g[a][b] = g[b][a] = min(g[a][b], c);
//	}
//	int res = INF;
//	memcpy(d, g, sizeof d);
//	for (int k = 1;k <= n;k++)// dp思路, 假设k是环上的最大点, i ~ k ~ j(Floyd的思想)
//	{
//		for(int i=1;i<k;i++)
//			for(int j=i+1;j<k;j++)
//				if ((long long)d[i][j] + g[j][k] + g[k][i] < res)
//				{
//					res = d[i][j] + g[j][k] + g[k][i];
//					cnt = 0;
//					path[cnt++] = k;// 先把k放进去
//					path[cnt++] = i;// 从k走到i(k固定的)
//					get_path(i, j);// 递归求i到j的路径
//					path[cnt++] = j;// j到k, k固定
//				}
//		// Floyd, 更新一下所有ij经过k的最短路径
//		for(int i=1;i<=n;i++)
//			for(int j=1;j<=n;j++)
//				if (d[i][j] > d[i][k] + d[k][j])
//				{
//					d[i][j] = d[i][k] + d[k][j];
//					pos[i][j] = k;
//				}
//	}
//	if(res==INF) puts("No solution.");
//	else
//	{
//		for (int i = 0;i < cnt;i++) cout << path[i] << endl;
//		cout << endl;
//	}
//}







//牛站
#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
const int N = 210;
int k, n, m, s, e;
int g[N][N];
int res[N][N];
void mul(int c[][N], int a[][N], int b[][N])
{
	static int temp[N][N];
	memset(temp, 0x3f, sizeof temp);
	for (int k = 1;k <= n;k++)
		for (int i = 1;i <= n;i++)
			for (int j = 1;j <= n;j++)
				temp[i][j] = min(temp[i][j], a[i][k] + b[k][j]);
	memcpy(c, temp, sizeof temp);
}
void qmi()
{
	memset(res, 0x3f, sizeof res);
	for (int i = 0;i <= n;i++) res[i][i] = 0;
	while (k)
	{
		if (k & 1) mul(res, res, g);
		mul(g, g, g);
		k >>= 1;
	}
}
int main()
{
	cin >> k >> m >> s >> e;
	memset(g, 0x3f, sizeof g);
	map<int, int>ids;
	if (!ids.count(s)) ids[s] = ++n;
	if (!ids.count(e)) ids[e] = ++n;
	s = ids[s], e = ids[e];
	while (m--)
	{
		int a, b, c;
		cin >> c >> a >> b;
		if (!ids.count(a)) ids[a] = ++n;
		if (!ids.count(b)) ids[b] = ++n;
		a = ids[a], b = ids[b];
		g[a][b] = g[b][a] = min(g[a][b], c);
	}
	qmi();
	cout << res[s][e] << endl;
}
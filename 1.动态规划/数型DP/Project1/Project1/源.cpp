#define  _CRT_SECURE_NO_WARNINGS 1
//树的最长路径
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//const int N = 10010, M = N * 2;
//int n;
//int h[N], e[M], ne[M], w[M], idx;
//int ans;
//void add(int a, int b, int c)
//{
//	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
//}
//int dfs(int u, int father)//father表示u的父节点,因为该图为无向图,并且迭代过程中不能回到父节点,所以要特殊标记.
//{
//	int dist = 0;//表示当前节点往下走的最大长度
//	int d1 = 0, d2 = 0;
//	for (int i = h[u];i != -1;i = ne[i])
//	{
//		int j = e[i];
//		if (j == father) continue;
//		int d = dfs(j, u) + w[i];//求出路径的长度
//		dist = max(dist, d);
//		if (d > d1) d2 = d1, d1 = d;
//		else if (d > d2) d2 = d;
//	}
//	ans = max(ans, d1 + d2);
//	return dist;
//}
//int main()
//{
//	cin >> n;
//	memset(h, -1, sizeof h);
//	for (int i = 0;i < n - 1;i++)
//	{
//		int a, b, c;
//		cin >> a >> b >> c;
//		add(a, b, c), add(b, a, c);
//	}
//	dfs(1, -1);
//	cout << ans << endl;
//	return 0;
//}




//树的中心
//#include<iostream>
//#include<algorithm>
//#include<cstring>
//using namespace std;
//const int n = 10010, m = n * 2, inf = 0x3f3f3f3f;
//int n;
//int h[n], e[m], ne[m], w[m], idx;
//int d1[n], d2[n], p1[n], up[n];
//bool is_leaf[n];
//void add(int a, int b, int c)
//{
//	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
//}
//int dfs_d(int u, int father)//返回u的最长向下路径
//{
//	d1[u] = d2[u] = -inf;
//	for (int i = h[u];i != -1;i = ne[i])
//	{
//		int j = e[i];
//		if (j == father) continue;
//		int d = dfs_d(j, u) + w[i];//u节点从j节点向下走的最大距离
//		if (d >= d1[u])//更新一下最长和第二长的路径，并记录下从该路径是从哪一个点下去的
//		{
//			d2[u] = d1[u], d1[u] = d;
//			p1[u] = j;//表示u向下经过j点时有最大距离
//		}
//		else if (d > d2[u]) d2[u] = d;
//	}
//	if (d1[u] == -inf)//如果没有改变过该点的距离，就证明这个点是叶节点
//	{
//		d1[u] = d2[u] = 0;
//		is_leaf[u] = true;
//	}
//	return d1[u];
//}
//void dfs_u(int u, int father)//用父节点更新一下子节点向上的最长路径
//{
//	for (int i = h[u];i != -1;i = ne[i])
//	{
//		int j = e[i];
//		if (j == father) continue;
//		if (p1[u] == j) up[j] = max(up[u], d2[u]) + w[i];
//		//如果从父节点向下的最长路径进过了要更新的子节点，那么就用第二长的路径更新
//		else up[j] = max(up[u], d1[u] + w[i]);
//		dfs_u(j, u);//用j更新j的子节点的最长向上距离
//	}
//}
//int main()
//{
//	cin >> n;
//	memset(h, -1, sizeof h);
//	for (int i = 0;i < n - 1;i++)
//	{
//		int a, b, c;
//		cin >> a >> b >> c;
//		add(a, b, c), add(b, a, c);
//	}
//	dfs_d(1, - 1), dfs_u(1, -1);
//	int res = d1[1];
//	for (int i = 2;i <= n;i++)
//	{
//		if (is_leaf[i]) res = min(res, up[i]);
//		else res = min(res, max(d1[i], up[i]));
//	}
//	cout << res << endl;
//	return 0;
//}




//数字转换
//#include<iostream>
//#include<algorithm>
//#include<cstring>
//using namespace std;
//const int N = 50010;
//int n;
//int h[N], e[N], ne[N], idx;
//int sum[N];
//bool st[N];
//int ans;
//void add(int a, int b)
//{
//	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
//}
//int dfs(int u)
//{
//	int d1 = 0, d2 = 0;
//	for (int i = h[u]; i != -1;i = ne[i])
//	{
//		int j = e[i];
//		int d = dfs(j) + 1;
//		if (d > d1) d2 = d1, d1 = d;
//		else if (d > d2) d2 = d;
//	}
//	ans = max(ans, d1 + d2);
//	return d1;
//}
//int main()
//{
//	cin >> n;
//	for (int i = 1;i <= n;i++)
//		for (int j = 2;j <= n / i;j++)
//			sum[i * j] += i;
//	memset(h, -1, sizeof h);
//	for(int i = 2;i <= n;i++)
//		if (i > sum[i])
//		{
//			add(sum[i], i);
//			st[i] = true;
//		}
//	for (int i = 1;i <= n;i++)
//		if (!st[i])
//			dfs(i);
//	cout << ans << endl;
//	return 0;
//}





//二叉苹果树
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//const int N = 110, M = N * 2;
//int n, m;
//int h[N], e[M], ne[M], w[M], idx;
//int f[N][N];
//void add(int a, int b, int c)
//{
//	e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
//}
//void dfs(int u, int father)
//{
//	for (int i = h[u];~i;i = ne[i])
//	{
//		if (e[i] == father) continue;
//		dfs(e[i], u);
//		for (int j = m;j >= 0;j--)
//			for (int k = 0;k < j;k++)
//				f[u][j] = max(f[u][j], f[u][j - k - 1] + f[e[i]][k] + w[i]);
//	}
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
//	dfs(1, -1);
//	cout << f[1][m] << endl;
//}




//战略游戏
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//const int N = 1510;
//int n;
//int h[N], e[N], ne[N], idx;
//int f[N][2];
//bool st[N];
//void add(int a, int b)
//{
//	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
//}
//void dfs(int u)
//{
//	f[u][0] = 0, f[u][1] = 1;
//	for (int i = h[u];~i;i = ne[i])
//	{
//		int j = e[i];
//		dfs(j);
//		f[u][0] += f[j][1];
//		f[u][1] += min(f[j][1], f[j][0]);
//	}
//}
//int main()
//{
//	while (cin >> n)
//	{
//		memset(h, -1, sizeof h);
//		idx = 0;
//		memset(st, 0, sizeof st);
//		for (int i = 0;i < n;i++)
//		{
//			int id, cnt;
//			scanf("%d:(%d)", &id, &cnt);
//			while (cnt--)
//			{
//				int ver;
//				cin >> ver;
//				add(id, ver);
//				st[ver] = true;
//			}
//		}
//		int root = 0;
//		while (st[root]) root++;
//		dfs(root);
//		cout << min(f[root][1], f[root][0]) << endl;
//	}
//	return 0;
//}





//皇宫看守
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 1510;
int n;
int h[N], e[N], w[N], ne[N], idx;
int f[N][3];
bool st[N];
void add(int a, int b)
{
	e[idx] = b, ne[idx] = h[a],h[a] = idx++;
}
void dfs(int u)
{
	f[u][2] = w[u];
	int sum = 0;
	for (int i = h[u];~i;i = ne[i])
	{
		int j = e[i];
		dfs(j);
		f[u][0] += min(f[j][1], f[j][2]);
		f[u][2] += min(min(f[j][0], f[j][1]), f[j][2]);
		sum += min(f[j][1], f[j][2]);
	}
	f[u][1] = 1e9;
	for (int i = h[u];~i;i = ne[i])
	{
		int j = e[i];
		f[u][1] = min(f[u][1], sum - min(f[j][1], f[j][2]) + f[j][2]);
	}
}
int main()
{
	cin >> n;
	memset(h, -1, sizeof h);
	for (int i = 1;i <= n;i++)
	{
		int id, cost, cnt;
		cin >> id >> cost >> cnt;
		w[id] = cost;
		while (cnt--)
		{
			int ver;
			cin >> ver;
			add(id, ver);
			st[ver] = true;
		}
	}
	int root = 1;
	while (st[root]) root++;
	dfs(root);
	cout << min(f[root][1], f[root][2]) << endl;
	return 0;
}
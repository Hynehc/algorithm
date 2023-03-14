//关押罪犯
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//const int N = 20010, M = 200010;
//int n, m;
//int h[N], e[M], ne[M], w[M], idx;
//int color[N];
//void add(int a, int b, int c)
//{
//	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
//}
//bool dfs(int u, int c, int mid)
//{
//	color[u] = c;
//	for (int i = h[u];~i;i = ne[i])
//	{
//		int j = e[i];
//		if (w[i] <= mid) continue;
//		if (color[j])
//		{
//			if (color[j] == c) return false;
//		}
//		else if (!dfs(j, 3 - c, mid)) return false;
//	}
//	return true;
//}
//bool check(int mid)
//{
//	memset(color, 0, sizeof color);
//	for (int i = 1;i <= n;i++)
//		if (color[i] == 0)
//			if (!dfs(i, 1, mid)) return false;
//	return true;
//}
//int main()
//{
//	cin >> n >> m;
//	memset(h, -1, sizeof h);
//	while (m--)
//	{
//		int a, b, c;
//		cin >> a >> b >> c;
//		add(a, b, c), add(b, a, c);
//	}
//	int l = 0, r = 1e9;
//	while (l < r)
//	{
//		int mid = l + r >> 1;
//		if (check(mid)) r = mid;
//		else l = mid + 1;
//	}
//	cout << r << endl;
//}





// 棋盘覆盖
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//#define x first
//#define y second
//typedef pair<int, int>PII;
//const int N = 110;
//int n, m;
//PII match[N][N];
//bool g[N][N], st[N][N];
//int dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 };
//bool find(int x, int y)
//{
//	for (int i = 0;i < 4;i++)
//	{
//		int a = x + dx[i], b = y + dy[i];
//		if (a<1 || a>n || b<1 || b>n) continue;
//		if (st[a][b] || g[a][b]) continue;
//		st[a][b] = true;
//		PII t = match[a][b];
//		//1 t.x==-1说明女[a,b]还没和其他人配对 则男[x,y]和女[a,b]可以直接配对
//		//2 女[a,b]已经有人配对,但和女[a,b]配对的男t还有其他选项
//		//  男t放弃和女[a,b]配对 让女[a,b]给男[x,y]配对
//		if (t.x == 0 || find(t.x, t.y))
//		{
//			match[a][b] = { x,y };
//			return true;
//		}
//	}
//	return false;
//}
//int main()
//{
//	cin >> n >> m;
//	while (m--)
//	{
//		int x, y;
//		cin >> x >> y;
//		g[x][y] = true;
//	}
//	int res = 0;
//	for(int i=1;i<=n;i++)
//		for(int j=1;j<=n;j++)
//			if ((i + j) % 2 && !g[i][j])
//			{
//				memset(st, 0, sizeof st);//每次都需要清空st数组，因为匹配好的一对可能会有下家
//				if (find(i, j)) res++;//如果[i,j]能配对
//			}
//	cout << res << endl;
//}





// 机器任务
//#include<iostream>
//#include<algorithm>
//#include<cstring>
//using namespace std;
//const int N = 110;
//int n, m, k;
//bool g[N][N], st[N];
//int match[N];
//bool find(int x)
//{
//	for(int i=1;i<m;i++)
//		if (!st[i] && g[x][i])
//		{
//			st[i] = true;
//			int t = match[i];
//			if (t == 0 || find(t))
//			{
//				match[i] = x;
//				return true;
//			}
//		}
//	return false;
//}
//int main()
//{
//	while (cin >> n, n)
//	{
//		cin >> m >> k;
//		memset(g, 0, sizeof g);
//		memset(match, 0, sizeof match);
//		while (k--)
//		{
//			int t, a, b;
//			cin >> t >> a >> b;
//			if (!a || !b) continue;
//			g[a][b] = true;
//		}
//		int res = 0;
//		for (int i = 1;i < n;i++)
//		{
//			memset(st, 0, sizeof st);
//			if (find(i)) res++;
//		}
//		cout << res << endl;
//	}
//}
//




// 骑士放置
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#define x first
//#define y second
//using namespace std;
//typedef long long ll;
//typedef pair<int, int>PII;
//const int N = 110;
//int n, m, k;
//PII match[N][N];
//bool g[N][N], st[N][N];
//int dx[8] = { -2,-1,1,2,2,1,-1,-2 };
//int dy[8] = { 1,2,2,1,-1,-2,-2,-1 };
//bool find(int x, int y)
//{
//	for (int i = 0;i < 8;i++)
//	{
//		int a = x + dx[i], b = y + dy[i];
//		if (a<1 || a>n || b<1 || b>m) continue;
//		if (g[a][b] || st[a][b]) continue;
//		st[a][b] = true;
//		PII t = match[a][b];
//		if (t.x == 0 || find(t.x, t.y))
//		{
//			match[a][b] = { x,y };
//			return true;
//		}
//	}
//	return false;
//}
//int main()
//{
//	cin >> n >> m >> k;
//	for (int i = 0;i < k;i++)
//	{
//		int x, y;
//		cin >> x >> y;
//		g[x][y] = true;
//	}
//	int res = 0;
//	for(int i=1;i<=n;i++)
//		for (int j = 1;j <= m;j++)
//		{
//			if ((i + j) % 2 || g[i][j]) continue;
//			memset(st, 0, sizeof st);
//			if (find(i, j)) res++;
//		}
//	cout << n * m - k - res << endl;
//}
//
//
//



//捉迷藏
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 210, M = 30010;
int n, m;
bool d[N][N], st[N];
int match[N];
bool find(int x)
{
	for (int i = 1;i <= n;i++)
	{
		if (d[x][i] && !st[i])
		{
			st[i] = true;
			int t = match[i];
			if (t == 0 || find(t))
			{
				match[i] = x;
				return true;
			}
		}
	}
	return false;
}
int main()
{
	cin >> n >> m;
	while (m--)
	{
		int a, b;
		cin >> a >> b;
		d[a][b] = true;
	}
	for (int k = 1;k <= n;k++)
		for (int i = 1;i <= n;i++)
			for (int j = 1;j <= n;j++)
				d[i][j] |= d[i][k] & d[k][j];
	int res = 0;
	for (int i = 1;i <= n;i++)
	{
		memset(st, 0, sizeof st);
		if (find(i)) res++;
	}
	cout << n - res << endl;
}
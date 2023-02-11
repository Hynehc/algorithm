#define  _CRT_SECURE_NO_WARNINGS 1
//多重背包问题 III
//#include<iostream>
//#include<algorithm>
//#include<cstring>
//using namespace std;
//const int N = 20010;
//int n, m;
//int f[N], g[N], q[N];
//int main()
//{
//	cin >> n >> m;
//	for (int i = 0;i < n;i++)
//	{
//		int v, w, s;
//		cin >> v >> w >> s;
//		memcpy(g, f, sizeof f);
//		for (int j = 0;j < v;j++)
//		{
//			int hh = 0, tt = -1;
//			for (int k = j;k <= m;k += v)
//			{
//				if (hh <= tt && q[hh] < k - s * v) hh++;
//				if (hh <= tt) f[k] = max(f[k], g[q[hh]] + (k - q[hh])/v * w);
//				while (hh <= tt && g[q[tt]] - (q[tt] - j) / v * w <= g[k] - (k - j) / v * w) tt--;
//				q[++tt] = k;
// 			}
//		}
//	}
//	cout << f[m] << endl;
//	return 0;
//}







//采药
//#include<iostream>
//#include<algorithm>
//using namespace std;
//const int N = 1010;
//int m, n;
//int f[N];
//int main()
//{
//	cin >> m >> n;
//	for (int i = 0;i < n;i++)
//	{
//		int v, w;
//		cin >> v >> w;
//		for (int j = m;j >= v;j--) f[j] = max(f[j], f[j - v] + w);
//	}
//	cout << f[m] << endl;
//}




//装箱问题
//#include<iostream>
//#include<algorithm>
//using namespace std;
//const int N = 20010;
//int m, n;
//int f[N];
//int main()
//{
//	cin >> m >> n;
//	for (int i = 0;i < n;i++)
//	{
//		int v;
//		cin >> v;
//		for (int j = m;j >= v;j--) f[j] = max(f[j], f[j - v] + v);
//	}
//	cout << m - f[m] << endl;
//	return 0;
//}






//宠物小精灵之收服
//#include<iostream>
//#include<algorithm>
//using namespace std;
//const int N = 1010, M = 510;
//int n, V1, V2;
//int f[N][M];
////V1:精灵球的数量  V2：皮卡丘的体力  n: 皮卡丘的数量
//int main()
//{
//	cin >> V1 >> V2 >> n;
//	for (int i = 0;i < n;i++)
//	{
//		int v1, v2;
//		cin >> v1 >> v2;
//		for (int j = V1;j >= v1;j--)
//			for (int k = V2 - 1;k >= v2;k--)//皮卡丘的体力不能为零
//				f[j][k] = max(f[j][k], f[j - v1][k - v2] + 1);
//	}
//	cout << f[V1][V2 - 1] << " ";
//	int k = V2;
//	while (k > 0 && f[V1][k - 1] == f[V1][V2 - 1]) k--;
//	cout << V2 - k << endl;
//	return 0;
//}



//二维费用的背包问题
//#include<iostream>
//#include<algorithm>
//using namespace std;
//const int N = 110;
//int n, V, M;
//int f[N][N];
//int main()
//{
//	cin >> n >> V >> M;
//	for (int i = 0;i < n;i++)
//	{
//		int v, m, w;
//		cin >> v >> m >> w;
//		for (int j = V;j >= v;j--)
//			for (int k = M;k >= m;k--)
//				f[j][k] = max(f[j][k], f[j - v][k - m] + w);
//	}
//	cout << f[V][M] << endl;
//	return 0;
//}




//潜水员
//#include<iostream>
//#include<algorithm>
//#include<cstring>
//using namespace std;
//const int N = 22, M = 80;
//int n, m, k;
//int f[N][M];
//int main()
//{
//	cin >> n >> m >> k;
//	memset(f, 0x3f, sizeof f);
//	f[0][0] = 0;
//	while (k--)
//	{
//		int v1, v2, w;
//		cin >> v1 >> v2 >> w;
//		for (int i = n;i >= 0;i--)
//			for (int j = m;j >= 0;j--)
//				f[i][j] = min(f[i][j], f[max(0, i - v1)][max(0, j - v2)] + w);
//	}
//	cout << f[n][m] << endl;
//	return 0;
//}




//数字组合
//#include<iostream>
//#include<algorithm>
//using namespace std;
//const int N = 10010;
//int n, m;
//int f[N];
//int main()
//{
//	cin >> n >> m;
//	f[0] = 1;
//	for (int i = 0;i < n;i++)
//	{
//		int v;
//		cin >> v;
//		for (int j = m;j >= v;j--)
//			f[j] += f[j - v];
//	}
//	cout << f[m] << endl;
//	return 0;
//}




//庆功会
//#include<iostream>
//#include<algorithm>
//using namespace std;
//const int N = 6010;
//int n, m;
//int f[N];
//int main()
//{
//	cin >> n >>  m;
//	for (int i = 0;i < n;i++)
//	{
//		int v, w, s;
//		cin >> v >> w >> s;
//		for (int j = m;j >= 0;j--)
//			for (int k = 0;k <= s && k * v <= j;k++)
//				f[j] = max(f[j], f[j - k * v] + k * w);
//	}
//	cout << f[m] << endl;
//	return 0;
//}
//
//




//买书
//#include<iostream>
//using namespace std;
//const int N = 1010;
//int v[4] = { 10,20,50,100 };
//int f[N];
//int main()
//{
//	int m;
//	cin >> m;
//	f[0] = 1;
//	for (int i = 0;i < 4;i++)
//		for(int j=v[i];j<=m;j++)
//			f[j] += f[j - v[i]];
//	cout << f[m] << endl;
//	return 0;
//}



//背包问题求具体方案
//#include<iostream>
//using namespace std;
//const int N = 1010;
//int n, m;
//int v[N], w[N];
//int f[N][N];
//int main()
//{
//	cin >> n >> m;
//	for (int i = 1;i <= n;i++) cin >> v[i] >> w[i];
//	for(int i=n;i>=1;i--)
//		for (int j = 0;j <= m;j++)
//		{
//			f[i][j] = f[i + 1][j];
//			if (j >= v[i]) f[i][j] = max(f[i][j], f[i + 1][j - v[i]] + w[i]);
//		}
//	int j = m;
//	for(int i=1;i<=n;i++)
//		if (j >= v[i] && f[i][j] == f[i + 1][j - v[i]] + w[i])
//		{
//			cout << i << " ";
//			j -= v[i];
//		}
//	return 0;
//}








//机器分配
//#include<iostream>
//#include<algorithm>
//using namespace std;
//const int N = 11, M = 16;
//int n, m;
//int w[N][M], f[N][M];
//int way[N];
//int main()
//{
//	cin >> n >> m;
//	for (int i = 1;i <= n;i++)
//		for (int j = 1;j <= m;j++)
//			cin >> w[i][j];
//	for (int i = 1;i <= n;i++)
//		for (int j = 0;j <= m;j++)
//			for (int k = 0;k <= j;k++)
//				f[i][j] = max(f[i][j], f[i - 1][j - k] + w[i][k]);
//	cout << f[n][m] << endl;
//	int j = m;
//	for(int i=n;i;i--)
//		for(int k=0;k<=j;k++)
//			if (f[i][j] == f[i - 1][j - k] + w[i][k])
//			{
//				way[i] = k;
//				j -= k;
//				break;
//			}
//	for (int i = 1;i <= n;i++) cout << i << " " << way[i] << endl;
//	return 0;
//}



//金明的预算方案
//#include<iostream>
//#include<algorithm>
//#include<vector>
//#include<cstring>
//using namespace std;
//#define v first
//#define w second
//typedef pair<int, int>PII;
//const int N = 60, M = 32010;
//int n, m;
//PII master[N];
//vector<PII> servent[N];
//int f[M];
//int main()
//{
//	cin >> m >> n;
//	for (int i = 1;i <= n;i++)
//	{
//		int V, P, Q;
//		cin >> V >> P >> Q;
//		P *= V;
//		if (!Q) master[i] = { V,P };
//		else servent[Q].push_back({ V,P });
// 	}
//	for (int i = 1;i <= n;i++)
//		for (int u = m;u >= 0;u--)
//		{
//			for (int j = 0;j < 1 << servent[i].size();j++)
//			{
//				int v = master[i].v, w = master[i].w;
//				for (int k = 0;k < servent[i].size();k++)
//					if (j >> k & 1)
//					{
//						v += servent[i][k].v;
//						w += servent[i][k].w;
//					}
//				if (u >= v) f[u] = max(f[u], f[u - v] + w);
//			}
//		}
//	cout << f[m] << endl;
//	return 0;
//}




//开心的金明
//#include<iostream>
//#include<algorithm>
//using namespace std;
//const int N = 30010;
//int n, m;
//int f[N];
//int main()
//{
//	cin >> m >> n;
//	for (int i = 0;i < n;i++)
//	{
//		int v, w;
//		cin >> v >> w;
//		w *= v;
//		for (int j = m;j >= v;j--) f[j] = max(f[j], f[j - v] + w);
//	}
//	cout << f[m] << endl;
//	return 0;
//}
//






// 货币系统
//#include<iostream>
//#include<algorithm>
//using namespace std;
//typedef long long ll;
//const int N = 3010;
//int n, m;
//ll f[N];
//int main()
//{
//	cin >> n >> m;
//	f[0] = 1;
//	for (int i = 0;i < n;i++)
//	{
//		int a;
//		cin >> a;
//		for (int j = a;j <= m;j++) f[j] += f[j - a];
//	}
//	cout << f[m] << endl;
//	return 0;
//}




//货币系统
//#include<iostream>
//#include<algorithm>
//#include<cstring>
//using namespace std;
//const int N = 110, M = 25010l;
//int n;
//int a[N], f[M];
//int main()
//{
//	int T;
//	cin >> T;
//	while (T--)
//	{
//		cin >> n;
//		for (int i = 0;i < n;i++) cin >> a[i];
//		sort(a, a + n);
//		int m = a[n - 1];
//		memset(f, 0, sizeof f);
//		f[0] = 1;
//		int res = 0;
//		for (int i = 0;i < n;i++)
//		{
//			if (!f[a[i]]) res++;
//			for (int j = a[i];j <= m;j++)
//				f[j] += f[j - a[i]];
//		}
//		cout << res << endl;
//	}
//}






//混合背包问题
//#include<iostream>
//#include<algorithm>
//#include<cstring>
//using namespace std;
//const int N = 1010;
//int n, m;
//int f[N];
//int main()
//{
//	cin >> n >> m;
//	for (int i = 0;i < n;i++)
//	{
//		int v, w, s;
//		cin >> v >> w >> s;
//		if (s == 0)
//		{
//			for (int j = v;j <= m;j++) f[j] = max(f[j], f[j - v] + w);
//		}
//		else
//		{
//			if (s == -1) s = 1;
//			for (int k = 1;k <= s;k *= 2)
//			{
//				for (int j = m;j >= k * v;j--)
//					f[j] = max(f[j], f[j - k * v] + k * w);
//				s -= k;
//			}
//			if (s)
//			{
//				for (int j = m;j >= s * v;j--)
//					f[j] = max(f[j], f[j - s * v] + s * w);
//			}
//		}
//	}
//	cout << f[m] << endl;
//	return 0;
//}



//有依赖的背包问题
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//const int N = 110;
//int n, m;
//int h[N], e[N], ne[N], idx;
//int v[N], w[N], f[N][N];
//void add(int a, int b)
//{
//	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
//}
//void dfs(int u)
//{
//	for (int i = h[u];i != -1;i = ne[i])
//	{
//		int son = e[i];
//		dfs(son);
//		for (int j = m - v[u];j >= 0;j--)
//		{
//			for (int k = 0;k <= j;k++)
//				f[u][j] = max(f[u][j], f[u][j - k] + f[son][k]);
//		}
//	}
//	for (int i = m;i >= v[u];i--)
//		f[u][i] = f[u][i - v[u]] + w[u];
//	for (int i = 0;i < v[u];i++)
//		f[u][i] = 0;
//}
//int main()
//{
//	memset(h, -1, sizeof h);
//	cin >> n >> m;
//	int root;
//	for (int i = 1;i <= n;i++)
//	{
//		int p;
//		cin >> v[i] >> w[i] >> p;
//		if (p == -1) root = i;
//		else add(p, i);//如果不是根节点就加入邻接表,其中p是该节点的父节点，i是当前是第几个节点
//	}
//	dfs(root);
//	cout << f[root][m] << endl;
//}




//背包问题求方案数
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//const int N = 1010, mod = 1e9 + 7;
//int n, m;
//int f[N], g[N];
//int main()
//{
//	cin >> n >> m;
//	memset(f, -0x3f, sizeof f);
//	f[0] = 0, g[0] = 1;
//	for (int i = 0;i < n;i++)
//	{
//		int v, w;
//		cin >> v >> w;
//		for (int j = m;j >= v;j--)
//		{
//			int maxv = max(f[j], f[j - v] + w);
//			int cnt = 0;
//			if (maxv == f[j]) cnt += g[j];
//			if (maxv == f[j - v] + w) cnt += g[j - v];
//			g[j] = cnt % mod;
//			f[j] = maxv;
//		}
//	}
//	int res = 0;
//	for (int i = 0;i <= m;i++) res = max(res, f[i]);
//	int cnt = 0;
//	for (int i = 0;i <= m;i++)
//		if (res == f[i])
//			cnt = (cnt + g[i]) % mod;
//	cout << cnt << endl;
//	return 0;
//}



// 能量石
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 10010;
int n;
struct Stone
{
	int s, e, l;
	bool operator< (const Stone& W) const
	{
		return s * W.l < l* W.s;
	}
}stone[N];
int f[N];
int main()
{
	int T;
	cin >> T;
	for (int C = 1; C <= T;C++)
	{
		int m = 0;
		cin >> n;
		for (int i = 0;i < n;i++)
		{
			int s, e, l;
			cin >> s >> e >> l;
			stone[i] = { s,e,l };
			m += s;
		}
		sort(stone, stone + n);
		memset(f, -0x3f, sizeof f);
		f[0] = 0;
		for (int i = 0;i < n;i++)
		{
			int s = stone[i].s, e = stone[i].e, l = stone[i].l;
			for (int j = m;j >= s;j--)
				f[j] = max(f[j], f[j - s] + e - (j - s) * l);
		}
		int res = 0;
		for (int i = 0;i <= m;i++) res = max(res, f[i]);
		printf("Case #%d: %d\n", C, res);
	}
	return 0;
}
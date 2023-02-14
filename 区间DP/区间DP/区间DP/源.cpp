#define  _CRT_SECURE_NO_WARNINGS 1
//环形石子合并
//#include<iostream>
//#include<algorithm>
//#include<cstring>
//using namespace std;
//const int N = 410, INF = 0x3f3f3f3f;
//int n;
//int s[N], w[N];
//int f[N][N], g[N][N];
//int main()
//{
//	cin >> n;
//	for (int i = 1;i <= n;i++)
//	{
//		cin >> w[i];
//		w[i + n] = w[i];
//	}
//	for (int i = 1;i <= n * 2;i++) s[i] = s[i - 1] + w[i];
//	memset(f, 0x3f, sizeof f);
//	memset(g, -0x3f, sizeof g);
//	for (int len = 1;len <= n;len++)
//	{
//		for (int l = 1;l + len - 1 <= n * 2;l++)
//		{
//			int r = l + len - 1;
//			if (len == 1) f[l][r] = g[l][r] = 0;
//			for (int k = l; k < r;k++)
//			{
//				f[l][r] = min(f[l][r], f[l][k] + f[k + 1][r] + s[r] - s[l - 1]);
//				g[l][r] = max(g[l][r], g[l][k] + g[k + 1][r] + s[r] - s[l - 1]);
//			}
//		}
//	}
//	int minv = INF, maxv = -INF;
//	for (int i = 1;i <= n;i++)
//	{
//		minv = min(minv, f[i][i + n - 1]);
//		maxv = max(maxv, g[i][i + n - 1]);
//	}
//	cout << minv << endl << maxv << endl;
//	return 0;
//}




//能量项链
//#include<iostream>
//#include<algorithm>
//#include<cstring>
//using namespace std;
//const int N = 210;
//int n;
//int w[N];
//int f[N][N];
//int main()
//{
//	cin >> n;
//	for (int i = 1;i <= n;i++)
//	{
//		cin >> w[i];
//		w[i + n] = w[i];
//	}
//	for (int len = 3;len <= n + 1;len++)
//	{
//		for (int l = 1;l + len - 1 <= n * 2;l++)
//		{
//			int r = l + len - 1;
//			for (int k = l + 1;k < r;k++)
//			{
//				f[l][r] = max(f[l][r], f[l][k] + f[k][r] + w[l] * w[k] * w[r]);
//			}
//		}
//	}
//	int res = 0;
//	for (int i = 1;i <= n;i++)
//		res = max(res, f[i][i + n]);
//	cout << res << endl;
//	return 0;
//}






//凸多边形的划分
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//const int N = 55, M = 35, INF = 1e9;
//typedef long long ll;
//int n;
//int w[N];
//ll f[N][N][M];
//void add(ll a[], ll b [])
//{
//	static ll c[M];
//	memset(c, 0, sizeof c);
//	for (int i = 0, t = 0;i < M;i++)
//	{
//		t += a[i] + b[i];
//		c[i] = t % 10;
//		t /= 10;
//	}
//	memcpy(a, c, sizeof c);
//}
//void mul(ll a[], ll b)
//{
//	static ll c[M];
//	memset(c, 0, sizeof c);
//	ll t = 0;
//	for (int i = 0;i < M;i++)
//	{
//		t += a[i] * b;
//		c[i] = t % 10;
//		t /= 10;
//	}
//	memcpy(a, c, sizeof c);
//}
//int cmp(ll a[], ll b[])
//{
//	for (int i = M - 1;i >= 0;i--)
//		if (a[i] > b[i]) return 1;
//		else if (a[i] < b[i]) return -1;
//	return 0;
//}
//void print(ll a[])
//{
//	int k = M - 1;
//	while (k && !a[k]) k--;
//	while (k >= 0) cout << a[k--];
//	cout << endl;
//}
//int main()
//{
//	cin >> n;
//	for (int i = 1;i <= n;i++) cin >> w[i];
//	ll tmp[M];
//	for (int len = 3;len <= n;len++)
//	{
//		for (int l = 1;l + len - 1 <= n;l++)
//		{
//			int r = l + len - 1;
//			f[l][r][M - 1] = 1;
//			for (int k = l + 1;k < r;k++)
//			{
//				memset(tmp, 0, sizeof tmp);
//				tmp[0] = w[l];
//				mul(tmp, w[k]);
//				mul(tmp, w[r]);
//				add(tmp, f[l][k]);
//				add(tmp, f[k][r]);
//				if (cmp(f[l][r], tmp) > 0)
//					memcpy(f[l][r], tmp, sizeof tmp);
//			}
//		}
//	}
//	print(f[1][n]);
//	return 0;
//}




//加分二叉树
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//const int N = 30;
//int n;
//int w[N];
//int f[N][N], g[N][N];
//void dfs(int l, int r)
//{
//	if (l > r) return;
//	int root = g[l][r];
//	cout << root << " ";
//	dfs(l, root - 1), dfs(root + 1, r);
//}
//int main()
//{
//	cin >> n;
//	for (int i = 1;i <= n;i++) cin >> w[i];
//	for(int len = 1;len <= n;len++)
//		for (int l = 1;l + len - 1 <= n;l++)
//		{
//			int r = l + len - 1;
//			if (len == 1) f[l][r] = w[l], g[l][r] = l;
//			else
//			{
//				for (int k = l;k <= r;k++)
//				{
//					int left = k == l ? 1 : f[l][k - 1];
//					int right = k == r ? 1 : f[k + 1][r];
//					int score = left * right + w[k];
//					if (f[l][r] < score)
//					{
//						f[l][r] = score;
//						g[l][r] = k;
//					}
//				}
//			}
//		}
//	cout << f[1][n] << endl;
//	dfs(1, n);
//	return 0;
//}




//棋盘分割
//#include<iostream>
//#include<algorithm>
//#include<cstring>
//#include<cmath>
//using namespace std;
//const int N = 15, M = 9;
//const double INF = 1e9;
//int n, m = 8;
//int s[M][M];
//double f[M][M][M][M][N];
//double X;
//int get_sum(int x1, int y1, int x2, int y2)
//{
//	return s[x2][y2] - s[x2][y1 - 1] - s[x1 - 1][y2] + s[x1 - 1][y1 - 1];
//}
//double get(int x1, int y1, int x2, int y2)
//{
//	double sum = get_sum(x1, y1, x2, y2) - X;
//	return (double)sum * sum / n;
//}
//double dp(int x1, int y1, int x2, int y2, int k)
//{
//	double& v = f[x1][y1][x2][y2][k];
//	if (v >= 0) return v;
//	if (k == 1) return v = get(x1, y1, x2, y2);
//	v = INF;
//	for (int i = x1;i < x2;i++)
//	{
//		v = min(v, get(x1, y1, i, y2) + dp(i + 1, y1, x2, y2, k - 1));
//		v = min(v, get(i + 1, y1, x2, y2) + dp(x1, y1, i, y2, k - 1));
//	}
//	for (int i = y1;i < y2;i++)
//	{
//		v = min(v, get(x1, y1, x2, i) + dp(x1, i + 1, x2, y2, k - 1));
//		v = min(v, get(x1, i + 1, x2, y2) + dp(x1, y1, x2, i, k - 1));
//	}
//	return v;
//}
//int main()
//{
//	cin >> n;
//	for(int i = 1;i <= m;i++)
//		for (int j = 1;j <= m;j++)
//		{
//			cin >> s[i][j];
//			s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
//		}
//	X = (double)s[m][m] / n;
//	memset(f, -1, sizeof f);
//	printf("%.3lf\n", sqrt(dp(1, 1, 8, 8, n)));
//}
//#define  _CRT_SECURE_NO_WARNINGS 1
////Devu和鲜花
//#include <cstring>
//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//typedef long long ll;
//const int N = 20, mod = 1e9 + 7;
//ll A[N];
//int down = 1;
//int qmi(int a, int k, int p)
//{
//	int res = 1;
//	while (k)
//	{
//		if (k & 1) res = (ll)res * a % p;
//		a = (ll)a * a % p;
//		k >>= 1;
//	}
//	return res;
//}
//int C(ll a, ll b)
//{
//	if (a < b) return 0;
//	int up = 1;
//	for (ll i = a;i > a - b;i--) up = i % mod * up % mod;
//	return (ll)up * down % mod;
//}
//int main()
//{
//	ll n, m;
//	cin >> n >> m;
//	for (int i = 0;i < n;i++) cin >> A[i];
//	for (int j = 1;j <= n - 1;j++) down = (ll)j * down % mod;
//	down = qmi(down, mod - 2, mod);
//	int res = 0;
//	for (int i = 0;i < 1 << n;i++)
//	{
//		ll a = m + n - 1, b = n - 1;
//		int sign = 1;
//		for(int j=0;j<n;j++)
//			if (i >> j & 1)
//			{
//				sign *= -1;
//				a -= A[j] + 1;
//			}
//		res = (res + C(a, b) * sign) % mod;
//	}
//	cout << (res + mod) % mod << endl;
//}


// 破译密码
//#include <cstdio>
//#include <cstring>
//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//typedef long long LL;
//
//const int N = 50010;
//
//int primes[N], cnt;
//bool st[N];
//int mobius[N], sum[N];
//
//// 线性筛法，求莫比乌斯函数
//void init(int n)
//{
//    mobius[1] = 1;
//    for (int i = 2; i <= n; i++)
//    {
//        if (!st[i])
//        {
//            primes[cnt++] = i;
//            mobius[i] = -1;
//        }
//        for (int j = 0; primes[j] * i <= n; j++)
//        {
//            int t = primes[j] * i;
//            st[t] = true;
//            if (i % primes[j] == 0)
//            {
//                mobius[t] = 0;
//                break;
//            }
//            mobius[t] = mobius[i] * -1;
//        }
//    }
//
//    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + mobius[i];
//}
//
//int main()
//{
//    init(N - 1);
//
//    int T;
//    scanf("%d", &T);
//    while (T--)
//    {
//        int a, b, d;
//        scanf("%d%d%d", &a, &b, &d);
//        a /= d, b /= d;
//        int n = min(a, b);
//        LL res = 0;
//        for (int l = 1, r; l <= n; l = r + 1)
//        {
//            r = min(n, min(a / (a / l), b / (b / l)));
//            res += (sum[r] - sum[l - 1]) * (LL)(a / l) * (b / l);
//        }
//
//        printf("%lld\n", res);
//    }
//
//    return 0;
//}



////绿豆蛙的归宿
//#include<iostream>
//#include<algorithm>
//#include<cstring>
//using namespace std;
//const int N = 100010, M = 200010;
//int n, m;
//int h[N], e[M], ne[M], w[M], idx;
//int dout[N];
//double f[N];
//void add(int a, int b, int c)
//{
//	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
//}
//double dp(int u)
//{
//	if (f[u] >= 0) return f[u];
//	f[u] = 0;
//	for (int i = h[u];~i;i = ne[i])
//	{
//		int j = e[i];
//		f[u] += (w[i] + dp(j)) / dout[u];
//	}
//	return f[u];
//}
//int main()
//{
//	cin >> n >> m;
//	memset(h, -1, sizeof h);
//	for (int i = 0;i < m;i++)
//	{
//		int a, b, c;
//		cin >> a >> b >> c;
//		add(a, b, c);
//		dout[a]++;
//	}
//	memset(f, -1, sizeof f);
//	printf("%.2lf\n", dp(1));
//}

//扑克牌
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 14;
const double INF = 1e20;
int A, B, C, D;
double f[N][N][N][N][5][5];
double dp(int a, int b, int c, int d, int x, int y)
{
	double& v = f[a][b][c][d][x][y];
	if (v >= 0) return v;
	int as = a + (x == 0) + (y == 0);
	int bs = b + (x == 1) + (y == 1);
	int cs = c + (x == 2) + (y == 2);
	int ds = d + (x == 3) + (y == 3);
	if (as >= A && bs >= B && cs >= C && ds >= D) return v = 0;
	int sum = a + b + c + d + (x != 4) + (y != 4);
	sum = 54 - sum;
	if (sum <= 0) return v = INF;
	v = 1;
	if (a < 13) v += (13.0 - a) / sum * dp(a + 1, b, c, d, x, y);
	if (b < 13) v += (13.0 - b) / sum * dp(a, b + 1, c, d, x, y);
	if (c < 13) v += (13.0 - c) / sum * dp(a, b, c + 1, d, x, y);
	if (d < 13) v += (13.0 - d) / sum * dp(a, b, c, d + 1, x, y);
	if (x == 4)
	{
		double t = INF;
		for (int i = 0;i < 4;i++) t = min(t, 1.0 / sum * dp(a, b, c, d, i, y));
		v += t;
	}
	if (y == 4)
	{
		double t = INF;
		for (int i = 0;i < 4;i++) t = min(t, 1.0 / sum * dp(a, b, c, d, x, i));
		v += t;
	}
	return v;
}
int main()
{
	cin >> A >> B >> C >> D;
	memset(f, -1, sizeof f);
	double t = dp(0, 0, 0, 0, 4, 4);
	if (t > INF / 2) t = -1;
	printf("%.3lf\n", t);
}
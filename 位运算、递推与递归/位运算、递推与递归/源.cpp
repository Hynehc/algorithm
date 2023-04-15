#define  _CRT_SECURE_NO_WARNINGS 1

////64位整数乘法
//#include<iostream>
//using namespace std;
//typedef long long ll;
//ll add(ll a, ll b, ll p)
//{
//	ll res = 0;
//	while (b)
//	{
//		if (b & 1) res = (res + a) % p;
//		a = (a + a) % p;
//		b >>= 1;
//	}
//	return res;
//}
//int main()
//{
//	ll a, b, p;
//	cin >> a >> b >> p;
//	cout << add(a, b, p) << endl;
//}



//费解的开关
//#include<iostream>
//#include<cstring>
//using namespace std;
//const int N = 6;
//char g[N][N], bg[N][N];
//int dx[5] = { -1,0,1,0,0 }, dy[5] = { 0,1,0,-1,0 };
//void turn(int x, int y)
//{
//	for (int i = 0;i < 5;i++)
//	{
//		int a = x + dx[i], b = y + dy[i];
//		if (a < 0 || b < 0 || a >= 5 || b >= 5) continue;
//		g[a][b] ^= 1;
//	}
//}
//int main()
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		for (int i = 0;i < 5;i++) cin >> bg[i];
//		int res = 10;
//		for (int op = 0;op < 32;op++)
//		{
//			int cnt = 0;
//			memcpy(g, bg, sizeof g);
//			for(int i=0;i<5;i++)
//				if (op >> i & 1)
//				{
//					turn(0, i);
//					cnt++;
//				}
//			for(int i=0;i<4;i++)
//				for(int j=0;j<5;j++)
//					if (g[i][j] == '0')
//					{
//						turn(i + 1, j);
//						cnt++;
//					}
//			bool s = true;
//			for (int i = 0;i < 5;i++)
//				if (g[4][i] == '0')
//					s = false;
//			if (s && res > cnt) res = cnt;
//		}
//		if (res > 6) res = -1;
//		printf("%d\n", res);
//	}
//}



// 约数之和
//#include<iostream>
//using namespace std;
//const int mod = 9901;
//int qmi(int a, int k)
//{
//	int res = 1;;
//	a %= mod;
//	while (k)
//	{
//		if (k & 1) res = res * a % mod;
//		a = a * a % mod;
//		k >>= 1;
//	}
//	return res;
//}
//int sum(int p, int k)
//{
//	if (k == 1) return 1;
//	if (k % 2 == 0) return (1 + qmi(p, k / 2)) * sum(p, k / 2) % mod;
//	return (sum(p, k - 1) + qmi(p, k - 1)) % mod;
//}
//int main()
//{
//	int a, b;
//	cin >> a >> b;
//	int res = 1;
//	for(int i=2;i*i<=a;i++)
//		if (a % i == 0)
//		{
//			int s = 0;
//			while (a % i == 0)
//			{
//				a /= i, s++;
//			}
//			res = res * sum(i, b * s + 1) % mod;
//		}
//	if (a > 1) res = res * sum(a, b + 1) % mod;
//	if (a == 0) res = 0;
//	cout << res << endl;
//}



//分形之城
#include <cstdio>
#include <cstring>
#include <cmath>
typedef long long LL;
struct Point
{
    LL x, y;
};
Point get(LL n, LL a)
{
    if (n == 0) return { 0, 0 };
    LL block = 1ll << n * 2 - 2, len = 1ll << n - 1;
    auto p = get(n - 1, a % block);
    LL x = p.x, y = p.y;
    int z = a / block;

    if (z == 0) return { y, x };
    else if (z == 1) return { x, y + len };
    else if (z == 2) return { x + len, y + len };
    return { len * 2 - 1 - y, len - 1 - x };
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        LL n, a, b;
        scanf("%lld%lld%lld", &n, &a, &b);
        auto pa = get(n, a - 1);
        auto pb = get(n, b - 1);
        double dx = pa.x - pb.x, dy = pa.y - pb.y;
        printf("%.0lf\n", sqrt(dx * dx + dy * dy) * 10);
    }
    return 0;
}

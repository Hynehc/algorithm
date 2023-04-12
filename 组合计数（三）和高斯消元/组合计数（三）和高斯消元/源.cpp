#define  _CRT_SECURE_NO_WARNINGS 1
//有趣的数列
//#include <cstring>
//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//typedef long long LL;
//
//const int N = 2000010;
//
//int n, p;
//int primes[N], cnt;
//bool st[N];
//
//void init(int n)
//{
//    for (int i = 2; i <= n; i++)
//    {
//        if (!st[i]) primes[cnt++] = i;
//        for (int j = 0; primes[j] * i <= n; j++)
//        {
//            st[i * primes[j]] = true;
//            if (i % primes[j] == 0) break;
//        }
//    }
//}
//
//int qmi(int a, int k)
//{
//    int res = 1;
//    while (k)
//    {
//        if (k & 1) res = (LL)res * a % p;
//        a = (LL)a * a % p;
//        k >>= 1;
//    }
//    return res;
//}
//
//int get(int n, int p)
//{
//    int s = 0;
//    while (n)
//    {
//        s += n / p;
//        n /= p;
//    }
//    return s;
//}
//
//int C(int a, int b)
//{
//    int res = 1;
//    for (int i = 0; i < cnt; i++)
//    {
//        int prime = primes[i];
//        int s = get(a, prime) - get(b, prime) - get(a - b, prime);
//
//        res = (LL)res * qmi(prime, s) % p;
//    }
//
//    return res;
//}
//
//int main()
//{
//    scanf("%d%d", &n, &p);
//    init(n * 2);
//
//    cout << (C(n * 2, n) - C(n * 2, n - 1) + p) % p << endl;
//
//    return 0;
//}
//


//球形空间产生器
//#include <cstdio>
//#include <cstring>
//#include <iostream>
//#include <algorithm>
//#include <cmath>
//using namespace std;
//const int N = 15;
//int n;
//double a[N][N], b[N][N];
//void gauss()
//{
//	for (int r = 1, c = 1;c <= n;c++, r++)
//	{
//		int t = r;
//		for (int i = r + 1;i <= n;i++)
//			if (fabs(b[i][c]) > fabs(b[t][c]))
//				t = i;
//		for (int i = c;i <= n + 1;i++) swap(b[t][i], b[r][i]);
//		for (int i = n + 1;i >= c;i--) b[r][i] /= b[r][c];
//		for (int i = r + 1;i <= n;i++)
//			for (int j = n + 1;j >= c;j--)
//				b[i][j] -= b[i][c] * b[r][j];
//	}
//	for(int i=n;i>1;i--)
//		for (int j = i - 1;j;j--)
//		{
//			b[j][n + 1] -= b[i][n + 1] * b[j][i];
//			b[i][j] = 0;
//		}
//}
//int main()
//{
//	cin >> n;
//	for (int i = 0;i < n + 1;i++)
//		for (int j = 1;j <= n;j++)
//			cin >> a[i][j];
//	for(int i=1;i<=n;i++)
//		for (int j = 1;j <= n;j++)
//		{
//			b[i][j] += 2 * (a[i][j] - a[0][j]);
//			b[i][n + 1] += a[i][j] * a[i][j] - a[0][j] * a[0][j];
//		}
//	gauss();
//	for (int i = 1;i <= n;i++) printf("%.3lf ", b[i][n + 1]);
//}


//开关问题
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 35;

int n;
int a[N][N];

int gauss()
{
    int r, c;
    for (r = 1, c = 1; c <= n; c++)
    {
        // 找主元
        int t = r;
        for (int i = r + 1; i <= n; i++)
            if (a[i][c])
                t = i;

        if (!a[t][c]) continue;
        // 交换
        for (int i = c; i <= n + 1; i++) swap(a[t][i], a[r][i]);
        // 消
        for (int i = r + 1; i <= n; i++)
            for (int j = n + 1; j >= c; j--)
                a[i][j] ^= a[i][c] & a[r][j];
        r++;
    }

    int res = 1;
    if (r < n + 1)
    {
        for (int i = r; i <= n; i++)
        {
            if (a[i][n + 1]) return -1;  // 出现了 0 == !0，无解
            res *= 2;
        }
    }

    return res;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        memset(a, 0, sizeof a);
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) scanf("%d", &a[i][n + 1]);
        for (int i = 1; i <= n; i++)
        {
            int t;
            scanf("%d", &t);
            a[i][n + 1] ^= t;
            a[i][i] = 1;
        }

        int x, y;
        while (scanf("%d%d", &x, &y), x || y) a[y][x] = 1;

        int t = gauss();
        if (t == -1) puts("Oh,it's impossible~!!");
        else printf("%d\n", t);
    }

    return 0;
}

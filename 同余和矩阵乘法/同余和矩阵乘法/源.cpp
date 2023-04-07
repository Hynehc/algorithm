#define  _CRT_SECURE_NO_WARNINGS 1
// 同余方程
//#include<iostream>
//using namespace std;
//typedef long long ll;
//int exgcd(int a, int b, int& x, int &y)
//{
//	if (!b)
//	{
//		x = 1, y = 0;
//		return a;
//	}
//	int d = exgcd(b, a % b, y, x);
//	y -= a / b * x;
//	return d;
//}
//int main()
//{
//	int a, b;
//	cin >> a >> b;
//	int x, y;
//	exgcd(a, b, x, y);
//	cout << (x % b + (ll)b) % b << endl;
//}

//青蛙的约会
//#include<iostream>
//using namespace std;
//typedef long long ll;
//ll exgcd(ll a, ll b, ll& x, ll& y)
//{
//	if (!b)
//	{
//		x = 1, y = 0;
//		return a;
//	}
//	ll d = exgcd(b, a % b, y, x);
//	y -= a / b * x;
//	return d;
//}
//int main()
//{
//	ll a, b, m, n, l;
//	cin >> a >> b >> m >> n >> l;
//	ll x, y;
//	ll d = exgcd(m - n, l, x, y);
//	if ((b - a) % d) puts("Impossible");
//	else
//	{
//		x *= (b - a) / d;
//		ll t = abs(l / d);
//		cout << (x % t + t) % t << endl;
//	}
//
//	return 0;
//}



//最幸运的数字
//#include <cstdio>
//#include <cstring>
//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//typedef long long LL;
//LL qmul(LL a, LL k, LL b)
//{
//    LL res = 0;
//    while (k)
//    {
//        if (k & 1) res = (res + a) % b;
//        a = (a + a) % b;
//        k >>= 1;
//    }
//    return res;
//}
//
//LL qmi(LL a, LL k, LL b)
//{
//    LL res = 1;
//    while (k)
//    {
//        if (k & 1) res = qmul(res, a, b);
//        a = qmul(a, a, b);
//        k >>= 1;
//    }
//    return res;
//}
//
//LL get_euler(LL C)
//{
//    LL res = C;
//    for (LL i = 2; i <= C / i; i++)
//        if (C % i == 0)
//        {
//            while (C % i == 0) C /= i;
//            res = res / i * (i - 1);
//        }
//    if (C > 1) res = res / C * (C - 1);
//    return res;
//}
//int main()
//{
//	int T = 1;
//	LL L;
//	while (cin >> L, L)
//	{
//		int d = 1;
//		while (L % (d * 2) == 0 && d * 2 <= 8) d *= 2;
//		LL C = 9 * L / d;
//
//		LL phi = get_euler(C);
//
//		LL res = 1e18;
//		if (C % 2 == 0 || C % 5 == 0) res = 0;
//		else
//		{
//			for (LL d = 1; d * d <= phi; d++)
//				if (phi % d == 0)
//				{
//					if (qmi(10, d, C) == 1) res = min(res, d);
//					if (qmi(10, phi / d, C) == 1) res = min(res, phi / d);
//				}
//		}
//
//		printf("Case %d: %lld\n", T++, res);
//	}
//}




//曹冲养猪
//#include <cstring>
//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//typedef long long LL;
//
//const int N = 10;
//
//int n;
//int A[N], B[N];
//
//void exgcd(LL a, LL b, LL& x, LL& y)
//{
//    if (!b) x = 1, y = 0;
//    else
//    {
//        exgcd(b, a % b, y, x);
//        y -= a / b * x;
//    }
//}
//
//int main()
//{
//    scanf("%d", &n);
//
//    LL M = 1;
//    for (int i = 0; i < n; i++)
//    {
//        scanf("%d%d", &A[i], &B[i]);
//        M *= A[i];
//    }
//
//    LL res = 0;
//    for (int i = 0; i < n; i++)
//    {
//        LL Mi = M / A[i];
//        LL ti, x;
//        exgcd(Mi, A[i], ti, x);
//        res += B[i] * Mi * ti;
//    }
//
//    cout << (res % M + M) % M << endl;
//
//    return 0;
//}
//斐波那契前 n 项和
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 3;

int n, m;

void mul(int c[], int a[], int b[][N])
{
    int temp[N] = { 0 };
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            temp[i] = (temp[i] + (LL)a[j] * b[j][i]) % m;

    memcpy(c, temp, sizeof temp);
}

void mul(int c[][N], int a[][N], int b[][N])
{
    int temp[N][N] = { 0 };
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            for (int k = 0; k < N; k++)
                temp[i][j] = (temp[i][j] + (LL)a[i][k] * b[k][j]) % m;

    memcpy(c, temp, sizeof temp);
}

int main()
{
    cin >> n >> m;

    int f1[N] = { 1, 1, 1 };
    int a[N][N] = {
        {0, 1, 0},
        {1, 1, 1},
        {0, 0, 1}
    };

    n--;
    while (n)
    {
        if (n & 1) mul(f1, f1, a);  // res = res * a
        mul(a, a, a);  // a = a * a
        n >>= 1;
    }

    cout << f1[2] << endl;

    return 0;
}


//#define  _CRT_SECURE_NO_WARNINGS 1
////车的放置
//#include <cstring>
//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//typedef long long ll;
//const int N = 2010, mod = 100003;
//int fact[N], infact[N];
//int qmi(int a, int k)
//{
//	int res = 1;
//	while (k)
//	{
//		if (k & 1) res = (ll)res * a % mod;
//		a = (ll)a * a % mod;
//		k >>= 1;
//	}
//	return res;
//}
//int C(int a, int b)
//{
//	if (a < b) return 0;
//	return (ll)fact[a] * infact[a - b] % mod * infact[b] % mod;
//}
//int P(int a, int b)
//{
//	if (a < b) return 0;
//	return (ll)fact[a] * infact[a - b] % mod;
//}
//int main()
//{
//	fact[0] = infact[0] = 1;
//	for (int i = 1;i < N;i++)
//	{
//		fact[i] = (ll)fact[i - 1] * i % mod;
//		infact[i] = (ll)infact[i - 1] * qmi(i, mod - 2) % mod;
//	}
//	int a, b, c, d, k;
//	cin >> a >> b >> c >> d >> k;
//	int res = 0;
//	for (int i = 0;i <= k;i++)
//	{
//		res = (res + (ll)C(b, i) * P(a, i) % mod * C(d, k - i) % mod * P(a + c - i, k - i)) % mod;
//	}
//	cout << res << endl;
//}



//数三角形
//#include <cstring>
//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//typedef long long LL;
//
//int gcd(int a, int b)
//{
//    return b ? gcd(b, a % b) : a;
//}
//
//LL C(int n)
//{
//    return (LL)n * (n - 1) * (n - 2) / 6;
//}
//
//int main()
//{
//    int n, m;
//    cin >> n >> m;
//
//    n++, m++;
//
//    LL res = C(n * m) - (LL)n * C(m) - (LL)m * C(n);
//    for (int i = 1; i <= n; i++)
//        for (int j = 1; j <= m; j++)
//            res -= 2ll * (gcd(i, j) - 1) * (n - i) * (m - j);
//
//    cout << res << endl;
//
//    return 0;
//}




//序列统计
//#include <cstring>
//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//typedef long long LL;
//
//const int p = 1000003;
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
//int C(int a, int b)
//{
//    if (a < b) return 0;
//
//    int down = 1, up = 1;
//    for (int i = a, j = 1; j <= b; i--, j++)
//    {
//        up = (LL)up * i % p;
//        down = (LL)down * j % p;
//    }
//
//    return (LL)up * qmi(down, p - 2) % p;
//}
//
//int Lucas(int a, int b)
//{
//    if (a < p && b < p) return C(a, b);
//    return (LL)Lucas(a / p, b / p) * C(a % p, b % p) % p;
//}
//
//int main()
//{
//    int T;
//    cin >> T;
//    while (T--)
//    {
//        int n, l, r;
//        cin >> n >> l >> r;
//        cout << (Lucas(r - l + n + 1, r - l + 1) + p - 1) % p << endl;
//    }
//
//    return 0;
//}




// 网格
//#include <cstring>
//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//const int N = 100010;
//
//int primes[N], cnt;
//bool st[N];
//int a[N], b[N];
//
//void init(int n)
//{
//    for (int i = 2; i <= n; i++)
//    {
//        if (!st[i]) primes[cnt++] = i;
//        for (int j = 0; primes[j] * i <= n; j++)
//        {
//            st[primes[j] * i] = true;
//            if (i % primes[j] == 0) break;
//        }
//    }
//}
//
//int get(int n, int p)
//{
//    int s = 0;
//    while (n) s += n / p, n /= p;
//    return s;
//}
//
//void mul(int r[], int& len, int x)
//{
//    int t = 0;
//    for (int i = 0; i < len; i++)
//    {
//        t += r[i] * x;
//        r[i] = t % 10;
//        t /= 10;
//    }
//    while (t)
//    {
//        r[len++] = t % 10;
//        t /= 10;
//    }
//}
//
//void sub(int a[], int al, int b[], int bl)
//{
//    for (int i = 0, t = 0; i < al; i++)
//    {
//        a[i] -= t + b[i];
//        if (a[i] < 0) a[i] += 10, t = 1;
//        else t = 0;
//    }
//}
//
//int C(int x, int y, int r[N])
//{
//    int len = 1;
//    r[0] = 1;
//
//    for (int i = 0; i < cnt; i++)
//    {
//        int p = primes[i];
//        int s = get(x, p) - get(y, p) - get(x - y, p);
//        while (s--) mul(r, len, p);
//    }
//
//    return len;
//}
//
//int main()
//{
//    init(N - 1);
//
//    int n, m;
//    cin >> n >> m;
//    int al = C(n + m, m, a);
//    int bl = C(n + m, n + 1, b);
//
//    sub(a, al, b, bl);
//
//    int k = al - 1;
//    while (!a[k] && k > 0) k--;
//    while (k >= 0) printf("%d", a[k--]);
//
//    return 0;
//}




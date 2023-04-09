#define  _CRT_SECURE_NO_WARNINGS 1
//轻拍牛头
//#include<iostream>
//using namespace std;
//const int N = 1000010;
//int n;
//int a[N], cnt[N], s[N];
//int main()
//{
//	cin >> n;
//	for (int i = 0;i < n;i++)
//	{
//		cin >> a[i];
//		cnt[a[i]]++;
//	}
//	for (int i = 1;i < N;i++)
//		for (int j = i;j < N;j += i)
//			s[j] += cnt[i];
//	for (int i = 0;i < n;i++) cout << s[a[i]] - 1 << endl;
//}


//樱花
//#include<iostream>
//using namespace std;
//const int N = 1e6 + 10, mod = 1e9 + 7;
//typedef long long ll;
//int primes[N], cnt;
//bool st[N];
//void init(int n)
//{
//	for (int i = 2;i <= n;i++)
//	{
//		if (!st[i]) primes[cnt++] = i;
//		for (int j = 0;primes[j] * i <= n;j++)
//		{
//			st[primes[j] * i] = true;
//			if (i % primes[j] == 0) break;
//		}
//	}
//}
//int main()
//{
//	int n;
//	cin >> n;
//	init(n);
//	int res = 1;
//	for (int i = 0;i < cnt;i++)
//	{
//		int p = primes[i];
//		int s = 0;
//		for (int j = n;j;j /= p) s += j / p;
//		res = (ll)res * (2 * s + 1) % mod;
//	}
//	cout << res << endl;
//}



//反素数
//#include <cstring>
//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//typedef long long LL;
//
//int primes[9] = { 2, 3, 5, 7, 11, 13, 17, 19, 23 };
//int maxd, number;
//int n;
//void dfs(int u, int last, int p, int s)
//{
//	if (s > maxd || s == maxd && p < number)
//	{
//		maxd = s;
//		number = p;
//	}
//	if (u == 9) return;
//	for (int i = 1;i <= last;i++)
//	{
//		if ((LL)p * primes[u] > n) break;
//		p *= primes[u];
//		dfs(u + 1, i, p, s * (i + 1));
//	}
//}
//int main()
//{
//	cin >> n;
//
//	dfs(0, 30, 1, 1);
//
//	cout << number << endl;
//
//	return 0;
//}




// Hankson的趣味题
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
//struct Factor
//{
//    int p, s;
//}factor[10];
//int fcnt;
//
//int dividor[1601], dcnt;
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
//void dfs(int u, int p)
//{
//    if (u == fcnt)
//    {
//        dividor[dcnt++] = p;
//        return;
//    }
//
//    for (int i = 0; i <= factor[u].s; i++)
//    {
//        dfs(u + 1, p);
//        p *= factor[u].p;
//    }
//}
//
//int gcd(int a, int b)
//{
//    return b ? gcd(b, a % b) : a;
//}
//
//int main()
//{
//    init(N - 1);
//
//    int n;
//    cin >> n;
//    while (n--)
//    {
//        int a, b, c, d;
//        cin >> a >> b >> c >> d;
//
//        fcnt = 0;
//        int t = d;
//        for (int i = 0; primes[i] <= t / primes[i]; i++)
//        {
//            int p = primes[i];
//            if (t % p == 0)
//            {
//                int s = 0;
//                while (t % p == 0) t /= p, s++;
//                factor[fcnt++] = { p, s };
//            }
//        }
//
//        if (t > 1) factor[fcnt++] = { t, 1 };
//
//        dcnt = 0;
//        dfs(0, 1);
//
//        int res = 0;
//        for (int i = 0; i < dcnt; i++)
//        {
//            int x = dividor[i];
//            if (gcd(a, x) == b && (LL)c * x / gcd(c, x) == d) res++;
//        }
//
//        cout << res << endl;
//    }
//
//    return 0;
//}
//


//可见的点
//
//#include <cstring>
//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//const int N = 1010;
//int primes[N], cnt;
//bool st[N];
//int phi[N];
//void init(int n)
//{
//	phi[1] = 1;
//	for (int i = 2;i <= n;i++)
//	{
//		if (!st[i])
//		{
//			primes[cnt++] = i;
//			phi[i] = i - 1;
//		}
//		for (int j = 0;primes[j] * i <= n;j++)
//		{
//			st[i * primes[j]] = true;
//			if (i % primes[j] == 0)
//			{
//				phi[i * primes[j]] = phi[i] * primes[j];
//				break;
//			}
//			phi[i * primes[j]] = phi[i] * (primes[j] - 1);
//		}
//	}
//}
//int main()
//{
//	init(N - 1);
//	int n, m;
//	cin >> m;
//	for (int t = 1;t <= m;t++)
//	{
//		cin >> n;
//		int res = 1;
//		for (int i = 1;i <= n;i++) res += phi[i] * 2;
//		cout << t << " " << n << " " << res << endl;
//	}
//}



//最大公约数
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;
const int N = 1e7 + 10;
int primes[N], cnt;
bool st[N];
int phi[N];
LL s[N];
void init(int n)
{
	for (int i = 2;i <= n;i++)
	{
		if (!st[i])
		{
			primes[cnt++] = i;
			phi[i] = i - 1;
		}
		for (int j = 0;primes[j] * i <= n;j++)
		{
			st[primes[j] * i] = true;
			if (i % primes[j] == 0)
			{
				phi[i * primes[j]] = phi[i] * primes[j];
				break;
			}
			phi[i * primes[j]] = phi[i] * (primes[j] - 1);
		}
	}
	for (int i = 1;i <= n;i++) s[i] = s[i - 1] + phi[i];
}
int main()
{
	int n;
	cin >> n;
	init(n);
	LL res = 0;
	for (int i = 0;i < cnt;i++)
	{
		int p = primes[i];
		res += s[n / p] * 2 + 1;
	}
	cout << res << endl;
}
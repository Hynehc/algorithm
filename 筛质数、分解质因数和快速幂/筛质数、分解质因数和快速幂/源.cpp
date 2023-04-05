//#define  _CRT_SECURE_NO_WARNINGS 1
////哥德巴赫猜想
//#include <cstdio>
//#include <cstring>
//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//const int N = 1000010;
//int primes[N], cnt;
//bool st[N];
//void init(int n)
//{
//	for (int i = 2;i <= n;i++)
//	{
//		if (!st[i]) primes[cnt++] = i;
//		for (int j = 0;primes[j] * i <= n; j++)
//		{
//			st[primes[j] * i] = true;
//			if (i % primes[j] == 0) break;
//		}
//	}
//}
//int main()
//{
//	init(N - 1);
//	int n;
//	while (cin >> n, n)
//	{
//		for (int i = 1;;i++)
//		{
//			int a = primes[i];
//			int b = n - a;
//			if (!st[b])
//			{
//				printf("%d = %d + %d\n", n, a, b);
//				break;
//			}
//		}
//	}
//}

////夏洛克和他的女朋友
//#include<iostream>
//using namespace std;
//const int N = 100010;
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
//	init(n + 1);
//	if (n <= 2) cout << 1 << endl;
//	else cout << 2 << endl;
//	for (int i = 2;i <= n + 1;i++)
//	{
//		if (!st[i]) cout << 1 << " ";
//		else  cout << 2 << " ";
//	}
//}




// 质数距离
//#include <cstring>
//#include <iostream>
//#include <algorithm>
//using namespace std;
//typedef long long ll;
//const int N = 1000010;
//int primes[N], cnt;
//bool st[N];
//void init(int n)
//{
//	memset(st, 0, sizeof st);
//	cnt = 0;
//	for (int i = 2;i <= n;i++)
//	{
//		if (!st[i]) primes[cnt++] = i;
//		for (int j = 0;primes[j] * i <= n;j++)
//		{
//			st[primes[j] * i] == true;
//			if (i % primes[j] == 0) break;
//		}
//	}
//}
//int main()
//{
//	int l, r;
//	while (cin >> l >> r)
//	{
//		init(50000);
//		memset(st, 0, sizeof st);
//		for (int i = 0;i < cnt;i++)
//		{
//			ll p = primes[i];
//			for (ll j = max(2 * p, (l + p - 1) / p * p);j <= r;j += p)
//				st[j - l] = true;
//		}
//		cnt = 0;
//		for (int i = 0;i <= r - l;i++)
//			if (!st[i] && i + l >= 2)
//				primes[cnt++] = i + l;
//		if (cnt < 2) puts("There are no adjacent primes.");
//		else
//		{
//			int minp = 0, maxp = 0;
//			for (int i = 0;i + 1 < cnt;i++)
//			{
//				int d = primes[i + 1] - primes[i];
//				if (d < primes[minp + 1] - primes[minp]) minp = i;
//				if (d > primes[maxp + 1] - primes[maxp]) maxp = i;
//			}
//			printf("%d,%d are closest, %d,%d are most distant.\n",
//				primes[minp], primes[minp + 1],
//				primes[maxp], primes[maxp + 1]);
//		}
//	}
//}



//阶乘分解
//#include<iostream>
//using namespace std;
//const int N = 1000010;
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
//	for (int i = 0;i < cnt;i++)
//	{
//		int p = primes[i];
//		int s = 0;
//		for (int j = n;j;j /= p) s += j / p;
//		cout << p << " " << s << endl;
//	}
//}



// 序列的第k个数
//#include<iostream>
//using namespace std;
//typedef long long ll;
//const int mod = 200907;
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
//int main()
//{
//	int n;
//	cin >> n;
//	while (n--)
//	{
//		int a,b, c, k;
//		cin >> a >> b >> c >> k;
//		if (a + c == b * 2) cout << (a + (b - a) * (ll)(k - 1)) % mod << endl;
//		else cout << (ll)a * qmi(b / a, k - 1) % mod << endl;
//	}
//}

//越狱
#include<iostream>
using namespace std;
const int mod = 100003;
typedef long long ll;
int qmi(int a, ll k)
{
	int res = 1;
	while (k)
	{
		if (k & 1) res = (ll)res * a % mod;
		a = (ll)a * a % mod;
		k >>= 1;
	}
	return res;
}
int main()
{
	int m;
	ll n;
	cin >> m >> n;
	cout << (qmi(m, n) - (ll)m * qmi(m - 1, n - 1) % mod + mod) % mod << endl;
}
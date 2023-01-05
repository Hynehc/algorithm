#define  _CRT_SECURE_NO_WARNINGS 1
//欧拉函数
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		int x;
		cin >> x;
		int res = x;
		for (int i = 2;i <= x / i;i++)
			if (x % i == 0)
			{
				res = res / i * (i - 1);
				while (x % i == 0) x /= i;
			}
		if (x > 1) res = res / x * (x - 1);
		cout << res << endl;
	}
}




//筛法求欧拉函数
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1e6 + 10;
typedef long long ll;
int primes[N], cnt;
int phi[N];
bool st[N];
ll get_eulers(int n)
{
	phi[1] = 1;
	for (int i = 2;i <= n;i++)
	{
		if (!st[i])
		{
			primes[cnt++] = i;
			phi[i] = i - 1;
		}
		for (int j = 0;primes[j] <= n / i;j++)
		{
			st[primes[j] * i] = true;
			if (i % primes[j] == 0)
			{
				phi[primes[j] * i] = phi[i] * primes[j];
				break;
			}
			phi[primes[j] * i] = phi[i] * (primes[j] - 1);
		}
	}
	ll res = 0;
	for (int i = 1;i <= n;i++) res += phi[i];
	return res;
}
int main()
{
	int n;
	cin >> n;
	cout << get_eulers(n) << endl;
}






//快速幂
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int qmi(int a, int k, int p)
{
	int res = 1;
	while (k)
	{
		if (k & 1) res = (ll)res * a % p;
		k >>= 1;
		a = (ll)a * a % p;
	}
	return res;
}
int main()
{
	int n;
	scanf("%d", &n);
	while (n--)
	{
		int a, k, p;
		scanf("%d%d%d", &a, &k, &p);
		printf("%d\n", qmi(a, k, p));
	}
	return 0;
}




// 快速幂求逆元
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int qmi(int a, int k, int p)
{
	int res = 1;
	while (k)
	{
		if (k & 1) res = (ll)res * a % p;
		k >>= 1;
		a = (ll)a * a % p;
	}
	return res;
}
int main()
{
	int n;
	scanf("%d", &n);
	while (n--)
	{
		int a, p;
		scanf("%d%d", &a, &p);
		int res = qmi(a, p - 2, p);
		if (a % p) printf("%d\n", res);
		else puts("impossible");
	}
	return 0;
}







//扩展欧几里得算法
#include<iostream>
using namespace std;
int exgcd(int a, int b, int& x, int& y)
{
	if (!b)
	{
		x = 1, y = 0;
		return a;
	}
	int d = exgcd(b, a % b, y, x);
	y -= a / b * x;
	return d;
}
int main()
{
	int n;
	scanf("%d", &n);
	while (n--)
	{
		int a, b, x, y;
		scanf("%d%d", &a, &b);
		exgcd(a, b, x, y);
		printf("%d %d\n", x, y);
	}
}



//线性同余方程
#include<iostream>
using namespace std;
typedef long long ll;
int exgcd(int a, int b, int& x, int& y)
{
	if (!b)
	{
		x = 1, y = 0;
		return a;
	}
	int d = exgcd(b, a % b, y, x);
	y -= a / b * x;
	return d;
}
int main()
{
	int n;
	scanf("%d", &n);
	while (n--)
	{
		int a, b, m;
		scanf("%d%d%d", &a, &b, &m);
		int x, y;
		int d = exgcd(a, m, x, y);
		if (b % d) puts("impossible");
		else printf("%d\n", (ll)x * (b / d) % m);
	}
}




//中国剩余定理--表达整数的奇怪方式
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll exgcd(ll a, ll b, ll& x, ll& y)
{
	if (!b)
	{
		x = 1, y = 0;
		return a;
	}
	ll d = exgcd(b, a % b, y, x);
	y -= a/b * x;
	return d;
}
int main()
{
	int n;
	cin >> n;
	bool has_answer = true;
	ll a1, m1;
	cin >> a1 >> m1;
	for (int i = 0;i < n - 1;i++)
	{
		ll a2, m2;
		cin >> a2 >> m2;
		ll k1, k2;
		ll d = exgcd(a1, a2, k1, k2);
		if ((m2 - m1) % d)
		{
			has_answer = false;
			break;
		}
		k1 *= (m2 - m1) / d;
		ll t = a2 / d;
		k1 = (k1 % t + t) % t;
		m1 = a1 * k1 + m1;
		a1 = abs(a1 / d * a2);
	}
	if (has_answer)
	{
		cout << ((m1 % a1 + a1)%a1) << endl;
	}
	else puts("-1");
}

#define  _CRT_SECURE_NO_WARNINGS 1
#define  _CRT_SECURE_NO_WARNINGS 1
//�Գ����ж�����
#include<iostream>
#include<algorithm>
using namespace std;
bool is_prime(int n)
{
	if (n < 2) return false;
	for (int i = 2;i <= n / i;i++)
		if (n % i == 0)
			return false;
	return true;
}



//�ֽ�������
#include<iostream>
#include<algorithm>
using namespace std;
void divide(int n)
{
	for (int i = 2;i <= n / i;i++)
		if (n % i == 0)
		{
			int s = 0;
			while (n % i == 0)
			{
				n /= i;
				s++;
			}
			cout << i << " " << s << endl;
		}
	if (n > 1) cout << n << " " << 1 << endl;
	puts("");
}



//ɸ����
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1e6 + 10;
int primes[N], cnt;
bool st[N];
void get_primes(int n)
{
	for (int i = 2;i <= n;i++)
	{
		//����ɸ��
		if (!st[i])
		{
			primes[cnt++] = i;
			//�Ż�
			for (int j = i + i;j <= n;j += i) st[j] = true;
		}
		//����ɸ
		/*if (!st[i])
			primes[cnt++] = n;
		for (int j = 0;primes[j] <= n / i;j++)
		{
			st[primes[j] * i] = true;
			if (i % primes[j] == 0) break;//primes[j]һ����i����С������
		}*/
		//����
		/*for (int j = i + i;j <= n;j += i)
			st[j] = true;*/
	}
}








//�Գ�����Լ��
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> get_divisors(int n)
{
	vector<int> res;
	for (int i = 1;i <= n / i;i++)
		if (n % i == 0)
		{
			res.push_back(i);
			if (i != n / i) res.push_back(n / i);
		}
	sort(res.begin(), res.end());
	return res;
}
int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		int x;
		cin >> x;
		auto res = get_divisors(x);
		for (auto t : res) cout << t << " ";
		cout << endl;
	}
	return 0;
}




//Լ������
#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
int main()
{
	int n;
	cin >> n;
	unordered_map<int, int> primes;
	while (n--)
	{
		int x;
		cin >> x;
		for (int i = 2;i <= x / i;i++)
			while (x % i == 0)
			{
				x /= i;
				primes[i]++;
			}
		if (x > 1) primes[x]++;
	}
	ll res = 1;
	for (auto prime : primes) res = res * (prime.second + 1) % mod;
	cout << res << endl;
}




//Լ�����
#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
int main()
{
	int n;
	cin >> n;
	unordered_map<int, int> primes;
	while (n--)
	{
		int x;
		cin >> x;
		for (int i = 2;i <= x / i;i++)
			while (x % i == 0)
			{
				x /= i;
				primes[i]++;
			}
		if (x > 1) primes[x]++;
	}
	ll res = 1;
	for (auto prime : primes)
	{
		int p = prime.first, a = prime.second;
		ll t = 1;
		while (a--) t = (t * p + 1) % mod;
		res = res * t % mod;
	}
	cout << res << endl;
}



//���Լ��
#include<iostream>
using namespace std;
int gcd(int a, int b)
{
	return b ? gcd(b, a % b) : a;
}
int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		int a, b;
		cin >> a >> b;
		cout << gcd(a, b) << endl;
	}
}
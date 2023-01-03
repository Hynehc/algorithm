#define  _CRT_SECURE_NO_WARNINGS 1
//高斯消元--解线性方程组
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int N = 110;
const double eps = 1e-8;
int n;
double a[N][N];
int gauss()   // 高斯消元，答案存于a[i][n]中，0 <= i < n
{
	int c, r;//c=col(列),r=row(行)
	for (c = 0, r = 0; c < n; c++)
	{
		int t = r;
		for (int i = r;i < n;i++)  // 找绝对值最大的行
			if (fabs(a[i][c]) > fabs(a[t][c]))
				t = i;
		if (fabs(a[t][c]) < eps) continue;  // 如果当前这一列的最大数都是 0 ，那么所有数都是 0，就没必要去算了，因为它的约束方程，可能在上面几行
		for (int i = c;i <= n;i++) swap(a[t][i], a[r][i]); // 将绝对值最大的行换到最顶端
		for (int i = n;i >= c;i--) a[r][i] /= a[r][c];  // 将当前行的首位变成1, 从第n位开始，是为了不覆盖掉第c位的值
		for (int i = r + 1;i < n;i++)  // 把当前列下面的所有数，全部消成 0
			if (fabs(a[i][c]) > eps)  // 如果非0 再操作，已经是 0就没必要操作了
				for (int j = n;j >= c;j--)
					a[i][j] -= a[r][j] * a[i][c];
		r++;
	}
	if (r < n)  // 说明剩下方程的个数是小于 n 的，说明不是唯一解，判断是无解还是无穷多解
	{
		// 因为已经是阶梯型，所以 r ~ n-1 的值应该都为 0
		for (int i = r;i < n;i++)
			if (fabs(a[i][n]) > eps)
				return 2;//a[i][n] 代表 b_i ,即 左边=0，右边=b_i,0 != b_i, 所以无解。
		return 1;// 否则， 0 = 0，就是r ~ n-1的方程都是多余方程

		/*如果方程组有唯一解，那么消完上三角矩阵后对角线上全部都是非零的数，左下方全部是0，右上方的数任意。
		如果消的过程中某一列没有非零的数，那么最终得到的上三角矩阵就会从这一行开始，所有的最左边的非零数会向右错一位，那么最后就会多一行零，那么r就会小于n。
		最后方程组无解的条件是出现等号左边是0，但等号右边不是0，g[i][n]就是等号右边的数。*/
	}
	// 唯一解 ↓，从下往上回代，得到方程的解
	for (int i = n - 1;i >= 0;i--)
		for (int j = i + 1;j < n;j++)
			a[i][n] -= a[j][n] * a[i][j];//因为只要得到解，所以只用对 b_i 进行操作，中间的值，可以不用操作，因为不用输出
	return 0;
}
int main()
{
	cin >> n;
	for (int i = 0;i < n;i++)
		for (int j = 0;j < n + 1;j++)
			cin >> a[i][j];
	int t = gauss();
	if (t == 2) cout << "No solution" << endl;
	else if (t == 1) cout << "Infinite group solutions" << endl;
	else
	{
		for (int i = 0;i < n;i++)
		{
			if (fabs(a[i][n]) < eps) a[i][n] = 0;// 去掉输出 -0.00 的情况
			printf("%.2lf\n", a[i][n]);
		}
	}
	return 0;
}


//高斯消元解异或线性方程组 





//求组合数 I
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 2010, mod = 1e9 + 7;
int c[N][N];
void init()
{
	for (int i = 0;i < N;i++)
		for (int j = 0;j <= i;j++)
			if (!j) c[i][j] = 1;
			else c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
}
int main()
{
	init();
	int n;
	cin >> n;
	while (n--)
	{
		int a, b;
		cin >> a >> b;
		cout << c[a][b] << endl;
	}
	return 0;
}




//求组合数 II
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1e5 + 10, mod = 1e9 + 7;
typedef long long ll;
int fact[N], infact[N];
int qmi(int a, int k, int p)
{
	int res = 1;
	while (k)
	{
		if (k & 1) res = (ll)res * a % p;
		a = (ll)a * a % p;
		k >>= 1;
	}
	return res;
}
int main()
{
	fact[0] = infact[0] = 1;
	for (int i = 1;i < N;i++)
	{
		fact[i] = (ll)fact[i - 1] * i % mod;
		infact[i] = (ll)infact[i - 1] * qmi(i, mod - 2, mod) % mod;
	}
	int n;
	cin >> n;
	while (n--)
	{
		int a, b;
		cin >> a >> b;
		printf("%d\n", (ll)fact[a] * infact[b] % mod * infact[a - b] % mod);
	}
	return 0;
}




//求组合数 III
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int p;
int qmi(int a, int k)
{
	int res = 1;
	while (k)
	{
		if (k & 1) res = (ll)res * a % p;
		a = (ll)a * a % p;
		k >>= 1;
	}
	return res;
}
int C(int a, int b)
{
	int res = 1;
	for (int i = 1, j = a;i <= b;i++, j--)
	{
		res = (ll)res * j % p;
		res = (ll)res * qmi(i, p - 2) % p;
	}
	return res;
}
int lucas(ll a, ll b)
{
	if (a < p && b < p) return C(a, b);
	return (ll)C(a % p, b % p) * lucas(a / p, b / p) % p;
}
int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		ll a, b;
		cin >> a >> b >> p;
		cout << lucas(a, b) << endl;
	}
	return 0;
}





//求组合数 IV
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int N = 5010;
int primes[N], cnt;
int sum[N];
bool st[N];
void get_primes(int n)
{
	for (int i = 2;i <= n;i++)
	{
		if (!st[i]) primes[cnt++] = i;
		for (int j = 0;primes[j] <= n / i;j++)
		{
			st[primes[j] * i] = true;
			if (i % primes[j] == 0) break;
		}
	}
}
// 对p的各个<=a的次数算整除下取整倍数
int get(int n, int p)
{
	int res = 0;
	while (n)
	{
		res += n / p;
		n /= p;
	}
	return res;
}
//高精度乘
vector<int> mul(vector<int> a, int b)
{
	vector<int>c;
	int t = 0;
	for (int i = 0;i < a.size();i++)
	{
		t += a[i] * b;
		c.push_back(t % 10);
		t /= 10;
	}
	while (t)
	{
		c.push_back(t % 10);
		t /= 10;
	}
	return c;
}
int main()
{
	int a, b;
	cin >> a >> b;
	get_primes(a);
	for (int i = 0;i < cnt;i++)
	{
		int  p = primes[i];
		sum[i] = get(a, p) - get(a - b, p) - get(b, p);
	}
	vector<int>res;
	res.push_back(1);
	for (int i = 0;i < cnt;i++)
		for (int j = 0;j < sum[i];j++)
			res = mul(res, primes[i]);
	for (int i = res.size() - 1;i >= 0;i--) printf("%d", res[i]);
	cout << endl;
}





//满足条件的01序列
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10, mod = 1e9 + 7;
int qmi(int a, int k, int p)
{
	int res = 1;
	while (k)
	{
		if (k & 1) res = (ll)res * a % p;
		a = (ll)a * a % p;
		k >>= 1;
	}
	return res;
}
int main()
{
	int n;
	cin >> n;
	int a = 2 * n, b = n;
	int res = 1;
	for (int i = a;i > a - b;i--) res = (ll)res * i % mod;
	for (int i = 1;i <= b;i++) res = (ll)res * qmi(i, mod - 2, mod) % mod;
	res = (ll)res * qmi(n + 1, mod - 2, mod) % mod;
	cout << res << endl;
	return 0;
}







//高斯消元解异或线性方程组
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 110;
int n;
int a[N][N];
int gauss()
{
	int c, r;
	for (c = r = 0;c < n;c++)
	{
		int t = r;
		for (int i = r;i < n;i++)
			if (a[i][c])
				t = i;
		if (!a[t][c]) continue;
		for (int i = c;i <= n;i++) swap(a[r][i], a[t][i]);
		for (int i = r + 1; i < n; i++)
			if (a[i][c])
				for (int j = n; j >= c; j--)
					a[i][j] ^= a[r][j];
		r++;
	}
	if (r < n)
	{
		for (int i = r;i < n;i++)
			if (a[i][n])
				return 2;
		return 1;
	}
	for (int i = n - 1;i >= 0;i--)
		for (int j = i + 1;j < n;j++)
			a[i][n] ^= a[i][j] * a[j][n];
	return 0;
}
int main()
{
	cin >> n;
	for (int i = 0;i < n;i++)
		for (int j = 0;j <= n;j++)
			cin >> a[i][j];
	int t = gauss();
	if (t == 0)
	{
		for (int i = 0;i < n;i++) cout << a[i][n] << endl;
	}
	else if (t == 1) puts("Multiple sets of solutions");
	else puts("No solution");

	return 0;
}

#define  _CRT_SECURE_NO_WARNINGS 1
//��˹��Ԫ--�����Է�����
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int N = 110;
const double eps = 1e-8;
int n;
double a[N][N];
int gauss()   // ��˹��Ԫ���𰸴���a[i][n]�У�0 <= i < n
{
	int c, r;//c=col(��),r=row(��)
	for (c = 0, r = 0; c < n; c++)
	{
		int t = r;
		for (int i = r;i < n;i++)  // �Ҿ���ֵ������
			if (fabs(a[i][c]) > fabs(a[t][c]))
				t = i;
		if (fabs(a[t][c]) < eps) continue;  // �����ǰ��һ�е���������� 0 ����ô���������� 0����û��Ҫȥ���ˣ���Ϊ����Լ�����̣����������漸��
		for (int i = c;i <= n;i++) swap(a[t][i], a[r][i]); // ������ֵ�����л������
		for (int i = n;i >= c;i--) a[r][i] /= a[r][c];  // ����ǰ�е���λ���1, �ӵ�nλ��ʼ����Ϊ�˲����ǵ���cλ��ֵ
		for (int i = r + 1;i < n;i++)  // �ѵ�ǰ���������������ȫ������ 0
			if (fabs(a[i][c]) > eps)  // �����0 �ٲ������Ѿ��� 0��û��Ҫ������
				for (int j = n;j >= c;j--)
					a[i][j] -= a[r][j] * a[i][c];
		r++;
	}
	if (r < n)  // ˵��ʣ�·��̵ĸ�����С�� n �ģ�˵������Ψһ�⣬�ж����޽⻹��������
	{
		// ��Ϊ�Ѿ��ǽ����ͣ����� r ~ n-1 ��ֵӦ�ö�Ϊ 0
		for (int i = r;i < n;i++)
			if (fabs(a[i][n]) > eps)
				return 2;//a[i][n] ���� b_i ,�� ���=0���ұ�=b_i,0 != b_i, �����޽⡣
		return 1;// ���� 0 = 0������r ~ n-1�ķ��̶��Ƕ��෽��

		/*�����������Ψһ�⣬��ô���������Ǿ����Խ�����ȫ�����Ƿ�����������·�ȫ����0�����Ϸ��������⡣
		������Ĺ�����ĳһ��û�з����������ô���յõ��������Ǿ���ͻ����һ�п�ʼ�����е�����ߵķ����������Ҵ�һλ����ô���ͻ��һ���㣬��ôr�ͻ�С��n��
		��󷽳����޽�������ǳ��ֵȺ������0�����Ⱥ��ұ߲���0��g[i][n]���ǵȺ��ұߵ�����*/
	}
	// Ψһ�� �����������ϻش����õ����̵Ľ�
	for (int i = n - 1;i >= 0;i--)
		for (int j = i + 1;j < n;j++)
			a[i][n] -= a[j][n] * a[i][j];//��ΪֻҪ�õ��⣬����ֻ�ö� b_i ���в������м��ֵ�����Բ��ò�������Ϊ�������
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
			if (fabs(a[i][n]) < eps) a[i][n] = 0;// ȥ����� -0.00 �����
			printf("%.2lf\n", a[i][n]);
		}
	}
	return 0;
}


//��˹��Ԫ��������Է����� 





//������� I
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




//������� II
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




//������� III
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





//������� IV
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
// ��p�ĸ���<=a�Ĵ�����������ȡ������
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
//�߾��ȳ�
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





//����������01����
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







//��˹��Ԫ��������Է�����
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

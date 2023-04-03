//#define  _CRT_SECURE_NO_WARNINGS 1
////¼Ñ¼ÑµÄì³²¨ÄÇÆõ
//#include <cstring>
//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//typedef long long LL;
//
//const int N = 4;
//int n, m;
//void mul(int c[][N], int a[][N], int b[][N])
//{
//	static int t[N][N];
//	memset(t, 0, sizeof t);
//	for (int i = 0;i < N;i++)
//		for (int j = 0;j < N;j++)
//			for (int k = 0;k < N;k++)
//				t[i][j] = (t[i][j] + (LL)a[i][k] * b[k][j]) % m;
//	memcpy(c, t, sizeof t);
//}
//int main()
//{
//	cin >> n >> m;
//	int f1[N][N] = { 1,1,1,0 };
//	int a[N][N] = {
//		{0, 1, 0, 0},
//		{1, 1, 1, 0},
//		{0, 0, 1, 1},
//		{0, 0, 0, 1},
//	};
//	int k = n - 1;
//	while (k)
//	{
//		if (k & 1) mul(f1, f1, a);
//		mul(a, a, a);
//		k >>= 1;
//	}
//	cout << (((LL)n * f1[0][2] - f1[0][3]) % m + m) % m << endl;
//}



//GT¿¼ÊÔ
//#include <cstring>
//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//const int N = 25;
//int n, m, mod;
//char str[N];
//int ne[N];
//int a[N][N];
//void mul(int c[][N], int a[][N], int b[][N])
//{
//	static int t[N][N];
//	memset(t, 0, sizeof t);
//	for (int i = 0;i < m;i++)
//		for (int j = 0;j < m;j++)
//			for (int k = 0;k < m;k++)
//				t[i][j] = (t[i][j] + a[i][k] * b[k][j]) % mod;
//	memcpy(c, t, sizeof t);
//}
//int qmi(int k)
//{
//	int f0[N][N] = { 1 };
//	while (k)
//	{
//		if (k & 1) mul(f0, f0, a);
//		mul(a, a, a);
//		k >>= 1;
//	}
//	int res = 0;
//	for (int i = 0;i < m;i++) res = (res + f0[0][i]) % mod;
//	return res;
//}
//int main()
//{
//	cin >> n >> m >> mod;
//	cin >> str + 1;
//	for (int i = 2, j = 0;i <= m;i++)
//	{
//		while (j && str[j + 1] != str[i]) j = ne[j];
//		if (str[j + 1] == str[i]) j++;
//		ne[i] = j;
//	}
//	for(int j=0;j<m;j++)
//		for (int c = '0';c <= '9';c++)
//		{
//			int k = j;
//			while (k && str[k + 1] != c) k = ne[k];
//			if (str[k + 1] == c) k++;
//			if (k < m) a[j][k]++;
//		}
//	cout << qmi(n) << endl;
//}





////ÄµÅ£ºÍêòÅ£
//#include<iostream>
//#include<algorithm>
//using namespace std;
//const int N = 100010, mod = 5000011;
//int n, k;
//int f[N], s[N];
//int main()
//{
//	cin >> n >> k;
//	f[0] = s[0] = 1;
//	for (int i = 1;i <= n;i++)
//	{
//		f[i] = s[max(i - k - 1, 0)];
//		s[i] = (s[i - 1] + f[i]) % mod;
//	}
//	cout << s[n] << endl;
//}





// ·½³ÌµÄ½â
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 150;
int k, x;
int f[1000][100][N];
int qmi(int a, int b, int p)
{
	int res = 1;
	while (b)
	{
		if (b & 1) res = res * a % p;
		a = a * a % p;
		b >>= 1;
	}
	return res;
}
void add(int c[], int a[], int b[])
{
	for (int i = 0, t = 0;i < N;i++)
	{
		t += a[i] + b[i];
		c[i] = t % 10;
		t /= 10;
	}
}
int main()
{
	cin >> k >> x;
	int n = qmi(x % 1000, x, 1000);
	for (int i = 0;i < n;i++)
		for (int j = 0;j <= i && j < k;j++)
			if (!j) f[i][j][0] = 1;
			else add(f[i][j], f[i - 1][j], f[i - 1][j - 1]);
	int* g = f[n - 1][k - 1];
	int i = N - 1;
	while (!g[i]) i--;
	while (i >= 0) cout << g[i--];
}

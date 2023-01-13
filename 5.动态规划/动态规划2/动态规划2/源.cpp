#define  _CRT_SECURE_NO_WARNINGS 1
//����DP
//����������
//#include<iostream>
//#include<algorithm>
//using namespace std;
//const int N = 510, INF = 1e9;
//int n;
//int a[N][N];
//int f[N][N];
//int main()
//{
//	cin >> n;
//	for (int i = 1;i <= n;i++)
//		for (int j = 1;j <= i;j++)
//			cin >> a[i][j];
//	for (int i = 0;i <= n;i++)
//		for (int j = 0;j <= i + 1;j++)
//			f[i][j] = -INF;
//	f[1][1] = a[1][1];
//	for (int i = 2;i <= n;i++)
//		for (int j = 1;j <= i;j++)
//			f[i][j] = max(f[i - 1][j - 1] + a[i][j], f[i - 1][j] + a[i][j]);
//	int res = -INF;
//	for (int i = 1;i <= n;i++) res = max(res, f[n][i]);
//	cout << res << endl;
//}





//�����������
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1010;
int n;
int a[N], f[N];
int main()
{
	cin >> n;
	for (int i = 1;i <= n;i++) cin >> a[i];
	for (int i = 1;i <= n;i++)
	{
		f[i] = 1;
		for (int j = 1;j <= i;j++)
			if (a[j] < a[i])
				f[i] = max(f[i], f[j] + 1);
	}
	int res = 0;
	for (int i = 1;i <= n;i++) res = max(res, f[i]);
	cout << res << endl;
}





//�����������
//������巽��
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1010;
int n;
int a[N], f[N], g[N];
int main()
{
	cin >> n;
	for (int i = 1;i <= n;i++) cin >> a[i];
	for (int i = 1;i <= n;i++)
	{
		f[i] = 1;
		g[i] = 0;
		for (int j = 1;j <= i;j++)
			if (a[j] < a[i])
				if (f[i] < f[j] + 1)
				{
					f[i] = f[j] + 1;
					g[i] = j;
				}
	}
	int k = 1;
	for (int i = 1;i <= n;i++)
		if (f[k] < f[i])
			k = i;
	cout << f[k] << endl;
	for (int i = 0, len = f[k];i < len;i++)
	{
		cout << a[k];
		k = g[k];
	}
	return 0;
}





//����������� II
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 100010;
int n;
int a[N], q[N];
int main()
{
	cin >> n;
	for (int i = 0;i < n;i++) cin >> a[i];
	int len = 0;
	q[0] = -2e9;
	for (int i = 0;i < n;i++)
	{
		int l = 0, r = len;
		while (l < r)
		{
			int mid = l + r + 1 >> 1;
			if (q[mid] < a[i]) l = mid;
			else r = mid - 1;
		}
		len = max(len, r + 1);
		q[r + 1] = a[i];
	}
	cout << len;
}









//�����������

//#include<iostream>
//#include<algorithm>
//using namespace std;
//const int N = 1010;
//int n, m;
//char a[N], b[N];
//int f[N][N];
//int main()
//{
//	cin >> n >> m;
//	cin >> a + 1 >> b + 1;
//	for(int i=1;i<=n;i++)
//		for (int j = 1;j <= m;j++)
//		{
//			f[i][j] = max(f[i - 1][j], f[i][j - 1]);
//			if (a[i] == b[j]) f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
//		}
//	cout << f[n][m];
//}



//ʯ�Ӻϲ�
//#include<iostream>
//#include<algorithm>
//using namespace std;
//const int N = 310;
//int n;
//int s[N];
//int f[N][N];
//int main()
//{
//	cin >> n;
//	for (int i = 1;i <= n;i++) cin >> s[i];
//	for (int i = 1;i <= n;i++) s[i] += s[i - 1];
//	for (int len = 2;len <= n;len++) //���䳤�ȴ�2��ʼö��
//		for (int i = 1;i + len - 1 <= n;i++)//ö�ٶ˵�
//		{
//			int l = i, r = i + len - 1;
//			f[l][r] = 1e8;
//			for (int k = l;k < r;k++)
//				f[l][r] = min(f[l][r], f[l][k] + f[k + 1][r] + s[r] - s[l - 1]);
//		}
//	cout << f[1][n] << endl;
//}





//��̱༭����
//#include<iostream>
//#include<algorithm>
//using namespace std;
//const int N = 1010;
//int n, m;
//char a[N], b[N];
//int f[N][N];
//int main()
//{
//	cin >> n >> a + 1 >> m >> b + 1;
//	for (int i = 0;i <= m;i++) f[0][i] = i;
//	for (int i = 0;i <= n;i++) f[i][0] = i;
//	for(int i=1;i<=n;i++)
//		for (int j = 1;j <= m;j++)
//		{
//			f[i][j] = min(f[i - 1][j] + 1, f[i][j - 1] + 1);
//			if (a[i] == b[j]) f[i][j] = min(f[i][j], f[i - 1][j - 1]);
//			else f[i][j] = min(f[i][j], f[i - 1][j - 1] + 1);
//		}
//	cout << f[n][m];
//}



//�༭����
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
const int N = 15, M = 1010;
int n, m;
int f[N][N];
char str[M][M];
int edit_distance(char a[], char b[])
{
	int la = strlen(a + 1), lb = strlen(b + 1);
	for (int i = 0;i <= lb;i++) f[0][i] = i;
	for (int i = 0;i <= la;i++) f[i][0] = i;
	for(int i=1;i<=la;i++)
		for (int j = 1;j <= lb;j++)
		{
			f[i][j] = min(f[i - 1][j] + 1, f[i][j - 1] + 1);
			f[i][j] = min(f[i][j], f[i - 1][j - 1] + (a[i] != b[j]));
		}
	return f[la][lb];
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0;i < n;i++) scanf("%s", str[i] + 1);
	while (m--)
	{
		char s[N];
		int limit;
		scanf("%s%d", s + 1, &limit);
		int res = 0;
		for (int i = 0;i < n;i++)
			if (edit_distance(str[i], s) <= limit)
				res++;
		printf("%d\n", res);
	}
}





//������DP
//��������--�ⷨ1
//f[i][j] = f[i-1][j] + f[i-1][j-i] + f[i-1][j-2i] + ... + f[i-1][j-si];
//f[i][j-i] =           f[i-1][j-i] + f[i-1][j-2i] + ... + f[i-1][j-si];
//f[i][j] = f[i-1][j] + f[i][[j-i]
//f[j] = f[j]+f[j-i];
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1010, mod = 1e9 + 7;
int n;
int f[N];
int main()
{
	cin >> n;
	f[0] = 1;
	for (int i = 1;i <= n;i++)
		for (int j = i;j <= n;j++)
			f[j] = (f[j] + f[j - 1]) % mod;
	cout << f[n] << endl;
	return 0;
}



//�ⷨ2
//f[i][j]��ʾ�ܺ�Ϊi,�ܸ���Ϊj�ķ�����
//f[i][j] = f[i-1][j-1] + f[i-j][j]//��Сֵ��1������Сֵ����1--����ȥ1�����i-j
//ans = f[n][1] + f[n][2] + ... + f[n][n]
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1010, mod = 1e9 + 7;
int n;
int f[N][N];
int main()
{
	cin >> n;
	f[1][1] = 1;
	for (int i = 2;i <= n;i++)
		for (int j = 1;j <= i;j++)
			f[i][j] = (f[i - 1][j - 1] + f[i - j][j]) % mod;
	int res = 0;
	for (int i = 1;i <= n;i++) res = (res + f[n][i]) % mod;
	cout << res << endl;
}
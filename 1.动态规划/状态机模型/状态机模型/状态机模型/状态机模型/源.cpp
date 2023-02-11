#define  _CRT_SECURE_NO_WARNINGS 1
//´óµÁ°¢¸£
//#include<iostream>
//#include<algorithm>
//#include<cstring>
//using namespace std;
//const int N = 100010, INF = 0x3f3f3f3f;
//int n;
//int w[N], f[N][2];
//int main()
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		cin >> n;
//		for (int i = 1;i <= n;i++) cin >> w[i];
//		f[0][0] = 0,f[0][1] = -INF;
//		for (int i = 1;i <= n;i++)
//		{
//			f[i][0] = max(f[i - 1][0], f[i - 1][1]);
//			f[i][1] = f[i - 1][0] + w[i];
//		}
//		cout << max(f[n][0], f[n][1]) << endl;
//	}
//	return 0;
//}





//¹ÉÆ±ÂòÂô IV
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//const int N = 100010, M = 110, INF = 0x3f3f3f3f;
//int n, m;
//int w[N];
//int f[N][M][2];
//int main()
//{
//	cin >> n >> m;
//	for (int i = 1;i <= n;i++) cin >> w[i];
//	memset(f, -0x3f, sizeof f);
//	for (int i = 0;i <= n;i++) f[i][0][0] = 0;
//	for(int i = 1;i <= n;i++)
//		for (int j = 1;j <= m;j++)
//		{
//			f[i][j][0] = max(f[i - 1][j][0], f[i - 1][j][1] + w[i]);
//			f[i][j][1] = max(f[i - 1][j][1], f[i - 1][j - 1][0] - w[i]);
//		}
//	int res = 0;
//	for (int i = 0;i <= m;i++) res = max(res, f[n][i][0]);
//	cout << res << endl;
//	return 0;
//}





//¹ÉÆ±ÂòÂô V
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//const int N = 100010, INF = 0x3f3f3f3f;
//int n;
//int w[N];
//int f[N][3];
//int main()
//{
//	cin >> n;
//	for (int i = 1;i <= n;i++) cin >> w[i];
//	f[0][0] = f[0][1] = -INF;
//	f[0][2] = 0;
//	for (int i = 1;i <= n;i++)
//	{
//		f[i][0] = max(f[i - 1][0], f[i - 1][2] - w[i]);
//		f[i][1] = f[i - 1][0] + w[i];
//		f[i][2] = max(f[i - 1][2], f[i - 1][1]);
//	}
//	cout << max(f[n][1], f[n][2]) << endl;
//	return 0;
//}





//Éè¼ÆÃÜÂë
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 55, mod = 1e9 + 7;
int n, m;
char str[N];
int f[N][N];
int main()
{
	cin >> n >> str + 1;
	m = strlen(str + 1);
	int next[N] = { 0 };
	for (int i = 2, j = 0;i <= n;i++)
	{
		while(j && str[i] != str[j + 1]) j = next[j];
		if (str[i] == str[j + 1]) j++;
		next[i] = j;
	}
	f[0][0] = 1;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			for(char k = 'a';k <= 'z';k++)
			{
				int u = j;
				while (u && k != str[u + 1]) u = next[u];
				if (k == str[u + 1]) u++;
				if (u < m) f[i + 1][u] = (f[i + 1][u] + f[i][j]) % mod;
			}
	int res = 0;
	for (int i = 0;i < m;i++) res = (res + f[n][i]) % mod;
	cout << res << endl;
	return 0;
}























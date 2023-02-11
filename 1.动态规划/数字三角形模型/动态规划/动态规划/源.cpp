#define  _CRT_SECURE_NO_WARNINGS 1

//摘花生
//#include<iostream>
//#include<algorithm>
//#include<cstring>
//using namespace std;
//const int N = 110;
//int n, m;
//int w[N][N], f[N][N];
//int main()
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		cin >> n >> m;
//		for (int i = 1;i <= n;i++)
//			for (int j = 1;j <= m;j++)
//				cin >> w[i][j];
//		for (int i = 1;i <= n;i++)
//			for (int j = 1;j <= m;j++)
//				f[i][j] = max(f[i - 1][j], f[i][j - 1]) + w[i][j];
//		cout << f[n][m] << endl;
//	}
//	return 0;
//}



//最低通行费
//#include<iostream>
//#include<algorithm>
//using namespace std;
//const int N = 110, INF = 1e9;
//int n;
//int w[N][N], f[N][N];
//int main()
//{
//	cin >> n;
//	for (int i = 1;i <= n;i++)
//		for (int j = 1;j <= n;j++)
//			cin >> w[i][j];
//	for (int i = 1;i <= n;i++)
//		for (int j = 1;j <= n;j++)
//		{
//			if (i == 1 && j == 1) f[i][j] = w[i][j];
//			else
//			{
//				f[i][j] = INF;
//				if (i > 1) f[i][j] = min(f[i][j],f[i - 1][j] + w[i][j]);
//				if (j > 1) f[i][j] = min(f[i][j], f[i][j - 1] + w[i][j]);
//			}
//		}
//	cout << f[n][n] << endl;
//	return 0;
//}




//方格取数
//#include<iostream>
//#include<algorithm>
//using namespace std;
//const int N = 15;
//int n;
//int w[N][N];
//int f[N + N][N][N];
//int main()
//{
//	cin >> n;
//	int a, b, c;
//	while (cin >> a >> b >> c, a || b || c) w[a][b] = c;
//	for(int k=2;k<=n+n;k++)
//		for(int i1=1;i1<=n;i1++)
//			for (int i2 = 1;i2 <= n;i2++)
//			{
//				int j1 = k - i1, j2 = k - i2;
//				if (j1 >= 1 && j1 <= n && j2 >= 1 && j2 <= n)
//				{
//					int t = w[i1][j1];
//					if (i1 != i2) t += w[i2][j2];
//					int& x = f[k][i1][i2];
//					x = max(x, f[k - 1][i1 - 1][i2 - 1] + t);
//					x = max(x, f[k - 1][i1 - 1][i2] + t);
//					x = max(x, f[k - 1][i1][i2 - 1] + t);
//					x = max(x, f[k - 1][i1][i2] + t);
//				}
//			}
//	cout << f[n + n][n][n] << endl;
//	return 0;
//}



//传纸条
//#include<iostream>
//#include<algorithm>
//using namespace std;
//const int N = 55;
//int n,m;
//int w[N][N];
//int f[N + N][N][N];
//int main()
//{
//	cin >> n >> m;
//	for (int i = 1;i <= n;i++)
//		for (int j = 1;j <= m;j++)
//			cin >> w[i][j];
//	for(int k = 2;k <= n+m;k++)
//		for(int i1 = max(1,k - m);i1 <= min(k - 1,n);i1++)
//			for (int i2 = max(1, k - m);i2 <= min(k - 1, n);i2++)
//			{
//				int j1 = k - i1, j2 = k - i2;
//				int t = w[i1][j1];
//				if (i1 != i2) t += w[i2][j2];
//				for (int a = 0;a <= 1;a++)
//					for (int b = 0;b <= 1;b++)
//						f[k][i1][i2] = max(f[k][i1][i2], f[k - 1][i1 - a][i2 - b] + t);
//			}
//	cout << f[n + m][n][n] << endl;
//	return 0;
//}
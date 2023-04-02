#define  _CRT_SECURE_NO_WARNINGS 1
// 移棋子游戏
//#include<iostream>
//#include<set>
//#include<algorithm>
//#include<cstring>
//using namespace std;
//const int N = 2010, M = 6010;
//int n, m, k;
//int h[N], e[M], ne[M], idx;
//int f[N];
//void add(int a, int b)
//{
//	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
//}
//int sg(int u)
//{
//	if (f[u] != -1) return f[u];
//	set<int>S;
//	for (int i = h[u];~i;i = ne[i])
//	{
//		int j = e[i];
//		S.insert(sg(j));
//	}
//	for (int i = 0;;i++)
//		if (S.count(i) == 0)
//		{
//			f[u] = i;
//			break;
//		}
//	return f[u];
//}
//int main()
//{
//	cin >> n >> m >> k;
//	memset(h, -1, sizeof h);
//	for (int i = 0;i < m;i++)
//	{
//		int a, b;
//		cin >> a >> b;
//		add(a, b);
//	}
//	memset(f, -1, sizeof f);
//	int res = 0;
//	for (int i = 0;i < k;i++)
//	{
//		int u;
//		cin >> u;
//		res ^= sg(u);
//	}
//	if (res) cout << "win" << endl;
//	else cout << "lose" << endl;
//}




////取石子
//#include<iostream>
//#include<cstring>
//using namespace std;
//const int N = 55, M = 50050;
//int f[N][M];
//int dp(int a, int b)
//{
//	int& v = f[a][b];
//	if (v != -1) return v;
//	if (!a) return v = b % 2;
//	if (b == 1) return dp(a + 1, 0);
//	if (a && !dp(a - 1, b)) return v = 1;
//	if (b && !dp(a, b - 1)) return v = 1;
//	if (a >= 2 && !dp(a - 2, b + (b ? 3 : 2))) return v = 1;
//	if (a && b && !dp(a - 1, b + 1)) return v = 1;
//	return v = 0;
//}
//int main()
//{
//	memset(f, -1, sizeof f);
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		int n;
//		cin >> n;
//		int a = 0, b = 0;
//		for (int i = 0;i < n;i++)
//		{
//			int x;
//			cin >> x;
//			if (x == 1) a++;
//			else b += b ? x + 1 : x;
//		}
//		if (dp(a, b)) puts("YES");
//		else puts("NO");
//	}
//}



//取石子游戏
#include <cstdio>
using namespace std;
const int N = 1010;
int n;
int a[N];
int l[N][N], r[N][N];
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

        for (int len = 1; len <= n; len++)
            for (int i = 1; i + len - 1 <= n; i++)
            {
                int j = i + len - 1;
                if (len == 1) l[i][j] = r[i][j] = a[i];
                else
                {
                    int L = l[i][j - 1], R = r[i][j - 1], X = a[j];
                    if (R == X) l[i][j] = 0;
                    else if (X < L && X < R || X > L && X > R) l[i][j] = X;
                    else if (L > R) l[i][j] = X - 1;
                    else l[i][j] = X + 1;

                    L = l[i + 1][j], R = r[i + 1][j], X = a[i];
                    if (L == X) r[i][j] = 0;
                    else if (X < L && X < R || X > L && X > R) r[i][j] = X;
                    else if (R > L) r[i][j] = X - 1;
                    else r[i][j] = X + 1;
                }
            }
        if (n == 1) puts("1");
        else printf("%d\n", l[2][n] != a[1]);
    }
}
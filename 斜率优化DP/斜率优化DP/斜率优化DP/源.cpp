#define  _CRT_SECURE_NO_WARNINGS 1
//任务安排1
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//typedef long long ll;
//const int N = 5010;
//int n, s;
//int sumt[N], sumc[N];
//ll f[N], q[N];
//int main()
//{
//	cin >> n >> s;
//	for (int i = 1;i <= n;i++)
//	{
//		int t, c;
//		cin >> t >> c;
//		sumt[i] = sumt[i - 1] + t;
//		sumc[i] = sumc[i - 1] + c;
//	}
//	memset(f, 0x3f, sizeof f);
//	f[0] = 0;
//	for (int i = 1;i <= n;i++)
//		for (int j = 0;j < i;j++)
//			f[i] = min(f[i], f[j] + (ll)sumt[i] * (sumc[i] - sumc[j]) + (ll)s * (sumc[n] - sumc[j]));
//	cout << f[n] << endl;
//}





//任务安排2
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//typedef long long ll;
//const int N = 300010;
//int n, s;
//ll c[N], t[N];
//ll f[N];
//int q[N];
//int main()
//{
//	cin >> n >> s;
//	for(int i=1;i<=n;i++)
//	{
//		cin >> t[i] >> c[i];
//		t[i] += t[i - 1];
//		c[i] += c[i - 1];
//	}
//	int hh = 0, tt = 0;
//	q[0] = 0;
//	for (int i = 1;i <= n;i++)
//	{
//		while (hh < tt && (f[q[hh + 1]] - f[q[hh]]) <= (t[i] + s) * (c[q[hh + 1]] - c[q[hh]])) hh++;
//		int j = q[hh];
//		f[i] = f[j] - (t[i] + s) * c[j] + t[i] * c[i] + s * c[n];
//		while (hh < tt && (ll)(f[q[tt]] - f[q[tt - 1]]) * (c[i] - c[q[tt - 1]]) >= (ll)(f[i] - f[q[tt - 1]]) * (c[q[tt]] - c[q[tt - 1]])) tt--;
//		q[++tt] = i;
//	}
//	cout << f[n] << endl;
//}




//任务安排3
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//typedef long long ll;
//const int N = 300010;
//int n, s;
//ll t[N], c[N];
//ll f[N];
//int q[N];
//int main()
//{
//	cin >> n >> s;
//	for (int i = 1;i <= n;i++)
//	{
//		cin >> t[i] >> c[i];
//		t[i] += t[i - 1];
//		c[i] += c[i - 1];
//	}
//	int hh = 0, tt = 0;
//	q[0] = 0;
//    for (int i = 1; i <= n; i++)
//    {
//        int l = hh, r = tt;
//        while (l < r)
//        {
//            int mid = l + r >> 1;
//            if (f[q[mid + 1]] - f[q[mid]] > (t[i] + s) * (c[q[mid + 1]] - c[q[mid]])) r = mid;
//            else l = mid + 1;
//        }
//
//        int j = q[r];
//        f[i] = f[j] - (t[i] + s) * c[j] + t[i] * c[i] + s * c[n];
//        while (hh < tt && (double)(f[q[tt]] - f[q[tt - 1]]) * (c[i] - c[q[tt - 1]]) >= (double)(f[i] - f[q[tt - 1]]) * (c[q[tt]] - c[q[tt - 1]])) tt--;
//        q[++tt] = i;
//    }
//    cout << f[n] << endl;
//}





//运输小猫 
//#include <cstring>
//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//typedef long long LL;
//
//const int N = 100010, M = 100010, P = 110;
//
//int n, m, p;
//LL d[N], t[N], a[N], s[N];
//LL f[P][M];
//int q[M];
//
//LL get_y(int k, int j)
//{
//    return f[j - 1][k] + s[k];
//}
//
//int main()
//{
//    scanf("%d%d%d", &n, &m, &p);
//
//    for (int i = 2; i <= n; i++)
//    {
//        scanf("%lld", &d[i]);
//        d[i] += d[i - 1];
//    }
//
//    for (int i = 1; i <= m; i++)
//    {
//        int h;
//        scanf("%d%lld", &h, &t[i]);
//        a[i] = t[i] - d[h];
//    }
//
//    sort(a + 1, a + m + 1);
//
//    for (int i = 1; i <= m; i++) s[i] = s[i - 1] + a[i];
//
//    memset(f, 0x3f, sizeof f);
//    for (int i = 0; i <= p; i++) f[i][0] = 0;
//
//    for (int j = 1; j <= p; j++)
//    {
//        int hh = 0, tt = 0;
//        q[0] = 0;
//
//        for (int i = 1; i <= m; i++)
//        {
//            while (hh < tt && (get_y(q[hh + 1], j) - get_y(q[hh], j)) <= a[i] * (q[hh + 1] - q[hh])) hh++;
//            int k = q[hh];
//            f[j][i] = f[j - 1][k] - a[i] * k + s[k] + a[i] * i - s[i];
//            while (hh < tt && (get_y(q[tt], j) - get_y(q[tt - 1], j)) * (i - q[tt]) >=
//                (get_y(i, j) - get_y(q[tt], j)) * (q[tt] - q[tt - 1])) tt--;
//            q[++tt] = i;
//        }
//    }
//
//    printf("%lld\n", f[p][m]);
//
//    return 0;
//}
//




//修复DNA
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 1010;
int n, m;
int tr[N][4], dar[N], idx;
int q[N], ne[N];
char str[N];
int f[N][N];
int get(char c)
{
	if (c == 'A') return 0;
	if (c == 'T') return 1;
	if (c == 'G') return 2;
	return 3;
}
void insert()
{
	int p = 0;
	for (int i = 0;str[i];i++)
	{
		int t = get(str[i]);
		if (tr[p][t] == 0) tr[p][t] = ++idx;
		p = tr[p][t];
	}
	dar[p] = 1;
}
void build()
{
	int hh = 0, tt = -1;
	for (int i = 0;i < 4;i++)
	{
		if (tr[0][i])
			q[++tt] = tr[0][i];
	}
	while (hh <= tt)
	{
		int t = q[hh++];
		for (int i = 0;i < 4;i++)
		{
			int p = tr[t][i];
			if (!p) tr[t][i] = tr[ne[t]][i];
			else
			{
				ne[p] = tr[ne[t]][i];
				q[++tt] = p;
				dar[p] |= dar[ne[p]];
			}
		}
	}
}
int main()
{
	int T = 1;
	while (scanf("%d", &n), n)
	{
		memset(tr, 0, sizeof tr);
		memset(dar, 0, sizeof dar);
		memset(ne, 0, sizeof ne);
		idx = 0;

		for (int i = 0; i < n; i++)
		{
			scanf("%s", str);
			insert();
		}

		build();

		scanf("%s", str + 1);
		m = strlen(str + 1);

		memset(f, 0x3f, sizeof f);
		f[0][0] = 0;
		for (int i = 0; i < m; i++)
			for (int j = 0; j <= idx; j++)
				for (int k = 0; k < 4; k++)
				{
					int t = get(str[i + 1]) != k;
					int p = tr[j][k];
					if (!dar[p]) f[i + 1][p] = min(f[i + 1][p], f[i][j] + t);
				}

		int res = 0x3f3f3f3f;
		for (int i = 0; i <= idx; i++) res = min(res, f[m][i]);

		if (res == 0x3f3f3f3f) res = -1;
		printf("Case %d: %d\n", T++, res);
	}

	return 0;
}

//宝藏
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 12, M = 1 << 12, INF = 0x3f3f3f3f;

int n, m;
int d[N][N];
int f[M][N], g[M];

int main()
{
	scanf("%d%d", &n, &m);

	memset(d, 0x3f, sizeof d);
	for (int i = 0; i < n; i++) d[i][i] = 0;

	while (m--)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		a--, b--;
		d[a][b] = d[b][a] = min(d[a][b], c);
	}

	for (int i = 1; i < 1 << n; i++)
		for (int j = 0; j < n; j++)
			if (i >> j & 1)
			{
				for (int k = 0; k < n; k++)
					if (d[j][k] != INF)
						g[i] |= 1 << k;
			}

	memset(f, 0x3f, sizeof f);
	for (int i = 0; i < n; i++) f[1 << i][0] = 0;

	for (int i = 1; i < 1 << n; i++)
		for (int j = (i - 1); j; j = (j - 1) & i)
			if ((g[j] & i) == i)
			{
				int remain = i ^ j;
				int cost = 0;
				for (int k = 0; k < n; k++)
					if (remain >> k & 1)
					{
						int t = INF;
						for (int u = 0; u < n; u++)
							if (j >> u & 1)
								t = min(t, d[k][u]);
						cost += t;
					}

				for (int k = 1; k < n; k++) f[i][k] = min(f[i][k], f[j][k - 1] + cost * k);
			}

	int res = INF;
	for (int i = 0; i < n; i++) res = min(res, f[(1 << n) - 1][i]);

	printf("%d\n", res);
	return 0;
}

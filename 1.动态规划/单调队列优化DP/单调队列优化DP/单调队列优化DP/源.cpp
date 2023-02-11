//
//#define  _CRT_SECURE_NO_WARNINGS 1
////最大子序和
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//const int N = 300010;
//int n, m;
//int s[N], q[N];
//int main()
//{
//	scanf(" %d%d", &n, &m);
//	for (int i = 1;i <= n;i++)
//	{
//		scanf("%d", &s[i]);
//		s[i] += s[i - 1];
//	}
//	int res = -1e9;
//	int hh = 0, tt = 0;
//	for (int i = 1;i <= n;i++)
//	{
//		if (q[hh] < i - m) hh++;
//		res = max(res, s[i] - s[q[hh]]);
//		while (hh <= tt && s[q[tt]] >= s[i]) tt--;
//		q[++tt] = i;
//	}
//	printf("%d\n", res);
//}





//旅行问题
//#include <cstring>
//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//typedef long long LL;
//
//const int N = 2e6 + 10;
//
//int n;
//int oil[N], dist[N];
//LL s[N];
//int q[N];
//bool ans[N];
//
//int main()
//{
//    scanf("%d", &n);
//    for (int i = 1; i <= n; i++)
//    {
//        scanf("%d%d", &oil[i], &dist[i]);
//        s[i] = s[i + n] = oil[i] - dist[i];
//    }
//    for (int i = 1; i <= n * 2; i++) s[i] += s[i - 1];
//
//    int hh = 0, tt = 0;
//    q[0] = n * 2 + 1;
//    for (int i = n * 2; i >= 0; i--)
//    {
//        if (q[hh] > i + n) hh++;
//        if (i < n)
//        {
//            if (s[i] <= s[q[hh]]) ans[i + 1] = true;
//        }
//        while (hh <= tt && s[q[tt]] >= s[i]) tt--;
//        q[++tt] = i;
//    }
//
//    dist[0] = dist[n];
//    for (int i = 1; i <= n; i++) s[i] = s[i + n] = oil[i] - dist[i - 1];
//    for (int i = 1; i <= n * 2; i++) s[i] += s[i - 1];
//
//    hh = 0, tt = 0;
//    q[0] = 0;
//    for (int i = 1; i <= n * 2; i++)
//    {
//        if (q[hh] < i - n) hh++;
//        if (i > n)
//        {
//            if (s[i] >= s[q[hh]]) ans[i - n] = true;
//        }
//        while (hh <= tt && s[q[tt]] <= s[i]) tt--;
//        q[++tt] = i;
//    }
//
//    for (int i = 1; i <= n; i++)
//        if (ans[i]) puts("TAK");
//        else puts("NIE");
//
//    return 0;
//}
//




//烽火传递
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//const int N = 200010;
//int n, m;
//int w[N], f[N], q[N];
//int main()
//{
//	cin >> n >> m;
//	for (int i = 1;i <= n;i++) cin >> w[i];
//	int hh = 0, tt = 0;
//	for (int i = 1;i <= n;i++)
//	{
//		if (q[hh] < i - m) hh++;
//		f[i] = f[q[hh]] + w[i];
//		while (hh <= tt && f[q[tt]] >= f[i]) tt--;
//		q[++tt] = i;
//	}
//	int res = 1e9;
//	for (int i = n - m + 1;i <= n;i++) res = min(res, f[i]);
//	cout << res << endl;
//	return 0;
//}




//绿色通道
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//const int N = 50010;
//int n, m;
//int w[N], q[N], f[N];
//bool check(int limit)
//{
//	int hh = 0, tt = 0;
//	for (int i = 1;i <= n;i++)
//	{
//		if (q[hh] < i - limit - 1) hh++;
//		f[i] = f[q[hh]] + w[i];
//		while (hh <= tt && f[q[tt]] >= f[i]) tt--;
//		q[++tt] = i;
//	}
//	for (int i = n - limit;i <= n;i++)
//		if (f[i] <= m)
//			return true;
//	return false;
//}
//int main()
//{
//	cin >> n >> m;
//	for (int i = 1;i <= n;i++) cin >> w[i];
//	int l = 0, r = n;
//	while (l < r)
//	{
//		int mid = l + r >> 1;
//		if (check(mid)) r = mid;
//		else l = mid + 1;
//	}
//	cout << r << endl;
//}





//修剪草坪
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//typedef long long ll;
//const int N = 1e5 + 10;
//int n, m;
//ll s[N], f[N];
//int q[N];
//ll g(int i)
//{
//	return f[i - 1] - s[i];
//}
//int main()
//{
//	cin >> n >> m;
//	for (int i = 1;i <= n;i++)
//	{
//		cin >> s[i];
//		s[i] += s[i - 1];
//	}
//	int hh = 0, tt = 0;
//	for (int i = 1;i <= n;i++)
//	{
//		if (q[hh] < i - m) hh++;
//		f[i] = max(f[i - 1], g(q[hh]) + s[i]);
//		while (hh <= tt && g(q[tt]) <= g(i)) tt--;
//		q[++tt] = i;
//	}
//	cout << f[n] << endl;
//}




//理想的正方
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010, INF = 1e9;

int n, m, k;
int w[N][N];
int row_min[N][N], row_max[N][N];
int q[N];

void get_min(int a[], int b[], int tot)
{
    int hh = 0, tt = -1;
    for (int i = 1; i <= tot; i++)
    {
        if (hh <= tt && q[hh] <= i - k) hh++;
        while (hh <= tt && a[q[tt]] >= a[i]) tt--;
        q[++tt] = i;
        b[i] = a[q[hh]];
    }
}

void get_max(int a[], int b[], int tot)
{
    int hh = 0, tt = -1;
    for (int i = 1; i <= tot; i++)
    {
        if (hh <= tt && q[hh] <= i - k) hh++;
        while (hh <= tt && a[q[tt]] <= a[i]) tt--;
        q[++tt] = i;
        b[i] = a[q[hh]];
    }
}



int main()
{
    scanf("%d%d%d", &n, &m, &k);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d", &w[i][j]);

    for (int i = 1; i <= n; i++)
    {
        get_min(w[i], row_min[i], m);
        get_max(w[i], row_max[i], m);
    }

    int res = INF;
    int a[N], b[N], c[N];
    for (int i = k; i <= m; i++)
    {
        for (int j = 1; j <= n; j++) a[j] = row_min[j][i];
        get_min(a, b, n);

        for (int j = 1; j <= n; j++) a[j] = row_max[j][i];
        get_max(a, c, n);

        for (int j = k; j <= n; j++) res = min(res, c[j] - b[j]);
    }

    printf("%d\n", res);

    return 0;
}


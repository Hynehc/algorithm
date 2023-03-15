#define  _CRT_SECURE_NO_WARNINGS 1
//铲雪车
//#include<iostream>
//#include<cmath>
//#include<algorithm>
//using namespace std;
//int main()
//{
//	double x1, y1, x2, y2;
//	cin >> x1 >> y1;
//	double sum = 0;
//	while (cin >> x1 >> y1 >> x2 >> y2)
//	{
//		double dx = x1 - x2;
//		double dy = y1 - y2;
//		sum += sqrt(dx * dx + dy * dy) * 2;
//	}
//	int minutes = round(sum / 1000 / 20 * 60);
//	int hours = minutes / 60;
//	minutes %= 60;
//	printf("%d:%02d\n", hours, minutes);
//	return 0;
//}

//欧拉回路
//#include <cstdio>
//#include <cstring>
//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//const int N = 100010, M = 400010;
//
//int type;
//int n, m;
//int h[N], e[M], ne[M], idx;
//bool used[M];
//int ans[M], cnt;
//int din[N], dout[N];
//
//void add(int a, int b)
//{
//    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
//}
//
//void dfs(int u)
//{
//    for (int& i = h[u]; ~i;)
//    {
//        if (used[i])
//        {
//            i = ne[i];
//            continue;
//        }
//
//        used[i] = true;
//        if (type == 1) used[i ^ 1] = true;
//
//        int t;
//
//        if (type == 1)
//        {
//            t = i / 2 + 1;
//            if (i & 1) t = -t;
//        }
//        else t = i + 1;
//
//        int j = e[i];
//        i = ne[i];
//        dfs(j);
//
//        ans[++cnt] = t;
//    }
//}
//
//int main()
//{
//    scanf("%d", &type);
//    scanf("%d%d", &n, &m);
//    memset(h, -1, sizeof h);
//
//    for (int i = 0; i < m; i++)
//    {
//        int a, b;
//        scanf("%d%d", &a, &b);
//        add(a, b);
//        if (type == 1) add(b, a);
//        din[b] ++, dout[a] ++;
//    }
//
//    if (type == 1)
//    {
//        for (int i = 1; i <= n; i++)
//            if (din[i] + dout[i] & 1)
//            {
//                puts("NO");
//                return 0;
//            }
//    }
//    else
//    {
//        for (int i = 1; i <= n; i++)
//            if (din[i] != dout[i])
//            {
//                puts("NO");
//                return 0;
//            }
//    }
//
//    for (int i = 1; i <= n; i++)
//        if (h[i] != -1)
//        {
//            dfs(i);
//            break;
//        }
//
//    if (cnt < m)
//    {
//        puts("NO");
//        return 0;
//    }
//
//    puts("YES");
//    for (int i = cnt; i; i--) printf("%d ", ans[i]);
//    puts("");
//
//    return 0;
//}
//

// 骑马修栅栏
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//const int N = 510;
//int n = 500, m;
//int g[N][N];
//int ans[1100], cnt;
//int d[N];
//void dfs(int u)
//{
//	for (int i = 1;i <= n;i++)
//		if (g[u][i])
//		{
//			g[u][i]--, g[i][u]--;
//			dfs(i);
//		}
//	ans[++cnt] = u;
//}
//int main()
//{
//	cin >> m;
//	while (m--)
//	{
//		int a, b;
//		cin >> a >> b;
//		g[a][b]++, g[b][a]++;
//		d[a]++, d[b]++;
//	}
//	int start = 1;
//	while (!d[start]) start++;
//	for(int i=1;i<=n;i++)
//		if (d[i] % 2)
//		{
//			start = i;
//			break;
//		}
//	dfs(start);
//	for (int i = cnt;i;i--) cout << ans[i] << endl;
//}

//单词游戏
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 30;

int n;
int din[N], dout[N], p[N];
bool st[N];

int find(int x)
{
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main()
{
    char str[1010];

    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        memset(din, 0, sizeof din);
        memset(dout, 0, sizeof dout);
        memset(st, 0, sizeof st);
        for (int i = 0; i < 26; i++) p[i] = i;

        for (int i = 0; i < n; i++)
        {
            scanf("%s", str);
            int len = strlen(str);
            int a = str[0] - 'a', b = str[len - 1] - 'a';
            st[a] = st[b] = true;
            dout[a] ++, din[b] ++;
            p[find(a)] = find(b);
        }

        int start = 0, end = 0;
        bool success = true;
        for (int i = 0; i < 26; i++)
            if (din[i] != dout[i])
            {
                if (din[i] == dout[i] + 1) end++;
                else if (din[i] + 1 == dout[i]) start++;
                else
                {
                    success = false;
                    break;
                }
            }

        if (success && !(!start && !end || start == 1 && end == 1)) success = false;

        int rep = -1;
        for (int i = 0; i < 26; i++)
            if (st[i])
            {
                if (rep == -1) rep = find(i);
                else if (rep != find(i))
                {
                    success = false;
                    break;
                }
            }

        if (success) puts("Ordering is possible.");
        else puts("The door cannot be opened.");
    }

    return 0;
}

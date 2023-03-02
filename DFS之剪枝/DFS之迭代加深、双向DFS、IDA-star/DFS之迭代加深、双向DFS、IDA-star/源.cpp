#define  _CRT_SECURE_NO_WARNINGS 1
//加成序列
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//const int N = 110;
//int n;
//int path[N];
//bool dfs(int u, int depth)//当前  最大
//{
//	if (u > depth) return false;
//	if (path[u - 1] == n) return true;
//	bool st[N] = { 0 };
//	for (int i = u - 1;i >= 0;i--)
//		for (int j = i;j >= 0;j--)
//		{
//			int s = path[i] + path[j];
//			if (s > n || s <= path[u - 1] || st[s]) continue;
//			st[u] = true;
//			path[u] = s;
//			if (dfs(u + 1, depth)) return true;
//		}
//	return false;
//}
//int main()
//{
//	path[0] = 1;
//	while (cin >> n, n)
//	{
//		int depth = 1;
//		while (!dfs(1, depth)) depth++;
//		for (int i = 0;i < depth;i++) cout << path[i] << " ";
//		cout << endl;
//	}
//}





// 送礼物
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//const int N = 46;
//typedef long long ll;
//int n, m, k;
//int w[N];
//int weight[1 << 25], cnt = 1, ans;
//void dfs1(int u, int s)
//{
//	if (u == k)
//	{
//		weight[cnt++] = s;
//		return;
//	}
//	dfs1(u + 1, s);
//	if ((ll)s + w[u] <= m) dfs1(u + 1, s + w[u]);
//} 
//void dfs2(int u, int s)
//{
//	if (u >= n)
//	{
//		int l = 0, r = cnt - 1;
//		while (l < r)
//		{
//			int mid = l + r + 1 >> 1;
//			if (weight[mid] <= m - s) l = mid;
//			else r = mid - 1;
//		}
//		ans = max(ans, weight[l] + s);
//		return;
//	}
//	dfs2(u + 1, s);
//	if ((ll)s + w[u] <= m) dfs2(u + 1, s + w[u]);
//}
//int main()
//{
//	cin >> m >> n;
//	for (int i = 0;i < n;i++) cin >> w[i];
//	sort(w, w + n);
//	reverse(w, w + n);
//	k = n >> 1;
//	dfs1(0, 0);
//	sort(weight, weight + cnt);
//	cnt = unique(weight, weight + cnt) - weight;
//	dfs2(k, 0);
//	cout << ans << endl;
//}






//排书
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//const int N = 15;
//int n;
//int q[N];
//int w[5][N];
//int f()
//{
//	int tot = 0;
//	for (int i = 0;i + 1 < n;i++)
//		if (q[i + 1] != q[i] + 1)
//			tot++;
//	return (tot + 2) / 3;
//}
//bool dfs(int depth, int max_depth)
//{
//	if (depth + f() > max_depth) return false;
//	if (f() == 0) return true;
//	for (int len = 1;len <= n;len++)
//		for (int l = 0;l + len - 1 < n;l++)
//		{
//			int r = l + len - 1;
//			for (int k = r + 1;k < n;k++)
//			{
//				memcpy(w[depth], q, sizeof q);
//				int y = l;
//				for (int x = r + 1;x <= k;x++, y++) q[y] = w[depth][x];
//				for (int x = l;x <= r;x++, y++) q[y] = w[depth][x];
//				if (dfs(depth + 1, max_depth)) return true;
//				memcpy(q, w[depth], sizeof q);
//			}
//		}
//	return false;
//}
//int main()
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		cin >> n;
//		for (int i = 0;i < n;i++) cin >> q[i];
//		int depth = 0;
//		while (depth < 5 && !dfs(0, depth)) depth++;
//		if (depth >= 5) puts("5 or more");
//		else cout << depth << endl;
//	}
//}





//回转游戏
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 24;
int op[8][7] = {
    {0, 2, 6, 11, 15, 20, 22},
    {1, 3, 8, 12, 17, 21, 23},
    {10, 9, 8, 7, 6, 5, 4},
    {19, 18, 17, 16, 15, 14, 13},
    {23, 21, 17, 12, 8, 3, 1},
    {22, 20, 15, 11, 6, 2, 0},
    {13, 14, 15, 16, 17, 18, 19},
    {4, 5, 6, 7, 8, 9, 10}
};
int opposite[8] = { 5,4,7,6,1,0,3,2 };
int center[8] = { 6,7,8,11,12,15,16,17 };
int q[N];
int path[100];
int f()
{
    static int sum[4];
    memset(sum, 0, sizeof sum);
    for (int i = 0;i < 8;i++) sum[q[center[i]]]++;
    int maxv = 0;
    for (int i = 1;i <= 3;i++) maxv = max(maxv, sum[i]);
    return 8 - maxv;
}
void operate(int x)
{
    int t = q[op[x][0]];
    for (int i = 0;i < 6;i++) q[op[x][i]] = q[op[x][i + 1]];
    q[op[x][6]] = t;
}
bool dfs(int depth, int max_depth, int last)
{
    if (depth + f() > max_depth) return false;
    if (f() == 0) return true;
    for (int i = 0;i < 8;i++)
        if (last != opposite[i])
        {
            operate(i);
            path[depth] = i;
            if (dfs(depth + 1, max_depth, i)) return true;
            operate(opposite[i]);
        }
    return false;
}
int main()
{
    while (cin >> q[0], q[0])
    {
        for (int i = 1;i < 24;i++) cin >> q[i];
        int depth = 0;
        while (!dfs(0, depth, -1)) depth++;
        if(!depth) printf("No moves needed");
        else
        {
            for (int i = 0;i < depth;i++) printf("%c", 'A' + path[i]);
        }
        printf("\n%d\n", q[6]);
    }
}
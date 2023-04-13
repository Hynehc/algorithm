#define  _CRT_SECURE_NO_WARNINGS 1
////七夕祭
//#include<iostream>
//#include<algorithm>
//#include<cstring>
//using namespace std;
//const int N = 100010;
//typedef long long ll;
//int row[N], col[N], s[N], c[N];
//ll work(int n, int a[])
//{
//	for (int i = 1;i <= n;i++) s[i] = s[i - 1] + a[i];
//	if (s[n] % n) return -1;
//	int avg = s[n] / n;
//	c[1] = 0;
//	for (int i = 2;i <= n;i++) c[i] = s[i - 1] - (i - 1) * avg;
//	sort(c + 1, c + n + 1);
//	ll res = 0;
//	for (int i = 1;i <= n;i++) res += abs(c[i] - c[(n + 1) / 2]);
//	return res;
//}
//int main()
//{
//    int n, m, cnt;
//    scanf("%d%d%d", &n, &m, &cnt);
//
//    while (cnt--)
//    {
//        int x, y;
//        scanf("%d%d", &x, &y);
//        row[x] ++, col[y] ++;
//    }
//
//    ll r = work(n, row);
//    ll c = work(m, col);
//
//    if (r != -1 && c != -1) printf("both %lld\n", r + c);
//    else if (r != -1) printf("row %lld\n", r);
//    else if (c != -1) printf("column %lld\n", c);
//    else printf("impossible\n");
//
//    return 0;
//}



//动态中位数
//#include<iostream>
//#include <cstring>
//#include <algorithm>
//#include <queue>
//using namespace std;
//int main()
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		int n, m;
//		cin >> m >> n;
//		cout << m << " " << (n + 1) / 2 << endl;
//		priority_queue<int>down;
//		priority_queue<int, vector<int>, greater<int>>up;
//		int cnt = 0;
//		for (int i = 1;i <= n;i++)
//		{
//			int x;
//			cin >> x;
//			if (down.empty() || x <= down.top()) down.push(x);
//			else up.push(x);
//			if (down.size() > up.size() + 1) up.push(down.top()), down.pop();
//			if (up.size() > down.size()) down.push(up.top()), up.pop();
//			if (i % 2)
//			{
//				cout << down.top() << " ";
//				if (++cnt % 10 == 0) cout << endl;
//			}
//		}
//		if (cnt % 10) cout << endl;
//	}
//}


//
////超快速排序
//#include<iostream>
//using namespace std;
//const int N = 500010;
//int n;
//typedef long long ll;
//ll q[N], w[N];
//ll merge_sort(int l, int r)
//{
//	if (l == r) return 0;
//	int mid = l + r >> 1;
//	ll res = merge_sort(l, mid) + merge_sort(mid + 1, r);
//	int i = l, j = mid + 1, k = 0;
//	while (i <= mid && j <= r)
//		if (q[i] <= q[j]) w[k++] = q[i++];
//		else
//		{
//			res += mid - i + 1;
//			w[k++] = q[j++];
//		}
//	while (i <= mid) w[k++] = q[i++];
//	while (j <= r) w[k++] = q[j++];
//	for (i = l, j = 0;i <= r;i++, j++) q[i] = w[j];
//	return res;
//}
//int main()
//{
//	while (scanf("%d", &n), n)
//	{
//		for (int i = 0; i < n; i++) scanf("%d", &q[i]);
//
//		printf("%lld\n", merge_sort(0, n - 1));
//	}
//
//	return 0;
//}


//天才的记忆
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
const int N = 200010, M = 18;
int n, m;
int w[N];
int f[N][M];
void init()
{
	for (int j = 0;j < M;j++)
		for (int i = 1;i + (1 << j) - 1 <= n;i++)
			if (!j) f[i][j] = w[i];
			else f[i][j] = max(f[i][j - 1], f[i + (1 << j - 1)][j - 1]);
}
int query(int l, int r)
{
	int len = r - l + 1;
	int k = log(len) / log(2);
	return max(f[l][k], f[r - (1 << k) + 1][k]);
}
int main()
{
	cin >> n;
	for (int i = 1;i <= n;i++) cin >> w[i];
	init();
	cin >> m;
	while (m--)
	{
		int l, r;
		cin >> l >> r;
		cout << query(l, r) << endl;
	}
}

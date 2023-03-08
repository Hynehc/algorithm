#define  _CRT_SECURE_NO_WARNINGS 1
//糖果
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//typedef long long ll;
//const int N = 100010, M = 300010;
//int n, m;
//int h[N], e[M], ne[M], w[M], idx;
//ll dist[N];
//int q[N], cnt[N];
//bool st[N];
//void add(int a, int b, int c)
//{
//	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
//}
//bool spfa()
//{
//	int hh = 0, tt = 1;
//	memset(dist, -0x3f, sizeof dist);
//	dist[0] = 0;
//	q[0] = 0;
//	st[0] = true;
//	while (hh != tt)
//	{
//		int t = q[--tt];
//		st[t] = false;
//		for (int i = h[t];~i;i = ne[i])
//		{
//			int j = e[i];
//			if (dist[j] < dist[t] + w[i])
//			{
//				dist[j] = dist[t] + w[i];
//				cnt[j] = cnt[t] + 1;
//				if (cnt[j] >= n + 1) return false;
//				if (!st[j])
//				{
//					q[tt++] = j;
//					st[j] = true;
//				}
//			}
//		}
//	}
//	return true;
//}
//int main()
//{
//	cin >> n >> m;
//	memset(h, -1, sizeof h);
//	while (m--)
//	{
//		int x, a, b;
//		cin >> x >> a >> b;
//		if (x == 1) add(b, a, 0), add(a, b, 0);
//		else if (x == 2) add(a, b, 1);
//		else if (x == 3) add(b, a, 0);
//		else if (x == 4) add(b, a, 1);
//		else add(a, b, 0);
//	}
//	for (int i = 1;i <= n;i++) add(0, i, 1);
//	if (!spfa()) puts("-1");
//	else
//	{
//		ll res = 0;
//		for (int i = 1;i <= n;i++) res += dist[i];
//		cout << res << "\n";
//	}
//}






//区间
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//const int N = 50010, M = N * 3 + 10;
//int n;
//int h[N], e[M], ne[M], w[M], idx;
//int dist[N];
//int q[N];
//bool st[N];
//void add(int a, int b, int c)
//{
//	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
//}
//void spfa()
//{
//	int hh = 0, tt = 1;
//	memset(dist, -0x3f, sizeof dist);
//	dist[0] = 0;
//	q[0] = 0;
//	st[0] = true;
//	while (hh != tt)
//	{
//		int t = q[hh++];
//		if (hh == N) hh = 0;
//		st[t] = false;
//		for (int i = h[t];~i;i = ne[i])
//		{
//			int j = e[i];
//			if (dist[j] < dist[t] + w[i])
//			{
//				dist[j] = dist[t] + w[i];
//				if (!st[j])
//				{
//					q[tt++] = j;
//					if (tt == N) tt = 0;
//					st[j] = true;
//				}
//			}
//		}
//	}
//}
//int main()
//{
//	cin >> n;
//	memset(h, -1, sizeof h);
//	for (int i = 1;i < N;i++)
//	{
//		add(i - 1, i, 0);
//		add(i, i - 1, -1);
//	}
//	while (n--)
//	{
//		int a, b, c;
//		cin >> a >> b >> c;
//		a++, b++;
//		add(a - 1, b, c);
//	}
//	spfa();
//	cout << dist[50001] << endl;
//}





//排队布局
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//const int N = 1010, M = 21010, INF = 0x3f3f3f3f;
//int n, m1, m2;
//int h[N], e[M], w[M], ne[M], idx;
//int dist[N];
//int q[N], cnt[N];
//bool st[N];
//void add(int a, int b, int c)
//{
//	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
//}
//bool spfa(int size)
//{
//	memset(dist, 0x3f, sizeof dist);
//	memset(cnt, 0, sizeof cnt);
//	memset(st, 0, sizeof st);
//	int hh = 0, tt = 0;
//	for (int i = 1;i <= size;i++)
//	{
//		dist[i] = 0;
//		q[tt++] = i;
//		st[i] = true;
//	}
//	while (hh != tt)
//	{
//		int t = q[hh++];
//		if (hh == N) hh = 0;
//		st[t] = false;
//		for (int i = h[t];~i;i = ne[i])
//		{
//			int j = e[i];
//			if (dist[j] > dist[t] + w[i])
//			{
//				dist[j] = dist[t] + w[i];
//				cnt[j] = cnt[t] + 1;
//				if (cnt[j] >= n) return true;
//				if (!st[j])
//				{
//					q[tt++] = j;
//					if (tt == N) tt = 0;
//					st[j] = true;
//				}
//			}
//		}
//	}
//	return false;
//}
//int main()
//{
//	cin >> n >> m1 >> m2;
//	memset(h, -1, sizeof h);
//	for (int i = 1;i < n;i++) add(i + 1, i, 0);
//	while (m1--)
//	{
//		int a, b, c;
//		cin >> a >> b >> c;
//		if (b < a) swap(a, b);
//		add(a, b, c);
//	}
//	while (m2--)
//	{
//		int a, b, c;
//		cin >> a >> b >> c;
//		if (b < a) swap(b, a);
//		add(b, a, -c);
//	}
//	if (spfa(n)) puts("-1");
//	else
//	{
//		spfa(1);
//		if (dist[n] == INF) puts("-2");
//		else cout << dist[n] << endl;
//	}
//}



//雇佣收银员
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 30, M = 100;
int n;
int h[N], e[M], ne[M], w[M], idx;
int r[N], num[N];
int dist[N];
int q[N], cnt[N];
bool st[N];
void add(int a, int b, int c)
{
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}
void build(int c)
{
	memset(h, -1, sizeof h);
	idx = 0;
	for (int i = 1;i <= 24;i++)
	{
		add(i - 1, i, 0);
		add(i, i - 1, -num[i]);
	}
	for (int i = 8;i <= 24;i++) add(i - 8, i, r[i]);
	for (int i = 1;i <= 7;i++) add(i + 16, i, -c + r[i]);
	add(0, 24, c), add(24, 0, -c);
}
bool spfa(int c)
{
	build(c);
	memset(dist, -0x3f, sizeof dist);
	memset(cnt, 0, sizeof cnt);
	memset(st, 0, sizeof st);
	dist[0] = 0;
	int hh = 0, tt = 1;
	q[0] = 0;
	st[0] = true;
	while (hh != tt)
	{
		int t = q[hh++];
		if (hh == N) hh = 0;
		st[t] = false;
		for (int i = h[t];~i;i = ne[i])
		{
			int j = e[i];
			if (dist[j] < dist[t] + w[i])
			{
				dist[j] = dist[t] + w[i];
				cnt[j] = cnt[t] + 1;
				if (cnt[j] >= 25) return false;
				if (!st[j])
				{
					q[tt++] = j;
					if (tt == N) tt = 0;
					st[j] = true;
				}
			}
		}
	}
	return true;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		for (int i = 1;i <= 24;i++) cin >> r[i];
		cin >> n;
		memset(num, 0, sizeof num);
		for (int i = 0;i < n;i++)
		{
			int t;
			cin >> t;
			num[t + 1]++;
		}
		bool s = false;
		for(int i=0;i<=1000;i++)
			if (spfa(i))
			{
				cout << i << endl;
				s = true;
				break;
			}
		if (!s) cout << "No Solution" << endl;
	}
}
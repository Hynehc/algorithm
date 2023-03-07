#define  _CRT_SECURE_NO_WARNINGS 1
//�涴
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//const int N = 510, M = 5210;
//int n, m1, m2;
//int h[N], e[M], w[M], ne[M], idx;
//int dist[N];
//int q[N], cnt[N];
//bool st[N];
//void add(int a, int b, int c)
//{
//	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
//}
//bool spfa()
//{
//	int hh = 0, tt = 0;
//	memset(dist, 0, sizeof dist);
//	memset(st, 0, sizeof st);
//	memset(cnt, 0, sizeof cnt);
//	for (int i = 1;i <= n;i++)
//	{
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
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		cin >> n >> m1 >> m2;
//		memset(h, -1, sizeof h);
//		idx = 0;
//		while (m1--)
//		{
//			int a, b, c;
//			cin >> a >> b >> c;
//			add(a, b, c), add(b, a, c);
//		}
//		while (m2--)
//		{
//			int a, b, c;
//			cin >> a >> b >> c;
//			add(a, b, -c);
//		}
//		if (spfa()) cout << "YES" << "\n";
//		else cout << "NO" << "\n";
//	}
//	return 0;
//}





//�۹���ţ
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//const int N = 1010, M = 5010;
//int n, m;
//int wf[N];
//int h[N], e[M], wt[M], ne[M], idx;
//double dist[N];
//int q[N], cnt[N];
//bool st[N];
//void add(int a, int b, int c)
//{
//	e[idx] = b, wt[idx] = c, ne[idx] = h[a], h[a] = idx++;
//}
//bool check(double mid)
//{
//	memset(st, 0, sizeof st);
//	memset(cnt, 0, sizeof cnt);
//	int hh = 0, tt = 0;
//	for (int i = 1;i <= n;i++)
//	{
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
//			if (dist[j] < dist[t] + wf[t] - mid * wt[i])
//			{
//				dist[j] = dist[t] + wf[t] - mid * wt[i];
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
//	cin >> n >> m;
//	memset(h, -1, sizeof h);
//	for (int i = 1;i <= n;i++) cin >> wf[i];
//	while (m--)
//	{
//		int a, b, c;
//		cin >> a >> b >> c;
//		add(a, b, c);
//	}
//	double l = 0, r = 1010;
//	while (r - l > 1e-4)
//	{
//		double mid = (l + r) / 2;
//		if (check(mid)) l = mid;
//		else r = mid;
//	}
//	printf("%.2lf\n", r);
//}







//���ʻ�
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 700, M = 100010;
int n;
int h[N], e[M], w[M], ne[M], idx;
double dist[N];
int q[N], cnt[N];
bool st[N];
void add(int a, int b, int c)
{
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}
bool check(double mid)
{
	memset(st, 0, sizeof st);
	memset(cnt, 0, sizeof cnt);
	int hh = 0, tt = 0;
	for (int i = 0;i < 676;i++)
	{
		q[tt++] = i;
		st[i] = true;
	}
	int count = 0;
	while (hh != tt)
	{
		int t = q[hh++];
		if (hh == N) hh = 0;
		st[t] = false;
		for (int i = h[t];~i;i = ne[i])
		{
			int j = e[i];
			if (dist[j] < dist[t] + w[i] - mid)
			{
				dist[j] = dist[t] + w[i] - mid;
				cnt[j] = cnt[t] + 1;
				if (++count > 10000) return true;
				if (cnt[j] >= N) return true;
				if (!st[j])
				{
					q[tt++] = j;
					if (tt == N) tt = 0;
					st[j] = true;
				}
			}
		}
	}
	return false;
}
int main()
{
	char str[1010];
	while (scanf("%d", &n), n)
	{
		memset(h, -1, sizeof h);
		idx = 0;
		for (int i = 0;i < n;i++)
		{
			scanf("%s", str);
			int len = strlen(str);
			if (len >= 2)
			{
				int left = (str[0] - 'a') * 26 + str[1] - 'a';
				int right = (str[len - 2] - 'a') * 26 + str[len - 1] - 'a';
				add(left, right, len);
			}
		}
		if (!check(0)) puts("No solution");
		else
		{
			double l = 0, r = 1000;
			while (r - l > 1e-4)
			{
				double mid = (l + r) / 2;
				if (check(mid)) l = mid;
				else r = mid;
			}
			printf("%lf\n", r);
		}
	}
}
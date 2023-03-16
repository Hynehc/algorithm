#define  _CRT_SECURE_NO_WARNINGS 1
//家谱树
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//const int N = 110, M = N * N / 2;
//int n;
//int h[N], e[M], ne[M], idx;
//int q[N];
//int d[N];
//void add(int a, int b)
//{
//	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
//}
//void topsort()
//{
//	int hh = 0, tt = -1;
//	for (int i = 1;i <= n;i++)
//		if (!d[i])
//			q[++tt] = i;
//	while (hh <= tt)
//	{
//		int t = q[hh++];
//		for (int i = h[t];~i;i = ne[i])
//		{
//			int j = e[i];
//			if (--d[j] == 0)
//				q[++tt] = j;
//		}
//	}
//}
//int main()
//{
//	cin >> n;
//	memset(h, -1, sizeof h);
//	for (int i = 1;i <= n;i++)
//	{
//		int son;
//		while (cin >> son, son)
//		{
//			add(i, son);
//			d[son]++;
//		}
//	}
//	topsort();
//	for (int i = 0;i < n;i++)
//		cout << q[i] << " ";
//}
//

//奖金
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//const int N = 10010, M = 20010;
//int n, m;
//int h[N], e[M], ne[M], idx;
//int q[N];
//int d[N];
//int dist[N];
//void add(int a, int b)
//{
//	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
//}
//bool topsort()
//{
//	int hh = 0, tt = -1;
//	for (int i = 1;i <= n;i++)
//		if (!d[i])
//			q[++tt] = i;
//	while (hh <= tt)
//	{
//		int t = q[hh++];
//		for (int i = h[t];~i;i = ne[i])
//		{
//			int j = e[i];
//			if (--d[j] == 0)
//				q[++tt] = j;
//		}
//	}
//	return tt == n - 1;
//}
//int main()
//{
//	cin >> n >> m;
//	memset(h, -1, sizeof h);
//	while (m--)
//	{
//		int a, b;
//		cin >> a >> b;
//		add(b, a);
//		d[a]++;
//	}
//	if (!topsort()) puts("Poor Xed");
//	else
//	{
//		for (int i = 1;i <= n;i++) dist[i] = 100;
//		for (int i = 0;i < n;i++)
//		{
//			int j = q[i];
//			for (int k = h[j];~k;k = ne[k])
//				dist[e[k]] = max(dist[e[k]], dist[j] + 1);
//		}
//		int res = 0;
//		for (int i = 1;i <= n;i++) res += dist[i];
//		cout << res << endl;
//	}
//}





//可达性统计
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<bitset>
//using namespace std;
//const int N = 30010, M = 30010;
//int n, m;
//int h[N], e[M], ne[M], idx;
//int d[N], q[N];
//bitset<N>f[N];
//void add(int a, int b)
//{
//	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
//}
//void topsort()
//{
//	int hh = 0, tt = -1;
//	for (int i = 1;i <= n;i++)
//		if (!d[i])
//			q[++tt] = i;
//	while (hh <= tt)
//	{
//		int t = q[hh++];
//		for (int i = h[t];~i;i = ne[i])
//		{
//			int j = e[i];
//			if (--d[j] == 0)
//				q[++tt] = j;
//		}
//	}
//}
//int main()
//{
//	cin >> n >> m;
//	memset(h, -1, sizeof h);
//	for (int i = 0;i < m;i++)
//	{
//		int a, b;
//		cin >> a >> b;
//		add(a, b);
//		d[b]++;
//	}
//	topsort();
//	for (int i = n - 1;i >= 0;i--)
//	{
//		int j = q[i];
//		f[j][j] = 1;
//		for (int k = h[j];~k;k = ne[k])
//			f[j] |= f[e[k]];
//	}
//	for (int i = 1;i <= n;i++) cout << f[i].count() << endl;
//}


//车站分级 
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 2010, M = 1000010;
int n, m;
int h[N], e[M], ne[M], w[M], idx;
int q[N], d[N];
int dist[N];
bool stt[N];
void add(int a, int b, int c)
{
	e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
	d[b]++;
}
void topsort()
{
	int hh = 0, tt = -1;
	for (int i = 1;i <= n + m;i++)
		if (!d[i])
			q[++tt] = i;
	while (hh <= tt)
	{
		int t = q[hh++];
		for (int i = h[t];~i;i = ne[i])
		{
			int j = e[i];
			if (--d[j] == 0)
				q[++tt] = j;
		}
	}
}
int main()
{
	cin >> n >> m;
	memset(h, -1, sizeof h);
	for (int i = 1;i <= m;i++)
	{
		memset(stt, 0, sizeof stt);
		int cnt;
		cin >> cnt;
		int st = n, ed = 1;
		while (cnt--)
		{
			int stop;
			cin >> stop;
			st = min(st, stop);
			ed = max(ed, stop);
			stt[stop] = true;
		}
		int ver = n + i;
		for (int j = st;j <= ed;j++)
			if (!stt[j]) add(j, ver, 0);
			else add(ver, j, 1);
	}
	topsort();
	for (int i = 1;i <= n;i++) dist[i] = 1;
	for (int i = 0;i < n + m;i++)
	{
		int j = q[i];
		for (int k = h[j];~k;k = ne[k])
			dist[e[k]] = max(dist[e[k]], dist[j] + w[k]);
	}
	int res = 0;
	for (int i = 1;i <= n;i++) res = max(res, dist[i]);
	cout << res << endl;
}
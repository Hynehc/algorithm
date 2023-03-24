#define  _CRT_SECURE_NO_WARNINGS 1
//ËÑË÷¹Ø¼ü´Ê
//#include <cstdio>
//#include <cstring>
//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//const int N = 10010, S = 55, M = 1000010;
//int n;
//int tr[N * S][26], cnt[N * S], idx;
//char str[M];
//int q[N * S], ne[N * S];
//void insert()
//{
//	int p = 0;
//	for (int i = 0;str[i];i++)
//	{
//		int t = str[i] - 'a';
//		if (!tr[p][t]) tr[p][t] = ++idx;
//		p = tr[p][t];
//	}
//	cnt[p]++;
//}
//void build()
//{
//	int hh = 0, tt = -1;
//	for (int i = 0;i < 26;i++)
//		if (tr[0][i])
//			q[++tt] = tr[0][i];
//	while (hh <= tt)
//	{
//		int t = q[hh++];
//		for (int i = 0;i < 26;i++)
//		{
//			int p = tr[t][i];
//			if (!p) tr[t][i] = tr[ne[t]][i];
//			else
//			{
//				ne[p] = tr[ne[t]][i];
//				q[++tt] = p;
//			}
//		}
//	}
//}
//int main()
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		memset(tr, 0, sizeof tr);
//		memset(cnt, 0, sizeof cnt);
//		memset(ne, 0, sizeof ne);
//		idx = 0;
//		cin >> n;
//		for (int i = 0;i < n;i++)
//		{
//			cin >> str;
//			insert();
//		}
//		build();
//		cin >> str;
//		int res = 0;
//		for (int i = 0,j = 0;str[i];i++)
//		{
//			int t = str[i] - 'a';
//			j = tr[j][t];
//			int p = j;
//			while (p)
//			{
//				res += cnt[p];
//				cnt[p] = 0;
//				p = ne[p];
//			}
//		}
//		cout << res << endl;
//	}
//}



//µ¥´Ê
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 1000010;
int n;
int tr[N][26], f[N], idx;
int q[N], ne[N];
char str[N];
int id[210];
void insert(int x)
{
	int p = 0;
	for (int i = 0;str[i];i++)
	{
		int t = str[i] - 'a';
		if (!tr[p][t]) tr[p][t] = ++idx;
		p = tr[p][t];
		f[p]++;
	}
	id[x] = p;
}
void build()
{
	int hh = 0, tt = -1;
	for (int i = 0;i < 26;i++)
		if (tr[0][i])
			q[++tt] = tr[0][i];
	while (hh <= tt)
	{
		int t = q[hh++];
		for (int i = 0;i < 26;i++)
		{
			int& p = tr[t][i];
			if (!p) p = tr[ne[t]][i];
			else
			{
				ne[p] = tr[ne[t]][i];
				q[++tt] = p;
			}
		}
	}
}
int main()
{
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		cin >> str;
		insert(i);
	}
	build();
	for (int i = idx - 1;i >= 0;i--) f[ne[q[i]]] += f[q[i]];
	for (int i = 0;i < n;i++) cout << f[id[i]] << endl;
}
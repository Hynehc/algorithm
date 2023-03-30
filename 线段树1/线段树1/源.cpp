//#define  _CRT_SECURE_NO_WARNINGS 1
////最大数
//#include<iostream>
//#include<algorithm>
//#include<cstring>
//using namespace std;
//typedef long long ll;
//const int N = 200010;
//int m, p;
//struct Node
//{
//	int l, r;
//	int v;//区间[l, r]的最大值
//}tr[N * 4];
//void pushup(int u)//由子节点信息计算父节点信息
//{
//	tr[u].v = max(tr[u << 1].v, tr[u << 1 | 1].v);
//}
//void build(int u, int l, int r)
//{
//	tr[u] = { l,r };
//	if (l == r) return;
//	int mid = l + r >> 1;
//	build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
//}
//int query(int u, int l, int r)
//{
//	if (tr[u].l >= l && tr[u].r <= r) return tr[u].v;
//	//树中节点已经完全被包含在[l, r]中
//
//	int mid = tr[u].l + tr[u].r >> 1;
//	int v = 0;
//	if (l <= mid) v = query(u << 1, l, r);
//	if (r > mid) v = max(v, query(u << 1 | 1, l, r));
//	return v;
//}
//void modify(int u, int x, int v)
//{
//	if (tr[u].l == x && tr[u].r == x) tr[u].v = v;
//	else
//	{
//		int mid = tr[u].l + tr[u].r >> 1;
//		if (x <= mid) modify(u << 1, x, v);
//		else modify(u << 1 | 1, x, v);
//		pushup(u);
//	}
//}
//int main()
//{
//	int n = 0, last = 0;
//	cin >> m >> p;
//	build(1, 1, m);
//	int x;
//	char op[2];
//	while (m--)
//	{
//		cin >> op >> x;
//		if (*op == 'Q')
//		{
//			last = query(1, n - x + 1, n);
//			cout << last << endl;
//		}
//		else
//		{
//			modify(1, n + 1, ((ll)last + x) % p);
//			n++;
//		}
//	}
//}




//你能回答这些问题吗
//#include<iostream>
//#include<algorithm>
//#include<cstring>
//using namespace std;
//const int N = 500010;
//int n, m;
//int w[N];
//struct Node
//{
//	int l, r;
//	int sum, lmax, rmax, tmax;//总和，前缀，后缀，区间和
//}tr[N * 4];
//void pushup(Node& u, Node& l, Node& r)
//{
//	u.sum = l.sum + r.sum;
//	u.lmax = max(l.lmax, l.sum + r.lmax);
//	u.rmax = max(r.rmax, r.sum + l.rmax);
//	u.tmax = max(max(l.tmax, r.tmax), l.rmax + r.lmax);
//}
//void pushup(int u)
//{
//	pushup(tr[u], tr[u << 1], tr[u << 1 | 1]);
//}
//void build(int u,int l,int r)
//{
//	if (l == r) tr[u] = { l,r,w[r],w[r],w[r],w[r] };
//	else
//	{
//		tr[u] = { l,r };
//		int mid = l + r >> 1;
//		build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
//		pushup(u);
//	}
//}
//int modify(int u, int x, int v)
//{
//	if (tr[u].l == x && tr[u].r == x) tr[u] = { x,x,v,v,v,v };
//	else
//	{
//		int mid = tr[u].l + tr[u].r >> 1;
//		if (x <= mid) modify(u << 1, x, v);
//		else modify(u << 1 | 1, x, v);
//		pushup(u);
//	}
//}
//Node query(int u, int l, int r)
//{
//	if (tr[u].l >= l && tr[u].r <= r) return tr[u];
//	else
//	{
//		int mid = tr[u].l + tr[u].r >> 1;
//		if (r <= mid) return query(u << 1, l, r);
//		else if (l > mid) return query(u << 1 | 1, l, r);
//		else
//		{
//			Node res;
//			auto left = query(u << 1, l, r);
//			auto right = query(u << 1 | 1, l, r);
//			pushup(res, left, right);
//			return res;
//		}
//	}
//}
//int main()
//{
//	cin >> n >> m;
//	for (int i = 1;i <= n;i++) cin >> w[i];
//	build(1, 1, n);
//	int k, x, y;
//	while (m--)
//	{
//		cin >> k >> x >> y;
//		if (k == 1)
//		{
//			if (x > y) swap(x, y);
//			cout << query(1, x, y).tmax << endl;
//		}
//		else modify(1, x, y);
//	}
//}



//区间最大公约数
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 500010;
typedef long long ll;
int n, m;
ll w[N];
struct Node
{
	int l, r;
	ll sum, d;
}tr[N * 4];
ll gcd(ll a, ll b)
{
	return b ? gcd(b, a % b) : a;
}
void pushup(Node& u, Node& l, Node& r)
{
	u.sum = l.sum + r.sum;
	u.d = gcd(l.d, r.d);
}
void pushup(int u)
{
	pushup(tr[u], tr[u << 1], tr[u << 1 | 1]);
}
void built(int u, int l, int r)
{
	if (l == r)
	{
		ll b = w[r] - w[r - 1];
		tr[u] = { l,r,b,b };
	}
	else
	{
		tr[u].l = l, tr[u].r = r;
		int mid = l + r >> 1;
		built(u << 1, l, mid), built(u << 1 | 1, mid + 1, r);
		pushup(u);
	}
}
void modify(int u, int x, ll v)
{
	if (tr[u].l == x && tr[u].r == x)
	{
		ll b = tr[u].sum + v;
		tr[u] = { x,x,b,b };
	}
	else
	{
		int mid = tr[u].l + tr[u].r >> 1;
		if (x <= mid) modify(u << 1, x, v);
		else modify(u << 1 | 1, x, v);
		pushup(u);
	}
}
Node query(int u, int l, int r)
{
	if (tr[u].l >= l && tr[u].r <= r) return tr[u];
	else
	{
		int mid = tr[u].l + tr[u].r >> 1;
		if (r <= mid) return query(u << 1, l, r);
		else if (l > mid) return query(u << 1 | 1, l, r);
		else
		{
			Node res;
			auto left = query(u << 1, l, r);
			auto right = query(u << 1 | 1, l, r);
			pushup(res, left, right);
			return res;
		}
		
	}
}
int main()
{
	cin >> n >> m;
	for (int i = 1;i <= n;i++) cin >> w[i];
	built(1, 1, n);
	int l, r;
	ll d;
	char op[2];
	while (m--)
	{
		cin >> op >> l >> r;
		if (*op == 'Q')
		{
			auto left = query(1, 1, l);
			Node right({ 0,0,0,0 });
			if (l + 1 <= r) right = query(1, l + 1, r);
			cout << abs(gcd(left.sum, right.d)) << endl;
		}
		else
		{
			cin >> d;
			modify(1, l, d);
			if (r + 1 <= n) modify(1, r + 1, -d);
		}
	}
}
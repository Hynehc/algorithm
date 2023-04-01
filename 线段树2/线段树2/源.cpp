//#define  _CRT_SECURE_NO_WARNINGS 1
////一个简单的整数问题2
//#include<iostream>
//#include<algorithm>
//#include<cstring>
//using namespace std;
//typedef long long ll;
//const int N = 100010;
//int n, m;
//int w[N];
//struct Node
//{
//	int l, r;
//	ll sum, add;
//}tr[N * 4];
//void pushup(int u)
//{
//	tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
//}
//void pushdown(int u)
//{
//	auto& root = tr[u], & left = tr[u << 1], & right = tr[u << 1 | 1];
//	if (root.add)
//	{
//		left.add += root.add, left.sum += (ll)(left.r - left.l + 1) * root.add;
//		right.add += root.add, right.sum += (ll)(right.r - right.l + 1) * root.add;
//		root.add = 0;
//	}
//}
//void build(int u, int l, int r)
//{
//	if (l == r) tr[u] = { l,r,w[r],0 };
//	else
//	{
//		tr[u] = { l,r };
//		int mid = l + r >> 1;
//		build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
//		pushup(u);
//	}
//}
//void modify(int u, int l, int r, int d)
//{
//	if (tr[u].l >= l && tr[u].r <= r)
//	{
//		tr[u].sum += (ll)(tr[u].r - tr[u].l + 1) * d;
//		tr[u].add += d;
//	}
//	else // 分裂
//	{
//		pushdown(u);
//		int mid = tr[u].l + tr[u].r >> 1;
//		if (l <= mid) modify(u << 1, l, r, d);
//		if (r > mid) modify(u << 1 | 1, l, r, d);
//		pushup(u);
//	}
//}
//ll query(int u, int l, int r)
//{
//	if (tr[u].l >= l && tr[u].r <= r) return tr[u].sum;
//	pushdown(u);
//	int mid = tr[u].l + tr[u].r >> 1;
//	ll sum = 0;
//	if (l <= mid) sum = query(u << 1, l, r);
//	if (r > mid) sum += query(u << 1 | 1, l, r);
//	return sum;
//}
//int main()
//{
//	cin >> n >> m;
//	for (int i = 1;i <= n;i++) cin >> w[i];
//	build(1, 1, n);
//	char op[2];
//	int l, r, d;
//	while (m--)
//	{
//		cin >> op >> l >> r;
//		if (*op == 'C')
//		{
//			cin >> d;
//			modify(1, l, r, d);
//		}
//		else cout << query(1, l, r) << endl;
//	}
//}



//亚特兰蒂斯
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<vector>
//using namespace std;
//const int N = 100010;
//int n;
//struct Segment
//{
//	double x, y1, y2;
//	int k;
//	bool operator< (const Segment& t) const
//	{
//		return x < t.x;
//	}
//}seg[N * 2];
//struct Node
//{
//	int l, r;
//	int cnt;
//	double len;
//}tr[N * 8];
//vector<double>ys;
//int find(double y)
//{
//	return lower_bound(ys.begin(), ys.end(), y) - ys.begin();
//}
//void pushup(int u)
//{
//	if (tr[u].cnt) tr[u].len = ys[tr[u].r + 1] - ys[tr[u].l];
//	else if (tr[u].l != tr[u].r)
//		tr[u].len = tr[u << 1].len + tr[u << 1 | 1].len;
//	else tr[u].len = 0;
//}
//void build(int u, int l, int r)
//{
//	tr[u] = { l,r,0,0 };
//	if (l != r)
//	{
//		int mid = l + r >> 1;
//		build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
//	}
//}
//void modify(int u, int l, int r, int k)
//{
//	if (tr[u].l >= l && tr[u].r <= r)
//	{
//		tr[u].cnt += k;
//		pushup(u);
//	}
//	else
//	{
//		int mid = tr[u].l + tr[u].r >> 1;
//		if (l <= mid) modify(u << 1, l, r, k);
//		if (r > mid) modify(u << 1 | 1, l, r, k);
//		pushup(u);
//	}
//}
//int main()
//{
//	int t = 1;
//	while (cin >> n, n)
//	{
//		ys.clear();
//		for (int i = 0, j = 0;i < n;i++)
//		{
//			double x1, y1, x2, y2;
//			cin >> x1 >> y1 >> x2 >> y2;
//			seg[j++] = { x1,y1,y2,1 };
//			seg[j++] = { x2,y1,y2,-1 };
//			ys.push_back(y1), ys.push_back(y2);
//		}
//		sort(ys.begin(), ys.end());
//		ys.erase(unique(ys.begin(), ys.end()), ys.end());
//		build(1, 0, ys.size() - 2);
//		sort(seg, seg + n * 2);
//		double res = 0;
//		for (int i = 0;i < n * 2;i++)
//		{
//			if (i > 0) res += tr[1].len * (seg[i].x - seg[i - 1].x);
//			modify(1, find(seg[i].y1), find(seg[i].y2) - 1, seg[i].k);
//		}
//		printf("Test case #%d\n", t++);
//		printf("Total explored area: %.2lf\n\n", res);
//	}
//}




//维护序列
//#include<iostream>
//#include<algorithm>
//#include<cstring>
//using namespace std;
//typedef long long ll;
//const int N = 100010;int n, p, m;
//int w[N];
//struct Node
//{
//	int l, r;
//	int sum, add, mul;
//}tr[N * 4];
//void pushup(int u)
//{
//	tr[u].sum = (tr[u << 1].sum + tr[u << 1 | 1].sum) % p;
//}
//void eval(Node &t, int add, int mul)
//{
//	t.sum = ((ll)t.sum * mul + (ll)(t.r - t.l + 1) * add) % p;
//	t.mul = (ll)t.mul * mul % p;
//	t.add = ((ll)t.add * mul + add) % p;
//}
//void pushdown(int u)
//{
//	eval(tr[u << 1], tr[u].add, tr[u].mul);
//	eval(tr[u << 1 | 1], tr[u].add, tr[u].mul);
//	tr[u].add = 0, tr[u].mul = 1;
//}
//void build(int u, int l, int r)
//{
//	if (l == r) tr[u] = { l,r,w[r],0,1 };
//	else
//	{
//		tr[u] = { l,r,0,0,1 };
//		int mid = l + r >> 1;
//		build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
//		pushup(u);
//	}
//}
//void modify(int u, int l, int r, int add, int mul)
//{
//	if (tr[u].l >= l && tr[u].r <= r) eval(tr[u], add, mul);
//	else
//	{
//		pushdown(u);
//		int mid = tr[u].l + tr[u].r >> 1;
//		if (l <= mid) modify(u << 1, l, r, add, mul);
//		if (r > mid) modify(u << 1 | 1, l, r, add, mul);
//		pushup(u);
//	}
//}
//int query(int u, int l, int r)
//{
//	if (tr[u].l >= l && tr[u].r <= r) return tr[u].sum;
//	pushdown(u);
//	int mid = tr[u].l + tr[u].r >> 1;
//	int sum = 0;
//	if (l <= mid) sum = query(u << 1, l, r);
//	if (r > mid) sum = (sum + query(u << 1 | 1, l, r)) % p;
//	return sum;
//}
//int main()
//{
//	cin >> n >> p;
//	for (int i = 1;i <= n;i++) cin >> w[i];
//	build(1, 1, n);
//	cin >> m;
//	while (m--)
//	{
//		int t, l, r, d;
//		cin >> t >> l >> r;
//		if (t == 1)
//		{
//			cin >> d;
//			modify(1, l, r, 0, d);
//		}
//		else if (t == 2)
//		{
//			cin >> d;
//			modify(1, l, r, d, 1);
//		}
//		else cout << query(1, l, r) << endl;
//	}
//}
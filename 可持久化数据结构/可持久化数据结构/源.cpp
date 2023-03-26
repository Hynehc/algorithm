//#define  _CRT_SECURE_NO_WARNINGS 1
//// 最大异或和
//#include<iostream>
//#include<algorithm>
//#include<cstring>
//using namespace std;
//const int N = 600010, M = N * 25;
//int n, m;
//int s[N];
//int tr[M][2], max_id[M];
//int root[N], idx;
//void insert(int i, int k, int p, int q)
//{
//	if (k < 0)
//	{
//		max_id[q] = i;
//		return;
//	}
//	int v = s[i] >> k & 1;
//	if (p) tr[q][v ^ 1] = tr[p][v ^ 1];
//	tr[q][v] = ++idx;
//	insert(i, k - 1, tr[p][v], tr[q][v]);;
//	max_id[q] = max(max_id[tr[q][0]], max_id[tr[q][1]]);
//}
//int query(int root, int c, int l)
//{
//	int p = root;
//	for (int i = 23;i >= 0;i--)
//	{
//		int v = c >> i & 1;
//		if (max_id[tr[p][v ^ 1]] >= l) p = tr[p][v ^ 1];
//		else p = tr[p][v];
//	}
//	return c ^ s[max_id[p]];
//}
//int main()
//{
//	cin >> n >> m;
//	max_id[0] = -1;
//	root[0] = ++idx;
//	insert(0, 23, 0, root[0]);
//	for (int i = 1;i <= n;i++)
//	{
//		int x;
//		cin >> x;
//		s[i] = s[i - 1] ^ x;
//		root[i] = ++idx;
//		insert(i, 23, root[i - 1], root[i]);
//	}
//	char op[2];
//	int l, r, x;
//	while (m--)
//	{
//		cin >> op;
//		if (*op == 'A')
//		{
//			cin >> x;
//			n++;
//			s[n] = s[n - 1] ^ x;
//			root[n] = ++idx;
//			insert(n, 23, root[n - 1], root[n]);
//		}
//		else
//		{
//			cin >> l >> r >> x;
//			cout << query(root[r - 1], s[n] ^ x, l - 1) << endl;
//		}
//	}
//}



//第K小数
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int N = 100010, M = 10010;
int n, m;
int a[N];
vector<int>nums;
struct Node
{
	int l, r;
	int cnt;
}tr[N * 4 + N * 17];
int root[N], idx;
int find(int x)
{
	return lower_bound(nums.begin(), nums.end(), x) - nums.begin();
}
int build(int l, int r)
{
	int p = ++idx;
	if (l == r) return p;
	int mid = l + r >> 1;
	tr[p].l = build(l, mid), tr[p].r = build(mid + 1, r);
	return p;
}
int insert(int p, int l, int r, int x)
{
	int q = ++idx;
	tr[q] = tr[p];
	if (l == r)
	{
		tr[q].cnt++;
		return q;
	}
	int mid = l + r >> 1;
	if (x <= mid) tr[q].l = insert(tr[p].l, l, mid, x);
	else tr[q].r = insert(tr[p].r, mid + 1, r, x);
	tr[q].cnt = tr[tr[q].l].cnt + tr[tr[q].r].cnt;
	return q;
}
int query(int q, int p, int l, int r, int k)
{
	if (l == r) return r;
	int cnt = tr[tr[q].l].cnt - tr[tr[p].l].cnt;
	int mid = l + r >> 1;
	if (k <= cnt) return query(tr[q].l, tr[p].l, l, mid, k);
	else return query(tr[q].r, tr[p].r, mid + 1, r, k - cnt);
}
int main()
{
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		nums.push_back(a[i]);
	}
	sort(nums.begin(), nums.end());
	nums.erase(unique(nums.begin(), nums.end()), nums.end());
	root[0] = build(0, nums.size() - 1);
	for (int i = 1;i <= n;i++)
		root[i] = insert(root[i - 1], 0, nums.size() - 1, find(a[i]));
	while (m--)
	{
		int l, r, k;
		cin >> l >> r >> k;
		cout << nums[query(root[r], root[l - 1], 0, nums.size() - 1, k)] << endl;
	}
}
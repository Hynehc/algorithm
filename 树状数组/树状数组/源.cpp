#define  _CRT_SECURE_NO_WARNINGS 1
// 楼兰图腾
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//typedef long long ll;
//const int N = 200010;
//int n;
//int a[N];
//int tr[N];
//int g[N], l[N];
//int lowbit(int x)
//{
//	return x & -x;
//}
//void add(int x, int c)//将下标为x的数增加c
//{
//	for (int i = x;i <= n;i += lowbit(i)) tr[i] += c;
//}
//int sum(int x)//下标从1到x的前缀和   ask
//{
//	int res = 0;
//	for (int i = x;i;i -= lowbit(i)) res += tr[i];
//	return res;
//}
////1111 1110 1100 1000
////111 110 100 7 6 4
//int main()
//{
//	cin >> n;
//	for (int i = 1;i <= n;i++) cin >> a[i];
//	for (int i = 1;i <= n;i++)
//	{
//		int y = a[i];
//		g[i] = sum(n) - sum(y);
//		l[i] = sum(y - 1);
//		add(y, 1);
//	}
//	memset(tr, 0, sizeof tr);
//	ll res1 = 0, res2 = 0;
//	for (int i = n;i;i--)
//	{
//		int y = a[i];
//		res1 += g[i]*(ll)(sum(n) - sum(y));
//		res2 += l[i] * (ll)(sum(y - 1));
//		add(y, 1);
//	}
//	cout << res1 << " " << res2 << endl;
//}






// 一个简单的整数问题
//#include<iostream>
//#include<algorithm>
//#include<cstring>
//using namespace std;
//typedef long long ll;
//const int N = 100010;
//int n, m;
//int a[N];
//ll tr[N];
//int lowbit(int x)
//{
//	return x & -x;
//}
//void add(int x, int c)
//{
//	for (int i = x;i <= n;i += lowbit(i)) tr[i] += c;
//}
//ll sum(int x)
//{
//	ll res = 0;
//	for (int i = x;i;i -= lowbit(i)) res += tr[i];
//	return res;
//}
//int main()
//{
//	cin >> n >> m;
//	for (int i = 1;i <= n;i++) cin >> a[i];
//	for (int i = 1;i <= n;i++) add(i, a[i] - a[i - 1]);
//	while (m--)
//	{
//		char op[2];
//		int l, r, d;
//		cin >> op >> l;
//		if (*op == 'C')
//		{
//			cin >> r >> d;
//			add(l, d), add(r + 1, -d);
//		}
//		else cout << sum(l) << endl;
//	}
//}




//一个简单的整数问题2
//#include<iostream>
//#include<algorithm>
//#include<cstring>
//using namespace std;
//typedef long long ll;
//const int N = 100010;
//int n, m;
//int a[N];
//ll trr1[N], trr2[N];
//int lowbit(int x)
//{
//	return x & -x;
//}
//void add(ll tr[], int x, ll c)
//{
//	for (int i = x;i <= n;i += lowbit(i)) tr[i] += c;
//}
//ll sum(ll tr[], int x)
//{
//	ll res = 0;
//	for (int i = x;i;i -= lowbit(i)) res += tr[i];
//	return res;
//}
//ll prefix_sum(int x)
//{
//	return sum(trr1, x) * (x + 1) - sum(trr2, x);
//}
//int main()
//{
//	cin >> n >> m;
//	for (int i = 1;i <= n;i++) cin >> a[i];
//	for (int i = 1;i <= n;i++)
//	{
//		int b = a[i] - a[i - 1];
//		add(trr1, i, b);
//		add(trr2, i, (ll)b * i);
//	}
//	while (m--)
//	{
//		char op[2];
//		int l, r, d;
//		cin >> op >> l >> r;
//		if (*op == 'Q') cout << prefix_sum(r) - prefix_sum(l - 1) << endl;
//		else
//		{
//			cin >> d;
//			add(trr1, l, d), add(trr2, l, l * d);
//			add(trr1, r + 1, -d), add(trr2, r + 1, (r + 1) * -d);
//		}
//	}
//}





//谜一样的牛
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 100010;
int n;
int h[N];
int ans[N];
int tr[N];
int lowbit(int x)
{
	return x & -x;
}
void add(int x, int c)
{
	for (int i = x;i <= n;i += lowbit(i)) tr[i] += c;
}
int sum(int x)
{
	int res = 0;
	for (int i = x;i;i -= lowbit(i)) res += tr[i];
	return res;
}
int main()
{
	cin >> n;
	for (int i = 2;i <= n;i++) cin >> h[i];
	for (int i = 1;i <= n;i++) tr[i] = lowbit(i);
	for (int i = n;i;i--)
	{
		int k = h[i] + 1;
		int l = 1, r = n;
		while (l < r)
		{
			int mid = l + r >> 1;
			if (sum(mid) >= k) r = mid;
			else l = mid + 1;
		}
		ans[i] = r;
		add(r, -1);
	}
	for (int i = 1;i <= n;i++) cout << ans[i] << endl;
}
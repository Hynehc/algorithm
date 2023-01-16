#define  _CRT_SECURE_NO_WARNINGS 1


//区间选点
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 100010;
int n;
struct Range
{
	int l, r;
	bool operator< (const Range& w)const
	{
		return r < w.r;
	}
}range[N];
int main()
{
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		int l, r;
		cin >> l >> r;
		range[i] = { l,r };
	}
	sort(range, range + n);
	int res = 0, ed = -2e9;
	for(int i=0;i<n;i++)
		if (range[i].l > ed)
		{
			res++;
			ed = range[i].r;
		}
	cout << res << endl;
	return 0;
}





// 最大不相交区间数量
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 100010;
int n;
struct Range
{
	int l, r;
	bool operator< (const Range& w)const
	{
		return r < w.r;
	}
}range[N];
int main()
{
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		int l, r;
		cin >> l >> r;
		range[i] = { l,r };
	}
	sort(range, range + n);
	int res = 0, ed = -2e9;
	for (int i = 0;i < n;i++)
		if (range[i].l > ed)
		{
			res++;
			ed = range[i].r;
		}
	cout << res << endl;
	return 0;
}





//区间分组
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
const int N = 100010;
int n;
struct Range
{
	int l, r;
	bool operator< (const Range& w)const
	{
		return l < w.l;
	}
}range[N];
int main()
{
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		int l, r;
		cin >> l >> r;
		range[i] = { l,r };
	}
	sort(range, range + n);
	priority_queue<int, vector<int>, greater<int>>heap;
	for (int i = 0;i < n;i++)
	{
		auto r = range[i];
		if (heap.empty() || heap.top() >= r.l) heap.push(r.r);
		else
		{
			heap.pop();
			heap.push(r.r);
		}
	}
	cout << heap.size() << endl;
}






//区间覆盖
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 100010;
struct Range
{
	int l, r;
	bool operator< (const Range& w) const
	{
		return l < w.l;
	}
}range[N];
int main()
{
	int st, ed;
	cin >> st >> ed;
	int n;
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		int l, r;
		cin >> l >> r;
		range[i] = { l,r };
	}
	sort(range, range + n);
	int res = 0;
	bool success = false;
	for (int i = 0;i < n;i++)
	{
		int j = i, r = -2e9;
		while (j < n && range[j].l <= st)
		{
			r = max(r,range[j].r);
			j++;
		}
		if (r < st)
		{
			res = -1;
			break;
		}
		res++;
		if (r >= ed)
		{
			success = true;
			break;
		}
		st = r;
		i = j - 1;
	}
	if (success)  cout << res << endl;
	else cout << -1 << endl;
}








//Huffman树--合并果子
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int main()
{
	int n;
	cin >> n;
	priority_queue<int, vector<int>, greater<int>> heap;
	while (n--)
	{
		int x;
		cin >> x;
		heap.push(x);
	}
	int res = 0;
	while (heap.size() > 1)
	{
		int a = heap.top();heap.pop();
		int b = heap.top();heap.pop();
		res += a + b;
		heap.push(a + b);
	}
	cout << res << endl;
}
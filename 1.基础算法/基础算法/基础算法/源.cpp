#define  _CRT_SECURE_NO_WARNINGS 1


//快速排序模板
#include<iostream>
using namespace std;
const int N = 1e6 + 10;
int n;
int q[N];
void quick_sort(int q[], int l, int r)
{
	if (l >= r) return;

	int x = q[l + r >> 1], i = l - 1, j = r + 1;//x可为q[i],q[r],q[(i+r+1)/2]
	while (i < j)
	{
		do i++; while (q[i] < x);
		do j--; while (q[j] > x);
		if (i < j) swap(q[i], q[j]);
	}
	quick_sort(q, l, j);
	quick_sort(q, j + 1, r);
	//当用j时，不可以用q[r]
	//当用i时，不可以用q[l]
}
int main()
{
	scanf("%d", &n);
	for (int i = 0;i < n;i++) scanf("%d", &q[i]);

	quick_sort(q, 0, n - 1);

	for (int i = 0;i < n;i++) printf("%d ", q[i]);
	return 0;
}



//第k个数
#include<iostream>
using namespace std;
const int N = 1e6 + 10;
int n, m;
int q[N];
void quick_sort(int q[], int l, int r)
{
	if (l >= r) return;
	int x = q[l + r >> 1], i = l - 1, j = r + 1;
	while (i < j)
	{
		do i++; while (q[i] < x);
		do j--; while (q[j] > x);
		if (i < j) swap(q[i], q[j]);
	}
	quick_sort(q, l, j);
	quick_sort(q, j + 1, r);
}
int main()
{
	cin >> n >> m;
	for (int i = 0;i < n;i++) scanf("%d", &q[i]);
	quick_sort(q, 0, n - 1);
	for (int i = 0;i < n;i++)
	{
		if (i == m - 1)
			printf("%d", q[i]);
	}
	return 0;
}




//归并排序模板
#include<iostream>
using namespace std;
const int N = 1000010;
int n;
int q[N], tmp[N];
void merge_sort(int q[], int l, int r)
{
	if (l >= r) return;
	int mid = l + r >> 1;
	merge_sort(q, l, mid), merge_sort(q, mid + 1, r);
	int k = 0, i = l, j = mid + 1;
	while (i <= mid && j <= r)
	{
		if (q[i] <= q[j]) tmp[k++] = q[i++];
		else tmp[k++] = q[j++];
	}
	while (i <= mid) tmp[k++] = q[i++];
	while (j <= r) tmp[k++] = q[j++];

	for (i = l, j = 0;i <= r;i++, j++) q[i] = tmp[j];
}
int main()
{
	scanf("%d", &n);
	for (int i = 0;i < n;i++) scanf("%d", &q[i]);
	merge_sort(q, 0, n - 1);
	for (int i = 0;i < n;i++) printf("%d ", q[i]);
	return 0;
}



//逆序对的数量
using namespace std;
const int N = 1e6;
int n;
typedef long long ll;
int q[N], tmp[N];
ll merge_sort(int l, int r)
{
	if (l >= r) return 0;
	int mid = l + r >> 1;
	ll res = merge_sort(l, mid) + merge_sort(mid + 1, r);
	int k = 0, i = l, j = mid + 1;
	while (i <= mid && j <= r)
	{
		if (q[i] <= q[j]) tmp[k++] = q[i++];
		else
		{
			tmp[k++] = q[j++];
			res += mid - i + 1;
		}
	}
	while (i <= mid) tmp[k++] = q[i++];
	while (j <= r) tmp[k++] = q[j++];
	for (i = l, j = 0;i <= r;i++, j++) q[i] = tmp[j];
	return res;
}
int main()
{
	cin >> n;
	for (int i = 0;i < n;i++) cin >> q[i];
	cout << merge_sort(0, n - 1) << endl;
}



//二分--整数
#include<iostream>
using namespace std;
const int N = 1e6;
int n, m;
int q[N];
int main()
{
	cin >> n >> m;
	for (int i = 0;i < n;i++) cin >> q[i];
	while (m--)
	{
		int x;
		cin >> x;
		int l = 0, r = n - 1;
		while (l < r)
		{
			int mid = l + r >> 1;
			if (q[mid] >= x) r = mid;
			else l = mid + 1;
		}
		if (q[l] != x) cout << "-1 -1" << endl;
		else
		{
			cout << l << " ";
			int l = 0, r = n - 1;
			while (l < r)
			{
				int mid = l + r + 1 >> 1;
				if (q[mid] <= x) l = mid;
				else r = mid - 1;
			}
			cout << l << endl;
		}
	}
	return 0;
}


//二分--浮点数
#include<iostream>
using namespace std;
int main()
{
	double x;
	cin >> x;
	double l = 0, r = x;
	while (r - l > 1e-8)
	{
		double mid = (l + r) / 2;
		if (mid * mid >= x) r = mid;
		else l = mid;
	}
	cout << l << endl;
	return 0;
}






//数的三次方根
#include<iostream>
using namespace std;
double n;
int main()
{
	cin >> n;
	double l = -100, r = 100;
	while (r - l > 1e-8)
	{
		double mid = (l + r) / 2;
		if (mid * mid * mid >= n) r = mid;
		else l = mid;
	}
	printf("%.6lf", l);
	return 0;
}





//高精度加法
//#include<iostream>
//#include<vector>
//using namespace std;
//vector<int> add(vector<int>& A, vector<int>& B)
//{
//	vector<int> C;
//	int t = 0;//进位
//	for (int i = 0;i < A.size() || i < B.size();i++)
//	{
//		if (i < A.size()) t += A[i];
//		if (i < B.size()) t += B[i];
//		C.push_back(t % 10);
//		t /= 10;
//	}
//	//如果C还存在，则向前进1
//	if (t) C.push_back(1);
//	return C;
//}
//int main()
//{
//	string a, b;
//	vector<int> A, B;
//
//	cin >> a >> b;
//	//低位存低位
//	for (int i = a.size() - 1;i >= 0;i--) A.push_back(a[i] - '0');
//	for (int i = b.size() - 1;i >= 0;i--) B.push_back(b[i] - '0');
//
//	auto C = add(A, B);
//
//	for (int i = C.size() - 1;i >= 0;i--) printf("%d", C[i]);
//	return 0;
//}



//高精度减法
#include<iostream>
#include<vector>
using namespace std;
//判断是否A>=B
bool cmp(vector<int>& A, vector<int>& B)
{
	if (A.size() != B.size()) return A.size() > B.size();
	for (int i = A.size() - 1;i >= 0;i--)
		if (A[i] != B[i])
			return A[i] > B[i];
	return true;
}
//C=A-B
vector<int> sub(vector<int>& A, vector<int>& B)
{
	vector<int> C;
	for (int i = 0, t = 0;i < A.size();i++)
	{
		t = A[i] - t;
		if (i < B.size()) t -= B[i];
		C.push_back((t + 10) % 10);
		if (t < 0) t = 1;
		else t = 0;
	}
	while (C.size() > 1 && C.back() == 0) C.pop_back();//去掉前导0
	return C;
}
int main()
{
	string a, b;
	vector<int> A, B;

	cin >> a >> b;
	for (int i = a.size() - 1;i >= 0;i--) A.push_back(a[i] - '0');
	for (int i = b.size() - 1;i >= 0;i--) B.push_back(b[i] - '0');

	if (cmp(A, B))
	{
		auto C = sub(A, B);
		for (int i = C.size() - 1;i >= 0;i--) printf("%d", C[i]);
	}
	else
	{
		auto C = sub(B, A);
		printf("-");
		for (int i = C.size() - 1;i >= 0;i--) printf("%d", C[i]);
	}
	return 0;
}





//高精度乘法
#include<iostream>
#include<vector>
using namespace std;
vector<int> mul(vector<int>& A, int b)
{
	vector<int> C;
	int t = 0;
	for (int i = 0;i < A.size() || t;i++)
	{
		if (i < A.size()) t += A[i] * b;
		C.push_back(t % 10);
		t /= 10;
	}
	return C;
}
int main()
{
	string a;
	int b;
	cin >> a >> b;
	vector<int> A;
	for (int i = a.size() - 1;i >= 0;i--) A.push_back(a[i] - '0');
	auto C = mul(A, b);
	if (b == 0) cout << '0' << endl;
	else
	{
		for (int i = C.size() - 1;i >= 0;i--) printf("%d", C[i]);
	}
	return 0;
}

//高精度除法
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> div(vector<int>& A, int b, int& r)
{
	vector<int> C;
	r = 0;
	for (int i = A.size() - 1;i >= 0;i--)
	{
		r = r * 10 + A[i];
		C.push_back(r / b);
		r %= b;
	}
	reverse(C.begin(), C.end());
	while (C.size() > 1 && C.back() == 0) C.pop_back();
	return C;
}
int main()
{
	string a;
	int b, r;
	cin >> a >> b;
	vector<int> A;
	for (int i = a.size() - 1;i >= 0;i--) A.push_back(a[i] - '0');
	auto C = div(A, b, r);
	for (int i = C.size() - 1;i >= 0;i--) printf("%d", C[i]);
	cout << endl << r << endl;
}




//前缀和
#include<iostream>
using namespace std;
const int N = 100010;
int n, m;
int a[N], s[N];
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1;i <= n;i++) scanf("%d", &a[i]);
	for (int i = 1;i <= n;i++) s[i] = s[i - 1] + a[i];
	while (m--)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		printf("%d\n", s[r] - s[l - 1]);
	}
	return 0;
}




//二维前缀和
//#include<iostream>
//using namespace std;
//const int N = 1010;
//int n, m, q;
//int a[N][N], s[N][N];
//int main()
//{
//	scanf("%d%d%d", &n, &m, &q);
//	for (int i = 1;i <= n;i++)
//		for (int j = 1;j <= m;j++)
//			scanf("%d", &a[i][j]);
//	for (int i = 1;i <= n;i++)
//		for (int j = 1;j <= m;j++)
//			s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
//	while (q--)
//	{
//		int x1, y1, x2, y2;
//		cin >> x1 >> y1 >> x2 >> y2;
//		printf("%d\n", s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1]);
//	}
//	return 0;
//}



//差分
#include<iostream>
using namespace std;
const int N = 100010;
int n, m;
int a[N], b[N];//原数组，差分数组
void insert(int l, int r, int c)
{
	b[l] += c;
	b[r + 1] -= c;
}
int main()
{
	cin >> n >> m;
	for (int i = 1;i <= n;i++) cin >> a[i];
	for (int i = 1;i <= n;i++)
		insert(i, i, a[i]);
	//输入第一个数时，输入第二个数减去第一个数，因为a[2] = b[1]+b[2],a[1]=b[1]
	//b是a的差分数组
	//等价于  b[i]=a[i]-a[i-1];
	while (m--)
	{
		int l, r, c;
		cin >> l >> r >> c;
		insert(l, r, c);
	}
	for (int i = 1;i <= n;i++) b[i] += b[i - 1];
	for (int i = 1;i <= n;i++) cout << b[i] << " ";
	return 0;
}




//二维数组差分
//#include<iostream>
//using namespace std;
//const int N = 1010;
//int n, m, q;
//int a[N][N], b[N][N];
//void insert(int x1, int y1, int x2, int y2, int c)
//{
//	b[x1][y1] += c;
//	b[x2 + 1][y1] -= c;
//	b[x1][y2 + 1] -= c;
//	b[x2 + 1][y2 + 1] += c;
//}
//int main()
//{
//	cin >> n >> m >> q;
//	for (int i = 1;i <= n;i++)
//		for (int j = 1;j <= m;j++)
//			cin >> a[i][j];
//
//	for (int i = 1;i <= n;i++)
//		for (int j = 1;j <= m;j++)
//			insert(i, j, i, j, a[i][j]);
//	
//	while (q--)
//	{
//		int x1, y1, x2, y2, c;
//		cin >> x1 >> y1 >> x2 >> y2 >> c;
//		insert(x1, y1, x2, y2, c);
//	}
//
//	for (int i = 1;i <= n;i++)
//		for (int j = 1;j <= m;j++)
//			b[i][j] += b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];
//
//	for (int i = 1;i <= n;i++)
//	{
//		for (int j = 1;j <= m;j++)
//			printf("%d ", b[i][j]);
//		cout << end;
//	}
//	return 0;
//}




//双指针算法
//最长连续不重复子序列
#include<iostream>
using namespace std;
const int N = 100010;
int n;
int a[N], s[N];
int main()
{
	cin >> n;
	for (int i = 0;i < n;i++) cin >> a[i];

	int res = 0;
	for (int i = 0, j = 0;i < n;i++)
	{
		s[a[i]]++;
		while (s[a[i]] > 1)
		{
			s[a[j]]--;
			j++;
		}
		res = max(res, i - j + 1);
	}
	cout << res << endl;
	return 0;
}




//位运算
#include<iostream>
using namespace std;
int lowbit(int x)
{
	return x & -x;
}
int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		int x;
		cin >> x;
		int res = 0;
		while (x) x -= lowbit(x), res++;
		cout << res << endl;
	}
	return 0;
}



//离散化
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int, int>PII;//每次操作2个数，用pair来储存
const int N = 300010;
int n, m;
int a[N], s[N];//a[N]存数字，s[N]存前缀和
vector<int> alls;//存离散化数字
vector<PII> add, query;//插入操作和求解操作
int find(int x)//find函数用于求出离散化后的结果--二分查找
{
	int l = 0, r = alls.size() - 1;
	while (l < r)
	{
		int mid = l + r >> 1;
		if (alls[mid] >= x) r = mid;//找到>=x的最小数
		else l = mid+1;
	}
	return r + 1;//把所有的数映射到从一开始的自然数，方便前缀和处理边界
}
int main()
{
	cin >> n >> m;
	for (int i = 0;i < n;i++)
	{
		int x, c;
		cin >> x >> c;
		add.push_back({ x,c });//存入x和c,在x位置加上c
		alls.push_back(x);//将x存入离散化数组中
	}
	for (int i = 0;i < n;i++)
	{
		int l, r;
		cin >> l >> r;//左右区间
		query.push_back({ l,r });//将左右区间存入query数组
		alls.push_back(l);
		alls.push_back(r);//进行离散化
	}

	//去重
	sort(alls.begin(), alls.end());//排序
	alls.erase(unique(alls.begin(), alls.end()), alls.end());//去重--对需要操作的数传入find函数中进行离散化
	//unique函数，删除重复元素，所有不重复元素放到数组前面，
	//返回新数组最后一个位置，删除新数组的位置到结尾的所有冗余的元素

	//处理插入
	for (auto item:add)//遍历add
	{
		int x = find(item.first);//对x进行离散化
		a[x] += item.second;//将c存入a数组中
	}
	//前缀和
	for (int i = 1;i <= alls.size();i++) s[i] = s[i - 1] + a[i];

	for (auto item : query)//遍历query
	{
		int l = find(item.first), r = find(item.second);//对l,r进行离散化
		cout << s[r] - s[l - 1] << endl;
	}
	return 0;
}





//区间合并
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int N = 100010;
typedef pair<int, int>PII;
int n;
vector<PII>segs;
void merge(vector<PII>& segs)
{
	vector<PII> res;
	sort(segs.begin(), segs.end());
	int st = -2e9, ed = -2e9;
	for (auto seg : segs)
	{
		if (ed < seg.first)
		{
			if (st != -2e9) res.push_back({ st,ed });
			st = seg.first, ed = seg.second;
		}
		else ed = max(ed, seg.second);
	}
	if (st != -2e9) res.push_back({ st,ed });
	segs = res;
}
int main()
{
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		int l, r;
		cin >> l >> r;
		segs.push_back({ l,r });
	}
	merge(segs);
	cout << segs.size() << endl;
	return 0;
}

#define  _CRT_SECURE_NO_WARNINGS 1
//������
//#include<iostream>
//using namespace std;
//const int N = 100010;
//int head, e[N], ne[N],idx;//head-ͷ����±꣬idx��ʾ�õ����ĸ���
////��ʼ��
//void init()
//{
//	head = -1;
//	idx = 0;
//}
////��x���뵽ͷ���
//void add_to_head(int x)
//{
//	e[idx] = x, ne[idx] = head, head = idx ++;
//}
////��x����k������
//void add(int k, int x)
//{
//	e[idx] = x, ne[idx] = ne[k], ne[k] = idx ++;
//}
////ɾ��k����Ľ��
//void remove(int k)
//{
//	ne[k] = ne[ne[k]];
//}
//int main()
//{
//	int m;
//	cin >> m;
//	init();
//	while (m--)
//	{
//		int k, x;
//		char op;
//		cin >> op;
//		if (op == 'H')
//		{
//			cin >> x;
//			add_to_head(x);
//		}
//		else if (op == 'D')
//		{
//			cin >> k;
//			if (!k) head = ne[head];
//			else remove(k-1);
//		}
//		else
//		{
//			cin >> k >> x;
//			add(k-1, x);
//		}
//	}
//	for (int i = head;i != -1;i=ne[i]) cout << e[i] << " ";
//	cout << endl;
//	return 0;
//}








//˫����
//#include<iostream>
//using namespace std;
//const int N = 100010;
//int m;
//int e[N], l[N], r[N], idx;
////��ʼ��
//void init()
//{
//	r[0] = 1, l[1] = 0;
//	idx = 2;
//}
////���±���k�ĵ���ұߣ�����x
//void add(int k, int x)
//{
//	e[idx] = x;
//	r[idx] = r[k];
//	l[idx] = k;
//	l[r[k]] = idx;
//	r[k] = idx++; 
//}
////ɾ����k����
//void remove(int k)
//{
//	r[l[k]] = r[k];
//	l[r[k]] = l[k];
//}
//int main()
//{
//	cin >> m;
//	init();
//	while (m--)
//	{
//		string op;
//		cin >> op;
//		int k, x;
//		if (op == "L")
//		{
//			cin >> x;
//			add(0, x);
//		}
//		else if (op == "R")
//		{
//			cin >> x;
//			add(l[1], x);
//		}
//		else if (op == "D")
//		{
//			cin >> k;
//			remove(k + 1);
//		}
//		else if (op == "IL")
//		{
//			cin >> k >> x;
//			add(l[k + 1], x);
//		}
//		else
//		{
//			cin >> k >> x;
//			add(k + 1, x);
//		}
//	}
//	for (int i = r[0];i != 1;i = r[i]) cout << e[i] << " ";
//	cout << endl;
//	return 0;
//}











//����ջ
//#include<iostream>
//using namespace std;
//const int N = 100010;
//int n;
//int stk[N], tt;
//int main()
//{
//	cin >> n;
//	for (int i = 0;i < n;i++)
//	{
//		int x;
//		cin >> x;
//		while (tt && stk[tt] >= x) tt--;
//		if (tt) cout << stk[tt] << " ";
//		else cout << -1 << " ";
//		stk[++tt] = x;
//	}
//	return 0;
//}








//��������--������������
#include<iostream>
using namespace std;
const int N = 1e6 + 10;
int n, k;
int a[N], q[N];//a��Ԫ��ֵ��q���±�
int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 0;i < n;i++) scanf("%d", &a[i]);
	int hh = 0, tt = -1;//hhΪ��ͷ,ttΪ��β
	//����Сֵ
	for (int i = 0;i < n;i++)
	{
		//�ж϶�ͷ�Ƿ񻬳�����
		if (hh <= tt && i - q[hh] + 1 > k ) hh++;
		//��ͷС�ڶ�β��i-q[hh]+1Ϊ�����е�Ԫ�ظ�����������kʱ�����ͷ++
		while (hh <= tt && a[q[tt]] >= a[i]) tt--;
		//��ͷС�ڶ�β������β��Ԫ��ֵ����Ҫ���ӵ�ֵʱ��ɾ����βԪ�أ�������Ԫ��
		q[++tt] = i;//�����в�����Ԫ��
		if (i >= k - 1) printf("%d ", a[q[hh]]);
		//ֻҪ���±�i>k-1ʱ����ʼ���Ԫ��
	}
	puts("");

	//�����ֵ
	hh = 0, tt = -1;//hhΪ��ͷ,ttΪ��β
	//����Сֵ
	for (int i = 0;i < n;i++)
	{
		//�ж϶�ͷ�Ƿ񻬳�����
		if (hh <= tt && i - q[hh] + 1 > k) hh++;
		//��ͷС�ڶ�β��i-q[hh]+1Ϊ�����е�Ԫ�ظ�����������kʱ�����ͷ++
		while (hh <= tt && a[q[tt]] <= a[i]) tt--;
		//��ͷС�ڶ�β������β��Ԫ��ֵС����Ҫ���ӵ�ֵʱ��ɾ����βԪ�أ�������Ԫ��
		q[++tt] = i;//�����в�����Ԫ��
		if (i >= k - 1) printf("%d ", a[q[hh]]);
		//ֻҪ���±�i>k-1ʱ����ʼ���Ԫ��
	}
	puts("");

	return 0;
}


//KMP
#include<iostream>
using namespace std;
const int N = 100010, M = 1000010;
int n, m;
char p[N], s[M];
int ne[N];
int main()
{
	cin >> n >> p + 1 >> m >> s + 1;
	//��next
	for (int i = 2, j = 0;i <= n;i++)
	{
		while (j && p[i] != p[j + 1]) j = ne[j];
		if (p[i] == p[j + 1]) j++;
		ne[i] = j;
	}
	//KMPƥ�����
	for (int i = 1, j = 0;i <= m;i++)
	{
		while (j && s[i] != p[j + 1]) j = ne[j];
		if (s[i] == p[j + 1]) j++;
		if (j == n)
		{
			printf("%d ", i - n);
			j = ne[j];
		}
	}
	return 0;
}









//ջ(��/��ϣ��)--���ʽ��ֵ
#include<iostream>
#include<cstring>
#include<algorithm>
#include<stack>
#include<unordered_map>
using namespace std;
stack<int> num;
stack<char> op;
void eval()
{
	auto b = num.top();num.pop();
	auto a = num.top();num.pop();
	auto c = op.top();op.pop();
	int x;
	if (c == '+') x = a + b;
	else if (c == '-') x = a - b;
	else if (c == '*') x = a * b;
	else x = a / b;
	num.push(x);
}
int main()
{
	unordered_map<char, int> pr{ {'+',1},{'-',1},{'*',2},{'/',2} };
	string str;
	cin >> str;
	for (int i = 0;i < str.size();i++)
	{
		auto c = str[i];
		if (isdigit(c))
		{
			int x = 0, j = i;
			while (j < str.size() && isdigit(str[j]))
				x = x * 10 + str[j++] - '0';
			i = j - 1;
			num.push(x);
		}
		else if (c == '(') op.push(c);
		else if (c == ')')
		{
			while (op.top() != '(') eval();
			op.pop();
		}
		else
		{
			while (op.size() && pr[op.top()] >= pr[c]) eval();
			op.push(c);
		}
	}
	while (op.size()) eval();
	cout << num.top() << endl;
	return 0;
}






//Trie:(�ֵ�) ��Ч�ش洢�Ͳ����ַ���
#include<iostream>
using namespace std;
const int N = 1e5 + 10;
int son[N][26], cnt[N], idx;//�±�Ϊ0�ĵ㣬���Ǹ��ڵ㣬Ҳ�ǿսڵ�
char str[N];
void insert(char str[])
{
	int p = 0;
	for (int i = 0;str[i];i++)
	{
		int u = str[i] - 'a';
		if (!son[p][u]) son[p][u] = ++idx;
		p = son[p][u];
	}
	cnt[p]++;
}
int query(char str[])
{
	int p = 0;
	for (int i = 0;str[i];i++)
	{
		int u = str[i] - 'a';
		if (!son[p][u]) return 0;
		p = son[p][u];
	}
	return cnt[p];
}
int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		string op;
		cin >> op >> str;
		if (op == "I") insert(str);
		else cout << query(str) << endl;
	}
	return 0;
}


//�������--Trie��
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1e5 + 10, M = 3e6;
int n, idx;
int son[M][2];
int a[N];
void insert(int x)
{
	int p = 0;
	for (int i = 30;~i;i--)
	{
		/*int& s = son[p][x >> i & 1];
		if (!s) s = ++idx;
		p = s;*/
		int u = x >> i & 1;
		if (!son[p][u]) son[p][u] = ++idx;
		p = son[p][u];
	}
}
int query(int x)
{
	int res = 0, p = 0;
	for (int i = 30;~i;i--)
	{
		int s = x >> i & 1;
		if (son[p][!s])
		{
			res += 1 << i;
			p = son[p][!s];
		}
		else p = son[p][s];
	}
	return res;
}
int main()
{
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		cin >> a[i];
		insert(a[i]);
	}
	int res = 0;
	for (int i = 0;i < n;i++) res = max(res, query(a[i]));
	cout << res << endl;
	return 0;
}







//���鼯
#include<iostream>
using namespace std;
const int N = 1e5 + 10;
int n, m;
int p[N];//����Ǹ�Ԫ�صĸ��׽��
int find(int x)//����x�����ڽ��+·���Ż�
{
	if (p[x] != x) p[x] = find(p[x]);
	return p[x];
}
int main()
{
	cin >> n >> m;
	for (int i = 1;i <= n;i++) p[i] = i;
	while (m--)
	{
		char op;
		int a, b;
		cin >> op >> a >> b;
		if (op == 'M') p[find(a)] = find(b);
		else
		{
			if (find(a) == find(b)) puts("YES");
			else puts("NO");
		}
	}
	return 0;
}







/*


//�鲢��--��ͨ���е������
#include<iostream>
using namespace std;
const int N = 1e5 + 10;
int n, m;
int p[N],s[N];//����Ǹ�Ԫ�صĸ��׽��
int find(int x)//����x�����ڽ��+·���Ż�
{
	if (p[x] != x) p[x] = find(p[x]);
	return p[x];
}
int main()
{
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		p[i] = i;
		s[i] = 1;
	}
	while (m--)
	{
		char op[5];
		int a, b;
		cin >> op ;
		if (op[0] == 'C')
		{
			cin >> a >> b;
			if (find(a) == find(b)) continue;
			s[find(b)] += s[find(a)];
			p[find(a)] = find(b);
			
		}
		else if(op[1]=='1')
		{
			cin >> a >> b;
			if (find(a) == find(b)) puts("Yes");
			else puts("No");
		}
		else
		{
			cin >> a;
			cout << s[find(a)] << endl;
		}
	}
	return 0;
}

*/



/*

//ʳ����--���鼯
#include<iostream>
using namespace std;
const int N = 5e+10;
int n, m;
int p[N], d[N];
int find(int x)
{
	if (p[x] != x)
	{
		int t = find(p[x]);
		d[x] += d[p[x]];
		p[x] = t;
	}
	return p[x];
}
int main()
{
	cin >> n >> m;
	for (int i = 1;i <= n;i++) p[i] = i;
	int res = 0;
	while(m--)
	{
		int t, x, y;
		cin >> t >> x >> y;
		if (x > n || y > n) res++;
		else
		{
			int px = find(x), py = find(y);
			if (t == 1)
			{
				if (px == py && (d[x] - d[y]) % 3) res++;
				else if (px != py)
				{
					p[p[x]] = py;
					d[px] = d[y] - d[x];
				}
			}
			else
			{
				if ((px == py) && (d[x] - d[y] - 1) % 3) res++;
				else if (px != py)
				{
					p[px] = py;
					d[px] = d[y] + 1 - d[x];
				}
			}
		}
	}
	cout << res << endl;
	return 0;
}
*/


//������
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1e5 + 10;
int n, m;
int h[N],sz;
void down(int u)
{
	int t = u;
	if (u * 2 <= sz && h[u * 2] < h[t]) t = u * 2;
	if (u * 2 + 1 <= sz && h[u * 2 + 1] < h[t]) t = u * 2 + 1;
	if (u != t)
	{
		swap(h[u], h[t]);
		down(t);
	}
}
int main()
{
	cin >> n >> m;
	for (int i = 1;i <= n;i++) cin >> h[i];
	sz = n;
	for (int i = n / 2;i;i--) down(i);
	while (m--)
	{
		cout << h[1] << " ";
		h[1] = h[sz--];
		down(1);
	}
	return 0;
}



//ģ���
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
const int N = 1e5 + 10;
int h[N], ph[N], hp[N], sz;
void heap_swap(int a, int b)
{
	swap(ph[hp[a]], ph[hp[b]]);
	swap(hp[a], hp[b]);
	swap(h[a], h[b]);
}
void down(int u)
{
	int t = u;
	if (u * 2 <= sz && h[u * 2] < h[t]) t = u * 2;
	if (u * 2 + 1 <= sz && h[u * 2 + 1] < h[t]) t = u * 2 + 1;
	if (u != t)
	{
		heap_swap(u,t);
		down(t);
	}
}
void up(int u)
{
	while (u / 2 && h[u / 2] > h[u])
	{
		heap_swap(u, u / 2);
		u /= 2;
	}
}
int main()
{
	int n,m=0;
	cin >> n;
	while (n--)
	{
		char op[10];
		int k, x;
		cin >> op;
		if (!strcmp(op, "I"))
		{
			cin >> x;
			sz++;
			m++;
			ph[m] = sz, hp[sz] = m;
			h[sz] = x;
			up(sz);
		}
		else if (!strcmp(op, "PM")) cout << h[1] << endl;
		else if (!strcmp(op, "DM"))
		{
			heap_swap(1, sz);
			sz--;
			down(1);
		}
		else if (!strcmp(op, "D"))
		{
			cin >> k;
			k = ph[k];
			heap_swap(k, sz);
			sz--;
			down(k), up(k);
		}
		else
		{
			cin >> k >> x;
			k = ph[k];
			h[k] = x;
			down(k), up(k);
		}
	}
	return 0;
}






//��ϣ��--ģ��ɢ�б�--������
#include<iostream>
#include<cstring>
using namespace std;
const int N = 1e5 + 3;
int h[N], e[N], ne[N], idx;
void insert(int x)
{
	int k = (x % N + N) % N;
	e[idx] = x, ne[idx] = h[k], h[k] = idx++;
}
bool find(int x)
{
	int k = (x % N + N) % N;
	for (int i = h[k]; i != -1;i = ne[i])
		if (e[i] == x)
			return true;
	return false;
}
int main()
{
	int n;
	cin >> n;
	memset(h, -1, sizeof h);
	while (n--)
	{
		char op;
		int x;
		cin >> op >> x;
		if (op == 'I') insert(x);
		else
		{
			if (find(x)) puts("Yes");
			else puts("No");
		}
	}
	return 0;
}




//��ϣ��--ģ��ɢ�б�--����Ѱַ��
#include<iostream>
#include<cstring>
using namespace std;
const int N = 2e5 + 3, null = 0x3f3f3f3f;
int h[N];
bool fin(int x)
{
	int k = (x % N + N) % N;
	while (h[k] != null && h[k] != x)
	{
		k++;
		if (k == N) k = 0;
	}
	return k;
}
int main()
{
	int n;
	cin >> n;
	memset(h, 0x3f, sizeof h);
	while (n--)
	{
		char op;
		int x;
		cin >> op >> x;
		int k = fin(x);
		if (op == 'I') h[k]=x;
		else
		{
			if (h[k]!=null) puts("Yes");
			else puts("No");
		}
	}
	return 0;
}




//�ַ�����ϣ
#include<iostream>
using namespace std;
typedef unsigned long long ULL;
const int N = 1e5 + 10, P = 131;
int n, m;
char str[N];
ULL h[N], p[N];
ULL get(int l, int r)
{
	return h[r] - h[l - 1] * p[r - l + 1];
}
int main()
{
	cin >> n >> m >> str + 1;
	p[0] = 1;
	for (int i = 1;i <= n;i ++ )
	{
		p[i] = p[i - 1] * P;
		h[i] = h[i - 1] * P + str[i];
	}
	while (m--)
	{
		int l1, r1, l2, r2;
		cin >> l1 >> r1 >> l2 >> r2;
		if (get(l1, r1) == get(l2, r2)) puts("Yes");
		else puts("No");
	}
	return 0;
}

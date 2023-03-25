#define  _CRT_SECURE_NO_WARNINGS 1
//格子游戏
//#include<iostream>
//using namespace std;
//const int N = 40010;
//int n, m;
//int p[N];
//int get(int x, int y)
//{
//	return x * n + y;
//}
//int find(int x)
//{
//	if (x != p[x]) p[x] = find(p[x]);
//	return p[x];
//}
//int main()
//{
//	cin >> n >> m;
//	for (int i = 0;i < n * n;i++) p[i] = i;
//	int res = 0;
//	for (int i = 1;i <= m;i++)
//	{
//		int x, y;
//		char d;
//		cin >> x >> y >> d;
//		x--, y--;
//		int a = get(x, y);
//		int b;
//		if (d == 'D') b = get(x + 1, y);
//		else b = get(x, y + 1);
//
//		int pa = find(a), pb = find(b);
//		if (pa == pb)
//		{
//			res = i;
//			break;
//		}
//		p[pa] = pb;
//	}
//	if (!res) cout << "draw" << endl;
//	else cout << res << endl;
//
//}




//搭配购买
//#include<iostream>
//#include<algorithm>
//#include<cstring>
//using namespace std;
//const int N = 10010;
//int n, m, vol;
//int v[N], w[N];
//int p[N];
//int f[N];
//int find(int x)
//{
//	if (p[x] != x) p[x] = find(p[x]);
//	return p[x];
//}
//int main()
//{
//	cin >> n >> m >> vol;
//	for (int i = 1;i <= n;i++) p[i] = i;
//	for (int i = 1;i <= n;i++) cin >> v[i] >> w[i];
//	while (m--)
//	{
//		int a, b;
//		cin >> a >> b;
//		int pa = find(a), pb = find(b);
//		if (pa != pb)
//		{
//			v[pb] += v[pa];
//			w[pb] += w[pa];
//			p[pa] = p[pb];
//		}
//	}
//	for (int i = 1;i <= n;i++)
//		if (p[i] == i)
//			for (int j = vol;j >= v[i];j--)
//				f[j] = max(f[j], f[j - v[i]] + w[i]);
//	cout << f[vol] << endl;
//}




//程序自动分析
//#include<iostream>
//#include<algorithm>
//#include<cstring>
//#include<unordered_map>
//using namespace std;
//const int N = 2000010;
//int n, m;
//int p[N];
//unordered_map<int, int>s;
//struct query
//{
//	int x, y, e;
//}q[N];
//int get(int x)
//{
//	if (s.count(x) == 0) s[x] = ++n;
//	return s[x];
//}
//int find(int x)
//{
//	if (p[x] != x) p[x] = find(p[x]);
//	return p[x];
//}
//int main()
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		n = 0;
//		s.clear();
//		cin >> m;
//		for (int i = 0;i < m;i++)
//		{
//			int x, y, e;
//			cin >> x >> y >> e;
//			q[i] = { get(x), get(y), e };
//		}
//		for (int i = 1;i <= n;i++) p[i] = i;
//		for(int i=0;i<m;i++)
//			if (q[i].e == 1)
//			{
//				int pa = find(q[i].x), pb = find(q[i].y);
//				p[pa] = pb;
//			}
//		bool has_conflict = false;
//		for(int i=0;i<m;i++)
//			if (q[i].e == 0)
//			{
//				int pa = find(q[i].x), pb = find(q[i].y);
//				if (pa == pb)
//				{
//					has_conflict = true;
//					break;
//				}
//			}
//		if (has_conflict) puts("NO");
//		else puts("YES");
//	}
//}



//银河英雄传说
//#include<iostream>
//#include<algorithm>
//#include<cstring>
//using namespace std;
//const int N = 30010;
//int m;
//int p[N], sz[N], d[N];
//int find(int x)
//{
//	if (x != p[x])
//	{
//		int root = find(p[x]);
//		d[x] += d[p[x]];
//		p[x] = root;
//	}
//	return p[x];
//}
//int main()
//{
//	cin >> m;
//	for (int i = 1;i < N;i++)
//	{
//		p[i] = i;
//		sz[i] = 1;
//	}
//	while (m--)
//	{
//		char op[2];
//		int a, b;
//		cin >> op >> a >> b;
//		if (op[0] == 'M')
//		{
//			int pa = find(a), pb = find(b);
//			if (pa != pb)
//			{
//				d[pa] = sz[pb];
//				sz[pb] += sz[pa];
//				p[pa] = pb;
//			}
//		}
//		else
//		{
//			int pa = find(a), pb = find(b);
//			if (pa != pb) cout << -1 << endl;
//			else cout << max(0, abs(d[a] - d[b]) - 1) << endl;
//		}
//	}
//}




//奇偶游戏-带边权写法
//#include<iostream>
//#include<algorithm>
//#include<cstring>
//#include<unordered_map>
//using namespace std;
//const int N = 20010;
//int n, m;
//int p[N], d[N];
//unordered_map<int, int>s;
//int get(int x)
//{
//	if (s.count(x) == 0) s[x] = ++n;
//	return s[x];
//}
//int find(int x)
//{
//	if (p[x] != x)
//	{
//		int root = find(p[x]);
//		d[x] += d[p[x]];
//		p[x] = root;
//	}
//	return p[x];
//}
//int main()
//{
//	cin >> n >> m;
//	n = 0;
//	for (int i = 0;i < N;i++) p[i] = i;
//	int res = m;
//	for (int i = 1;i <= m;i++)
//	{
//		int a, b;
//		string type;
//		cin >> a >> b >> type;
//		a = get(a - 1), b = get(b);
//		int t = 0;
//		if (type == "odd") t = 1;
//		int pa = find(a), pb = find(b);
//		if (pa == pb)
//		{
//			if (((d[a] + d[b]) % 2 + 2) % 2 != t)
//			{
//				res = i - 1;
//				break;
//			}
//		}
//		else
//		{
//			p[pa] = pb;
//			d[pa] = d[a] ^ d[b] ^ t;
//		}
//	}
//	cout << res << endl;
//}


//扩展域写法
#include <cstring>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

const int N = 40010, Base = N / 2;

int n, m;
int p[N];
unordered_map<int, int> S;

int get(int x)
{
    if (S.count(x) == 0) S[x] = ++n;
    return S[x];
}

int find(int x)
{
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main()
{
    cin >> n >> m;
    n = 0;

    for (int i = 0; i < N; i++) p[i] = i;

    int res = m;
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        string type;
        cin >> a >> b >> type;
        a = get(a - 1), b = get(b);

        if (type == "even")
        {
            if (find(a + Base) == find(b))
            {
                res = i - 1;
                break;
            }
            p[find(a)] = find(b);
            p[find(a + Base)] = find(b + Base);
        }
        else
        {
            if (find(a) == find(b))
            {
                res = i - 1;
                break;
            }

            p[find(a + Base)] = find(b);
            p[find(a)] = find(b + Base);
        }
    }

    cout << res << endl;

    return 0;
}


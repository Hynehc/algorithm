#define  _CRT_SECURE_NO_WARNINGS 1
//�����·
//Dijkstra--����--O(n^2)
/*
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 510;
int g[N][N];//Ϊ�������������ڽӾ���洢
int dist[N];//��¼ÿһ���㵽��һ����ľ���
bool st[N];//���ڼ�¼�õ����̾����Ƿ��Ѿ�ȷ��
int n, m;
int Dijkstra()
{
	memset(dist, 0x3f, sizeof dist);//�����ʼ��
	dist[1] = 0;//��һ���㵽�Լ�Ϊ0
	for (int i = 0;i < n;i++)//n���㣬����n�ε���
	{
		int t = -1;//t���浱ǰ���ʵĵ�
		for (int j = 1;j <= n;j++)
			if (!st[j] && (t == -1 || dist[t] > dist[j])) // �ò��輴Ѱ�һ�δȷ�����·�ĵ���·����̵ĵ�
				t = j;
		st[t] = true;
		for (int j = 1;j <= n;j++)//���¾���,ÿһ��������һ��
			dist[j] = min(dist[j], dist[t] + g[t][j]);
	}
	if (dist[n] == 0x3f3f3f3f) return -1;
	return dist[n];
}
int main()
{
	cin >> n >> m;
	memset(g, 0x3f, sizeof g);
	while (m--)
	{
		int x, y, z;
		cin >> x >> y >> z;
		g[x][y] = min(g[x][y], z);//����ر�������̱�--x->y
	}
	cout << Dijkstra() << endl;
	return 0;
}*/






////Dijkstra--���Ż�--O(m*logn)
/*
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
typedef pair<int, int>PII;
const int N = 150010;
int h[N], w[N], e[N], ne[N], idx;//w[N]��Ȩ��
int dist[N];//��¼ÿһ���㵽��һ����ľ���
bool st[N];//���ڼ�¼�õ����̾����Ƿ��Ѿ�ȷ��
int n, m;
void add(int a, int b, int c)
{
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}
int Dijkstra()
{
	memset(dist, 0x3f, sizeof dist);//�����ʼ��
	dist[1] = 0;//��һ���㵽�Լ�Ϊ0

	priority_queue <PII, vector<PII>, greater<PII>> heap;//С����
	heap.push({ 0,1 });//�������ͽڵ���
	while (heap.size())
	{
		PII k = heap.top();//ȡ����Դ������ĵ�
		heap.pop();
		int ver = k.second, distance = k.first;//ver:�ڵ��ţ�distance:Դ�����ver �ľ���
		if (st[ver]) continue;
		st[ver] = true;
		for (int i = h[ver];i != -1;i = ne[i])//����ver��ָ��Ľڵ����
		{
			int j = e[i];// iֻ�Ǹ��±꣬e���ڴ����i����±��Ӧ�ĵ㡣
			if (dist[j] > distance + w[i])
			{
				dist[j] = distance + w[i];
				heap.push({ dist[j],j });//�����С�������
			}
		}
	}
	if (dist[n] == 0x3f3f3f3f) return -1;
	return dist[n];
}
int main()
{
	cin >> n >> m;
	memset(h,-1,sizeof h);
	while (m--)
	{
		int x, y, z;
		cin >> x >> y >> z;
		add(x, y, z);
	}
	cout << Dijkstra() << endl;
	return 0;
}
*/







//Bellman-Ford---O(nm)
//�б������Ƶ����·
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//const int N = 510, M = 1e5 + 10;
//struct Edge
//{
//	int a, b, w;
//}edges[M];
//int n, m, k;
//int dist[N], backup[N];
//int bellman_ford()
//{
//	memset(dist, 0x3f, sizeof dist);
//	dist[1] = 0;
//	for (int i = 0;i < k;i++)//����k��
//	{
//		memcpy(backup, dist, sizeof dist);//����dist��backup��
//		for (int j = 0;j < m;j++)
//		{
//			int a = edges[j].a, b = edges[j].b, w = edges[j].w;
//			dist[b] = min(dist[b], backup[a] + w);
//		}
//	}
//	if (dist[n] == 0x3f3f3f3f) return -1;
//	else return dist[n];
//}
//int main()
//{
//	cin >> n >> m >> k;
//	for (int i = 0;i < m;i++)
//	{
//		int a, b, w;
//		cin >> a >> b >> w;
//		edges[i] = { a,b,w };
//	}
//	bellman_ford();
//	if (dist[n] > 0x3f3f3f3f / 2) puts("impossible");
//	else cout << dist[n] << endl;
//	return 0;
//}




//spfa--һ��O(m),����O(nm)
//���·
/*
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
typedef pair<int, int>PII;
const int N = 150010;
int h[N], w[N], e[N], ne[N], idx;//w[N]��Ȩ��
int dist[N];//��¼ÿһ���㵽��һ����ľ���
bool st[N];//���ڼ�¼�õ����̾����Ƿ��Ѿ�ȷ��
int n, m;
void add(int a, int b, int c)
{
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}
int spfa()
{
	memset(dist, 0x3f, sizeof dist);//�����ʼ��
	dist[1] = 0;//��һ���㵽�Լ�Ϊ0
	queue<int>q;
	q.push(1);
	st[1] = true;
	while (q.size())
	{
		int t = q.front();
		q.pop();
		st[t] = false;
		for (int i = h[t];i != -1;i = ne[i])
		{
			int j = e[i];
			if (dist[j] > dist[t] + w[i])
			{
				dist[j] = dist[t] + w[i];
				if (!st[j])
				{
					q.push(j);
					st[j] = true;
				}
			}
		}
	}
	return dist[n];
}
int main()
{
	cin >> n >> m;
	memset(h,-1,sizeof h);
	while (m--)
	{
		int x, y, z;
		cin >> x >> y >> z;
		add(x, y, z);
	}
	int t = spfa();
	if (t == 0x3f3f3f3f) puts("impossible");
	else cout << t << endl;
	return 0;
}*/



//spfa--�жϸ���
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
typedef pair<int, int>PII;
const int N = 150010;
int h[N], w[N], e[N], ne[N], idx;//w[N]��Ȩ��
int dist[N];//��¼ÿһ���㵽��һ����ľ���
int cnt[N];//�����жϱ������Ƿ���ڸ���
bool st[N];//���ڼ�¼�õ����̾����Ƿ��Ѿ�ȷ��
int n, m;
void add(int a, int b, int c)
{
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}
bool spfa()
{
	queue<int>q;
	for (int i = 1;i <= n;i++)//�������е��ж�
	{
		st[i] = true;
		q.push(i);
	}
	while (q.size())
	{
		int t = q.front();
		q.pop();
		st[t] = false;
		for (int i = h[t];i != -1;i = ne[i])
		{
			int j = e[i];
			if (dist[j] > dist[t] + w[i])
			{
				dist[j] = dist[t] + w[i];
				cnt[j] = cnt[t] + 1;
				if (cnt[j] >= n) return true;
				if (!st[j])
				{
					q.push(j);
					st[j] = true;
				}
			}
		}
	}
	return false;
}
int main()
{
	cin >> n >> m;
	memset(h, -1, sizeof h);
	while (m--)
	{
		int x, y, z;
		cin >> x >> y >> z;
		add(x, y, z);
	}
	if (spfa()) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}






//Floyd O(n^3)
//���·
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//const int N = 210, INF = 1e9;
//int n, m, Q;
//int d[N][N];
//void floyd()
//{
//	for (int k = 1;k <= n;k++)
//		for (int i = 1;i <= n;i++)
//			for (int j = 1;j <= n;j++)
//				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
//}
//int main()
//{
//	cin >> n >> m >> Q;
//	for(int i=1;i<=n;i++)
//		for (int j = 1;j <= n;j++)
//		{
//			if (i == j) d[i][j] = 0;
//			else d[i][j] = INF;
//		}
//	while (m--)
//	{
//		int a, b, c;
//		cin >> a >> b >> c;
//		d[a][b] = min(d[a][b], c);
//	}
//	floyd();
//	while (Q--)
//	{
//		int a, b;
//		cin >> a >> b;
//		int t = d[a][b];
//		if (t > INF / 2) cout << "impossible" << endl;
//		else cout << t << endl;
//	}
//	return 0;
//}






//Prim--O(n^2)
//����С������
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//const int N = 510, INF = 0x3f3f3f3f;
//int n, m;
//int g[N][N];
//int dist[N];
//bool st[N];
//int prim()
//{
//	memset(dist, 0x3f, sizeof dist);
//	int res = 0;
//	for (int i = 0;i < n;i++)
//	{
//		int t = -1;
//		for (int j = 1;j <= n;j++)
//			if (!st[j] && (t == -1 || dist[t] > dist[j]))
//				t = j;
//		if (i && dist[t] == INF) return INF;
//		//���ǵ�һ��ȡ���Ľڵ㣬���ҵ�ǰ�ڵ�ľ���ΪINF,���ʾû�кͼ����е������ıߡ�
//		if (i) res += dist[t];
//		//���ǵ�һ��ȡ���Ľڵ㣬���������뼯���е������ߣ���С�ߣ�
//		st[t] = true;
//		for (int j = 1;j <= n;j++) dist[j] = min(dist[j], g[t][j]);
//	}
//	return res;
//}
//int main()
//{
//	cin >> n >> m;
//	memset(g, 0x3f, sizeof g);
//	while (m--)
//	{
//		int a, b, c;
//		cin >> a >> b >> c;
//		g[a][b] = g[b][a] = min(g[a][b], c);
//	}
//	int t = prim();
//	if (t == 0x3f3f3f3f) cout << "impossible" << endl;
//	else cout << t << endl;
//}
//



//Kruskal--O(mlogm)
//��С������
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//const int N = 1e5 + 10, M = 2e5 + 10, INF = 0x3f3f3f3f;
//int n, m;
//int p[N];
//struct Edge
//{
//	int a, b, w;
//	bool operator< (const Edge& W)const
//	{
//		return w < W.w;
//	}
//}edges[M];
//int find(int x)
//{
//	if (p[x] != x) p[x] = find(p[x]);
//	return p[x];
//}
//int kruskal()
//{
//	sort(edges, edges + m);
//	for (int i = 1;i <= n;i++) p[i] = i;
//	int res = 0, cnt = 0;
//	for (int i = 0;i < m;i++)
//	{
//		int a = edges[i].a, b = edges[i].b, w = edges[i].w;
//		a = find(a), b = find(b);
//		if (a != b)
//		{
//			p[a] = b;
//			res += w;
//			cnt++;
//		}
//	}
//	if (cnt < n - 1) return INF;
//	return res;
//}
//int main()
//{
//	cin >> n >> m;
//	for (int i = 0;i < m;i++)
//	{
//		int a, b, w;
//		cin >> a >> b >> w;
//		edges[i] = { a,b,w };
//	}
//	int t = kruskal();
//	if (t == INF) puts("impossible");
//	else cout << t << endl;
//	return 0;
//}







//Ⱦɫ���ж�����ͼ--O(m+n)
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 1e5 + 10, M = 2e5 + 10;
int n, m;//��ͱ�
int h[N], e[M], ne[M], idx;//�ڽӱ�洢ͼ
int color[N];//������������ɫ��0 δȾɫ��1 �Ǻ�ɫ��2 �Ǻ�ɫ
void add(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
bool dfs(int u, int c)
{
	color[u] = c;//u�ĵ�� c Ⱦɫ
	for (int i = h[u];i != -1;i = ne[i])//������ u ���ڵĵ�
	{
		int j = e[i];
		if (!color[j])//���ڵĵ�û����ɫ,��ݹ鴦��������ڵ�
		{
			if (!dfs(j, 3 - c)) return false;
		}
		else if (color[j] == c) return false;
	}
	return true;
}
int main()
{
	cin >> n >> m;
	memset(h, -1, sizeof h);
	while (m--)//�����
	{
		int a, b;
		cin >> a >> b;
		add(a, b), add(b, a);
	}
	bool flag = true;
	for (int i = 1;i <= n;i++)
		if (!color[i])//���ûȾɫ
			if (!dfs(i, 1))//Ⱦɫ�õ㣬���ݹ鴦��������ڵĵ�
			{
				flag = false;
				break;
			}
	if (flag) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}




//�������㷨--O(nm)
//����ͼ�����ƥ��
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 510, M = 1e5 + 10;
int n1, n2, m;
int h[N], e[M], ne[M], idx;
int match[N];
bool st[N];
void add(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
bool find(int x)
{
	for (int i = h[x];i != -1;i = ne[i])
	{
		int j = e[i];
		if (!st[j])
		{
			st[j] = true;
			if (match[j] == 0 || find(match[j]))
			{
				match[j] = x;
				return true;
			}
		}
	}
	return false;
}
int main()
{
	cin >> n1 >> n2 >> m;
	memset(h, -1, sizeof h);
	while (m--)
	{
		int a, b;
		cin >> a >> b;
		add(a, b);
	}
	int res = 0;
	for (int i = 1;i <= n1;i++)
	{
		memset(st, false, sizeof st);
		if (find(i)) res++;
	}
	cout << res << endl;
	return 0;
}
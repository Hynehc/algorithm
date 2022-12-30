#define  _CRT_SECURE_NO_WARNINGS 1


//DFS
#include<iostream>
using namespace std;
const int N = 10;
int n;
int path[N];
bool st[N];
void dfs(int u)
{
	if (u == n)
	{
		for (int i = 0;i < n;i++) cout << path[i] << " ";
		puts("");
		return;
	}
	for(int i=1;i<=n;i++)
		if (!st[i])
		{
			path[u] = i;
			st[i] = true;
			dfs(u + 1);
			st[i] = false;//�ָ��ֳ�
		}
}
int main()
{
	cin >> n;
	dfs(0);
	return 0;
}





//DFS--n�ʺ�����
//��һ��������ʽ
#include <iostream>

using namespace std;

const int N = 20;

int n;
char g[N][N];//����
bool col[N], dg[N], udg[N];//col����,dg�ǶԽ���,udg����һ���Խ���

void dfs(int u)
{
	if (u == n)
	{
		for (int i = 0; i < n; i++) puts(g[i]);//���ÿһ��·��
		puts("");
		return;
	}

	for (int i = 0; i < n; i++)
		if (!col[i] && !dg[u + i] && !udg[u - i + n])
		{
			g[u][i] = 'Q';
			col[i] = dg[u + i] = udg[u - i + n] = true;
			dfs(u + 1);
			col[i] = dg[u + i] = udg[u - i + n] = false;
			g[u][i] = '.';
		}
	//u+i��n-u+i�ǽؾ�,���ڵ�g[u]���ϣ���������Խ������ϲ�������������
	//y=x+b b=y-x(Ϊ���ýؾ����0�������ƫ����)
	//y=-x+b b=y+x;//��n��ʾ�Ǹ�
	//(u,i)
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)//��ʼ��
		for (int j = 0; j < n; j++)
			g[i][j] = '.';

	dfs(0);

	return 0;
}


//�ڶ���������ʽ
#include <iostream>

using namespace std;

const int N = 20;

int n;
char g[N][N];//����
bool row[N],col[N], dg[N], udg[N];//col����,dg�ǶԽ���,udg����һ���Խ���

void dfs(int x,int y,int s)
{
	if (y == n) y = 0, x++;
	if (x == n)
	{
		if (s == n)
		{
			for (int i = 0;i < n;i++) puts(g[i]);
			puts("");
		}
		return;
	}
	//����
	dfs(x, y + 1, s);
	//��
	if (!row[x] && !col[y] && !dg[x + y] && !udg[x - y + n])
	{
		g[x][y] = 'Q';
		row[x] = col[y] = dg[x + y] = udg[x - y + n]=true;
		dfs(x, y + 1, s + 1);
		row[x] = col[y] = dg[x + y] = udg[x - y + n] = false;
		g[x][y] = '.';
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)//��ʼ��
		for (int j = 0; j < n; j++)
			g[i][j] = '.';

	dfs(0,0,0);

	return 0;
}







//BFS--���Թ�
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef pair<int, int>PII;
const int N = 110;
int n, m;
int g[N][N];//��ŵ�ͼ
int d[N][N];//��ÿһ���㵽���ľ���
PII q[N * N];//ģ�����    //Prev[N][N]--·��;//����
int bfs()
{
	int hh = 0, tt = 0;
	q[0] = { 0,0 };
	memset(d, -1, sizeof d);//��ʼ������Ϊ-1��ʾû�о����õ�
	d[0][0] = 0;//������-1��0����ʾ�߹����
	int dx[4] = { -1,0,1,0 }, dy[4] = {0,1,0,-1};//�õ��������������
	while (hh <= tt)//���в�Ϊ��
	{
		auto t = q[hh++];//ȡ����ͷԪ��
		for (int i = 0;i < 4;i++)//ö��4������
		{
			int x = t.first + dx[i], y = t.second + dy[i];
			if (x >= 0 && x < n && y >= 0 && y < m && g[x][y] == 0 && d[x][y] == -1)//�ڽ��ڣ���Ϊ�գ���δ�߹�
			{
				d[x][y] = d[t.first][t.second] + 1;//��ʾ�����ľ���
				q[++tt] = { x,y };//���������
			}
		}
	}
	/*int x = n - 1, y = m - 1;
	while (x || y)
	{
		cout << x << " " << y << endl;
		auto t = Prev[x][y];
		x = t.frst, y = t.second;
	}*/
	return d[n - 1][m - 1];//�������½ǵ����ľ���
}
int main()
{
	cin >> n >> m;
	for (int i = 0;i < n;i++)
		for (int j = 0;j < m;j++)
			cin >> g[i][j];
	cout << bfs() << endl;;
	return 0;
}





//BFS--������
#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<queue>
#include<string>
using namespace std;
int bfs(string start)
{
	string end = "12345678x";//����Ŀ��״̬
	queue<string>q;//�������
	unordered_map<string, int>d;//����distance
	q.push(start);
	d[start] = 0;
	int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,-1,1 };
	while (q.size())
	{
		auto t = q.front();
		q.pop();
		int distance = d[t];//��¼��ǰ״̬����
		if (t == end) return distance;//���ؾ���
		int k = t.find('x');
		int x = k / 3, y = k % 3;//��һά����λ��ת��Ϊ��ά��������
		for (int i = 0;i < 4;i++)
		{
			int a = x + dx[i], b = y + dy[i];//ת�ƺ��x������
			if (a >= 0 && a < 3 && b >= 0 && b < 3)//�жϵ�ǰ�����Ƿ�Խ��
			{
				swap(t[k], t[a * 3 + b]);
				if (!d.count(t))
				{
					d[t] = distance + 1;
					q.push(t);
				}
				//�����ǰ״̬�ǵ�һ�α�������ӣ���¼����
				swap(t[k], t[a * 3 + b]);//��ԭ״̬
			}
		}
	}
	return - 1;//�޷��ﵽĿ��״̬������-1
}
int main()
{
	string c, start;
	for (int i = 0;i < 9;i++)
	{
		cin >> c;
		start += c;
	}
	cout << bfs(start) << endl;
	return 0;
}





//����ͼ��������ȱ���--��������
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//const int N = 1e5 + 10, M = N * 2;
//int n;
//int h[N], e[M], ne[M], idx;
//bool st[N];
//int ans = N;// ans ��¼�����ͨ���е���Сֵ ��ʼֵΪN
//void add(int a, int b)
//{
//	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
//}
////��nΪ���������е������
//int dfs(int u)
//{
//	st[u] = true;
//	int sum = 1, res = 0;
//	//res�Ǳ�ʾ��u��ȥ����ʣ�µ�����(��ͨ��)�����ֵ; 
//    //sum��ʾ��uΪ���������ĵ�Ķ��٣���ֵΪ1����Ϊ�Ѿ�����u�����,������õ��ϵ���ͨ������
//	for (int i = h[u];~i;i = ne[i])
//	{
//		int j = e[i];//��e[i]�д洢�����ֵ�����ţ����������������û�б���ѯ��
//		if (!st[j])
//		{
//			int s = dfs(j);//sΪu��������jΪ������ͨ��ĵ���
//			res = max(res, s);//��ǰ����Ҳ��һ����ͨ�� ��ʣ�µ�����(��ͨ��) ȡmax
//			sum += s;//�Զ���sΪ���ڵ������ �Ǹ���uΪ���ڵ�������һ����
//		}
//	}
//	res = max(res, n - sum);
//	ans = min(res, ans);
//	return sum;
//}
//int main()
//{
//	memset(h, -1, sizeof h);
//	cin >> n;
//	for (int i = 0;i < n - 1;i++)
//	{
//		int a, b;
//		cin >> a >> b;
//		add(a, b), add(b, a);//����ͼ
//	}
//	dfs(1);
//	cout << ans << endl;
//	return 0; 
//}
//









////BFS--ͼ�е�Ĳ��
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//const int N = 1e5 + 10;
//int n, m;
//int h[N], e[N], ne[N], idx;
//int d[N], q[N];
//void add(int a, int b)
//{
//	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
//}
//int bfs()
//{
//	int hh = 0, tt = 0;
//	q[0] = 1;
//	memset(d, -1, sizeof d);
//	d[1] = 0;
//	while (hh <= tt)
//	{
//		int t = q[hh++];
//		for (int i = h[t];~i;i = ne[i])
//		{
//			int j = e[i];
//			if (d[j] == -1)
//			{
//				d[j] = d[t] + 1;
//				q[++tt] = j;
//			}
//		}
//	}
//	return d[n];
//}
//int main()
//{
//	cin >> n >> m;
//	memset(h, -1, sizeof h);
//	for (int i = 0;i < m;i++)
//	{
//		int a, b;
//		cin >> a >> b;
//		add(a, b);
//	}
//	cout << bfs() << endl;
//	return 0;
//}



//����ͼ����������
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 1e5 + 10;
int n, m;
int h[N], e[N], ne[N], idx;
int q[N], d[N];//qΪ����,dΪ�õ�����
void add(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
bool topsort()
{
	int hh = 0, tt = -1;

	for (int i = 1; i <= n; i++)
		if (!d[i])
			q[++tt] = i;//�����Ϊ0�ĵ����

	while (hh <= tt)
	{
		int t = q[hh++];

		for (int i = h[t]; i != -1; i = ne[i])
		{
			int j = e[i];
			if (--d[j] == 0)//ɾ����tָ���j�ı�
				q[++tt] = j;//���j�����Ϊ0�������
		}
	}

	return tt == n - 1;//���n���㶼��ӵĻ������ͼΪ����ͼ������true
}

int main()
{
	cin >> n >> m;
	memset(h, -1, sizeof h);
	for (int i = 0;i < m;i++)
	{
		int a, b;
		cin >> a >> b;
		add(a, b);
		d[b]++;//aָ��b,b����ȼ�һ
	}
	if (topsort())
	{
		for (int i = 0;i < n;i++)
			cout << q[i] << " ";
		puts("");
	}
	else
		puts("-1");
	return 0;
}



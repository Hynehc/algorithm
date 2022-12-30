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
			st[i] = false;//恢复现场
		}
}
int main()
{
	cin >> n;
	dfs(0);
	return 0;
}





//DFS--n皇后问题
//第一种搜索方式
#include <iostream>

using namespace std;

const int N = 20;

int n;
char g[N][N];//棋盘
bool col[N], dg[N], udg[N];//col是列,dg是对角线,udg是另一条对角线

void dfs(int u)
{
	if (u == n)
	{
		for (int i = 0; i < n; i++) puts(g[i]);//输出每一条路径
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
	//u+i与n-u+i是截距,且在第g[u]行上，其列上与对角线你上不存在其他棋子
	//y=x+b b=y-x(为了让截距大于0，则加上偏移量)
	//y=-x+b b=y+x;//加n表示非负
	//(u,i)
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)//初始化
		for (int j = 0; j < n; j++)
			g[i][j] = '.';

	dfs(0);

	return 0;
}


//第二种搜索方式
#include <iostream>

using namespace std;

const int N = 20;

int n;
char g[N][N];//棋盘
bool row[N],col[N], dg[N], udg[N];//col是列,dg是对角线,udg是另一条对角线

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
	//不放
	dfs(x, y + 1, s);
	//放
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
	for (int i = 0; i < n; i++)//初始化
		for (int j = 0; j < n; j++)
			g[i][j] = '.';

	dfs(0,0,0);

	return 0;
}







//BFS--走迷宫
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef pair<int, int>PII;
const int N = 110;
int n, m;
int g[N][N];//存放地图
int d[N][N];//存每一个点到起点的距离
PII q[N * N];//模拟队列    //Prev[N][N]--路径;//队列
int bfs()
{
	int hh = 0, tt = 0;
	q[0] = { 0,0 };
	memset(d, -1, sizeof d);//初始化距离为-1表示没有经过该点
	d[0][0] = 0;//让起点从-1到0，表示走过起点
	int dx[4] = { -1,0,1,0 }, dy[4] = {0,1,0,-1};//该点的上下左右坐标
	while (hh <= tt)//队列不为空
	{
		auto t = q[hh++];//取出队头元素
		for (int i = 0;i < 4;i++)//枚举4个方向
		{
			int x = t.first + dx[i], y = t.second + dy[i];
			if (x >= 0 && x < n && y >= 0 && y < m && g[x][y] == 0 && d[x][y] == -1)//在界内，且为空，且未走过
			{
				d[x][y] = d[t.first][t.second] + 1;//表示到起点的距离
				q[++tt] = { x,y };//新坐标入队
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
	return d[n - 1][m - 1];//返回右下角到起点的距离
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





//BFS--八数码
#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<queue>
#include<string>
using namespace std;
int bfs(string start)
{
	string end = "12345678x";//定义目标状态
	queue<string>q;//定义队列
	unordered_map<string, int>d;//定义distance
	q.push(start);
	d[start] = 0;
	int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,-1,1 };
	while (q.size())
	{
		auto t = q.front();
		q.pop();
		int distance = d[t];//记录当前状态距离
		if (t == end) return distance;//返回距离
		int k = t.find('x');
		int x = k / 3, y = k % 3;//将一维数组位置转化为二维数组坐标
		for (int i = 0;i < 4;i++)
		{
			int a = x + dx[i], b = y + dy[i];//转移后的x的坐标
			if (a >= 0 && a < 3 && b >= 0 && b < 3)//判断当前坐标是否越界
			{
				swap(t[k], t[a * 3 + b]);
				if (!d.count(t))
				{
					d[t] = distance + 1;
					q.push(t);
				}
				//如果当前状态是第一次遍历，入队，记录距离
				swap(t[k], t[a * 3 + b]);//还原状态
			}
		}
	}
	return - 1;//无法达到目标状态，返回-1
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





//树与图的深度优先遍历--树的重心
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//const int N = 1e5 + 10, M = N * 2;
//int n;
//int h[N], e[M], ne[M], idx;
//bool st[N];
//int ans = N;// ans 记录最大连通块中的最小值 初始值为N
//void add(int a, int b)
//{
//	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
//}
////以n为根的子树中点的数量
//int dfs(int u)
//{
//	st[u] = true;
//	int sum = 1, res = 0;
//	//res是表示将u点去除后，剩下的子树(连通块)的最大值; 
//    //sum表示以u为根的子树的点的多少，初值为1，因为已经有了u这个点,用来求该点上的连通块数量
//	for (int i = h[u];~i;i = ne[i])
//	{
//		int j = e[i];//用e[i]中存储的数字当做编号，来看看这个数字有没有被查询过
//		if (!st[j])
//		{
//			int s = dfs(j);//s为u点下面以j为结点的连通块的点数
//			res = max(res, s);//当前子树也是一个连通块 和剩下的子树(连通块) 取max
//			sum += s;//以儿子s为根节点的子树 是父亲u为根节点子树的一部分
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
//		add(a, b), add(b, a);//无向图
//	}
//	dfs(1);
//	cout << ans << endl;
//	return 0; 
//}
//









////BFS--图中点的层次
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



//有向图的拓扑序列
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 1e5 + 10;
int n, m;
int h[N], e[N], ne[N], idx;
int q[N], d[N];//q为队列,d为该点的入度
void add(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
bool topsort()
{
	int hh = 0, tt = -1;

	for (int i = 1; i <= n; i++)
		if (!d[i])
			q[++tt] = i;//将入度为0的点入队

	while (hh <= tt)
	{
		int t = q[hh++];

		for (int i = h[t]; i != -1; i = ne[i])
		{
			int j = e[i];
			if (--d[j] == 0)//删除点t指向点j的边
				q[++tt] = j;//如果j的入度为0，则入队
		}
	}

	return tt == n - 1;//如果n个点都入队的话，则该图为拓扑图，返回true
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
		d[b]++;//a指向b,b的入度加一
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



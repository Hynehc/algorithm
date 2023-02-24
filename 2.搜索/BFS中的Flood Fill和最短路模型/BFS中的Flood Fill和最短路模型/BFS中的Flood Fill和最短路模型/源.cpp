#define  _CRT_SECURE_NO_WARNINGS 1
// 池塘计数
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//#define x first
//#define y second
//typedef pair<int, int>PII;
//const int N = 1010, M = N * N;
//int n, m;
//char g[N][N];
//PII q[M];
//bool st[N][N];
//void bfs(int sx, int sy)
//{
//	int hh = 0, tt = 0;
//	q[0] = { sx,sy };
//	st[sx][sy] = true;
//	while (hh <= tt)
//	{
//		auto t = q[hh++];
//		for (int i = t.x - 1;i <= t.x + 1;i++)
//			for (int j = t.y - 1;j <= t.y + 1;j++)
//			{
//				if (i == t.x && j == t.y) continue;
//				if (i < 0 || i >= n || j < 0 || j >= m) continue;
//				if (g[i][j] == '.' || st[i][j]) continue;
//				q[++tt] = { i,j };
//				st[i][j] = true;
//			}
//	}
//}
//int main()
//{
//	cin >> n >> m;
//	for (int i = 0;i < n;i++) cin >> g[i];
//	int cnt = 0;
//	for(int i=0;i<n;i++)
//		for(int j=0;j<m;j++)
//			if (g[i][j] == 'W' && !st[i][j])
//			{
//				bfs(i, j);
//				cnt++;
//			}
//	cout << cnt << endl;
//}





//城堡问题
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#define x first
//#define y second
//using namespace std;
//const int N = 55, M = N * N;
//int n, m;
//int g[N][N];
//typedef pair<int, int>PII;
//PII q[M];
//bool st[N][N];
//int bfs(int sx, int sy)
//{
//	int dx[4] = { 0,-1,0,1 }, dy[4] = { -1,0,1,0 };
//	int hh = 0, tt = 0;
//	int area = 0;
//	q[0] = { sx,sy };
//	st[sx][sy] = true;
//	while (hh <= tt)
//	{
//		auto t = q[hh++];
//		area++;
//		for (int i = 0;i < 4;i++)
//		{
//			int a = t.x + dx[i], b = t.y + dy[i];
//			if (a < 0 || a >= n || b < 0 || b >= m) continue;
//			if (st[a][b]) continue;
//			if (g[t.x][t.y] >> i & 1) continue;
//			q[++tt] = { a,b };
//			st[a][b] = true;
//		}
//	}
//	return area;
//}
//int main()
//{
//	cin >> n >> m;
//	for (int i = 0;i < n;i++)
//		for (int j = 0;j < m;j++)
//			cin >> g[i][j];
//	int cnt = 0, area = 0;
//	for(int i=0;i<n;i++)
//		for(int j=0;j<m;j++)
//			if (!st[i][j])
//			{
//				area = max(area, bfs(i, j));
//				cnt++;
//			}
//	cout << cnt << endl << area << endl;
//}






//山峰和山谷
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#define x first
//#define y second
//using namespace std;
//const int N = 1010, M = N * N;
//typedef pair<int, int>PII;
//int n;
//int h[N][N];
//PII q[M];
//bool st[N][N];
//void bfs(int sx, int sy, bool& has_higher, bool& has_lower)
//{
//	int hh = 0, tt = 0;
//	q[0] = { sx,sy };
//	st[sx][sy] = true;
//	while (hh <= tt)
//	{
//		auto t = q[hh++];
//		for (int i = t.x - 1;i <= t.x + 1;i++)
//			for (int j = t.y - 1;j <= t.y + 1;j++)
//			{
//				if (i < 0 || i >= n || j < 0 || j >= n) continue;
//				if (h[i][j] != h[t.x][t.y])
//				{
//					if (h[i][j] > h[t.x][t.y]) has_higher = true;
//					else has_lower = true;
//				}
//				else if (!st[i][j])
//				{
//					q[++tt] = { i,j };
//					st[i][j] = true;
//				}
//			}
//	}
//}
//int main()
//{
//	cin >> n;
//	for (int i = 0;i < n;i++)
//		for (int j = 0;j < n;j++)
//			cin >> h[i][j];
//	int peak = 0, valley = 0;
//	for(int i=0;i<n;i++)
//		for(int j=0;j<n;j++)
//			if (!st[i][j])
//			{
//				bool has_higher = false, has_lower = false;
//				bfs(i, j, has_higher, has_lower);
//				if (!has_higher) peak++;
//				if (!has_lower) valley++;
//			}
//	cout << peak << " " << valley << endl;
//}




//迷宫问题
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//#define x first
//#define y second
//typedef pair<int, int>PII;
//const int N = 1010, M = N * N;
//int n;
//int g[N][N];
//PII q[M];
//PII pre[N][N];
//void bfs(int sx, int sy)
//{
//	int dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 };
//	int hh = 0, tt = 0;
//	q[0] = { sx,sy };
//	memset(pre, -1, sizeof pre);
//	pre[sx][sy] = { 0,0 };
//	while (hh <= tt)
//	{
//		auto t = q[hh++];
//		for (int i = 0;i < 4;i++)
//		{
//			int a = t.x + dx[i], b = t.y + dy[i];
//			if (a < 0 || a >= n || b < 0 || b >= n) continue;
//			if (g[a][b]) continue;
//			if (pre[a][b].x != -1) continue;
//			q[++tt] = { a,b };
//			pre[a][b] = t;
//		}
//	}
//}
//int main()
//{
//	cin >> n;
//	for (int i = 0;i < n;i++)
//		for (int j = 0;j < n;j++)
//			scanf("%d", &g[i][j]);
//	bfs(n - 1, n - 1);
//	PII end(0, 0);
//	while (true)
//	{
//		printf("%d %d\n", end.x, end.y);
//		if (end.x == n - 1 && end.y == n - 1) break;
//		end = pre[end.x][end.y];
//	}
//}




//武士风度的牛
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#define x first
//#define y second
//using namespace std;
//typedef pair<int, int>PII;
//const int N = 155, M = N * N;
//int n, m;
//char g[N][N];
//PII q[M];
//int dist[N][N];
//int bfs()
//{
//	int dx[] = { -2,-1,1,2,2,1,-1,-2 };
//	int dy[] = { 1,2,2,1,-1,-2,-2,-1 };
//	int sx, sy;
//	for (int i = 0;i <= n;i++)
//		for (int j = 0;j <= m;j++)
//			if (g[i][j] == 'K')
//				sx = i, sy = j;
//	int hh = 0, tt = 0;
//	q[0] = { sx,sy };
//	memset(dist, -1, sizeof dist);
//	dist[sx][sy] = 0;
//	while (hh <= tt)
//	{
//		auto t = q[hh++];
//		for (int i = 0;i < 8;i++)
//		{
//			int a = t.x + dx[i], b = t.y + dy[i];
//			if (a < 0 || a >= n || b < 0 || b >= m) continue;
//			if (g[a][b] == '*') continue;
//			if (dist[a][b] != -1) continue;
//			if (g[a][b] == 'H') return dist[t.x][t.y] + 1;
//			dist[a][b] = dist[t.x][t.y] + 1;
//			q[++tt] = { a,b };
//		}
//	}
//	return -1;
//}
//int main()
//{
//	cin >> m >> n;
//	for (int i = 0;i < n;i++) cin >> g[i];
//	cout << bfs() << endl;
//}





//抓住那头牛
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 1e5 + 10;
int n, k;
int q[N];
int dist[N];
int bfs()
{
	memset(dist, -1, sizeof dist);
	dist[n] = 0;
	q[0] = n;
	int hh = 0, tt = 0;
	while (hh <= tt)
	{
		int t = q[hh++];
		if (t == k) return dist[k];
		if (t + 1 < N && dist[t + 1] == -1)
		{
			dist[t + 1] = dist[t] + 1;
			q[++tt] = t + 1;
		}
		if (t - 1 >= 0 && dist[t - 1] == -1)
		{
			dist[t - 1] = dist[t] + 1;
			q[++tt] = t - 1;
		}
		if (t * 2 < N && dist[t * 2] == -1)
		{
			dist[t * 2] = dist[t] + 1;
			q[++tt] = t * 2;
		}
	}
	return -1;
}
int main()
{
	cin >> n >> k;
	cout << bfs() << endl;
}
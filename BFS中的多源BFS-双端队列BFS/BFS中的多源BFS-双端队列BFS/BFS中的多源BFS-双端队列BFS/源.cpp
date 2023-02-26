#define  _CRT_SECURE_NO_WARNINGS 1
//æÿ’Ûæ‡¿Î
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
//int dist[N][N];
//void bfs()
//{
//	memset(dist, -1, sizeof dist);
//	int hh = 0, tt = -1;
//	for (int i = 0;i < n;i++)
//	{
//		for (int j = 0;j < m;j++)
//		{
//			if (g[i][j] == '1')
//			{
//				dist[i][j] = 0;
//				q[++tt] = { i,j };
//			}
//		}
//	}
//	int dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 };
//	while (hh <= tt)
//	{
//		auto t = q[hh++];
//		for (int i = 0;i < 4;i++)
//		{
//			int a = t.x + dx[i], b = t.y + dy[i];
//			if (a < 0 || a >= n || b < 0 || b >= m) continue;
//			if (dist[a][b] != -1) continue;
//			dist[a][b] = dist[t.x][t.y] + 1;
//			q[++tt] = { a,b };
//		}
//	}
//}
//int main()
//{
//	cin >> n >> m;
//	for (int i = 0;i < n;i++) cin >> g[i];
//	bfs();
//	for (int i = 0;i < n;i++)
//	{
//		for (int j = 0;j < m;j++)
//			cout << dist[i][j] << " ";
//		cout << endl;
//	}
//}






//ƒß∞Â
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<unordered_map>
//#include<queue>
//using namespace std;
//char g[2][4];
//unordered_map<string, pair<char, string>>pre;
//unordered_map<string, int>dist;
//void set(string state)
//{
//	for (int i = 0;i < 4;i++) g[0][i] = state[i];
//	for (int i = 7, j = 0;j < 4;i--, j++) g[1][j] = state[i];
//}
//string get()
//{
//	string res;
//	for (int i = 0;i < 4;i++) res += g[0][i];
//	for (int i = 3;i >= 0;i--) res+=g[1][i];
//	return res;
//}
//string move0(string state)
//{
//	set(state);
//	for (int i = 0;i < 4;i++) swap(g[0][i], g[1][i]);
//	return get();
//}
//string move1(string state)
//{
//	set(state);
//	int v0 = g[0][3], v1 = g[1][3];
//	for (int i = 3;i > 0;i--)
//	{
//		g[0][i] = g[0][i - 1];
//		g[1][i] = g[1][i - 1];
//	}
//	g[0][0] = v0, g[1][0] = v1;
//	return get();
//}
//string move2(string state)
//{
//	set(state);
//	int v = g[0][1];
//	g[0][1] = g[1][1];
//	g[1][1] = g[1][2];
//	g[1][2] = g[0][2];
//	g[0][2] = v;
//	return get();
//}
//int bfs(string start, string end)
//{
//	if (start == end) return 0;
//	queue<string>q;
//	q.push(start);
//	dist[start] = 0;
//	while (!q.empty())
//	{
//		auto t = q.front();
//		q.pop();
//		string m[3];
//		m[0] = move0(t);
//		m[1] = move1(t);
//		m[2] = move2(t);
//		for(int i=0;i<3;i++)
//			if (!dist.count(m[i]))
//			{
//				dist[m[i]] = dist[t] + 1;
//				pre[m[i]] = { 'A' + i,t };
//				q.push(m[i]);
//				if (m[i] == end) return dist[end];
//			}
//	}
//	return -1;
//}
//int main()
//{
//	int x;
//	string start, end;
//	for (int i = 0;i < 8;i++)
//	{
//		cin >> x;
//		end += char(x + '0');
//	}
//	for (int i = 1;i <= 8;i++) start += char('0' + i);
//	int step = bfs(start, end);
//	cout << step << endl;
//	string res;
//	while (end != start)
//	{
//		res += pre[end].first;
//		end = pre[end].second;
//	}
//	reverse(res.begin(), res.end());
//	if (step > 0) cout << res << endl;
//}




//µÁ¬∑Œ¨–ﬁ
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<deque>
//using namespace std;
//#define x first
//#define y second
//typedef pair<int, int>PII;
//const int N = 510, M = N * N;
//int n, m;
//char g[N][N];
//int dist[N][N];
//bool st[N][N];
//int bfs()
//{
//	memset(dist, 0x3f, sizeof dist);
//	memset(st, 0, sizeof st);
//	dist[0][0] = 0;
//	deque<PII>q;
//	q.push_back({ 0,0 });
//	char cs[] = "\\/\\/";
//	int dx[4] = { -1,-1,1,1 }, dy[4] = { -1,1,1,-1 };
//	int ix[4] = { -1,-1,0,0 }, iy[4] = { -1,0,0,-1 };
//	while (q.size())
//	{
//		PII t = q.front();
//		q.pop_front();
//		if (st[t.x][t.y]) continue;
//		st[t.x][t.y] = true;
//		for (int i = 0;i < 4;i++)
//		{
//			int a = t.x + dx[i], b = t.y + dy[i];
//			if (a<0 || a>n || b<0 || b>m)continue;
//			int ca = t.x + ix[i], cb = t.y + iy[i];
//			int d = dist[t.x][t.y] + (g[ca][cb] != cs[i]);
//			if (d < dist[a][b])
//			{
//				dist[a][b] = d;
//				if (g[ca][cb] != cs[i]) q.push_back({ a,b });
//				else q.push_front({ a,b });
//			}
//		}
//	}
//	return dist[n][m];
//}
//int main()
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		cin >> n >> m;
//		for (int i = 0;i < n;+i++) cin >> g[i];
//		int t = bfs();
//		if (t == 0x3f3f3f3f) puts("NO SOLUTION");
//		else cout << t << endl;
//	}
//}

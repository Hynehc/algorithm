#define  _CRT_SECURE_NO_WARNINGS 1
//字串交换
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<unordered_map>
//#include<queue>
//using namespace std;
//const int N = 6;
//int n;
//string A, B;
//string a[N], b[N];
//int extend(queue<string>& q, unordered_map<string, int>& da, unordered_map<string, int>& db, string a[], string b[])
//{
//	int d = da[q.front()];
//	while (q.size() && da[q.front()] == d)
//	{
//		string t = q.front();
//		q.pop();
//		for (int i = 0; i < n; i++)
//			for (int j = 0; j < t.size(); j++)
//				if (t.substr(j, a[i].size()) == a[i])
//				{
//					string r = t.substr(0, j) + b[i] + t.substr(j + a[i].size());
//					if (db.count(r)) return da[t] + 1 + db[r];
//					if (da.count(r)) continue;
//					da[r] = da[t] + 1;
//					q.push(r);
//				}
//	}
//	return 11;
//}
//int bfs()
//{
//	if (A == B) return 0;
//	queue<string>qa, qb;
//	unordered_map<string, int>da, db;
//	qa.push(A), qb.push(B);
//	da[A] = db[B] = 0;
//	int step = 0;
//	while (qa.size() && qb.size())
//	{
//		int t;
//		if (qa.size() < qb.size()) t = extend(qa, da, db, a, b);
//		else t = extend(qb, db, da, b, a);
//		if (t <= 10) return t;
//		if (++step == 10) return -1;
//	}
//	return -1;
//}
//int main()
//{
//	cin >> A >> B;
//	while (cin >> a[n] >> b[n]) n++;
//	int t = bfs();
//	if (t == -1) puts("NO ANSWER!");
//	else cout << t << endl;
//}





//八数码
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<queue>
//#include<unordered_map>
//using namespace std;
//typedef pair<int, string>PIS;
//int f(string state)//估计函数
//{
//	int res = 0;
//	for (int i = 0;i < state.size();i++)
//	{
//		if (state[i] != 'x')
//		{
//			int t = state[i] - '1';
//		res += abs(i / 3 - t / 3) + abs(i % 3 - t % 3);
//		}
//	}
//	return res;
//}
//string bfs(string start)
//{
//	int dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 };
//	char op[4] = { 'u','r','d','l' };
//	string end = "12345678x";
//	unordered_map<string, int>dist;//距离
//	unordered_map<string, pair<string, char>>prev;//存储一个元素由哪种状态,经过哪种操作得来
//	priority_queue<PIS, vector<PIS>, greater<PIS>> heap;//小根堆
//	heap.push({ f(start),start });//加入起点
//	dist[start] = 0;//起点到起点的距离为0
//	while (heap.size())
//	{
//		auto t = heap.top();
//		heap.pop();
//		string state = t.second;
//		if (state == end) break;
//		int step = dist[state];
//		int x, y;
//		for(int i=0;i<state.size();i++)
//			if (state[i] == 'x')
//			{
//				x = i / 3, y = i % 3;
//				break;
//			}
//		string source = state;
//		for (int i = 0;i < 4;i++)
//		{
//			int a = x + dx[i], b = y + dy[i];
//			if (a >= 0 && a < 3 && b >= 0 && b < 3)
//			{
//				swap(state[x * 3 + y], state[a * 3 + b]);//交换下标位置
//				if (!dist.count(state) || dist[state] > step + 1)//如果没有被记录或者小于记录值
//				{
//					dist[state] = step + 1;//更新距离
//					prev[state] = { source,op[i] };//标记由哪种状态转移而来,并且记录执行的操作
//					heap.push({ dist[state] + f(state),state });//加入堆中
//				}
//				swap(state[x * 3 + y], state[a * 3 + b]);//因为要扩展到四个方向,所以要还原
//			}
//		}
//	}
//	string res;
//	while (end != start)
//	{
//		res += prev[end].second;
//		end = prev[end].first;
//	}
//	reverse(res.begin(), res.end());
//	return res;
//}
//int main()
//{
//	string g, c, seq;
//	while (cin >> c)
//	{
//		g += c;
//		if (c != "x") seq += c;
//	}
//	int t = 0;
//	for (int i = 0;i < seq.size();i++)
//		for (int j = i + 1;j < seq.size();j++)
//			if (seq[i] > seq[j])
//				t++;
//	if (t % 2) puts("unsolvable");
//	else cout << bfs(g) << endl;
//}




//第k短路
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<queue>
//#define x first
//#define y second
//using namespace std;
//typedef pair<int, int>PII;
//typedef pair<int, PII>PIII;
//const int N = 1010, M = 200010;
//int n, m, S, T, K;
//int h[N], rh[N], e[M], ne[M], w[M], idx;
//int dist[N],cnt[N];
//bool st[N];
//void add(int h[], int a, int b, int c)
//{
//	e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
//}
//void dijkstra()
//{
//	priority_queue<PII, vector<PII>, greater<PII>>heap;
//	heap.push({ 0,T });//终点T是这里的起点 <距离，点编号>
//	memset(dist, 0x3f, sizeof dist);
//	dist[T] = 0;
//	while (heap.size())
//	{
//		auto t = heap.top();
//		heap.pop();
//		int ver = t.y;
//		if (st[ver]) continue;
//		st[ver] = true;
//		for (int i = rh[ver];~i;i = ne[i])
//		{
//			int j = e[i];
//			if (dist[j] > dist[ver] + w[i])
//			{
//				dist[j] = dist[ver] + w[i];
//				heap.push({ dist[j],j });
//			}
//		}
//	}
//}
//int astar()
//{
//	priority_queue<PIII, vector<PIII>, greater<PIII>>heap;
//	heap.push({ dist[S],{0,S} }); //估价值，{ 真实值，编号 }
//	while (heap.size())
//	{
//		auto t = heap.top();
//		heap.pop();
//		int ver = t.y.y, distance = t.y.x;
//	    cnt[ver] ++;
//		if (cnt[T] == K) return distance;
//		for (int i = h[ver];~i;i = ne[i])
//		{
//			int j = e[i];
//			if (cnt[j] < K)
//				heap.push({ distance + w[i] + dist[j] , { distance + w[i],j } });
//		}
//	}
//	return -1;
//}
//int main()
//{
//	cin >> n >> m;
//	memset(h, -1, sizeof h);
//	memset(rh, -1, sizeof rh);
//	for (int i = 0;i < m;i++)
//	{
//		int a, b, c;
//		cin >> a >> b >> c;
//		add(h, a, b, c);
//		add(rh, b, a, c);
//	}
//	cin >> S >> T >> K;
//	if (S == T) K++;
//	dijkstra();
//	cout << astar() << endl;
//}





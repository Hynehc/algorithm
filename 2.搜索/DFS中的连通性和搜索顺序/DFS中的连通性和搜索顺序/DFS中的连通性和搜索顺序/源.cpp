#define  _CRT_SECURE_NO_WARNINGS 1
//�Թ�
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//const int N = 110;
//int n;
//char g[N][N];
//bool st[N][N];
//int xa, ya, xb, yb;
//int dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 };
//bool dfs(int x, int y)
//{
//	if (g[x][y] == '#') return false;
//	if (x == xb && y == yb) return true;
//	st[x][y] = true;
//	for (int i = 0;i < 4;i++)
//	{
//		int a = x + dx[i], b = y + dy[i];
//		if (a < 0 || a >= n || b < 0 || b >= n) continue;
//		if (st[a][b]) continue;
//		if (dfs(a, b)) return true;
//	}
//	return false;
//}
//int main()
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		cin >> n;
//		for (int i = 0;i < n;i++) cin >> g[i];
//		memset(st, 0, sizeof st);
//		cin >> xa >> ya >> xb >> yb;
//		if (dfs(xa, ya)) puts("YES");
//		else puts("NO");
//	}
//}




//�����
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//const int N = 25;
//int n, m;
//char g[N][N];
//bool st[N][N];
//int dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 };
//int dfs(int x, int y)
//{
//	int cnt = 1;
//	st[x][y] = true;
//	for (int i = 0;i < 4;i++)
//	{
//		int a = x + dx[i], b = y + dy[i];
//		if (a < 0 || a >= n || b < 0 || b >= m) continue;
//		if (g[a][b] != '.') continue;
//		if (st[a][b]) continue;
//		cnt += dfs(a, b);
//	}
//	return cnt;
//}
//int main()
//{
//	while (cin >> m >> n, n || m)
//	{
//		for (int i = 0;i < n;i++) cin >> g[i];
//		int x, y;
//		for (int i = 0;i < n;i++)
//			for (int j = 0;j < m;j++)
//				if (g[i][j] == '@')
//					x = i, y = j;
//		memset(st, 0, sizeof st);
//		cout << dfs(x, y) << endl;
//	}
//}




//������
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//const int N = 10;
//int n, m;
//bool st[N][N];
//int ans;
//int dx[8] = { -2,-1,1,2,2,1,-1,-2 };
//int dy[8] = { 1,2,2,1,-1,-2,-2,-1 };
//void dfs(int x, int y, int cnt)
//{
//	if (cnt == n * m)
//	{
//		ans++;
//		return;
//	}
//	st[x][y] = true;
//	for (int i = 0;i < 8;i++)
//	{
//		int a = x + dx[i], b = y + dy[i];
//		if (a < 0 || a >= n || b < 0 || b >= m) continue;
//		if (st[a][b]) continue;
//		dfs(a, b, cnt + 1);
//	}
//	st[x][y] = false;
//}
//int main()
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		int x, y;
//		cin >> n >> m >> x >> y;
//		ans = 0;
//		dfs(x, y, 1);
//		cout << ans << endl;
//	}
//}



//���ʽ���
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//const int N = 21;
//int n;
//string word[N];
//int g[N][N];
//int used[N];
//int ans;
//void dfs(string dragon, int last)
//{
//	ans = max((int)dragon.size(), ans);
//	used[last]++;
//	for (int i = 0;i < n;i++)
//		if (g[last][i] && used[i] < 2)
//			dfs(dragon + word[i].substr(g[last][i]),i);
//	used[last]--;
//}
//int main()
//{
//	cin >> n;
//	for (int i = 0;i < n;i++) cin >> word[i];
//	char start;
//	cin >> start;
//	for (int i = 0;i < n;i++)
//		for (int j = 0;j < n;j++)
//		{
//			string a = word[i], b = word[j];
//			for (int k = 1;k < min(a.size(), b.size());k++)
//				if (a.substr(a.size() - k, k) == b.substr(0, k))
//				{
//					g[i][j] = k;
//					break;
//				}
//		}
//	for (int i = 0;i < n;i++)
//		if (word[i][0] == start)
//			dfs(word[i], i);
//	cout << ans << endl;
//}





//�ֳɻ�����
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 10;
int n;
int p[N];
int group[N][N];
bool st[N];
int ans = N;
int gcd(int a, int b)
{
	return b ? gcd(b, a % b) : a;
}
bool check(int group[], int gc, int i)// �жϵ�ǰ���е����Ƿ�͸���������(�������ܷ�Ž�����)
{
	for (int j = 0;j < gc;j++)// ö�ٴ�������ÿ����
		if (gcd(p[group[j]], p[i]) > 1) // ֻҪ���������͸����������˾� return false
			return false;
	return true;
}
void dfs(int g, int gc, int tc, int start)
{
	// gΪ��ǰ�����һ���������, gcΪ��ǰ������������������ţ�
	// tcΪ��ǰ����������������, startΪ��ǰ�鿪ʼ�������������;
	if (g >= ans) return;
	if (tc == n) ans = g;  // ������������е���,˵���˽�Ϊ��ǰ�����Ž�,�������Ž�
	bool flag = true;
	for (int i = start;i < n;i++)
		if (!st[i] && check(group[g], gc, i))
		{
			st[i] = true;
			group[g][gc] = i;
			dfs(g, gc + 1, tc + 1, i + 1);
			st[i] = false;
			flag = false;
		}
	if (flag) dfs(g + 1, 0, tc, 0);
}
int main()
{
	cin >> n;
	for (int i = 0;i < n;i++) cin >> p[i];
	dfs(1, 0, 0, 0); 
	// �ӵ�һ����g = 1, ����û����gc = 0��
	// ��û��������tc = 0, ��ǰ�黹δ��ʼ������start = 0�ĳ�ʼ״̬��ʼ����;
	cout << ans << endl;
}
#define  _CRT_SECURE_NO_WARNINGS 1
//С����
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<vector>
//using namespace std;
//typedef long long ll;
//const int N = 12, M = 1 << 10, K = 110;
//int n, m;
//vector<int> state;//��ʾ�Ϸ���״̬
//vector<int> head[M];//ÿһ״̬���п���ת�Ƶ�������״̬
//int cnt[M];
//ll f[N][K][M];
//bool check(int state)
//{
//	for (int i = 0;i < n;i++)
//		if ((state >> i & 1) && (state >> i + 1 & 1))
//			return false;//���������������1�Ļ��Ͳ��Ϸ�
//	return true;
//}
//int count(int state)//����ĳ��״̬����������1�ĸ���
//{
//	int res = 0;
//	for (int i = 0;i < n;i++) res += state >> i & 1;
//	return res;
//}
//int main()
//{
//	cin >> n >> m;
//	for(int i = 0;i < 1 << n;i++)
//		if (check(i))
//		{
//			state.push_back(i);
//			cnt[i] = count(i);
//		}
//	for (int i = 0;i < state.size();i++)
//		for (int j = 0;j < state.size();j++)
//		{
//			int a = state[i], b = state[j];//��a����ʾ��һ��״̬����b����ʾ�ڶ���״̬
//			if ((a & b) == 0 && check(a | b))
//				head[i].push_back(j);
//		}
//	f[0][0][0] = 1;
//	for(int i = 1;i <= n+1;i++)
//		for(int j = 0;j <= m;j++)
//			for(int a = 0;a < state.size();a++)
//				for (int b : head[a])
//				{
//					int c = cnt[state[a]];//��һ������a�����һ��1�ĸ����԰�
//					if (j >= c)
//					{
//						f[i][j][a] += f[i - 1][j - c][b];
//					}
//				}
//	cout << f[n + 1][m][0] << endl;
//	return 0;
//}





//������
//#include<iostream>
//#include<algorithm>
//#include<cstring>
//#include<vector>
//using namespace std;
//const int N = 14, M = 1 << 12, mod = 1e8;
//int n, m;
//int w[N];
//vector<int>state;
//vector<int>head[M];
//int f[N][M];
//bool check(int state)
//{
//	return !(state & (state << 1));
//}
//int main()
//{
//	cin >> n >> m;
//	for(int i = 1;i <= n;i++)
//		for (int j = 0;j < m;j++)
//		{
//			int t;
//			cin >> t;
//			w[i] += !t << j;//��1���0����0���1
//		}
//	for (int i = 0;i < 1 << m;i++)
//		if (check(i))
//			state.push_back(i);
//	for(int i=0;i<state.size();i++)
//		for (int j = 0;j < state.size();j++)
//		{
//			int a = state[i], b = state[j];
//			if ((a & b) == 0)
//				head[i].push_back(j);
//		}
//	f[0][0] = 1;
//	for(int i = 1;i <= n+1;i++)
//		for(int a = 0;a < state.size();a++)
//			for (int b : head[a])
//			{
//				if (w[i] & state[a]) continue;//������Ϊ1���У�w[i]��1ԭ����0��0Ҳ����
//				f[i][a] = (f[i][a] + f[i - 1][b]) % mod;
//			}
//	cout << f[n + 1][0] << endl;
//	return 0;
//}





//�ڱ����
//#include<iostream>
//#include<algorithm>
//#include<cstring>
//#include<vector>
//using namespace std;
//const int N = 110, M = 1 << 10;
//int n, m;
//int g[110];
//int f[2][N][M];
//int cnt[M];
//vector<int> state;
//bool check(int state)
//{
//	for (int i = 0;i < m;i++)
//	{
//		if ((state >> i & 1) && ((state >> i + 1 & 1) || (state >> i + 2 & 1)))
//			return false;
//	}
//	return true;
//}
//int count(int state)
//{
//	int res = 0;
//	for (int i = 0;i < m;i++) res += state >> i & 1;
//	return res;
//}
//int main()
//{
//	cin >> n >> m;
//	for (int i = 1;i <= n;i++)
//		for (int j = 0;j < m;j++)
//		{
//			char c;
//			cin >> c;
//			if (c == 'H') g[i] += 1 << j;
//		}
//	for (int i = 0;i < 1 << m;i++)
//	{
//		if (check(i))
//		{
//			state.push_back(i);
//			cnt[i] = count(i);
//		}
//	}
//	for(int i = 1;i <= n + 2;i++)
//		for(int j = 0;j < state.size();j++)
//			for(int k = 0;k < state.size();k++)
//				for (int u = 0;u < state.size();u++)
//				{
//					int a = state[j], b = state[k], c = state[u];
//					if ((a & b) | (a & c) | (b & c)) continue;
//					if ((g[i - 1] & a) | (g[i] & b)) continue;
//					f[i & 1][j][k] = max(f[i & 1][j][k], f[i - 1 & 1][u][j] + cnt[b]);
//				}
//	cout << f[n + 2 & 1][0][0] << endl;
//	return 0;
//}




//��ŭ��С��
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
#define x first
#define y second
typedef pair<double, double>PDD;
const int N = 18, M = 1 << 18;
const double eps = 1e-8;
int n, m;
PDD q[N];
int path[N][N];
int f[M];
int cmp(double x, double y)
{
	if (fabs(x - y) < eps) return 0;
	if (x < y) return -1;
	return 1;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		for (int i = 0;i < n;i++) cin >> q[i].x >> q[i].y;
		memset(path, 0, sizeof path);
		for (int i = 0;i < n;i++)
		{
			path[i][i] = 1 << i;
			for (int j = 0;j < n;j++)
			{
				double x1 = q[i].x, y1 = q[i].y;
				double x2 = q[j].x, y2 = q[j].y;
				if (!cmp(x1, x2)) continue;
				double a = (y1 / x1 - y2 / x2) / (x1 - x2);
				double b = y1 / x1 - a * x1;
				if (cmp(a, 0) >= 0) continue;
				int state = 0;
				for (int k = 0;k < n;k++)
				{
					double x = q[k].x, y = q[k].y;
					if (!cmp(a * x * x + b * x, y)) state += 1 << k;
				}
				path[i][j] = state;
			}
		}
		memset(f, 0x3f, sizeof f);
		f[0] = 0;
		for (int i = 0;i + 1 < 1 << n;i++)
		{
			int x = 0;
			for (int j = 0;j < n;j++)
			{
				if (!(i >> j & 1))
				{
					x = j;
					break;
				}
			}
			for (int j = 0;j < n;j++)
				f[i | path[x][j]] = min(f[i | path[x][j]], f[i] + 1);
		}
		cout << f[(1 << n) - 1] << endl;
	}
	return 0;
}
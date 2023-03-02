#define  _CRT_SECURE_NO_WARNINGS 1
// 小猫爬山
//#include<iostream>
//#include<algorithm>
//#include<cstring>
//using namespace std;
//const int N = 20;
//int n, m;
//int w[N];
//int sum[N];
//int ans = N;
//void dfs(int u, int k)//u:猫猫的数量，k:小车的数量
//{
//	//最优性剪枝
//	if (k >= ans) return;
//	if (u == n)
//	{
//		ans = k;
//		return;
//	}
//	for (int i = 0;i < k;i++)
//		if (sum[i] + w[u] <= m)
//		{
//			sum[i] += w[u];
//			dfs(u + 1, k);
//			sum[i] -= w[u];
//		}
// // 新开一辆车
//	sum[k] = w[u];
//	dfs(u + 1, k + 1);
//	sum[k] = 0;
//}
//int main()
//{
//	cin >> n >> m;
//	for (int i = 0;i < n;i++) cin >> w[i];
//	sort(w, w + n);
//	reverse(w, w + n);
//	dfs(0, 0);
//	cout << ans << endl;
//}





//数独
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//const int N = 9, M = 1 << N;
//int ones[M], map[M];// one[state]为该state中有几个1, map[state]为state对应的十进制值
//int row[N], col[N], cell[3][3];
//char str[100];
//void init()
//{
//	// 将行和列都用二进制来优化(刚开始的位置都为1)
//	for (int i = 0;i < N;i++) row[i] = col[i] = (1 << N) - 1;
//	for (int i = 0;i < 3;i++)
//		for (int j = 0;j < 3;j++)
//			cell[i][j] = (1 << N) - 1;
//}
//void draw(int x, int y, int t, bool is_set)// 在(x, y)的位置上(is_set)<是/否>填t的操作 
//{
//	if (is_set) str[x * N + y] = '1' + t;
//	else str[x * N + y] = '.';
//	int v = 1 << t;// 找到该数对应二进制之后的位置的数
//	if (!is_set) v = -v;// 如果该位置不填数，则将该数取负
//	row[x] -= v;//在这个原数对应的行减去该数的二进制数
//	col[y] -= v;// 在这个原数对应的列减去该数的二进制数
//	cell[x / 3][y / 3] -= v;// 在这个原数对应的小方格减去该数的二进制数
//}
//int lowbit(int x)
//{
//	return x & -x;
//}
//int get(int x, int y)// get(x, y) 找到该位置可以填哪些数的状态
//{
//	return row[x] & col[y] & cell[x / 3][y / 3];
//}
//bool dfs(int cnt)
//{
//	if (!cnt) return true;// 知道没有位置能填数就结束搜索
//	int minv = 10;// 记录当前最少枚举方案
//	int x, y; // x, y记录枚举方案最少的位置的x, y
//	for (int i = 0;i < N;i++)
//		for (int j = 0;j < N;j++)
//			if (str[i * N + j] == '.') // 该位置对应的字符串位置上为'.', 才说明能填数
//			{
//				int state = get(i, j);// 找到该位置上能填的数的状态
//				if (ones[state] < minv)// 只有当当前位置的方案少于当前最少方案才有搜索的必要
//				{
//					minv = ones[state];
//					x = i, y = j;
//				}
//			}
//	int state = get(x, y);// 找到最少枚举方案对应的位置的能填的数的状态
//	for (int i = state;i;i -= lowbit(i)) // 枚举该位置上能填的数
//	{
//		int t = map[lowbit(i)];// 找到该位置上能填的数
//		draw(x, y, t, true);// 填数
//		if (dfs(cnt - 1)) return true;// 继续搜索
//		draw(x, y, t, false);// 恢复
//	}
//	return false;
//}
//int main()
//{
//	for (int i = 0;i < N;i++) map[1 << i] = i; // 预处理map[]
//	for (int i = 0;i < 1 << N;i++)
//		for (int j = 0;j < N;j++)
//			ones[i] += i >> j & 1;// 预处理one[]
//	while (cin >> str, str[0] != 'e')
//	{
//		init();
//		int cnt = 0;// 记录有几个空格需要填数
//		for (int i = 0, k = 0;i < N;i++)
//			for (int j = 0;j < N;j++, k++)
//				if (str[k] != '.')
//				{
//					int t = str[k] - '1';
//					draw(i, j, t, true);
//				}
//				else cnt++;
//		dfs(cnt);
//		puts(str);
//	}
//}




//木棒
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//const int N = 70;
//int n;
//int w[N], sum, length;
//bool st[N];
//bool dfs(int u, int s, int start)//第u组，已有长度为s,第u组枚举的位置start
//{
//	if (u * length == sum) return true;//如果总长度到达了,返回true
//	if (s == length) return dfs(u + 1, 0, 0);
//	for (int i = start;i < n;i++)
//	{
//		if (st[i]) continue;
//		if (s + w[i] > length) continue;//大棍加小棍大于限制的长度
//		st[i] = true;
//		if (dfs(u, s + w[i], i + 1)) return true;
//		st[i] = false;
//		//如果第一根失败了或者最后一根失败了,就一定失败
//		if (!s) return false;
//		if (s + w[i] == length) return false;
//		int j = i;//如果i失败了,那么长度跟i一样的棍子也一定失败
//		while (j < n && w[j] == w[i]) j++;
//		i = j - 1;
//	}
//	return false;
//}
//int main()
//{
//	while (cin >> n, n)
//	{
//		memset(st, 0, sizeof st);
//		sum = 0;
//		for (int i = 0;i < n;i++)
//		{
//			cin >> w[i];
//			sum += w[i];
//		}
//		sort(w, w + n);
//		reverse(w, w + n);
//		length = 1;
//		while (true)
//		{
//			if (sum % length == 0 && dfs(0, 0, 0))
//			{
//				cout << length << endl;
//				break;
//			}
//			length++;
//			if (length > sum) break;
//		}
//	}
//	return 0;
//}







//生日蛋糕
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int N = 25, INF = 1e9;
int n, m;
int minv[N], mins[N];
int R[N], H[N];
int ans = INF;
void dfs(int u, int v, int s)//u当前层次，v当前处理的体积和，s当前处理的面积和
{
	if (v + minv[u] > n) return;
	if (s + mins[u] >= ans) return;
	if (s + 2 * (n - v) / R[u + 1] >= ans) return;
	if (!u)
	{
		if (v == n) ans = s;
		return;
	}
	//搜索顺序，先R后H，从大到小
	for (int r = min(R[u + 1] - 1, (int)sqrt(n - v));r >= u;r--)
		for (int h = min(H[u + 1] - 1, (n - v) / r / r);h >= u; h--)
		{
			int t = 0;
			//最底层的时候需要加上r*r
			if (u == m) t = r * r;
			R[u] = r, H[u] = h;
			dfs(u - 1, v + r * r * h, s + 2 * r * h + t);
		}
}
int main()
{
	cin >> n >> m;
	for (int i = 1;i <= m;i++)
	{
		minv[i] = minv[i - 1] + i * i * i;
		mins[i] = mins[i - 1] + 2 * i * i;
	}
	//m+1层不存在，作为哨兵，减少边界情况的判断
	R[m + 1] = H[m + 1] = INF;
	dfs(m, 0, 0);
	if (ans == INF) ans = 0;
	cout << ans << endl;
}
#define  _CRT_SECURE_NO_WARNINGS 1
// Сè��ɽ
//#include<iostream>
//#include<algorithm>
//#include<cstring>
//using namespace std;
//const int N = 20;
//int n, m;
//int w[N];
//int sum[N];
//int ans = N;
//void dfs(int u, int k)//u:èè��������k:С��������
//{
//	//�����Լ�֦
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
// // �¿�һ����
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





//����
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//const int N = 9, M = 1 << N;
//int ones[M], map[M];// one[state]Ϊ��state���м���1, map[state]Ϊstate��Ӧ��ʮ����ֵ
//int row[N], col[N], cell[3][3];
//char str[100];
//void init()
//{
//	// ���к��ж��ö��������Ż�(�տ�ʼ��λ�ö�Ϊ1)
//	for (int i = 0;i < N;i++) row[i] = col[i] = (1 << N) - 1;
//	for (int i = 0;i < 3;i++)
//		for (int j = 0;j < 3;j++)
//			cell[i][j] = (1 << N) - 1;
//}
//void draw(int x, int y, int t, bool is_set)// ��(x, y)��λ����(is_set)<��/��>��t�Ĳ��� 
//{
//	if (is_set) str[x * N + y] = '1' + t;
//	else str[x * N + y] = '.';
//	int v = 1 << t;// �ҵ�������Ӧ������֮���λ�õ���
//	if (!is_set) v = -v;// �����λ�ò��������򽫸���ȡ��
//	row[x] -= v;//�����ԭ����Ӧ���м�ȥ�����Ķ�������
//	col[y] -= v;// �����ԭ����Ӧ���м�ȥ�����Ķ�������
//	cell[x / 3][y / 3] -= v;// �����ԭ����Ӧ��С�����ȥ�����Ķ�������
//}
//int lowbit(int x)
//{
//	return x & -x;
//}
//int get(int x, int y)// get(x, y) �ҵ���λ�ÿ�������Щ����״̬
//{
//	return row[x] & col[y] & cell[x / 3][y / 3];
//}
//bool dfs(int cnt)
//{
//	if (!cnt) return true;// ֪��û��λ���������ͽ�������
//	int minv = 10;// ��¼��ǰ����ö�ٷ���
//	int x, y; // x, y��¼ö�ٷ������ٵ�λ�õ�x, y
//	for (int i = 0;i < N;i++)
//		for (int j = 0;j < N;j++)
//			if (str[i * N + j] == '.') // ��λ�ö�Ӧ���ַ���λ����Ϊ'.', ��˵��������
//			{
//				int state = get(i, j);// �ҵ���λ�������������״̬
//				if (ones[state] < minv)// ֻ�е���ǰλ�õķ������ڵ�ǰ���ٷ������������ı�Ҫ
//				{
//					minv = ones[state];
//					x = i, y = j;
//				}
//			}
//	int state = get(x, y);// �ҵ�����ö�ٷ�����Ӧ��λ�õ����������״̬
//	for (int i = state;i;i -= lowbit(i)) // ö�ٸ�λ�����������
//	{
//		int t = map[lowbit(i)];// �ҵ���λ�����������
//		draw(x, y, t, true);// ����
//		if (dfs(cnt - 1)) return true;// ��������
//		draw(x, y, t, false);// �ָ�
//	}
//	return false;
//}
//int main()
//{
//	for (int i = 0;i < N;i++) map[1 << i] = i; // Ԥ����map[]
//	for (int i = 0;i < 1 << N;i++)
//		for (int j = 0;j < N;j++)
//			ones[i] += i >> j & 1;// Ԥ����one[]
//	while (cin >> str, str[0] != 'e')
//	{
//		init();
//		int cnt = 0;// ��¼�м����ո���Ҫ����
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




//ľ��
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//const int N = 70;
//int n;
//int w[N], sum, length;
//bool st[N];
//bool dfs(int u, int s, int start)//��u�飬���г���Ϊs,��u��ö�ٵ�λ��start
//{
//	if (u * length == sum) return true;//����ܳ��ȵ�����,����true
//	if (s == length) return dfs(u + 1, 0, 0);
//	for (int i = start;i < n;i++)
//	{
//		if (st[i]) continue;
//		if (s + w[i] > length) continue;//�����С���������Ƶĳ���
//		st[i] = true;
//		if (dfs(u, s + w[i], i + 1)) return true;
//		st[i] = false;
//		//�����һ��ʧ���˻������һ��ʧ����,��һ��ʧ��
//		if (!s) return false;
//		if (s + w[i] == length) return false;
//		int j = i;//���iʧ����,��ô���ȸ�iһ���Ĺ���Ҳһ��ʧ��
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







//���յ���
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
void dfs(int u, int v, int s)//u��ǰ��Σ�v��ǰ���������ͣ�s��ǰ����������
{
	if (v + minv[u] > n) return;
	if (s + mins[u] >= ans) return;
	if (s + 2 * (n - v) / R[u + 1] >= ans) return;
	if (!u)
	{
		if (v == n) ans = s;
		return;
	}
	//����˳����R��H���Ӵ�С
	for (int r = min(R[u + 1] - 1, (int)sqrt(n - v));r >= u;r--)
		for (int h = min(H[u + 1] - 1, (n - v) / r / r);h >= u; h--)
		{
			int t = 0;
			//��ײ��ʱ����Ҫ����r*r
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
	//m+1�㲻���ڣ���Ϊ�ڱ������ٱ߽�������ж�
	R[m + 1] = H[m + 1] = INF;
	dfs(m, 0, 0);
	if (ans == INF) ans = 0;
	cout << ans << endl;
}
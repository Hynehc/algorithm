#define  _CRT_SECURE_NO_WARNINGS 1

//LIS �����������
//#include<iostream>
//#include<algorithm>
//using namespace std;
//const int N = 1010;
//int n;
//int a[N], f[N];
//int main()
//{
//	cin >> n;
//	for (int i = 1;i <= n;i++) cin >> a[i];
//	for (int i = 1;i <= n;i++)
//	{
//		f[i] = 1;
//		for (int j = 1;j < i;j++)
//			if (a[j] < a[i])
//				f[i] = max(f[i], f[j] + 1);
//	}
//	int res = 0;
//	for (int i = 1;i <= n;i++) res = max(res, f[i]);
//	cout << res << endl;
//	return 0;
//}


//�ֵ����µĻ�����--LIS ������⣫�������
//#include<iostream>
//#include<algorithm>
//using namespace std;
//const int N = 110;
//int n;
//int a[N], f[N];
//int main()
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		cin >> n;
//		for (int i = 1;i <= n;i++) cin >> a[i];
//		int res = 0;
//		for (int i = 1;i <= n;i++)
//		{
//			f[i] = 1;
//			for (int j = 1;j < i;j++)
//				if (a[i] > a[j])
//					f[i] = max(f[i], f[j] + 1);
//			res = max(res, f[i]);
//		}
//		for (int i = n;i;i--)
//		{
//			f[i] = 1;
//			for (int j = n;j > i;j--)
//				if (a[i] > a[j])
//					f[i] = max(f[i], f[j] + 1);
//			res = max(res, f[i]);
//		}
//		cout << res << endl;
//	}
//	return 0;
//}





//��ɽ
//#include<iostream>
//#include<algorithm>
//using namespace std;
//const int N = 1010;
//int n;
//int a[N], f[N],g[N];
//int main()
//{
//	cin >> n;
//	for (int i = 1;i <= n;i++) cin >> a[i];
//	for (int i = 1;i <= n;i++)
//	{
//		f[i] = 1;
//		for (int j = 1;j < i;j++)
//			if (a[i] > a[j])
//				f[i] = max(f[i], f[j] + 1);
//	}
//	for (int i = n;i;i--)
//	{
//		g[i] = 1;
//		for (int j = n;j > i;j--)
//			if (a[i] > a[j])
//				g[i] = max(g[i], g[j] + 1);
//	}
//	int res = 0;
//	for (int i = 1;i <= n;i++) res = max(res, f[i] + g[i] - 1);
//	cout << res << endl;
//	return 0;
//}




//�ϳ�����
// #include<iostream>
//#include<algorithm>
//using namespace std;
//const int N = 1010;
//int n;
//int a[N], f[N],g[N];
//int main()
//{
//	cin >> n;
//	for (int i = 1;i <= n;i++) cin >> a[i];
//	for (int i = 1;i <= n;i++)
//	{
//		f[i] = 1;
//		for (int j = 1;j < i;j++)
//			if (a[i] > a[j])
//				f[i] = max(f[i], f[j] + 1);
//	}
//	for (int i = n;i;i--)
//	{
//		g[i] = 1;
//		for (int j = n;j > i;j--)
//			if (a[i] > a[j])
//				g[i] = max(g[i], g[j] + 1);
//	}
//	int res = 0;
//	for (int i = 1;i <= n;i++) res = max(res, f[i] + g[i] - 1);
//	cout << n-res << endl;
//	return 0;
//}


// �Ѻó���  ����+LIS
//#include<iostream>
//#include<algorithm>
//using namespace std;
//typedef pair<int, int> PII;
//const int N = 5010;
//int n;
//PII q[N];
//int f[N];
//int main()
//{
//	cin >> n;
//	for (int i = 0;i < n;i++) cin >> q[i].first >> q[i].second;
//	sort(q, q + n);
//	int res = 0;
//	for (int i = 0;i < n;i++)
//	{
//		f[i] = 1;
//		for (int j = 0;j < i;j++)
//			if (q[i].second > q[j].second)
//				f[i] = max(f[i], f[j] + 1);
//		res = max(res, f[i]);
//	}
//	cout << res << endl;
//	return 0;
//}




//������������к�
//#include<iostream>
//#include<algorithm>
//using namespace std;
//const int N = 1010;
//int n;
//int a[N], f[N];
//int main()
//{
//	cin >> n;
//	for (int i = 1;i <= n;i++) cin >> a[i];
//	for (int i = 1;i <= n;i++)
//	{
//		f[i] = a[i];
//		for (int j = 1;j < i;j++)
//			if (a[j] < a[i])
//				f[i] = max(f[i], f[j] + a[i]);
//	}
//	int res = 0;
//	for (int i = 1;i <= n;i++) res = max(res, f[i]);
//	cout << res << endl;
//	return 0;
//}




//���ص���
//#include<iostream>
//#include<algorithm>
//using namespace std;
//const int N = 1010;
//int n;
//int q[N], f[N], g[N];
//int main()
//{
//	while (cin >> q[n]) n++;
//	int res = 0;
//	for (int i = 0;i < n;i++)
//	{
//		f[i] = 1;
//		for (int j = 0;j < i;j++)
//			if (q[j] >= q[i])
//				f[i] = max(f[i], f[j] + 1);
//		res = max(res, f[i]);
//	}
//	cout << res << endl;
//	int cnt = 0;//��ǰ�����еĸ���
//	for (int i = 0;i < n;i++)
//	{
//		int k = 0;//��ǰ����ö�ٵ�����
//		while (k < cnt && g[k] < q[i]) k++;//û��������������&&��ǰ���н�β��С�ڵ�ǰ��
//		g[k] = q[i];//�滻
//		if (k >= cnt) cnt++;//��������
//	}
//	cout<< cnt << endl;
//	return 0;
//}
//





//��������ϵͳ
//#include<iostream>
//#include<algorithm>
//using namespace std;
//const int N = 55;
//int n;
//int q[N], up[N], down[N];
//int ans;
//void dfs(int u, int su, int sd)//��ǰö�ٵ�����--��ǰ���������еĸ���--��ǰ�½������еĸ���
//{
//	if (su + sd >= ans) return;
//	if (u == n)
//	{
//		ans = su + sd;
//		return;
//	}
//	//���1������ǰ���ŵ�����������
//	int k = 0;
//	while (k < su && up[k] >= q[u]) k++;
//	int t = up[k];
//	up[k] = q[u];
//	if (k < su) dfs(u + 1, su, sd);
//	else dfs(u + 1, su + 1, sd);
//	up[k] = t;
//	//���2������ǰ���ŵ��½�������
//	k = 0;
//	while (k < sd && down[k] <= q[u]) k++;
//	t = down[k];
//	down[k] = q[u];
//	if (k < sd) dfs(u + 1, su, sd);
//	else dfs(u + 1, su, sd + 1);
//	down[k] = t;
//}
//int main()
//{
//	while (cin >> n, n)
//	{
//		for (int i = 0;i < n;i++) cin >> q[i];
//		ans = n;
//		dfs(0, 0, 0);
//		cout << ans << endl;
//	}
//	return 0;
//}



//���������������
//#include<iostream>
//#include<algorithm>
//using namespace std;
//const int N = 3010;
//int n;
//int a[N], b[N];
//int f[N][N];
//int main()
//{
//	cin >> n;
//	for (int i = 1;i <= n;i++) cin >> a[i];
//	for (int i = 1;i <= n;i++) cin >> b[i];
//	for (int i = 1;i <= n;i++)
//		for (int j = 1;j <= n;j++)
//		{
//			f[i][j] = f[i - 1][j];
//			//f[i][j]��������a[1 ~ i]��b[1 ~ j]����b[j]��β�Ĺ������������еļ���;
//			if (a[i] == b[j])
//			{
//				f[i][j] = max(f[i][j], 1);
//				for (int k = 1;k < j;k++)
//					if (b[k] < b[j])
//						f[i][j] = max(f[i][j], f[i][k] + 1);
//			}
//		}
//	int res = 0;
//	for (int i = 1;i <= n;i++) res = max(res, f[n][i]);
//	cout << res << endl;
//	return 0;
//}

#include<iostream>
#include<algorithm>
using namespace std;
const int N = 3010;
int n;
int a[N], b[N];
int f[N][N];
int main()
{
	cin >> n;
	for (int i = 1;i <= n;i++) cin >> a[i];
	for (int i = 1;i <= n;i++) cin >> b[i];
	for (int i = 1;i <= n;i++)
	{
		int maxv = 1;
		for (int j = 1;j <= n;j++)
		{
			f[i][j] = f[i - 1][j];
			//f[i][j]��������a[1 ~ i]��b[1 ~ j]����b[j]��β�Ĺ������������еļ���;
			if (a[i] == b[j]) f[i][j] = max(f[i][j], maxv);
			if (b[j] < a[i]) maxv = max(maxv, f[i][j] + 1);
		}
	}
	int res = 0;
	for (int i = 1;i <= n;i++) res = max(res, f[n][i]);
	cout << res << endl;
	return 0;
}


#define  _CRT_SECURE_NO_WARNINGS 1
//���򲻵�ʽ--�ŶӴ�ˮ
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N = 100010;
int n;
int t[N];
int main()
{
	cin >> n;
	for (int i = 0;i < n;i++) cin >> t[i];
	sort(t, t + n);
	ll res = 0;
	for (int i = 0;i < n;i++) res += t[i] * (n - i - 1);
	cout << res << endl;
}







//����ֵ����ʽ--����ѡַ
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 100010;
int n;
int a[N];
int main()
{
	cin >> n;
	for (int i = 0;i < n;i++) cin >> a[i];
	sort(a, a + n);
	int res = 0;
	for (int i = 0;i < n;i++) res += abs(a[i] - a[n / 2]);
	cout << res << endl;
}








//�ƹ�ʽ--ˣ�Ӽ���ţ
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 50010;
typedef pair<int, int>PII;
int n;
PII cow[N];
int main()
{
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		int w, s;
		cin >> w >> s;
		cow[i] = { w + s,w };
	}
	sort(cow, cow + n);
	int res = -2e9, sum = 0;
	for (int i = 0;i < n;i++)
	{
		int w = cow[i].second, s = cow[i].first - w;
		res = max(res, sum - s);
		sum += w;
	}
	cout << res << endl;
}